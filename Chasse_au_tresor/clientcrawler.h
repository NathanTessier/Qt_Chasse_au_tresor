#ifndef CLIENTCRAWLER_H
#define CLIENTCRAWLER_H

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

namespace Ui {

class ClientCrawler;
}

class ClientCrawler : public QWidget
{
    Q_OBJECT

public:
    explicit ClientCrawler(QWidget *parent = nullptr);
    ~ClientCrawler();
    void EnvoyerCommande(QChar commande);

private:
    Ui::ClientCrawler *ui;
    QGridLayout *grille;
    QTcpSocket *socketClient;
private slots:
    void onQTcpSocket_connected();

    void onQTcpSocket_disconnected();

    void onQTcpSocket_error(QAbstractSocket::SocketError socketError);

    void onQTcpSocket_readyRead();
};

#endif // CLIENTCRAWLER_H
