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

    // Memory Locations
    cout<<"The memory location for the xPtr pointer is "<<xPtr<<endl;
    cout<<"The memory location for the yPtr pointer is "<<yPtr<<endl;

    return 0;
}

int doMultipleThings(int *xPtr,int *yPtr)
{
    int temp = *xPtr;
    *xPtr = *yPtr * 10;
    *yPtr = temp * 10;

    return *xPtr + *yPtr;
}
