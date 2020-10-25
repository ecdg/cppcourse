// Search benchmark
// By Emily Dayanghirang
#include <iostream>
#include <fstream>

const int SIZE = 50;
void convertToUpperCase(std::string &);
int linearSearch(const std::string [], std::string, int, int &);
int binarySearch(const std::string [], std::string, int, int &);

int main()
{
    std::fstream inFile;
    std::string fileName, searchName;
    std::string names[SIZE];
    int linearSearchIndex = 0,
        binarySearchIndex = 0,
        linearComparisons = 0,
        binaryComparisons = 0;

    std::cout << "\nEnter the file name: ";
    getline(std::cin, fileName);

    inFile.open(fileName);

    if (inFile.fail())
    {
        std::cerr << "\nError!! Could not open file!" << std::endl;
    }
    else
    {
        for(int i=0; i<SIZE; i++)
            if(!getline(inFile, names[i]))
                break;

        inFile.close();

        std::cout << "\nEnter name to search: ";
        getline(std::cin, searchName);

        convertToUpperCase(searchName);

        linearSearchIndex = linearSearch(names, searchName, SIZE, linearComparisons);

        if(linearSearchIndex == -1)
        {
            std::cout << "\nUsing Linear Search, " << searchName
                 << " was not found in the array.";
        }
        else
        {
            std::cout << "\nUsing Linear Search, " << searchName
                 << " was found in the array in "
                 << linearComparisons << " comparisons.";
        }

        binarySearchIndex = binarySearch(names, searchName, SIZE, binaryComparisons);

        if(binarySearchIndex == -1)
        {
            std::cout << "\nUsing Binary Search, " << searchName
                 << " was not found in the array.";
        }
        else
        {
            std::cout << "\nUsing Binary Search, " << searchName
                 << " was found in the array in "
                 << binaryComparisons << " comparisons.";
        }
    }
    return 0;
}

void convertToUpperCase(std::string &userInput)
{
    for(int index = 0; index < userInput.length(); index++)
    {
        if(userInput[index] >= 'a' && userInput[index] <= 'z')
            userInput[index] = toupper(userInput[index]);
    }
}
int linearSearch(const std::string names[], std::string searchName, int size, int &linearComparisons)
{
    int i;
    bool found = false;
    std::string name;

    i = 0;
    while (i < size && !found)
    {
        name = names[i];
        convertToUpperCase(name);

        if (searchName == name)
        {
            found = true;
        }
        else
        {
            i++;
        }
        linearComparisons++;
    }
    if (!found)
        i = -1;
    return i;
}
int binarySearch(const std::string names[], std::string searchName, int size, int &binaryComparisons)
{
    int first = 0, middle, position = -1;
    int last = size - 1;
    bool found = false;
    std::string name;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        name = names[middle];
        convertToUpperCase(name);

        if (name == searchName)
        {
            found = true;
            position = middle;
        }
        else if (name > searchName)
            last = middle - 1;
        else
            first = middle + 1;

        binaryComparisons++;
    }
    return position;
}
