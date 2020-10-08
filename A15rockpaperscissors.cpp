// Rock, Paper, Scissors game
// By Emily Dayanghirang

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void displayMenu();
int getUserInput();
int generateComputerChoice();
void displayChoice(int,int);
void selectWinner(int, int);

int main()
{
    int userInput, compChoice;

    do
    {
        displayMenu();
        userInput = getUserInput();
        compChoice = generateComputerChoice();
        displayChoice(userInput, compChoice);
        selectWinner(userInput, compChoice);


    }while(userInput != 4);

    return 0;

}

void displayMenu()
{
    cout << "\nThis is the game of rock, paper, scissors.\n"
         << "***The program repeats until "
         << "you select 4 to Quit the program.\n\n"
         << "Choose from the following choices:\n"
         << "1. Rock\n"
         << "2. Paper\n"
         << "3. Scissors\n"
         << "4. Quit\n";
}

int getUserInput()
{
    int userInput;
    do
    {
        cout << "\nEnter your choice (1 - 4): ";
        cin >> userInput;
        if(userInput < 1 || userInput > 4)
            cout << "\nChoose from the numbers 1-4 only.\n";
    }while(userInput < 1 || userInput > 4);

    cout << endl;

    return userInput;
}

int generateComputerChoice()
{
    const int UPPER_LIMIT = 3;
    const int LOWER_LIMIT = 1;
    const int RANGE = UPPER_LIMIT - LOWER_LIMIT + 1;
    int compChoice;

   srand(time(0));
   compChoice = rand() % RANGE + LOWER_LIMIT;

   return compChoice;
}

void displayChoice(int userInput, int compChoice)
{
    cout << "The user chose " << userInput << ".\n"
         << "The computer chose " << compChoice << ".\n";
}

void selectWinner(int userInput, int compChoice)
{
    if(compChoice == 1 && userInput == 1)
        cout << "Tie.\n";

    else if(compChoice == 1 && userInput == 2)
        cout << "You won!\n";

    else if(compChoice == 1 && userInput == 3)
        cout << "You lost!\n";

    else if(compChoice == 2 && userInput == 1)
        cout << "You lost!\n";

    else if(compChoice == 2 && userInput == 2)
        cout << "Tie.\n";

    else if(compChoice == 2 && userInput == 3)
        cout << "You won!\n";

    else if(compChoice == 3 && userInput == 1)
        cout << "You won!\n";

    else if(compChoice == 3 && userInput == 2)
        cout << "You lost!\n";

    else if(compChoice == 3 && userInput == 3)
        cout << "Tie.\n";

    else
        cout << "You have decided to quit the program.\n"
             << "The game stops here. Goodbye.\n";

}