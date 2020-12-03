#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Coin.h"
using namespace std;

const int MAX_VALUE=2,
          MIN_VALUE=1,
          RANGE=MAX_VALUE-MIN_VALUE+1;

int main()
{
    Coin round;
    int number, side;

    srand(time(0));

    number = rand() % RANGE + MIN_VALUE;

    round.toss(number);

    side = round.getSideUp();

    if (side == 1)
        cout << side << ": Heads";
    else
        cout << side << ": Tails";

    return 0;
}