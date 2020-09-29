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

    bool newQuestion;

    // Seed the random number generator
    srand(time(0));

    do
    {
        // Assign a random number for the operands
        firstOperand = rand() % RANGE + LOWER_LIMIT;
        secondOperand = rand() % RANGE + LOWER_LIMIT;

        // Multiplication computation
        correctAnswer = firstOperand * secondOperand;

        // Prompt user
        cout << "\nHow much is " << firstOperand
             << " times " << secondOperand << "? ";

        cin >> userAnswer;

        cout << endl;

        do
        {
            // Test conditions
            if(userAnswer == correctAnswer && userAnswer != -1)
            {
                cout << "Very good!\n";

            }
            else if(userAnswer != correctAnswer && userAnswer != -1)
            {
                cout << "Incorrect Answer. Please try again.\n";
                newQuestion = false;

                // Re-prompt user for the same question
                cout << "\nHow much is " << firstOperand
                     << " times " << secondOperand << "? ";

                cin >> userAnswer;

                cout << endl;
            }
            else
            {
                // If user enters -1, then the user is done
                cout << "\nGoodbye!\n";
            }

        // Loop back to re-prompt until correct answer is given
        }while(userAnswer != correctAnswer && userAnswer != -1);

        /* At this point, the user has given
           a correct answer, therefore a new
           question is asked
        */

        newQuestion = true;

    // Loop back to ask a new mathematical question
    }while(newQuestion == true && userAnswer != -1);

    return 0;
}