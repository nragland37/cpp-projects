//****************************************************************************************************
// 		    File:                 Date.h
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

#ifndef DATE_H
#define DATE_H

//****************************************************************************************************

class Date {
   private:
    int day;
    int month;
    int year;

   public:
    Date();
    ~Date();
    int getDay() const;
    void setDay(const int& d);
    int getMonth() const;
    void setMonth(const int& m);
    int getYear() const;
    void setYear(const int& y);
    void inputDate();
    void displayDate();
};

//****************************************************************************************************

inline int Date::getDay() const {
    return day;
}

//****************************************************************************************************

inline void Date::setDay(const int& d) {
    day = d;
}

//****************************************************************************************************

inline int Date::getYear() const {
    return year;
}

//****************************************************************************************************

inline void Date::setYear(const int& y) {
    year = y;
}

//****************************************************************************************************

inline int Date::getMonth() const {
    return month;
}

//****************************************************************************************************

inline void Date::setMonth(const int& m) {
    month = m;
}

#endif
