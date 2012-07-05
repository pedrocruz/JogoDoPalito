#include "player.h"

Player::Player(QString name)
{
    this->name = name;
    this->guess = 0;
    this->index = 0;
    this->turn = 0;
    this->wins = 0;
}

Player::Player()
{
}
