// By Emily Dayanghirang
// The program gets the monthly collection and prints out its details

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double STATE_SALES_TAX = 0.04;
    const double COUNTY_SALES_TAX = 0.02;
    const double TOTAL_SALES_TAX = STATE_SALES_TAX + COUNTY_SALES_TAX;

    string month;
    int year;
    double total_amount_collected,
            product_sales,
            county_sales_tax_cost,
            state_sales_tax_cost,
            total_sales_tax_cost;

    // Prompt user
    cout << "What is the month of the collection? ";
    getline(cin, month);

    cout << "What is the year of the collection? ";
    cin >> year;

    cout << "What is the total amount collected at the cash register? ";
    cin >> total_amount_collected;

    // Calculations
    product_sales = (total_amount_collected / (1.00 + TOTAL_SALES_TAX));

    county_sales_tax_cost = (product_sales * COUNTY_SALES_TAX);
    state_sales_tax_cost = (product_sales * STATE_SALES_TAX);
    total_sales_tax_cost = county_sales_tax_cost + state_sales_tax_cost;

    // Display the month's collection
    cout << endl << setprecision(2) << fixed << showpoint
         << "Month: " << month << endl
         << "-------------------------" << endl
         << "Total Collected:" << setw(10) << "$" << setw(9) << total_amount_collected << endl
         << "Sales:" << setw(20) << "$" << setw(9) << product_sales << endl
         << "County Sales Tax:" << setw(9) << "$" << setw(9) << county_sales_tax_cost << endl
         << "State Sales Tax:" << setw(10) << "$" << setw(9) << state_sales_tax_cost << endl
         << "Total Sales Tax:" << setw(10) << "$" << setw(9) << total_sales_tax_cost << endl;

    return 0;
}

