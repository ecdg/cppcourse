/*
   Calculates the number of slices
   a pizza of any size can be divided into
   
   By Emily Dayanghirang
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double PI = 3.14159, AREA_SLICE = 14.125;
    double pizzaDiameter, pizzaRadius, areaOfPizza;
    int numberOfSlices;

    // Prompt user
    cout << "Enter pizza diameter: ";
    cin >> pizzaDiameter;

    // Calculations for radius and area of pizza
    pizzaRadius = pizzaDiameter / 2.0;
    areaOfPizza = PI * pow(pizzaRadius, 2.0);

    // Calculation for number of slices
    numberOfSlices = areaOfPizza / AREA_SLICE;

    // Display number of slices
    cout << numberOfSlices << " slices" << endl;

}
