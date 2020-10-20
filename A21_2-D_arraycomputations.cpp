// 2-D Array Computations
// By Emily Dayanghirang and Alina Corpora

#include <iostream>
#include <iomanip>
using namespace std;

// Global constants
const int ROWS = 3;
const int COLUMNS = 5;
const double NUMS = ROWS * COLUMNS;

// Function prototypes
double getTotal(int [][COLUMNS], int);
double getAverage(int [][COLUMNS], int);
double getRowTotal(int [][COLUMNS], int);
double getColumnTotal(int [][COLUMNS], int, int);
double getHighestInRow(int [][COLUMNS], int);
double getLowestInRow(int [][COLUMNS], int);

int main()
{
    int twoDArray[ROWS][COLUMNS] = {{17,25,2,10,4},
                                    {22,78,32,56,18},
                                    {6,46,19,97,86}
                                    };
    double average;

    // Print 2-D array
    cout << "\n The 2-D Array is: \n";
    for(int row = 0; row < ROWS; row++)
    {
        for(int column = 0; column < COLUMNS; column++)
        {
            cout << " " << twoDArray[row][column] << " ";
        }
        cout<<"\n";
    }

    // Get total
    cout << "\nThe total of all the values "
         << "in the 2-D array: " << getTotal(twoDArray,ROWS)
         << endl << endl;

    // Get average
    average = getAverage(twoDArray,ROWS);
    cout<<"The average of all the values in the "
        << "2-D array: "<< setprecision(4)
        << average << endl << endl;

    // Row totals
    for(int row = 0; row < ROWS; row++)
    {
        cout << "The total for row " << row+1 << ": "
             << getRowTotal(twoDArray,row) << endl;
    }

    cout << endl;

    // Column totals
    for(int col = 0; col < COLUMNS; col++)
    {
        cout << "The total for col " << col+1 << ": "
             << getColumnTotal(twoDArray,col,ROWS) << endl;
    }

    cout << endl;

    // Highest in row
    for(int row = 0; row < ROWS; row++)
    {
        cout << "The highest value for row " << row+1 << ": "
             << getHighestInRow(twoDArray,row) << endl;
    }

    cout << endl;

    // Lowest in row
    for(int row = 0; row < ROWS; row++)
    {
        cout << "The lowest value for row " << row+1 << ": "
             << getLowestInRow(twoDArray,row) << endl;
    }

}

// Get total
double getTotal(int twoDArray[][COLUMNS], int rows)
{
    double total = 0;
    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < COLUMNS; column++)
        {
            total += twoDArray[row][column];
        }
    }
    return total;
}


// Get average
double getAverage(int twoDArray[][COLUMNS], int rows)
{
    double total = 0;
    double average;

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < COLUMNS; column++)
        {
            total += twoDArray[row][column];
        }
    }
    average = total/NUMS;
    return average;
}

// Get row total
double getRowTotal(int twoDArray[][COLUMNS], int row)
{
    double rowTotal = 0;

    for(int column = 0; column < COLUMNS; column++)
    {
        rowTotal += twoDArray[row][column];
    }
    return rowTotal;
}

//Get column total
double getColumnTotal(int twoDArray[][COLUMNS], int columns, int rows)
{
    double total = 0;

    for(int row = 0; row < rows; row++)
    {
        total += twoDArray[row][columns];
    }
    return total;
}

// Get highest in row
double getHighestInRow(int twoDArray[][COLUMNS], int row)
{
    double highestInRow = twoDArray[row][0];

    for(int column = 0; column < COLUMNS; column++)
    {
        if(highestInRow < twoDArray[row][column])
            highestInRow = twoDArray[row][column];
    }
    return highestInRow;
}

// Get lowest in row
double getLowestInRow(int twoDArray[][COLUMNS], int row)
{
    double lowestInRow = twoDArray[row][0];

    for(int column = 0; column < COLUMNS; column++)
    {
        if(lowestInRow > twoDArray[row][column])
            lowestInRow = twoDArray[row][column];
    }
    return lowestInRow;
}