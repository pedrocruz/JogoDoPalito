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
#include <iostream>

#define separator ","
#define moveConst "<move>"
#define indexConst "<index>"
#define playersConst "<players>"
#define nameConst "<name>"

//move send format: "<move>,hand,guess"
//players subscription format: "<players>,name1,name2,name3
//move reception format: "<move>,hand1,guess1,hand2,guess2..."
//index format: "<index>,index"
//name format: "<name>,name"


class BasketSocket : public QObject
{
Q_OBJECT
public:
    BasketSocket(QWidget *parent = 0);
    QTcpSocket *tcpSocket;
    Player *player;
    QList<Player> otherPlayers;
    QList<int> winnersIndexes;
    qint16 blockSize;
    QString ipAddress;
    QNetworkSession *networkSession;
    bool connected;


    void sendMove(int hand, int guess);
    void connectTo(QString ip, int port);
    void parseMessage(QString message);
    void calculateWinner();
    ~BasketSocket();
signals:
    void gotResults();
    void playersListChanged();
    void indexChanged();
    void allPlayersReady();

 public slots:
    void messageReceived();
    void sendName();

private:
    void sendMessage(QString messageToSend);


};

#endif // BASKETSOCKET_H
