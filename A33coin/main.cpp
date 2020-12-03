// Heads or Tails
// By Alina Corpora and Emily Dayanghirang
#include "Coin.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
 
void displayWinner(int,int);
 
int main()
{
   int number, player1Count = 0, player2Count = 0;
 
   srand(time(0));
 
   cout << "Player 1's turn (3 tosses): \n";
 
   for(int i = 0; i < 3; i++)
   {
     Coin player1;
    
     if(player1.getSideUp() == 1)
     {
       cout << "User rolled Heads!" << endl;
       player1Count++;
     }
     else
       cout << "User rolled Tails!" << endl;
   }
 
   cout << "\n\nPlayer 2's turn (3 tosses): \n";
 
   for(int i = 0; i < 3; i++)
   {
     Coin player2;
 
     if(player2.getSideUp() == 1)
     {
       cout << "User rolled Heads!" << endl;
       player2Count++;
     }
     else
       cout << "User rolled Tails!" << endl;
   }
 
   displayWinner(player1Count,player2Count);
 
   return 0;
}
 
void displayWinner(int player1, int player2)
{
 if(player1 > player2)
 {
   cout << "\nPlayer 1 is the winner with " << player1
        << " number of heads!";
 }
 else if(player2 > player1)
 {
       cout << "\nPlayer 2 is the winner with " << player2
        << " number of heads!";
 }
 else
 {
   cout << "\nIt's a tie!";
 }
}
