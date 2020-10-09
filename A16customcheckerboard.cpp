// Custom Checkerboard
// Objectives: Pass by value and reference,
//             nested repetition,
//             using global constants
// By Emily Dayanghirang

#include <iostream>
using namespace std;

const int MAX_WIDTH = 40;
const double MAX_HEIGHT = MAX_WIDTH/2;

void checkerboard(int);
void getWidth(int &);

int main()
{
        int width;
        getWidth(width);
        checkerboard(width);

}
void checkerboard(int width)
{
    for (int i = 0; i < MAX_HEIGHT; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if((i%2==0 && j%2==0)||(i%2!=0 && j%2!=0))
                cout<<".";
            else
                cout<<"*";
        }

        cout << endl;
    }
}

void getWidth(int &width)
{
    int userInput;

    do
    {
        cout << "\nEnter an integer in the range of 1 to "
             << MAX_WIDTH << ": ";
        cin >> userInput;
        width = userInput;

        // Input validation for int
        if (cin.fail())
        {
            cout << "\nERROR: Please input an integer.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if((userInput < 1 || userInput > MAX_WIDTH) && cin)
        {
            cout << "\nERROR: Please input an integer in the "
                 << "range of 1 to " << MAX_WIDTH << ".\n";
        }

    }while(userInput < 1 || userInput > MAX_WIDTH || cin.fail());
}
