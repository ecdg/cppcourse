// Pointers and Functions
// Alina Corpora and Emily Dayanghirang

#include <iostream>
using namespace std;

// Function Prototype
int doMultipleThings(int*,int*);
int main()
{
    int num1 = 1, num2 = 2, value;
    int* xPtr = nullptr;
    int* yPtr = nullptr;

    xPtr = &num1;
    yPtr = &num2;

    // Call doMultipleThings Function
    value = doMultipleThings(xPtr,yPtr);

    cout<<"The function \"doMultipleThings\" returned "<<value<<endl;

    // Display Contents of the Memory Locations
    cout<<"The contents of the address xPtr points to is "<<*xPtr<<endl;
    cout<<"The contents of the address yPtr points to is "<<*yPtr<<endl;

    return 0;
}

int doMultipleThings(int *xPtr,int *yPtr)
{
    int temp = *xPtr;
    *xPtr = *yPtr * 10;
    *yPtr = temp * 10;

    return *xPtr + *yPtr;
}
