//*****************************************************************************************************
//
//		This program defines a Date class in C++ that handles date input and display. The class has a
//      default constructor that sets the date to January 1, 2000, a destructor, and methods for
//      inputting and displaying a date. The inputDate method validates the user input to ensure it
//      is a valid date, including checking for leap years, and sets the values using setter methods.
//      The displayDate method displays the date in month/day/year format using getter methods.
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

#include "Date.h"     // include header file for Date class

//*****************************************************************************************************

Date::Date() {     // default constructor sets date to 1/1/2000
    day = 1;
    month = 1;
    year = 2000;
}

//*****************************************************************************************************

Date::~Date() {
    // cout << "\nDestructor called" << endl;   // testing destructor call message
}

//*****************************************************************************************************

void Date::inputDate() {     // checks for valid date (leap years, days in month) and sets date
    cout << "\nEnter Year: ";
    cin >> year;

    while (year < 2022 || year > 2100) {
        cerr << "\nInvalid";     // cerr is unbuffered and best for error handling
        cout << "\nEnter Year(2022- ): ";
        cin >> year;

        cout << endl;
    }
    setYear(year);

    cout << "Enter Month: ";
    cin >> month;

    while (month < 1 || month > 12) {
        cerr << "\nInvalid";
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
            cerr << "\nInvalid";
            cout << "\nEnter Day(1-31): ";
            cin >> day;

            cout << endl;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        while (day < 1 || day > 30) {
            cerr << "\nInvalid";
            cout << "\nEnter Day(1-30): ";
            cin >> day;

            cout << endl;
        }
    } else if (year % 4 == 0) {     // February :: tests leap years
        while (day < 1 || day > 29) {
            cerr << "\nInvalid";
            cout << "\nEnter Day(1-29): ";
            cin >> day;

            cout << endl;
        }
    } else {
        while (day < 1 || day > 28) {
            cerr << "\nInvalid";
            cout << "\nEnter Day(1-28): ";
            cin >> day;

            cout << endl;
        }
    }
    setDay(day);
}

//*****************************************************************************************************

void Date::displayDate() {
    cout << getMonth() << "/" << getDay() << "/" << getYear();     // displays date in mm/dd/yyyy format
}

//*****************************************************************************************************