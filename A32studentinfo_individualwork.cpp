// Student Information - using pointers to structure
// By Emily Dayanghirang
#include <iostream>
#include <iomanip>
using namespace std;

struct Student
{
    string name;
    string idNum;
    float* tests;
    float average;
    char grade;
};

Student setInformation(int);
void setGrade(Student&);
bool validName(string);
void display(const Student*, int, int);

int main()
{
    Student* students;
    int numOfTests, numOfStudents;

    cout << "\nThe program will do the following by order: \n"
         << "(1) Ask the number of students you have\n"
         << "(2) Ask the number of tests taken by your students\n"
         << "(3) Ask for information of each student including test scores\n"
         << "(4) Average the test scores of each student\n"
         << "(5) Determine the grade of each student\n"
         << "(6) Display the information of each student\n";

    cout << "\nNumber of students: ";
    cin >> numOfStudents;
    while(numOfStudents < 1)
    {
        cout << "Please enter an input of more than zero for the # of students: ";
        cin >> numOfStudents;
    }
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid integer value for the # of students: ";
        cin >> numOfStudents;
    }
    cin.ignore();

    students = new Student[numOfStudents];

    cout << "\nEnter number of tests taken by your students: ";
    cin >> numOfTests;
    while(numOfTests < 1)
    {
        cout << "Please enter an input of more than zero for the # of tests: ";
        cin >> numOfTests;
    }
    while (cin.fail())
    {
        cout << "Please enter a valid integer value for the # of tests: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> numOfTests;
    }
    cin.ignore();

    for (int index = 0; index < numOfStudents; index++)
    {
        cout << "\nEnter Student #" << (index + 1) << " information: " << endl;
        *(students + index) = setInformation(numOfTests);
    }

    display(students, numOfStudents, numOfTests);

    for (int index = 0; index < numOfStudents; index++)
        delete [] (students + index)->tests;
    delete [] students;

    return 0;
}

Student setInformation(int numOfTests)
{
    float total = 0;
    Student studentInfo;
    cout << "Enter student name: ";
    getline(cin, studentInfo.name);
    while (!validName(studentInfo.name))
    {
        cout << "\nPlease try again: ";
        cin.clear();
        cin.ignore(1000, '\n');
        getline(cin, studentInfo.name);
    }
    cout << "Enter student ID: ";
    getline(cin, studentInfo.idNum);
    while (cin.fail())
    {
        cout << "Input error. Please try again: ";
        cin.clear();
        cin.ignore(1000, '\n');
        getline(cin, studentInfo.idNum);
    }

    studentInfo.tests = new float[numOfTests];

    for(int index = 0; index < numOfTests; index++)
    {
        cout << "Enter test #" << index + 1 << " score: ";
        cin >> *(studentInfo.tests+index);
        while (cin.fail())
        {
            cout << "Please enter a valid floating point value for the test score: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> *(studentInfo.tests+index);
        }
        cin.ignore();

        total += *(studentInfo.tests+index);
    }

    studentInfo.average = total/static_cast<float>(numOfTests);
    setGrade(studentInfo);

    return studentInfo;
}

void setGrade(Student& student)
{
    if(student.average >= 90.0)
        student.grade = 'A';
    if(student.average >= 80.0 && student.average < 90.0)
        student.grade = 'B';
    if(student.average >= 70.0 && student.average < 80.0)
        student.grade = 'C';
    if(student.average >= 60.0 && student.average < 70.0)
        student.grade = 'D';
    if(student.average < 60.0)
        student.grade = 'F';
}

bool validName(string name)
{
    if(name.length() == 0)
    {
        cout << "Name cannot be empty.";
        return false;
    }

    for(int i = 0; i < name.length(); i++)
    {
        if(name[i] >= '0' && name[i] <= '9')
        {
            cout << "\nName cannot contain numerical values.";
            return false;
        }
    }

    return true;
}

void display(const Student* student, int numOfStudents, int numOfTests)
{
    cout << "\nStudent Information:";
    for (int i = 0; i <  numOfStudents; i++)
    {
        cout << "\n|--------------------------------------------|";
        cout << "\n|Name: " << (student+i)->name;
        cout << "\n|ID: " << (student+i)->idNum;

        for(int index = 0; index < numOfTests; index++)
        {
            cout << "\n|Test #" << index + 1 << " score: " << fixed << setprecision(2)
                 << *((student+i)->tests+index);
        }

        cout << "\n|Average: " << fixed << setprecision(2)
             << (student+i)->average;
        cout << "\n|Grade: " << (student+i)->grade;
        cout << "\n|--------------------------------------------|";
    }
}
