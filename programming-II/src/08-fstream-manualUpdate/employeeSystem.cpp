//*****************************************************************************************************
//      Employee Management System
//
//      This program demonstrates the use of file input/output, dynamic memory allocation, and
//      structures to read employee information from a text file, allow the user to add new employees,
//      display all employee information, and manually write the updated employee information back to
//      the file.
//
//      Other files required:
//        1.  Employees.txt - number of employees and the employee information
//
//*****************************************************************************************************

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

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

Employee *readEmployees(const string &empFile, int &numEmps);
void displayEmployees(const Employee emps[], int numEmps);
Employee *inputEmployees(Employee *emps, int &numEmps);

//*****************************************************************************************************

int main() {
    string empFile = "Employees.txt";
    int numEmps;
    fstream f;
    char entry;

    f.open(empFile, ios::in);

    while (f.is_open()) {
        f >> numEmps;
        f.close();

        Employee *emps = readEmployees(empFile, numEmps);
        displayEmployees(emps, numEmps);

        cout << "\nAny additional employees need to be added? (Y/N)" << endl;
        cin >> entry;
        entry = toupper(entry);

        if (entry == 'Y') {
            Employee *newEmps = inputEmployees(emps, numEmps);
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
    if (!f)
        cerr << "Error: Unable to open file\n";

    return 0;
}

//*****************************************************************************************************

Employee *readEmployees(const string &empFile, int &numEmps) {
    fstream f;

    f.open(empFile, ios::in);               // open file for reading
    Employee *tmp = new Employee[numEmps];
    f.ignore(2);                            // ignore first two characters in file

    for (int i = 0; i < numEmps; ++i) {
        getline(f, tmp[i].name, ',');       // getline( file, string, delimiter )
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

//*****************************************************************************************************

Employee *inputEmployees(Employee *emps, int &numEmps) {
    fstream f;
    int newEntries,
        oldEmps = numEmps,
        age,
        month,
        day,
        year;
    string name;

    cout << "\nHow many?" << endl;
    cin >> newEntries;

    cin.ignore();
    Employee *newemps = new Employee[numEmps + newEntries];

    for (int i = 0; i < numEmps; i++) {
        newemps[i].name = emps[i].name;
        newemps[i].age = emps[i].age;
        newemps[i].date.month = emps[i].date.month;
        newemps[i].date.day = emps[i].date.day;
        newemps[i].date.year = emps[i].date.year;
    }

    numEmps = numEmps + newEntries;

    f.open("Employees.txt", ios::out);     // open file for writing
    f << numEmps << endl;

    for (int i = 0; i < numEmps - newEntries; ++i)
        f << newemps[i].name << ","
          << newemps[i].age << ","
          << newemps[i].date.month
          << "/" << newemps[i].date.day
          << "/" << newemps[i].date.year << endl;

    f.close();

    f.open("Employees.txt", ios::app);     // open file for appending

    for (int i = oldEmps; i < numEmps; ++i) {
        cout << "\nName: ";
        getline(cin, name);

        cout << "Age: ";
        cin >> age;

        cout << "\nDate Employed\n"
             << "Month: ";
        cin >> month;

        cout << "Day: ";
        cin >> day;

        cout << "Year: ";
        cin >> year;

        cin.ignore();
        newemps[i].name = name;
        newemps[i].age = age;
        newemps[i].date.month = month;
        newemps[i].date.day = day;
        newemps[i].date.year = year;
        f << newemps[i].name << ","
          << newemps[i].age << ","
          << newemps[i].date.month
          << "/" << newemps[i].date.day
          << "/" << newemps[i].date.year << endl;
    }
    f.close();

    return newemps;
}

//*****************************************************************************************************

void displayEmployees(const Employee emps[], int numEmps) {
    cout << left << setw(30) << "\nName" << setw(20) << "Age" << setw(10) << "Date Employed" << endl;

    cout << setfill('-') << setw(63) << "" << endl;
    cout << setfill(' ');

    for (int i = 0; i < numEmps; ++i)
        cout << left
             << setw(30) << emps[i].name
             << setw(23) << emps[i].age
             << right << setw(10)
             << setw(2) << emps[i].date.month << "/"
             << setw(2) << emps[i].date.day << "/"
             << setw(4) << emps[i].date.year << endl;
}

//*****************************************************************************************************
/*

Name                          Age                 Date Employed
---------------------------------------------------------------
Stephen Smith                 25                     12/15/2001
Susan Kim-Jones               33                      1/ 9/2012
Praew Chaem Choi              52                      8/22/1999

Any additional employees need to be added? (Y/N)
N

*****************************************************************************************************

Name                          Age                 Date Employed
---------------------------------------------------------------
Stephen Smith                 25                     12/15/2001
Susan Kim-Jones               33                      1/ 9/2012
Praew Chaem Choi              52                      8/22/1999

Any additional employees need to be added? (Y/N)
Y

How many?
3

Name: Nick Plant
Age: 31

Date Employed
Month: 7
Day: 8
Year: 1991

Name: Olivia Potters
Age: 24

Date Employed
Month: 2
Day: 27
Year: 1999

Name: Bob Bobbers
Age: 55

Date Employed
Month: 1
Day: 1
Year: 2023

Name                          Age                 Date Employed
---------------------------------------------------------------
Stephen Smith                 25                     12/15/2001
Susan Kim-Jones               33                      1/ 9/2012
Praew Chaem Choi              52                      8/22/1999
Nick Plant                    31                      7/ 8/1991
Olivia Potters                24                      2/27/1999
Bob Bobbers                   55                      1/ 1/2023

*/