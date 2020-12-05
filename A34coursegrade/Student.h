#ifndef STUDENT_H
#define STUDENT_H
#include <cstring>
 
class Student
{
   public:
       Student();
       Student(char*, char*, int);
       ~Student();
       const char* getName() const;
       const char* getId() const;
       int getNumTests() const;
       void setName (char*);
       void setId(char*);
       void setNumTests(int);
       void addTest(double, int);
       void generateInfo();
 
 
   private:
       char name[81]={};
       char idNum[11]={};
       int numTests;
       double* tests;
       double average;
       char grade;
       double calcAverage() const;
       char calcLetterGrade() const;
};
 
#endif // STUDENT_H