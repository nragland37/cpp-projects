//****************************************************************************************************
// 		    File:                 assignment_8.cpp
//
//		    Student:              Nicholas Ragland
//
//		    Assignment:           Program #8
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  April 11, 2022
//
//****************************************************************************************************

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//****************************************************************************************************
struct dateEmployed {
    int month,
        day,
        year;
};
struct Employee {
    string name;
    int age;
    dateEmployed date;
};

Employee* readEmployees(const string& empFile, int& numEmps);
void displayEmployees(const Employee emps[], int numEmps);
Employee* inputEmployees(Employee* emps, int& numEmps);

//****************************************************************************************************

int main() {
    string empFile = "Employees.txt";
    int numEmps;
    fstream f;
    char entry;

    f.open(empFile, ios::in);
    while (f.is_open()) {
        f >> numEmps;
        f.close();
        Employee* emps = readEmployees(empFile, numEmps);
        displayEmployees(emps, numEmps);
        cout << "\nAny additional employees need to be added? (Y/N)" << endl;
        cin >> entry;
        if (entry == 'y' || entry == 'Y') {
            Employee* newEmps = inputEmployees(emps, numEmps);
            displayEmployees(newEmps, numEmps);
            delete[] emps;
            emps = nullptr;
            delete[] newEmps;
            newEmps = nullptr;
        } else {
            delete[] emps;
            emps = nullptr;
            break;
        }
    }
    if (!f) {
        cout << "cannot open file" << endl;
    }

    return 0;
}

//****************************************************************************************************

Employee* readEmployees(const string& empFile, int& numEmps) {
    fstream f;
    f.open(empFile, ios::in);
    Employee* tmp = new Employee[numEmps];
    f.ignore(2);
    for (int i = 0; i < numEmps; ++i) {
        getline(f, tmp[i].name, ',');
        f >> tmp[i].age;
        f.ignore();
        f >> tmp[i].date.month;
        f.ignore();
        f >> tmp[i].date.day;
        f.ignore();
        f >> tmp[i].date.year;
        f.ignore();
    }
    f.close();

    return tmp;
}

//****************************************************************************************************

Employee* inputEmployees(Employee* emps, int& numEmps) {
    fstream f;
    int newEntries,
        oldEmps = numEmps,
        age,
        month,
        day,
        year;
    string name;

    cout << "How many?" << endl;
    cin >> newEntries;
    cin.ignore();

    Employee* newemps = new Employee[numEmps + newEntries];
    for (int i = 0; i < numEmps; i++) {
        newemps[i].name = emps[i].name;
        newemps[i].age = emps[i].age;
        newemps[i].date.month = emps[i].date.month;
        newemps[i].date.day = emps[i].date.day;
        newemps[i].date.year = emps[i].date.year;
    }

    numEmps = numEmps + newEntries;
    f.open("Employees.txt", ios::out);
    f << numEmps << endl;
    for (int i = 0; i < numEmps - newEntries; ++i) {
        f << newemps[i].name << "," << newemps[i].age << ","
          << newemps[i].date.month << "/" << newemps[i].date.day
          << "/" << newemps[i].date.year << endl;
    }
    f.close();
    f.open("Employees.txt", ios::app);
    for (int i = oldEmps; i < numEmps; ++i) {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter year: ";
        cin >> year;
        cin.ignore();
        newemps[i].name = name;
        newemps[i].age = age;
        newemps[i].date.month = month;
        newemps[i].date.day = day;
        newemps[i].date.year = year;
        f << newemps[i].name << "," << newemps[i].age << ","
          << newemps[i].date.month << "/" << newemps[i].date.day
          << "/" << newemps[i].date.year << endl;
    }
    f.close();
    return newemps;
}

//****************************************************************************************************

void displayEmployees(const Employee emps[], int numEmps) {
    cout << setw(30) << left << "\nNAME"
         << setw(20) << left << "AGE"
         << "DATE EMPLOYED" << endl;
    for (int i = 0; i < numEmps; ++i) {
        cout << setw(30) << left << emps[i].name
             << setw(20) << left << emps[i].age
             << emps[i].date.month << "/" << emps[i].date.day << "/" << emps[i].date.year << endl;
    }
}

/*

cannot open file

//****************************************************************************************************

NAME                          AGE                 DATE EMPLOYED
Stephen Smith                 25                  12/15/2001
Susan Kim-Jones               33                  1/9/2012
Praew Chaem Choi              52                  8/22/1999

Any additional employees need to be added? (Y/N)
N

//****************************************************************************************************

NAME                          AGE                 DATE EMPLOYED
Stephen Smith                 25                  12/15/2001
Susan Kim-Jones               33                  1/9/2012
Praew Chaem Choi              52                  8/22/1999

Any additional employees need to be added? (Y/N)
Y
How many?
2
Enter name: Nicholas Ragland
Enter age: 30
Enter month: 7
Enter day: 8
Enter year: 1991
Enter name: Olivia Davisson
Enter age: 23
Enter month: 2
Enter day: 27
Enter year: 1999

NAME                          AGE                 DATE EMPLOYED
Stephen Smith                 25                  12/15/2001
Susan Kim-Jones               33                  1/9/2012
Praew Chaem Choi              52                  8/22/1999
Nicholas Ragland              30                  7/8/1991
Olivia Davisson               23                  2/27/1999

//****************************************************************************************************
// File after update //
5
Stephen Smith,25,12/15/2001
Susan Kim-Jones,33,1/9/2012
Praew Chaem Choi,52,8/22/1999
Nicholas Ragland,30,7/8/1991
Olivia Davisson,23,2/27/1999

*/