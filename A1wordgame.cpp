// Word game
// By Emily Dayanghirang

#include <iostream>
using namespace std;

int main()
{
    string name, city, college, profession, animal, petName;
    int age;

    // Prompt user
    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter city: ";
    getline(cin, city);

    cout << "Enter age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter college: ";
    getline(cin, college);

    cout << "Enter profession: ";
    getline(cin, profession);

    cout << "Enter animal: ";
    getline(cin, animal);

    cout << "Enter pet name: ";
    getline(cin, petName);

    // Display the story
    cout << "\n\nThere once was a person named " << name
         << " who lived in " << city << ".\n"
         << "At the age of " << age << ", " << name << " went to college at " << college << ".\n"
         << name <<" graduated and went to work as a " << profession << ".\n"
         << "Then, " << name << " adopted a(n) " << animal << " named " << petName << ".\n"
         << "They both lived happily ever after!\n";

    return 0;
}
