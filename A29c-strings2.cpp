// C-Strings Pt.2
// By Alina Corpora, Emily Dayanghirang, and Sarra Osman

#include <iostream>
#include <cctype>
using namespace std;

// Function Prototypes
int words(char *cStr);
int nums(char *cStr);
int spaces(char *cStr);
int puncts(char *cStr);
int consts(char *cStr);

// Global Variables
const int SIZE = 51;

int main()
{
    char cStr[SIZE];
    cout << "Enter a string input containing no more than "
         <<(SIZE-1)<<" characters. : ";

    cin.getline(cStr, SIZE);

    int wordC=words(cStr);
    cout<<"Words: "<<wordC<<endl;

    int numC=nums(cStr);
    cout<<"Numbers: "<<numC<<endl;

    int spaceC=spaces(cStr);
    cout<<"Spaces: "<<spaceC<<endl;

    int punctC=puncts(cStr);
    cout<<"Punctuations:"<<punctC<<endl;

    int constC=consts(cStr);
    cout<<"Consonants: "<<constC<<endl;

    return 0;
}

// Count words
int words(char *cStr)
{
    int count = 0;
    while(*cStr != '\0')
    {
        if((ispunct(*cStr) || isspace(*cStr)) && (isalpha(*(cStr+1)) ||
                                                  isdigit(*(cStr+1))))
            count++;
        cStr++;
    }
    return count;
}

//Count Numbers
int nums(char *cStr)
{
    int count = 0;
    while(*cStr != '\0')
    {
        if (isdigit(*cStr))
            count++;
        cStr++;
    }
    return count;
}

// Count Spaces
int spaces(char *cStr)
{
    int count = 0;
    while(*cStr !='\0')
    {
        if(isspace(*cStr))
            count++;
        cStr++;
    }
    return count;
}

// Count punctuations
int puncts(char *cStr)
{
    int count = 0;
    while(*cStr != '\0')
    {
        if(ispunct(*cStr))
            count++;
        cStr++;
    }
    return count;
}

// Count consonants
int consts(char *cStr)
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
