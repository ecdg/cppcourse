// Overloaded Function
// By Emily Dayanghirang

#include <iostream>
#include <iomanip>
using namespace std;

int initialPatientInfo();

double totalCharges(int days,
                    double dailyRate,
                    double medicationCharges,
                    double servicesCharges);

double totalCharges(double servicesCharges,
                    double medicationCharges);

int main()
{

    cout << "\n***The program does not accept negative numbers.***\n";
    int patientInfo;
    patientInfo = initialPatientInfo();

    int days;
    double dailyRate,
           medicationCharges,
           servicesCharges,
           total;

    if(patientInfo == 1)
    {
        // Inpatient

        do
        {
            cout << "\nThe number of days of your stay at the hospital: ";
            cin >> days;

            if(days < 0)
            {
                cout << "\nInvalid input.\n";
            }

        }while(days < 0);

        do
        {
            cout << "\nThe daily rate at the hospital: ";
            cin >> dailyRate;

            if(dailyRate < 0)
            {
                cout << "\nInvalid input.\n";
            }

        }while(dailyRate < 0);

        do
        {
            cout << "\nHospital medications charges: ";
            cin >> medicationCharges;

            if(medicationCharges < 0)
            {
                cout << "\nInvalid input.\n";
            }

        }while(medicationCharges < 0);

        do
        {
            cout << "\nHospital services charges (lab tests, etc.): ";
            cin >> servicesCharges;

            if(servicesCharges < 0)
            {
                cout << "\nInvalid input.\n";
            }

        }while(servicesCharges < 0);

        total = totalCharges(days,
                             dailyRate,
                             medicationCharges,
                             servicesCharges);

        cout << fixed << setprecision(2);

        cout << "\nThe total charges are $" << total << " ." << endl;

    }

    if(patientInfo == 2)
    {
        // Outpatient

        do
        {
            cout << "\nHospital services charges (lab tests, etc.): ";
            cin >> servicesCharges;

            if(servicesCharges < 0)
            {
                cout << "\nInvalid input.\n";
            }

        }while(servicesCharges < 0);

        do
        {
            cout << "\nHospital medications charges: ";
            cin >> medicationCharges;

            if(medicationCharges < 0)
            {
                cout << "\nInvalid input.\n";
            }

        }while(medicationCharges < 0);


        total = totalCharges(servicesCharges,
                             medicationCharges);

        cout << fixed << setprecision(2);

        cout << "\nThe total charges are $" << total << " ." << endl;

    }

    return 0;
}

int initialPatientInfo()
{
    int patientInfo;

    do
    {
        cout << "\nWere you admitted as an inpatient or an outpatient?\n"
                "Input the number 1 if you were admitted as an inpatient.\n"
                "Input the number 2 if you were admitted as an outpatient.\n"
                "Input: ";

        cin >> patientInfo;

        if(patientInfo != 1 && patientInfo != 2)
        {
            cout << "\nInvalid input.\n";
        }

    }while(patientInfo != 1 && patientInfo != 2);

    return patientInfo;
}

double totalCharges(int days, double dailyRate, double medicationCharges, double servicesCharges)
{
    double total;

    total = (days * dailyRate) + medicationCharges + servicesCharges;

    return total;

}

double totalCharges(double servicesCharges, double medicationCharges)
{
    double total;

    total = servicesCharges + medicationCharges;

    return total;
}