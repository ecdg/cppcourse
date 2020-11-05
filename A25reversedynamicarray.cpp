// Dynamic Array Using Pointers
// Reverse the order of the contents of an array
// By Alina Corpora and Emily Dayanghirang

#include <iostream>
using namespace std;

float* reverse(float *array1, int arraySize);
void display(float *array, int arraySize);

const int SIZE = 5;

int main()
{
    float array1[SIZE] = {1,22,31,40,41};
    float* ptr;

    display(array1, SIZE);

    // Allocate ptr to the start of an array on the heap
    // Dynamically Allocate Memory
    ptr = new float[SIZE];
    ptr = reverse(array1, SIZE);
    display(ptr,SIZE);

    delete [] ptr;

    return 0;
}

void display(float *array, int arraySize)
{
    for(int index = 0; index < arraySize; index++)
    {
        cout << *(array + index) << "\t";
    }
    cout << endl;
}

float* reverse(float *array1, int  arraySize)
{
    float *array2 = nullptr;
    array2 = new float[arraySize];

    for (int index = 0; index < arraySize; index++)
        *(array2+index) = *(array1+index);

    for (size_t i = 0; i < arraySize / 2; i++) {
        int x = array2[i];
        array2[i] = array2[arraySize - i - 1];
        array2[arraySize - i - 1] = x;
    }
    return array2;
}
