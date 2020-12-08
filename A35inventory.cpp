// Inventory
// Working with binary file and struct
// By Alina Corpora, Emily Dayanghirang, and Sarra Osman
#include <iostream>
#include <fstream>
using namespace std;

//Global Variables
const int SIZE1=101,
        SIZE2=11;

struct Inventory
{
    char desc[SIZE1];
    char prodID[SIZE2];
    int quantity;
    double wholesale;
    double retail;
};

// Function Declarations
void printMenu();
void writeToFile(fstream &inventoryFile);
void getInput(Inventory*);
void readFromFile(fstream &inFile);

int main()
{
    fstream inventoryFile("inventory.dat", ios::in | ios::app | ios::binary);

    int input=0;

    if(!inventoryFile.fail())
    {
        do
        {
            printMenu();
            cin >> input;
            cin.ignore();
            inventoryFile.clear();
            switch(input)
            {
                case 1:
                    inventoryFile.seekp(0L, ios::end);
                    writeToFile(inventoryFile);
                    break;
                case 2:
                    inventoryFile.seekg(0L, ios::beg);
                    readFromFile(inventoryFile);
                    break;
                case 3:
                    inventoryFile.close();
                    cout << "\nGoodbye!\n";
                    break;
                default:
                    cout << "Invalid\n"
                         << "Please only select the numbers 1-3 as your choices."
                         << endl;
            }
        } while(input != 3);
    }
    else
        cout << "ERROR: Cannot open file" << endl;


    return 0;
}

void printMenu()
{
    cout << "\nPlease choose from the following menu choices\n"
         << "1) Add a new record to the file.\n"
         << "2) Display records in the file.\n"
         << "3) Exit.\n"
         << "Enter: ";
}

void writeToFile(fstream &inventoryFile)
{
    char cont;
    Inventory inv;
    do
    {
        getInput(&inv);
        cout << "Do you want to continue (press y or Y)? "<<endl;
        cout<< "If not, enter any other character. : ";
        cin >> cont;
        inventoryFile.write(reinterpret_cast<char *>(&inv), sizeof(inv));
        cin.ignore();
    }
    while (cont == 'y' || cont == 'Y');
}

void getInput(Inventory *inv)
{
    cout << "\nEnter Product Description (Max 100 Characters): ";
    cin.getline(inv->desc, SIZE1);
    cout << "Enter Product ID (Max 10 Characters): ";
    cin.getline(inv->prodID, SIZE2);
    cout << "Enter Quantity in Stock: ";
    cin >> inv->quantity;
    cout << "Enter Wholesale Price: $";
    cin >> inv->wholesale;
    cout << "Enter Retail Price: $";
    cin >> inv->retail;
}

void readFromFile(fstream &inFile)
{
    Inventory inventory;
    if (inFile)
    {
        inFile.read(reinterpret_cast<char *>(&inventory), sizeof(inventory));
        while(!inFile.eof())
        {
            cout << "\nDescription: " << inventory.desc << endl
                 << "Product ID: " << inventory.prodID << endl
                 << "Quantity: " << inventory.quantity << endl
                 << "Wholesale Price: " << inventory.wholesale << endl
                 << "Retail Price: " << inventory.retail << endl;

            inFile.read(reinterpret_cast<char *>(&inventory), sizeof(inventory));
        }
    }
    else
        cout << "Could not read from file..." << endl;
}

