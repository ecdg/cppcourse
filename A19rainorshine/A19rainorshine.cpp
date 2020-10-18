// Rain or Shine
// By Emily Dayanghirang

#include <iostream>
#include <fstream>
using namespace std;

const int NUMBER_OF_MONTHS = 3;
const int NUMBER_OF_DAYS = 30;

int main()
{

    ifstream infile("RainOrShine.txt");

    char weather[NUMBER_OF_MONTHS][NUMBER_OF_DAYS];
    int rainyDaysAllMonths[NUMBER_OF_MONTHS];

    int determineMonthlyWeather(char [][NUMBER_OF_DAYS], int);
    void determineAllWeather(char [][NUMBER_OF_DAYS], int, int);
    void introduction();

    int rainyFirstMonth,
        rainySecondMonth,
        rainyThirdMonth,
        largestNumberOfRainyDays,
        monthWithMostRainyDays;

    if(infile.is_open())
    {
        for(int i = 0; i < NUMBER_OF_MONTHS; i++)
        {
            for(int j = 0; j < NUMBER_OF_DAYS; j++)
            {
                infile >> weather[i][j];
            }
        }
    }

    introduction();

    for(int month = 0; month < NUMBER_OF_MONTHS; month++)
    {
            rainyDaysAllMonths[month] = determineMonthlyWeather(weather, month);
    }

    determineAllWeather(weather, NUMBER_OF_MONTHS, NUMBER_OF_DAYS);

    largestNumberOfRainyDays = rainyDaysAllMonths[0];

    for(int k = 0; k < NUMBER_OF_MONTHS; k++)
    {
        if(rainyDaysAllMonths[k] > largestNumberOfRainyDays)
        {
            largestNumberOfRainyDays = rainyDaysAllMonths[k];
            monthWithMostRainyDays = k + 1;

        }

    }

    cout << "\nMonth " << monthWithMostRainyDays
         << " had the largest number of rainy days"
         << " with " << largestNumberOfRainyDays
         << " rainy days.\n";

    return 0;
}

int determineMonthlyWeather(char weather[][NUMBER_OF_DAYS], int month)
{
    int rainy = 0,
        cloudy = 0,
        sunny = 0;

    for(int day = 0; day < NUMBER_OF_DAYS; day++)
    {
        if(weather[month][day] == 'R')
            rainy++;

        else if(weather[month][day] == 'C')
            cloudy++;

        else if(weather[month][day] == 'S')
            sunny++;
    }

    cout << "\nMonth " << month + 1 << ": \n"
         << "------------------------------\n"
         << rainy << " Rainy Days\n"
         << cloudy << " Cloudy Days\n"
         << sunny << " Sunny Days\n";

    return rainy;
}

void determineAllWeather(char weather[][NUMBER_OF_DAYS], int months, int days)
{
    int rainy = 0,
        cloudy = 0,
        sunny = 0;

    for(int month = 0; month < months; month++)
    {
        for(int day = 0; day < days; day++)
        {
            if(weather[month][day] == 'R')
                rainy++;

            else if(weather[month][day] == 'C')
                cloudy++;

            else if(weather[month][day] == 'S')
                sunny++;

        }
    }

    cout << "\nFor the whole three-month period there were: \n"
         << "--------------------------------------------------\n"
         << rainy << " Rainy Days\n"
         << cloudy << " Cloudy Days\n"
         << sunny << " Sunny Days\n";
}

void introduction()
{
    cout << "\nThe weather conditions during the past year’s three-month summer season:\n";
}
