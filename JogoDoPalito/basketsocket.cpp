#include "basketsocket.h"

BasketSocket::BasketSocket(QWidget *parent)
{
    networkSession = 0;
    tcpSocket = 0;
    blockSize = 0;
}




void BasketSocket::sendMove(int hand, int guess)
{
}

void BasketSocket::connectTo(QString ip, int port)
{
}

void BasketSocket::sendMessage(QString messageToSend)
{
}

void BasketSocket::receiveResults()
{
}

void BasketSocket::sessionOpened()
{
}
BasketSocket::~BasketSocket()
{
}
