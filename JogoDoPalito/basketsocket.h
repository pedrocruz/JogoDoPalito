#ifndef BASKETSOCKET_H
#define BASKETSOCKET_H

#include <QTcpSocket>
#include <QString>
#include <player.h>

class BasketSocket
{
public:
    BasketSocket();
    QTcpSocket socket;
    Player *player;

    ~BasketSocket();

signals:
    void gotResults();
public slots:
    void sendMove();
    void receiveResults();


};

#endif // BASKETSOCKET_H
