// Activity 4: Ingredient Adjuster
// By Emily Dayanghirang

#include <iostream>

using namespace std;

int main()
{
    // Exact amount of ingredients produces 48 cookies
    const double CUPS_OF_SUGAR = 1.5;
    const double CUPS_OF_FLOUR = 2.75;
    const int CUP_OF_BUTTER = 1;
    const int STANDARD_NUMBER_OF_COOKIES = 48;

    int userNumberOfCookies;
    double result, userCupsOfSugar, userCupsOfFlour, userCupsOfButter;

    // Prompt user
    cout << "How many cookies do you want to make? ";
    cin >> userNumberOfCookies;


    /*
    Computation for the number of cups of each
    ingredient needed for the specified number
    of cookies
    */

    // Explicit type casting
    result = static_cast<double>(userNumberOfCookies) / STANDARD_NUMBER_OF_COOKIES;
    userCupsOfSugar = result * CUPS_OF_SUGAR;
    userCupsOfFlour = result * CUPS_OF_FLOUR;
    userCupsOfButter = result * CUP_OF_BUTTER;

    // Display the ingredients the user will need
    cout << "\nTo make " << userNumberOfCookies << " cookies, you will need:\n";
    cout << "\t" << userCupsOfSugar << " cups of sugar\n"
         << "\t" << userCupsOfFlour << " cups of flour\n"
         << "\t" << userCupsOfButter << " cups of butter\n";

    return 0;
}

