// C-Strings
// By Alina Corpora, Emily Dayanghirang, and Sarra Osman
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
using namespace std;

int main()
{
    const int SIZE = 16;
    char line[SIZE];
    int count = 0,
            total = 0;

    while (line[count] != '\0')
    {
        line[count] = 0;
        count++;
    }

    // Prompt user
    cout << "\nEnter a series of single characters with no more than\n"
         << (SIZE-1) << " characters (alphabets and digits) and with nothing\n"
         << "separating them: ";

    cin >> setw(16) >> line;

    cout << "\nThe sum of all the single-digit numbers in the string:\n";

    for(int i= 0; i < SIZE; i++)
    {
        if(line[i]>'0' && line[i]<='9')
        {
            total += line[i]-'0';
        }
    }

    cout << total;

    return 0;
}
