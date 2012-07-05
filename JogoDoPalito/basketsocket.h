#ifndef BASKETSOCKET_H
#define BASKETSOCKET_H

#include <QTcpSocket>
#include <QObject>
#include <QString>
#include <player.h>
#include <QList>
#include <QNetworkSession>
#include <QNetworkConfigurationManager>
#include <QSettings>
#include <QStringList>

#define separator ","
#define moveConst "<move>"

//move format: "<move>,hand,guess"



class BasketSocket : public QObject
{
Q_OBJECT
public:
    BasketSocket(QWidget *parent = 0);
    QTcpSocket *tcpSocket;
    Player *player;
    QList<Player> otherPlayers;
    quint16 blockSize;
    QString ipAddress;
    QNetworkSession *networkSession;
    bool connected;


    void sendMove(int hand, int guess);
    void connectTo(QString ip, int port);
    void parseMessage(QString message);
    ~BasketSocket();
signals:
    void gotResults();

 public slots:
    void receiveResults();
    void sessionOpened();
    void messageReceived();

private:
    void sendMessage(QString messageToSend);


};

#endif // BASKETSOCKET_H
