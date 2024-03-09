//*****************************************************************************************************
//      Date class header file
//
//      This header file defines the private and public members and methods of the Date class and
//      defines the inline functions (getters and setters).
//
//*****************************************************************************************************

#ifndef DATE_H
#define DATE_H

//*****************************************************************************************************

class Date {
private:     // private can only be accessed within the class
    int day;
    int month;
    int year;

public:          // public can be accessed within and outside the class
    Date();      // constructor
    ~Date();     // destructor
    int getDay() const;
    void setDay(const int &d);
    int getMonth() const;
    void setMonth(const int &m);
    int getYear() const;
    void setYear(const int &y);
    void inputDate();
    void displayDate();
};

//*****************************************************************************************************

inline int Date::getDay() const {     // inline is a keyword for simple methods
    return day;
}

//*****************************************************************************************************

inline void Date::setDay(const int &d) {
    day = d;
}

//*****************************************************************************************************

inline int Date::getYear() const {
    return year;
}

//*****************************************************************************************************

inline void Date::setYear(const int &y) {
    year = y;
}

//*****************************************************************************************************

inline int Date::getMonth() const {
    return month;
}

//*****************************************************************************************************

inline void Date::setMonth(const int &m) {
    month = m;
}

//*****************************************************************************************************

#endif