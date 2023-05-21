//*****************************************************************************************************
//      Date class header file
//
//      This header file defines the private and public members and methods of the Date class and
//      defines the inline functions (getters and setters).
//
//*****************************************************************************************************

#ifndef DATE_H     // prevent multiple inclusion of header file
#define DATE_H

// note:: never use "using namespace std;" in a header file because it will cause problems when the
// header file is included in multiple source files

//*****************************************************************************************************

class Date {
   private:     // private member variables are not accessible outside the class
    int day;
    int month;
    int year;

   public:     // public member functions are accessible outside the class and can be called from main()
    Date();
    ~Date();     // optional destructor since there is no dynamic memory allocation or
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

inline int Date::getDay() const {     // inline functions are defined in the header file for efficiency
    return day;                       // used for small functions that are called frequently (typically getters and setters)
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

#endif     // end of #ifndef preprocessor directive
