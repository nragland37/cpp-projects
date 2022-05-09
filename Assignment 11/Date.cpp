//****************************************************************************************************
// 		    File:                 Date.cpp
//
//		    Student:              Nicholas Ragland
//
//		    Assignment:           Program #11
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  May 6, 2022
//
//****************************************************************************************************

#include "Date.h"

#include <iostream>

using namespace std;

//****************************************************************************************************

Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
}

//****************************************************************************************************

Date::~Date() {
    // cout << "\nDestructor called" << endl;    // deallocate memory ~ test: passed
}

//****************************************************************************************************

void Date::inputDate() {
    cout << "\nEnter Year: ";
    cin >> year;
    while (year < 2022 || year > 2100) {
        cout << "\n Invalid";
        cout << "\nEnter Year(2022- ): ";
        cin >> year;
        cout << endl;
    }
    setYear(year);
    cout << "Enter Month: ";
    cin >> month;
    while (month < 1 || month > 12) {
        cout << "\n Invalid";
        cout << "\nEnter Month(1-12): ";
        cin >> month;
        cout << endl;
    }
    setMonth(month);
    cout << "Enter Day: ";
    cin >> day;
    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) {
        while (day < 1 || day > 31) {
            cout << "\n Invalid";
            cout << "\nEnter Day(1-31): ";
            cin >> day;
            cout << endl;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        while (day < 1 || day > 30) {
            cout << "\n Invalid";
            cout << "\nEnter Day(1-30): ";
            cin >> day;
            cout << endl;
        }
    } else {
        if (year % 4 == 0) {  // February :: tests leap years
            while (day < 1 || day > 29) {
                cout << "\n Invalid";
                cout << "\nEnter Day(1-29): ";
                cin >> day;
                cout << endl;
            }
        } else {
            while (day < 1 || day > 28) {
                cout << "\n Invalid";
                cout << "\nEnter Day(1-28): ";
                cin >> day;
                cout << endl;
            }
        }
    }
    setDay(day);
}

//****************************************************************************************************

void Date::displayDate() {
    cout << getMonth() << "/" << getDay() << "/" << getYear();
}