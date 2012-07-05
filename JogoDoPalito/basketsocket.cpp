#include "basketsocket.h"

BasketSocket::BasketSocket()
{
}

BasketSocket::~BasketSocket()
{
    if(this->player){
        delete player;
        player = 0;
    }
}
