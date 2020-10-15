// Mode Calculation
// By Alina Corpora and Emily Dayanghirang

#include <iostream>
using namespace std;

// Function Prototypes
void getInput(int[], int);
void displayInput(int[], int);
int mode(int[], int);


int main()
{
    const int SIZE = 7;
    int userInt[SIZE],
        displayMode;

    // Get integers from user
    getInput(userInt,SIZE);

    // Display user’s integers
    displayInput(userInt,SIZE);

    // Display mode
    displayMode = mode(userInt,SIZE);
    cout << "The most recurring number is " << displayMode << "." << endl;

    return 0;
}

void getInput(int userInt[], int size)
{
    cout << "Enter 7 integers \n";

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the # for entry "
             << i + 1 << ": ";

        cin >> userInt[i];
    }
}

void displayInput(int userInt[], int size)
{
    cout << "\nYour input: ";

    for (int j = 0; j < size; j++)
    {
        cout << userInt[j] << " ";
    }

    cout << endl;
}

int  mode(int userInt[], int size)
{
    int maxMode = 0, number = 0;

    for(int index = 0; index < size; index++)
    {
        int count = 1;

        for (int check = index + 1; check < size; check++)
        {
            if(userInt[index] == userInt[check])
                count ++;
        }

        if(maxMode < count)
        {
            maxMode = count;
            number = userInt[index];
        }

    }

    return number;
}
