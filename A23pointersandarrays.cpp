// Pointers and Arrays
// By Emily Dayanghirang and Alina Corpora

#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 5;
    int number;
    int* ptr;
    int numbers[SIZE] = {43, 2, 56, 10, 9};

    ptr = &number;

    cout << "Enter an integer number: ";
    cin >> *ptr;

    *ptr *= 100;

    cout << "\nThe number multiplied to 100 is: "
         << *ptr;

    cout << endl;

    ptr = numbers;

    cout << "\nThe numbers in the array are: ";

    for(int index = 0; index < SIZE; index++)
    {
        cout << *(ptr + index) << " ";
    }

    cout << endl;

    return 0;
}
