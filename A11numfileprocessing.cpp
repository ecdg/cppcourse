// Numeric Processing using Files
// By Emily Dayanghirang

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    int numberOfNumbersInTheFile=0;
    double number, total=0, average;

    ifstream infile;

    // Open file
    infile.open("Random.txt");

    // Read all the numbers from the file
    while(infile >> number)
    {
        numberOfNumbersInTheFile++;
        total += number;
    }

    // Calculate average
    average = total / numberOfNumbersInTheFile;

    // Display results
    cout << fixed << setprecision(2)
         << "\nThe number of numbers in the file is " << numberOfNumbersInTheFile << endl
         << "The sum of all the numbers in the file is " << total << endl
         << "The average of all the numbers in the file is " << average << endl;

    // Close file
    infile.close();

    return 0;
}