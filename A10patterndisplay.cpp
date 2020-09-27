// Pattern Display
// By Emily Dayanghirang

#include <iostream>
using namespace std;

int main()
{
    int numberOfRows;

    /*
         * Prompt user to choose the number
          of rows of the pattern that will
          be displayed

        * Re-prompt when user's input is less than 1
          or greater than 20
    */

    do
    {
        cout << "Select the pattern's number of rows from 1 to 20: ";
        cin >> numberOfRows;
        cout << endl;
    } while (numberOfRows < 1 || numberOfRows > 20);

    // Display pattern
    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j)
            {
                cout << "#";
            }
            else
            {
                cout << "*";
            }
        }

        cout << endl;
    }

    return 0;
}