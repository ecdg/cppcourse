// Activity 22: Dynamic memory allocation
// By Emily Dayanghirang and Alina Corpora

#include <iostream>
using namespace std;

void display(float *p, int sizeArr);
float* expandArray(float *p, int &size);
bool insertAt(float *p, float item, int index, int count);

int main()
{
    int size = 5,
            index = 0,
            count = size;

    float *ptr = nullptr,
            item = 0.0;

    // Initialize dynamic array
    ptr = new float[size]{1.2, 2.6,
                           3.2,
                           4.7,
                           5.2};

    cout << "The list:\n";
    display(ptr, size);

    cout << "\nThe floating number you want to "
         << "insert at the beginning of the list: ";
    cin >> item;

    ptr = expandArray(ptr, size);

    if(insertAt(ptr, item, index, count))
    {
        cout << "\nThe new list:\n";
        display(ptr, size);
    }

    return 0;
}

void display(float *p, int sizeArr)
{
    for (int index = 0; index < sizeArr; index++)
        cout << *(p + index) << " ";
    cout << endl;
}

float* expandArray(float *p, int &size)
{
    int newSize = size * 2;
    float *newArr = nullptr;

    newArr = new float[newSize];
    for(int index = 0; index < size; index++)
    {
        // Copy the old array to the new array
        *(newArr + index) = *(p + index);
    }
    // Set the rest of the array elements to 0.0
    for(int index = size; index < newSize; index++)
    {
        *(newArr + index) = 0.0;
    }

    size = newSize;
    delete [] p;
    return newArr;
}

bool insertAt(float *p, float item, int index, int count)
{
    if(index < 0 || index > count)
        return false;
    // Move contents
    for(int i = count; i > index; i--)
    {
        *(p+i) = *(p+i-1);
    }
    // Insert item into the list
    *(p+index) = item;
    return true;
}
