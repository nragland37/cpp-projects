//*****************************************************************************************************
//      Sport Class Header File
//		
//      This header file defines the private and public members and methods of the Sport class and
//      defines the inline functions (getters and setters).
//
//      Other files required:
//          1.  Date.h - header file for Date class
//
//*****************************************************************************************************

#ifndef SPORT_H     // include guard to prevent multiple inclusion of the header file
#define SPORT_H

#include <string>

#include "Date.h"     // include Date.h to use Date class

// note:: never use "using namespace std;" in a header file because it will cause problems when the
// header file is included in multiple source files

//*****************************************************************************************************

class Sport {
   private:
    string name;
    Date nextGame;     // use Date class to store date of next game
    int numTeams;
    string *teamNames;     // use dynamic array to store names of teams (array size is numTeams)

   public:
    Sport(const string &n = "");     // default argument so that Sport object can be created without arguments
    ~Sport();
    string getName() const;     // const used to indicate that the function does not modify the object
    void setName(const string &n);
    Date getDate() const;
    void setDate(const Date &d);
    int getNumTeams() const;
    void setNumTeams(const int &n);
    void display() const;
    void populate();
    void addTeam(const string &n);
};

//*****************************************************************************************************

inline string Sport::getName() const {
    return name;
}

//*****************************************************************************************************

inline void Sport::setName(const string &n) {
    name = n;
}

//*****************************************************************************************************

inline Date Sport::getDate() const {
    return nextGame;
}

//*****************************************************************************************************

inline void Sport::setDate(const Date &d) {
    nextGame = d;
}

//*****************************************************************************************************
inline int Sport::getNumTeams() const {
    return numTeams;
}

//*****************************************************************************************************

inline void Sport::setNumTeams(const int &n) {
    numTeams = n;
}

//*****************************************************************************************************

#endif