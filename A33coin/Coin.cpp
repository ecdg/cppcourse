#include "Coin.h"

Coin::Coin()
{
    sideUp = 0;
}

void Coin::toss(int num)
{
    sideUp = num;
}

int Coin::getSideUp() const
{
    return sideUp;
}