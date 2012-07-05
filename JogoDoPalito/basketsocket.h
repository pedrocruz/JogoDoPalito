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
//#define separator ,
//#define moveConst <move>

//move format: "<move>,hand,guess"

class BasketSocket : public QObject
{
    Q_OBJECT

public:
    BasketSocket();


    QTcpSocket *tcpSocket;
    Player *player;
    QList<Player> otherPlayers;
    quint16 blockSize;
    QString ipAddress;
    QNetworkSession *networkSession;
    bool connected;


    void sendMove(int hand, int guess);
    void connectTo(QString ip, int port);
    ~BasketSocket();


signals:
    void gotResults();

public slots:    
    void receiveResults();
    void sessionOpened();

private:
    void sendMessage(QString messageToSend);


};

#endif // BASKETSOCKET_H
