// Dynamic String Array
// By Emily Dayanghirang and Alina Corpora
#include <iostream>
using namespace std;

// Function Prototypes
void printMenu();
void printList(string *p, int size);
string *expand(string *p, int &size);
bool insertAtZero(string *p, string item, int count);
bool insertAt(string *p, string item, int index, int count);
bool insertAtEnd(string *p, string item, int count);
bool removeFromEnd(string *p, int count);
bool removeFrom(string *p, int index, int count);
void sort(string *p, int count);

int main()
{
    int size = 5,
            input = 0,
            index = 0,
            count = size;

    string *ptr = nullptr,
            item = "";

    // Initialize dynamic array
    ptr = new string[size]{"Mary", "Kate",
                           "Ashley",
                           "Ken",
                           "Mark"};

    // Loops until user chooses to exit the program
    do
    {
        printMenu();
        cin >> input;
        switch(input)
        {
            case 1:
                cout << "The name you want to "
                     << "insert at the end of the list: ";
                cin >> item;
                if(count == size)
                    ptr = expand(ptr, size);
                if(insertAtEnd(ptr, item, count))
                {
                    cout << "\nThe new list:\n";
                    printList(ptr, size);
                    count++;
                }
                break;
            case 2:
                cout << "The name you want to "
                     << "insert at the beginning of the list: ";
                cin >> item;
                if(count == size)
                    ptr = expand(ptr, size);
                if(insertAtZero(ptr, item, count))
                {
                    cout << "\nThe new list:\n";
                    printList(ptr, size);
                    count++;
                }
                break;
            case 3:
                cout << "The index position in the list you want to "
                     << "insert a name: ";
                cin >> index;
                cout << "The name you want to "
                     << "insert at index " << index << ": ";
                cin >> item;
                if(count == size)
                    ptr = expand(ptr, size);
                if(insertAt(ptr, item, index, count))
                {
                    cout << "\nThe new list:\n";
                    printList(ptr, size);
                    count++;
                }
                break;
            case 4:
                if (removeFromEnd(ptr, count))
                {
                    cout << "\nThe new list:\n";
                    printList(ptr, size);
                    count++;
                }
                break;
            case 5:
                cout << "The index position in the list you want to "
                     << "delete a name: ";
                cin >> index;
                if(count == size)
                    ptr = expand(ptr, size);
                if(removeFrom(ptr, index, count))
                {
                    cout << "\nThe new list:\n";
                    printList(ptr, size);
                    count++;
                }
                break;
            case 6:
                cout<<"Now sorting the list..."<<endl;
                sort(ptr, count);
                cout << "\nThe new list:\n";
                printList(ptr, size);
                break;
            case 7:
                cout << "\nThe list:\n";
                printList(ptr, size);
                break;
            case 8:
                cout << "\nGoodbye!\n";
                break;
            default:
                cout << "\nThe valid choices are 1 through 8.\n"
                     << "Please enter again.\n";
        }
    }while(input != 8);

    return 0;
}

void printMenu()
{
    cout << "\nPlease choose from the following menu choices\n"
         << "1) Insert a new element to the end of the list.\n"
         << "2) Insert a new element at the beginning of the list.\n"
         << "3) Insert an element into the list at a given index.\n"
         << "4) Remove an element from the end of the list.\n"
         << "5) Remove an element from the list at a given index.\n"
         << "6) Sort the list.\n"
         << "7) Print the contents of the list.\n"
         << "8) Exit.\n\n"
         << "Enter: ";
}

string *expand(string *p, int &size)
{
    int newSize = size * 2;
    string *newArr = nullptr;

    newArr = new string[newSize];
    for(int index = 0; index < size; index++)
    {
        // Copy the old array to the new array
        *(newArr + index) = *(p + index);
    }
    // Set the rest of the array elements to empty strings
    for(int index = size; index < newSize; index++)
    {
        *(newArr + index) = "";
    }

    size = newSize;
    delete [] p;
    return newArr;
}

bool insertAtZero(string *p, string item, int count)
{
    return insertAt(p, item, 0, count);
}

// Credits to Umair Azmi for the function for insertAt
bool insertAt(string *p, string item, int index, int count)
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

bool insertAtEnd(string *p, string item, int count)
{
    return insertAt(p, item, count, count);
}

void printList(string *p, int size)
{
    for (int index = 0; index < size; index++)
        cout << *(p + index) << " ";
    cout << endl;
}

bool removeFrom(string *p, int index, int count)
{
    if(index < 0 || index >= count)
        return false;
    // Shift to left
    for(int i = index; i < count - 1; i++)
        *(p+i) = *(p+i+1);
    *(p+count-1)="";
    return true;
}

bool removeFromEnd(string *p, int count)
{
    return removeFrom(p, count - 1, count);
}

void sort(string *p, int count)
{
    string temp;
    int i, j;
    for(i = 0; i < count; i++)
    {
        for(j = i + 1; j < count; j++)
        {
            if((p+i)->compare(*(p+j)) > 0)
            {
                temp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = temp;
            }
        }
    }
}
