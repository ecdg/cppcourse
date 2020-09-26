// Dice Game
// By Emily Dayanghirang

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    const int UPPER_LIMIT = 8;
    const int LOWER_LIMIT = 1;
    const int RANGE = UPPER_LIMIT - LOWER_LIMIT + 1;

    int firstDiceValue, secondDiceValue,
        playerOnePoints=0, playerTwoPoints=0,
        total=0, playerOneRoundsOfGamesWon=0,
        playerTwoRoundsOfGamesWon=0;

    string playAgain;

    // Seed the random number generator
    srand(time(0));

    // Display game information
    cout << "\nWelcome to the dice game\n"
         << "--------------------------------------------------\n";

    cout << "The game has a total of 11 turns.\n"
            "In each turn, it will roll two eight-sided dice.\n"
            "and add up the numbers.\n\n"
            "If the total is even,\n"
            "player one gets a point.\n"
            "If the total is odd,\n"
            "player two gets a point.\n"
         << "--------------------------------------------------\n";

    do
    {
        // Simulates a total of 11 turns
        for(int count = 1, turn = 1; count <= 11; count++, turn++)
        {
            // Restarts the total to 0 for every iteration
            total = 0;

            /* Assigning random numbers within
            the range of 1-8 to generate
            the dice roll
            */
            cout << "\n(#" << turn << " turn)\n";
            cout << "First die rolling...";
            firstDiceValue = rand() % RANGE + LOWER_LIMIT;
            cout << "Result: " << firstDiceValue << endl;

            cout << "Second die rolling...";
            secondDiceValue = rand() % RANGE + LOWER_LIMIT;
            cout << "Result: " << secondDiceValue << endl;

            total += firstDiceValue + secondDiceValue;
            cout << "Total for this round: " << total << endl;

            /* If the total is even,
               player one gets a point.
               If it is odd,
               player two gets a points.
            */

            if(total % 2 == 0)
            {
                playerOnePoints++;
                cout << "A point for player one!\n\n";
            }
            else
            {
                playerTwoPoints++;
                cout << "A point for player two!\n\n";
            }
        }

        // Display the total points of each player
        cout << "\nPlayer one's total points: " << playerOnePoints << endl;
        cout << "Player two's total points: " << playerTwoPoints << endl;

        // Display the winner
        if(playerOnePoints > playerTwoPoints)
        {
            cout << "Player one won." << endl;
            playerOneRoundsOfGamesWon++;
        }
        else
        {
            cout << "Player two won." << endl;
            playerTwoRoundsOfGamesWon++;
        }

        /* Get players' points back to 0
           for when user decides to play again
        */
        playerOnePoints = 0;
        playerTwoPoints = 0;

        // Prompt user
        cout << "\nDo you want to play again?\n"
                "\nEnter Y or y for yes\n"
                "Enter N or n for no: ";
        cin >> playAgain;

    }while(playAgain == "Y" || playAgain == "y");

    cout << "\nRounds of games won for each player:\n"
         << "Player one: " << playerOneRoundsOfGamesWon << endl
         << "Player two: " << playerTwoRoundsOfGamesWon << endl;

    return 0;
}
