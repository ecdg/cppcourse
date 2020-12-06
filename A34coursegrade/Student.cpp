#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"
using namespace std;
 
 
Student::Student()
{
  strcpy(name,"none");
  strcpy(idNum,"none");
  numTests = 0;
  tests = nullptr;
}
 
Student::Student(char* name1, char* id, int numTests1)
{
  setName(name1);
  setId(id);
  setNumTests(numTests1);
  if (numTests > 0)
    tests = new double[numTests1];
  else
    tests = nullptr;
}
 
Student::~Student()
{
  if (numTests > 0)
    delete [] tests;
}
 
void Student::setName(char* n)
{
  strcpy(name,n);
}
 
void Student::setId(char* i)
{
  strcpy(idNum,i);
}
 
void Student::setNumTests(int i)
{
  numTests = i;
  if (numTests > 0)
    tests = new double[numTests];
  else
    tests = nullptr;
}
 
void Student::addTest(double tValue, int index)
{
  if (index >= 0 && index < numTests)
    *(tests + index) = tValue;
}
 
void Student::generateInfo()
{
  string letterGrade(1, calcLetterGrade());
  string tValues = "";
  for(int index = 0; index < numTests; index++)
    tValues += to_string(tests[index]) + "\t";
    
  cout << "\nName: \t\t" << getName() << "\n"
       << "ID: \t\t" << getId() << "\n"
       << setprecision(2) << fixed
       << "Tests: \t\t" << setprecision(4) << fixed << tValues << "\n"
       << "Average: \t" << setprecision(4) << fixed << calcAverage() << "\n"
       << "Letter: \t" << letterGrade << "\n";
}
 
const char* Student::getName() const
{
  return name;
}
 
const char* Student::getId() const
{
  return idNum;
}
 
int Student::getNumTests() const
{
  return numTests;
}
 
double Student::calcAverage() const
{
  double sum = 0.0;
  for(int index = 0; index < numTests; index++)
    sum += tests[index];
 
  return sum / numTests;
}
char Student::calcLetterGrade() const
{
  double average = calcAverage();
  char lGrade;
 
  if (average >= 90.0)
    lGrade = 'A';
  else if(average >= 80.0)
    lGrade = 'B';
  else if(average >= 70.0)
    lGrade = 'C';
  else if(average >= 60.0)
    lGrade = 'D';
  else
    lGrade = 'F';
  return lGrade;
}
