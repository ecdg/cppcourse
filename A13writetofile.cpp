// Write to File
// By Emily Dayanghirang

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outfile("output.txt");
    int userInput;
    char repeat;

    do
    {
        // Repeatedly checks whether the user entered an invalid input
        do
        {
            cout << "\nGive an integer input in the range 20 to 40 inclusive: ";
            cin >> userInput;

            // Input validation
            if (cin.fail())
            {
                cout << "\nERROR: Please input an integer.\n";
                cin.clear();
                cin.ignore(100, '\n');
            }

            if(userInput < 20 || userInput > 40)
            {
                cout << "\nInput must be an integer in the range 20 to 40 inclusive.\n";
            }

        } while (userInput < 20 || userInput > 40);

        // Check if the file is successfully opened
        if(outfile.is_open())
        {
            // Write user's input to file
            outfile << userInput << endl;

            cout << "\nYour input " << userInput << " is now written on file.\n";

            // Prompt user to continue or exit
            cout << "\nPress 'Y' or 'y' to give another integer input or 'N' or 'n' to exit: ";
            cin >> repeat;

        }

        else
        {
            cerr << "Error opening the file";
            cerr << "Error code: " << strerror(errno);
            exit(1);
        }


    } while(repeat != 'N' && repeat != 'n');

    outfile.close();
    return 0;
}