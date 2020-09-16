// Calculates average rainfall
// By Emily Dayanghirang

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string first_month,
           second_month,
           third_month;

    double first_month_rainfall,
           second_month_rainfall,
           third_month_rainfall,
           average_rainfall;

    // Prompt user
    cout << "Enter month: ";
    cin >> first_month;

    cout << "Enter rainfall for " << first_month << ": ";
    cin >> first_month_rainfall;

    cout << "Enter month: ";
    cin >> second_month;

    cout << "Enter rainfall for " << second_month << ": ";
    cin >> second_month_rainfall;

    cout << "Enter month: ";
    cin >> third_month;

    cout << "Enter rainfall for " << third_month << ": ";
    cin >> third_month_rainfall;

    // Calculate average rainfall
    average_rainfall = (first_month_rainfall + second_month_rainfall + third_month_rainfall)/3.0;

    // Display result
    cout << "The average rainfall for "
         << first_month << ", "
         << second_month << ", and "
         << third_month << " is "
         << setprecision(2) << fixed
         << average_rainfall << " inches."
         << endl;

    return 0;

}
