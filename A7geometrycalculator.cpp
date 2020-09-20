// Geometry Calculator
// By Emily Dayanghirang

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double PI = 3.14159;
    double radius, area, length, width, base, height;
    int number;

    // Display choices
    cout << "Geometry Calculator\n\n"

         << "1. Calculate the area of a Circle\n"
         << "2. Calculate the area of a Rectangle\n"
         << "3. Calculate the area of a Triangle\n"
         << "4. Quit\n";

    // Prompt user
    cout << "\nEnter your choice (1-4): ";
    cin >> number;

    // Calculations and input validation for each of the choices
    switch(number)
    {
        case 1:
            cout << "\nEnter the circle's radius: ";
            cin >> radius;
            if(radius < 0)
            {
                cout << "\nThe radius can not be less than zero." << endl;
                return 1;
            }
            else
            {
                area = PI * (pow(radius, 2.0));
                cout << "\nThe area is " << area << endl;
            }
            break;
        case 2:
            cout << "\nEnter the rectangle's length: ";
            cin >> length;
            cout << "Enter the rectangle's width: ";
            cin >> width;
            if(length < 0 || width < 0)
            {
                cout << "\nOnly enter positive values for length and width." << endl;
                return 1;
            }
            else
            {
                area = length * width;
                cout << "\nThe area is " << area << endl;
            }
            break;
        case 3:
            cout << "Enter the length of the base: ";
            cin >> base;
            cout << "Enter the triangle's height: ";
            cin >> height;
            if(base < 0 || height < 0)
            {
                cout << "\nOnly enter positive values for base and height." << endl;
                return 1;
            }
            else
            {
                area = 0.5 * (base * height);
                cout << "\nThe area is " << area << endl;
            }
            break;
        case 4:
            cout <<"Program ending." << endl;
            break;
        default:
            cout << "The valid choices are 1 through 4. Run the"
                 << "\nprogram again and select one of those."
                 << endl;
            return 1;

    }

    return 0;

}