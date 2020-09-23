// Mobile Service Provider
// By Emily Dayanghirang
#include <iostream>
using namespace std;

int main()
{
    const double PACKAGE_A_MONTHLY_PAYMENT = 39.99;
    const int PACKAGE_A_DATA = 4;
    const double PACKAGE_A_ADDITIONAL_DATA_COST = 10.00;

    const double PACKAGE_B_MONTHLY_PAYMENT = 59.99;
    const int PACKAGE_B_DATA = 8;
    const double PACKAGE_B_ADDITIONAL_DATA_COST = 5.00;

    const double PACKAGE_C_MONTHLY_PAYMENT = 69.99;
    const string PACKAGE_C_DATA = "unlimited";

    char package;
    double totalAmount;
    int gigabytesUsed, additionalDataUsed;

    // Display packages and their rates
    cout << "Package A:\n"
         << "Monthly Payment: $39.99\n"
         << "Data: 4 GB\n"
         << "Additional Data Cost: $10.00\n\n";

    cout << "Package B:\n"
         << "Monthly Payment: $59.99\n"
         << "Data: 8 GB\n"
         << "Additional Data Cost: $5.00\n\n";

    cout << "Package C:\n"
         << "Monthly Payment: $69.99\n"
         << "Data: Unlimited\n\n";

    // Prompt user
    cout << "Package purchased (A, B, or C): ";
    cin >> package;

    // Conditions
    // Calculations for each package
    switch(package)
    {
        case 'a':
        case 'A':
            cout << "Gigabytes used: ";
            cin >> gigabytesUsed;

            if(gigabytesUsed <= PACKAGE_A_DATA)
            {
                cout << "\nThe total amount due is $"  << PACKAGE_A_MONTHLY_PAYMENT << ".";
            }
            else
            {
                additionalDataUsed = gigabytesUsed - PACKAGE_A_DATA;
                totalAmount = PACKAGE_A_MONTHLY_PAYMENT +
                              (additionalDataUsed * PACKAGE_A_ADDITIONAL_DATA_COST);
                cout << "\nThe total amount due is $"  << totalAmount << ".";

            }
            break;
        case 'b':
        case 'B':
            cout << "Gigabytes used: ";
            cin >> gigabytesUsed;

            if(gigabytesUsed <= PACKAGE_B_DATA)
            {
                cout << "\nThe total amount due is $"  << PACKAGE_B_MONTHLY_PAYMENT << ".";
            }
            else
            {
                additionalDataUsed = gigabytesUsed - PACKAGE_B_DATA;
                totalAmount = PACKAGE_B_MONTHLY_PAYMENT +
                              (additionalDataUsed * PACKAGE_B_ADDITIONAL_DATA_COST);
                cout << "\nThe total amount due is $"  << totalAmount << ".";
            }
            break;
        case 'c':
        case 'C':
            cout << "\nThe total amount due is $"  << PACKAGE_C_MONTHLY_PAYMENT << ".";
            return 0;
        default:
            cout << "\nPlease enter the letters A, B, or C only.";

    }
    return 0;
}