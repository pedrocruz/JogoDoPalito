#ifndef PLAYER_H
#define PLAYER_H

#include <QTcpSocket>
#include <QString>

class Player
{
public:
    Player(QString name);
    Player();
    QString name;
    int maxHand;
    int turn;
    int hand;
    int guess;
    int index;
    int wins;
};

#endif // PLAYER_H
