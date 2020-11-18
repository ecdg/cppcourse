// C-Strings Manipulation
// By Emily Dayanghirang
#include <iostream>
#include <cctype>
using namespace std;

// Function Prototypes
char* backwards(const char* cStr);
int vowels(char* cStr);
int consts(char* cStr);
void reverse(char* cStr);

// Global Variable
const int SIZE = 51;

int main()
{
    char* backwardString = nullptr;
    char cStr[SIZE];

    // Prompt user
    cout << "Enter a string containing no more than "
         << (SIZE-1) << " characters: ";
    cin.getline(cStr, SIZE);

    // Display string backwards
    backwardString = backwards(cStr);
    cout << "\nBackwards string w/o changes made to the original argument: " << backwardString << endl;

    // Display number of vowels
    int vowC = vowels(cStr);
    cout << "Vowels: " << vowC << endl;

    // Display number of consonants
    int constC = consts(cStr);
    cout << "Consonants: " << constC << endl;

    // Reverse the original c-string argument and display it
    reverse(cStr);
    cout << "Reversed string with changes made to the original argument: " << cStr << endl;

    delete [] backwardString;

    return 0;
}

// String is returned backwards w/o making changes to the original arg
char* backwards(const char* cStr)
{
    int length = strlen(cStr);
    char* backwardString = new char[length];
    char temp;
    for(int i = 0, j = strlen(cStr)-1; i < j; i++,j--)
    {
        temp = *(cStr+i);
        *(backwardString+i) = *(cStr+j);
        *(backwardString+j) = temp;
    }
    return backwardString;
}

// Count vowels
int vowels(char* cStr)
{
    int count = 0;
    while(*cStr != '\0')
    {
        if (isalpha(*cStr))
        {
            char upCase = toupper(*cStr);
            if (upCase == 'A' || upCase == 'E' || upCase == 'I' || upCase == 'O'
                || upCase == 'U')
                count++;
        }
        cStr++;
    }
    return count;
}

// Count consonants
int consts(char* cStr)
{
    int count = 0;
    while(*cStr != '\0')
    {
        if (isalpha(*cStr))
        {
            char upCase = toupper(*cStr);
            if (upCase != 'A' && upCase != 'E' && upCase != 'I' && upCase != 'O'
                && upCase != 'U')
                count++;
        }
        cStr++;
    }
    return count;
}

// Reverse the string and make changes to the original arg
void reverse(char* cStr)
{
    char temp;
    for(int i = 0, j = strlen(cStr)-1; i < j; i++,j--)
    {
        temp = *(cStr+i);
        *(cStr+i) = *(cStr+j);
        *(cStr+j) = temp;
    }
}
