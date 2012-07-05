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
    gotResults();
public slots:
    sendMove();
    receiveResults();


};

#endif // BASKETSOCKET_H
