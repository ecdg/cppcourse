// Math Quiz for K-8 students
// With Random Number Simulation
// By Emily Dayanghirang

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    const int UPPER_LIMIT = 12;
    const int LOWER_LIMIT = 1;
    const int RANGE = UPPER_LIMIT - LOWER_LIMIT + 1;

    int firstOperand, secondOperand,
        userAnswer, correctAnswer;

    // Seed the random number generator
    srand(time(0));

    cout << "\nEnter -1 to exit the program\n";

    do
    {
        // Assign a random number for the operands
        firstOperand = rand() % RANGE + LOWER_LIMIT;
        secondOperand = rand() % RANGE + LOWER_LIMIT;

        // Prompt user
        cout << "\nHow much is " << firstOperand
             << " times " << secondOperand << "? ";

        cin >> userAnswer;

        // Multiplication computation
        correctAnswer = firstOperand * secondOperand;

        // User enters the correct answer
        if(userAnswer == correctAnswer)
            cout << "\nVery good!\n";

        while(userAnswer != correctAnswer && userAnswer != -1)
        {
            // Input validation for int
            if (cin.fail())
            {
                cout << "\nERROR: Please input an integer.\n";
                cin.clear();
                cin.ignore(1000,'\n');
                // Re-prompt
                cout << "\nHow much is " << firstOperand
                     << " times " << secondOperand << "? ";

                cin >> userAnswer;
            }
            else
            {
                cout << "\nIncorrect Answer. Please try again.\n";
                // Re-prompt user for the same question
                cout << "\nHow much is " << firstOperand
                     << " times " << secondOperand << "? ";

                cin >> userAnswer;
            }

            if(userAnswer == correctAnswer)
                cout << "\nVery good!\n";
        }

    // Loop back to ask a new mathematical question
    }while( userAnswer == correctAnswer && userAnswer != -1);

    cout << "\nGoodbye!\n";

    return 0;
}
