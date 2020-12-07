// Course grade - using class and object
// By Emily Dayanghirang and Alina Corpora

#include "Student.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
 
void getInput(Student*);
 
int main()
{
   const int SIZE = 1;
 
   string string1 = "john";
   string string2 = "w1234";
 
   char* cstr1 = new char[string1.length()+1];
   strcpy(cstr1, string1.c_str());
 
   char* cstr2 = new char[string2.length()+1];
   strcpy(cstr2, string2.c_str());
 
   Student student[SIZE] = {Student(cstr1, cstr2, 2)},
                           *students = nullptr;
 
   int numOfStudents;
 
   cout << "\nNumber of students: ";
   cin >> numOfStudents;
 
   while(numOfStudents < 1)
   {
       cout << "Please enter an input of more than zero for the # of students: ";
       cin >> numOfStudents;
   }
   cin.ignore();
 
   students = new Student[numOfStudents];
 
   for (int index = 0; index < numOfStudents; index++)
   {
       getInput(students + index);
   }
 
   for (int index = 0; index < numOfStudents; index++)
   {
       (students + index)->generateInfo();
   }
 
   delete [] students;
   return 0;
}
 
void getInput(Student* newSt)
{
   char* name = new char[81];
   char* id = new char[11];
   int numT;
   double test;
 
   cout << "\nEnter student name: ";
   cin.getline(name, 81);
   cout << "Enter student id: ";
   cin.getline(id, 11);
   cout << "Enter number of tests: ";
   cin >> numT;
 
   while(numT < 1)
   {
       cout << "Please enter an input of more than zero for the # of tests: ";
       cin >> numT;
   }
   cin.ignore();
 
   newSt->setName(name);
   newSt->setId(id);
   newSt->setNumTests(numT);
 
   if (numT > 0)
   {
       for(int index = 0; index < numT; index++)
       {
           cout << "Enter test#" << (index + 1) << ": ";
           cin >> test;
           newSt->addTest(test, index);
       }
   }
   cin.ignore();
 
   delete [] name;
   delete [] id;
}
