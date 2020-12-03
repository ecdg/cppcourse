#include "Coin.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
Coin::Coin()
{
  toss();
}
void Coin::toss()
{
   int num;
   num = rand() % 2;
   sideUp = num;
}
int Coin::getSideUp() const
{
   return sideUp;
}
