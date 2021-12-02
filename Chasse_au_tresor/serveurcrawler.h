#ifndef SERVEURCRAWLER_H
#define SERVEURCRAWLER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QPoint>
#include <QGridLayout>
#include <QRandomGenerator>
#include <QDateTime>
#include <QThread>
#include <QToolButton>
#include <QBuffer>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class ServeurCrawler; }
QT_END_NAMESPACE

class ServeurCrawler : public QWidget
{
    Q_OBJECT

public:
    explicit ServeurCrawler(QWidget *parent = nullptr);
    ~ServeurCrawler();

private:
    Ui::ServeurCrawler *ui;
    QTcpServer *socketEcoute;
    QList <QTcpSocket*> listeSocketsClient;
    QList <QPoint> listePositions;
    QPoint tresor;
    QGridLayout *grille;

private slots :

    void onQTcpServer_newConnection();
    void onQTcpSocket_readyRead();
    void onQTcpSocket_disconnected();
    QPoint DonnerPositionUnique();
    double CalculerDistance(QPoint pos);
    void EnvoyerDonnees(QTcpSocket * client,QPoint pt,QString msg);
    void AfficherGrille();
    void ViderGrille();

};
#endif // SERVEURCRAWLER_H
