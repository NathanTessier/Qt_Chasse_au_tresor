#include "clientcrawler.h"
#include "ui_clientcrawler.h"
#define TAILLE 1024

ClientCrawler::ClientCrawler(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientCrawler)
{
    socketClient = new QTcpSocket (this);
    connect(socketClient,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,
            &ClientCrawler::onQTcpSocket_error);
    connect(socketClient,&QTcpSocket::connected,this,&ClientCrawler::onQTcpSocket_connected);
    connect(socketClient,&QTcpSocket::disconnected,this,&ClientCrawler::onQTcpSocket_disconnected);
    connect(socketClient,&QTcpSocket::readyRead,this,&ClientCrawler::onQTcpSocket_readyRead);


    grille = new QGridLayout();
    ui->setupUi(this);
    for(int ligne=0; ligne<TAILLE; ligne++)
    {
        for (int colonne=0; colonne<TAILLE; colonne++)
        {
            QToolButton *b=new QToolButton();
            grille->addWidget(b,ligne,colonne,1,1);
        }
    }
    // Placement sur la grille des objets présents sur ui
    // les labels
    grille->addWidget(ui->labelAdresseServeur,TAILLE,0,1,5);
    grille->addWidget(ui->labelNumeroPort,TAILLE,6,1,5);
    grille->addWidget(ui->labelDistance,TAILLE+3,0,1,5);
    grille->addWidget(ui->labelInformations,TAILLE+3,12,1,5);
    // les QLineEdit adresse et port
    grille->addWidget(ui->lineEditAdresseServeur,TAILLE+1,0,1,5);
    grille->addWidget(ui->spinBoxPortServeur,TAILLE+1,6,1,5);
    // les QPushButton connexion et quitter
    grille->addWidget(ui->pushButtonConnexion,TAILLE+2,0,1,5);
    grille->addWidget(ui->pushButtonQuitter,TAILLE+2,6,1,5);
    // les QPushButton fleches
    grille->addWidget(ui->pushButtonUp,TAILLE,15,1,1);
    grille->addWidget(ui->pushButtonLeft,TAILLE+1,14,1,1);
    grille->addWidget(ui->pushButtonRight,TAILLE+1,16,1,1);
    grille->addWidget(ui->pushButtonDown,TAILLE+2,15,1,1);
    //distance et informations
    grille->addWidget(ui->lcdNumberDistance,TAILLE+3,6,1,5);
    this->setLayout(grille);

}
ClientCrawler::~ClientCrawler()
{
    delete ui;
}

void ClientCrawler::EnvoyerCommande(QChar commande)
{

    commande = 'N';
    QTcpSocket *socketClient;
    quint16 taille=0;
    QBuffer tampon;
    tampon.open(QIODevice::WriteOnly);
    QDataStream out(&tampon);
    //construction de la trame
    out<<taille<<commande;
    //calcul de la taille de la trame
    taille = tampon.size()-sizeof (taille);
    //placement sur la premiere position du flux pour pouvoir modifier la taille
    tampon.seek(0);
    //modification de la trame avec la taille reel de la trame
    out<<taille;
    //envoie du QByteArray du tampon via le socket
    socketClient->write(tampon.buffer());
}

void ClientCrawler::onQTcpSocket_connected()
{
    qDebug()<<"connecté" << this;
    ui->pushButtonConnexion->setText("Deconnexion");
}

void ClientCrawler::onQTcpSocket_disconnected()
{
    qDebug()<<"deconnecté" << this;
    ui->pushButtonConnexion->setText("Connexion");
}

void ClientCrawler::onQTcpSocket_error(QAbstractSocket::SocketError socketError)
{
    qDebug()<<"erreur" << this;

}

void ClientCrawler::onQTcpSocket_readyRead()
{
    qDebug()<<"Pret pour lire" << this;

}
