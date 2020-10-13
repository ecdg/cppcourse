// Lottery
// By Emily Dayanghirang
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void displayLotteryNumbers(const int [], int);
void displayUserNumbers(const int [], int);
int countMatchingDigits(const int [], const int [], int);
void results(int);

int main()
{
    const int NUM_DIGITS = 5;
    const int UPPER_LIMIT = 9;
    const int LOWER_LIMIT = 0;
    const int RANGE = UPPER_LIMIT - LOWER_LIMIT + 1;
    int lottery[NUM_DIGITS];
    int user[NUM_DIGITS];
    int matchingDigits;

    srand(time(0));

    for(int i = 0; i < NUM_DIGITS; i++)
    {
        lottery[i] = rand() % RANGE + LOWER_LIMIT;
    }


    cout << "This is the lottery game."
         << "\nEnter 5 digits (from 0 through 9)\n";

    for(int j = 0; j < NUM_DIGITS; j++)
    {
        int userInput;

        do
        {
            cout << "\nEnter #: ";
            cin >> userInput;

            if(userInput < 0 || userInput > 9)
                cout << "\nEnter numbers 1-9 only.\n";

        }while(userInput < 0 || userInput > 9);

        user[j] = userInput;
    }

    displayLotteryNumbers(lottery, NUM_DIGITS);
    displayUserNumbers(user, NUM_DIGITS);
    matchingDigits = countMatchingDigits(lottery, user, NUM_DIGITS);
    results(matchingDigits);

    return 0;
}

void displayLotteryNumbers(const int lottery[], int size)
{
    cout << "\nLottery Digits: ";

    for (int i = 0; i < size; i++)
    {
        cout << lottery[i] << " ";
    }

}

void displayUserNumbers(const int user[], int size)
{
    cout << "\nYour Digits: ";

    for (int i = 0; i < size; i++)
    {
        cout << user[i] << " ";
    }

}

int countMatchingDigits(const int lottery[], const int user[], int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (lottery[i] == user[i])
            count++;
    }

    return count;
}

void results(int count)
{
    if(count == 5)
        cout << "\n\nYou are the grand prize winner!\n";
    else
        cout << "\n\nYou are not the grand prize winner.\n";
}
