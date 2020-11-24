// Pointers to Structure
// By Emily Dayanghirang, Alina Corpora, Sarra Osman
#include <iostream>
#include <iomanip>
using namespace std;

struct NumList {
    float *list;   // list of values
    int   len;     // count of values in list
    float min,     // the minimal value in list
    max,     // the maximal value in list
    avg;     // the mean of the numbers
};

int computeStats(NumList *);

int main()
{
    NumList *num = new NumList;
    int size, error;
    float number;

    cout << "\nHow many numbers are you inputting: ";
    cin >> size;

    num->list = new float[size];

    if(size < 0)
        return -3;

    for(int i = 0; i < size; i++)
    {
        cout << "Enter #" << i+1 << ": ";
        cin >> number;
        *(num->list+i) = number;
    }

    num->len = size;

    cout << "\nThe length of the list is " << num->len << ".\n";

    error = computeStats(num);

    cout<<"\nThe error code returned was "<<error<<"."<<endl;

    delete [] num->list;
    num->list = nullptr;

    delete num;
    num = nullptr;

    return 0;
}

int computeStats(NumList *num)
{
    if(num == nullptr)
        return -1;
    if(num->list == nullptr)
        return -2;
    if(num->len<1)
        return -3;
    else
    {
        float min = *num->list;
        float max = *num->list;
        float total = 0, average;

        for(int i = 0; i < num->len; i++)
        {
            if(min > *(num->list+i))
                min = *(num->list+i);
        }

        cout << "\nThe minimum number is " << min << ".\n";

        for(int i = 0; i < num->len; i++)
        {
            if(max < *(num->list+i))
                max = *(num->list+i);
        }

        cout << "\nThe maximum number is " << max << ".\n";

        for(int i = 0; i < num->len; i++)
        {
            total += *(num->list+i);
        }

        cout << "\nThe total of the number is " << total << ".\n";

        average = total / num->len;

        cout << setprecision(2) << fixed
             << "\nThe average of the list is " << average << ".\n";

        return 0;
    }
}
