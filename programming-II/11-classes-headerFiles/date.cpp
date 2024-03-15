//*****************************************************************************************************
//      Date Class Implementation File
//
//      This class implementation file defines the methods (member functions) of the Date class.
//
//      Other files required:
//        1.  date.h - header file for Date class
//
//*****************************************************************************************************

#include "date.h"
#include <iostream>

//*****************************************************************************************************
// default constructor initializes member variables

Date::Date() {
    day = 1;
    month = 1;
    year = 2000;
}

//*****************************************************************************************************

Date::~Date() {
    std::cout << "\nDate object destroyed\n";
}

//*****************************************************************************************************
// checks for valid date (leap years, days in month) and sets date

void Date::inputDate() {
    std::cout << "\nEnter Year: ";
    std::cin >> year;

    while (year < 2022 || year > 2100) {
        std::cerr << "\nInvalid\n\n";
        std::cout << "Enter Year(2022- ): ";
        std::cin >> year;
    }

    setYear(year);

    std::cout << "Enter Month: ";
    std::cin >> month;

    while (month < 1 || month > 12) {
        std::cerr << "\nInvalid\n\n";
        std::cout << "Enter Month(1-12): ";
        std::cin >> month;
    }

    setMonth(month);

    std::cout << "Enter Day: ";
    std::cin >> day;

    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) {
        while (day < 1 || day > 31) {
            std::cerr << "\nInvalid\n\n";
            std::cout << "Enter Day(1-31): ";
            std::cin >> day;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        while (day < 1 || day > 30) {
            std::cerr << "\nInvalid\n\n";
            std::cout << "Enter Day(1-30): ";
            std::cin >> day;
        }
    } else if (year % 4 == 0) {     // February :: tests leap years
        while (day < 1 || day > 29) {
            std::cerr << "\nInvalid\n\n";
            std::cout << "Enter Day(1-29): ";
            std::cin >> day;
        }
    } else {
        while (day < 1 || day > 28) {
            std::cerr << "\nInvalid\n\n";
            std::cout << "Enter Day(1-28): ";
            std::cin >> day;
        }
    }

    setDay(day);
}

//*****************************************************************************************************

void Date::displayDate() {
    std::cout << getMonth() << "/" << getDay() << "/" << getYear();
}

//*****************************************************************************************************