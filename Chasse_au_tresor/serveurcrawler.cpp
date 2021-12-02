#include "serveurcrawler.h"
#include "ui_serveurcrawler.h"
#define TAILLE 255

ServeurCrawler::ServeurCrawler(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServeurCrawler)
{

    socketEcoute = new QTcpServer();
    grille = new QGridLayout();
    ui->setupUi(this);
    connect(socketEcoute,&QTcpServer::newConnection,this,&ServeurCrawler::onQTcpServer_newConnection);

}

ServeurCrawler::~ServeurCrawler()
{
    delete ui;
}

void ServeurCrawler::onQTcpServer_newConnection()
{


    QTcpSocket *socketClients;
    connect(socketClients,&QTcpSocket::disconnected,this,&ServeurCrawler::onQTcpSocket_disconnected);
    connect(socketClients,&QTcpSocket::readyRead,this,&ServeurCrawler::onQTcpSocket_readyRead);
    listeSocketsClient.append(socketClients);
    listePositions.append(DonnerPositionUnique());

    QString msg="start";
    quint16 taille=0;
    QBuffer tampon;
    tampon.open(QIODevice::WriteOnly);
    QDataStream out(&tampon);
    //construction de la trame
    out<<taille<<msg;
    //calcul de la taille de la trame
    taille = tampon.size()-sizeof (taille);
    //placement sur la premiere position du flux pour pouvoir modifier la taille
    tampon.seek(0);
    //modification de la trame avec la taille reel de la trame
    out<<taille;
    //envoie du QByteArray du tampon via le socket
    socketClients->write(tampon.buffer());
    this->setLayout(grille);
}

void ServeurCrawler::onQTcpSocket_readyRead()
{
    this->setLayout(grille);
}

void ServeurCrawler::onQTcpSocket_disconnected()

{
    QTcpSocket *client=(QTcpSocket*)sender();
    if (!client)
    {
        QMessageBox msg;
        msg.setText("erreur deconnexion : "+client->errorString());
        msg.exec();
    }
    else
    {
        listeSocketsClient.removeOne(client);
        client->deleteLater();
    }

    this->setLayout(grille);
}

QPoint ServeurCrawler::DonnerPositionUnique()
{
    QRandomGenerator gen;
    QPoint pt;
    gen.seed(QDateTime::currentMSecsSinceEpoch());
    int ligne;
    int colonne;
    do
    {
        ligne = gen.bounded(TAILLE);
        QThread::usleep(20000);
        // attendre 20ms
        colonne = gen.bounded(TAILLE);
        QThread::usleep(20000);
        // attendre 20ms
        pt = QPoint(colonne,ligne);
    }while (listePositions.contains(pt));
    return pt;
}


double ServeurCrawler::CalculerDistance(QPoint pos)
{
    double distance;
    int xVecteur = tresor.x()-pos.x();
    int yVecteur = tresor.y()-pos.y();
    distance = sqrt((xVecteur*xVecteur + yVecteur*yVecteur));
    return distance;
}

void ServeurCrawler::EnvoyerDonnees(QTcpSocket *client, QPoint pt, QString msg)
{

}

void ServeurCrawler::AfficherGrille()
{

}
void ServeurCrawler::ViderGrille()
{

}

