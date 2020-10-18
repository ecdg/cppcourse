// Magic Square
// By Emily Dayanghirang

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int ROWS = 3;
const int COLUMNS = 3;
const int DIAGONALS = 2;
const int NUMBER_OF_TOTALS = ROWS + COLUMNS + DIAGONALS;

int main()
{
    const int UPPER_LIMIT = 9;
    const int LOWER_LIMIT = 1;
    const int RANGE = UPPER_LIMIT - LOWER_LIMIT + 1;

    /*
    // Grid for testing
    // Use by making a comment block around
    // the code to randomly generate a number
    // for each square

    int grid[ROWS][COLUMNS] = {{4, 9, 2},
                               {3, 5, 7},
                               {8, 1, 6}};
    */

    int grid[ROWS][COLUMNS];
    int totals[NUMBER_OF_TOTALS];

    bool sumsAreEqual = 0;

    int rowTotal(int [][COLUMNS], int);
    int columnTotal(int [][COLUMNS], int);
    int diagonalTopLeftToRightTotal(int [][COLUMNS]);
    int diagonalTopRightToLeftTotal(int [][COLUMNS]);
    bool check(int [], int);

    srand(time(0));


    // Randomly generate a number for each square
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            grid[i][j] = rand() % RANGE + LOWER_LIMIT;
        }
    }

    // Print grid
    for (int k = 0; k < ROWS; ++k)
    {
        for (int l = 0; l < COLUMNS; ++l)
        {
            cout << grid[k][l] << ' ';
        }
        cout << endl;
    }

    // Store totals in an array
    for(int count = 0; count < 5; count++)
    {
        if(count < 3)
        {
            totals[count] = rowTotal(grid, count);
            totals[count + 3] = columnTotal(grid, count);
        }
        else if(count < 4)
            totals[count + 3] = diagonalTopLeftToRightTotal(grid);
        else
            totals[count + 3] = diagonalTopRightToLeftTotal(grid);
    }

    // Print row totals
    cout << "\nTotal in each row: ";

    for(int m = 0; m < ROWS; m++)
    {
        cout << totals[m] << " ";
    }

    // Print column totals
    cout << endl
         << "\nTotal in each column: ";

    for(int n = 0; n < COLUMNS; n++)
    {
        cout << totals[n + 3] << " ";
    }

    // Print diagonal totals
    cout << endl
         << "\nTotal in each diagonal: ";

    for(int o = 0; o < DIAGONALS; o++)
    {
        cout << totals[o + 6] << " ";
    }

    cout << endl;

    // Check if totals are equal to one another
    sumsAreEqual = check(totals, NUMBER_OF_TOTALS);

    // Print result
    if(sumsAreEqual)
        cout << "\nThe grid is a Lo Shu Magic Square.\n";
    else
        cout << "\nThe grid is not a Lo Shu Magic Square.\n";

}

// Get row total
int rowTotal(int grid[][COLUMNS], int row)
{
    int rowTotal = 0;

    for(int column = 0; column < COLUMNS; column++)
    {
        rowTotal += grid[row][column];
    }

    return rowTotal;
}

// Get column total
int columnTotal(int grid[][COLUMNS], int column)
{
    int columnTotal = 0;

    for(int row = 0; row < ROWS; row++)
    {
        columnTotal += grid[row][column];
    }

    return columnTotal;
}

/* credits to Jesus Hilarioh for the
 * functions for getting the sum of the
 * diagonal lines
*/

// Get first diagonal total
int diagonalTopLeftToRightTotal(int grid[][COLUMNS])
{
    int diagonalTopLeftToRightTotal = 0;

    for(int i = 0; i < ROWS; i++)
        diagonalTopLeftToRightTotal += grid[i][i];

    return diagonalTopLeftToRightTotal;
}

// Get second diagonal total
int diagonalTopRightToLeftTotal(int grid[][COLUMNS])
{
    int diagonalTopRightToLeftTotal = 0;

    int column = (ROWS - 1);

    for (int row = 0; row < ROWS; row++)
    {
        diagonalTopRightToLeftTotal += grid[row][column];
        column--;
    }

    return diagonalTopRightToLeftTotal;
}

// Check if totals are equal to one another
bool check(int totals[], int number)
{
    for(int count = 0; count < number; count++)
    {
        if(totals[count] != totals[0])
            return false;
    }

    return true;
}
