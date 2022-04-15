//****************************************************************************************************
// 		    File:                 assignment_8.cpp
//
//		    Student:              Niki Portell
//
//		    Assignment:           Program #8
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  April 11, 2022
// 
//          Description:          A program that stores information for employees.
//
//****************************************************************************************************

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Date {
    int month = 0;
    int day = 0;
    int year = 0;
};

struct Employee {
    string name;
    int age = 0;
    Date dateEmp;
};

Employee* readEmployees(const string& empFile, int& numEmps);
void displayEmployees(const Employee emps[], int numEmps);
Employee* inputEmployees(Employee* emps, int& numEmps);

//****************************************************************************************************

int main() {

    ofstream f;

    string empFile = "Employees.txt";
    int numEmps = 0;
    Employee* emps = nullptr;
    Employee* emps2 = nullptr;

    emps = readEmployees(empFile, numEmps);
    displayEmployees(emps, numEmps);
    emps2 = inputEmployees(emps, numEmps);
 
    f.open(empFile);

    for (int i = 0; i < numEmps; i++)
    {
        f << emps2[i].name << "," << emps2[i].age << "," << emps2[i].dateEmp.month << "/"
          << emps2[i].dateEmp.day << "/" << emps2[i].dateEmp.year << endl;
    }

    f.close();

    delete[] emps;
    delete[] emps2;
    
    return 0;
}

//****************************************************************************************************

Employee* readEmployees(const string& empFile, int& numEmps)
{
    fstream f;
    Employee* p = nullptr;

    f.open(empFile, ios::in);

    if (f)
    {
        f >> numEmps;
        f.ignore();
        p = new Employee[numEmps];
 
        for (int i = 0; i < numEmps; i++)
        {
            getline(f, p[i].name, ',');
            f >> p[i].age;
            f.ignore();
            f >> p[i].dateEmp.month;
            f.ignore();
            f >> p[i].dateEmp.day;
            f.ignore();
            f >> p[i].dateEmp.year;
            f.ignore();
        }
        f.close();
    }
    else
    {
        cout << "File not found.";
    }
    return p;
}

//****************************************************************************************************

void displayEmployees(const Employee emps[], int numEmps)
{
    cout << fixed << left << setw(30) << "NAME" << setw(30) << "AGE" << setw(30)
        << "DATE EMPLOYED" << endl;

    for (int i = 0; i < numEmps; i++)
    {
        cout << setw(30) << emps[i].name;
        cout << setw(30) << emps[i].age;
        cout << emps[i].dateEmp.month << "/" << emps[i].dateEmp.day << "/"
             << emps[i].dateEmp.year << endl;
    }
}

//****************************************************************************************************

Employee* inputEmployees(Employee* emps, int& numEmps)
{
    bool addEmps = false;
    int numAdded = 0;
    Employee* emps2 = nullptr;
    string temp;

    cout << "Do any additional employees need to be added to the list? (1 = yes/0 = no)";
    cin >> addEmps;
    if (addEmps)
    {
        cout << "How many employees need to be added?";
        cin >> numAdded;
        cin.ignore();
        numEmps += numAdded;

        emps2 = new Employee[numEmps];

        for (int i = 0; i < numEmps - numAdded; i++)
        {
            emps2[i].name = emps[i].name;
            emps2[i].age = emps[i].age;
            emps2[i].dateEmp.month = emps[i].dateEmp.month;
            emps2[i].dateEmp.day = emps[i].dateEmp.day;
            emps2[i].dateEmp.year = emps[i].dateEmp.year;
        }
        
        for (int i = numEmps - numAdded; i < numEmps; i++)
        {
            cout << setw(25) << "NAME:";
            getline(cin, emps2[i].name);
            cout << setw(25) << "AGE:";
            cin >> emps2[i].age;
            cout << setw(25) << "EMPLOYED: XX/XX/XXXX";
            cin >> temp;
            emps2[i].dateEmp.month = stoi(temp.substr(0, 2));
            emps2[i].dateEmp.day = stoi(temp.substr(3, 2));
            emps2[i].dateEmp.year = stoi(temp.substr(6, 4));
            cin.ignore();
        }
    }
    return emps2;
}

//****************************************************************************************************

/*

NAME                          AGE                           DATE EMPLOYED
Stephen Smith                 25                            12/15/2001
Susan Kim-Jones               33                            1/9/2012
Praew Chaem Choi              52                            8/22/1999
Do any additional employees need to be added to the list? (1 = yes/0 = no)1
How many employees need to be added?1
NAME:                    Niki Portell
AGE:                     36
EMPLOYED: XX/XX/XXXX     06/07/1985

*/