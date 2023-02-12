//*****************************************************************************************************
//
//		This is the header file for a Date class in C++. The class has private member variables to
//      store the day, month, and year of a date. The class has a default constructor, a destructor,
//      and methods for getting and setting the day, month, and year. It also has methods for
//      inputting a date and displaying a date. The member functions are declared inline for
//      efficiency. Additionally, the header file includes an #ifndef preprocessor directive to
//      prevent multiple inclusion of the header file.
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
    ~Date();
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
    return day;                       // are used for small functions that are called frequently (typically getters and setters)
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
