//*****************************************************************************************************
//      Sport Class Header File
//
//      This header file defines the private and public members and methods of the Sport class and
//      defines the inline functions (getters and setters).
//
//      Other files required:
//        1.  date.h - header file for Date class
//
//*****************************************************************************************************

#ifndef SPORT_H
#define SPORT_H

//*****************************************************************************************************

#include "date.h"
#include <string>

//*****************************************************************************************************

class Sport {
private:
    std::string name;
    Date nextGame;     // use Date class to store date of next game
    int numTeams;
    std::string *teamNames;

public:
    Sport(const std::string &n = "");     // default argument so that Sport object can be created without arguments
    ~Sport();
    std::string getName() const;     // const used when methods do not change the object's data members
    void setName(const std::string &n);
    Date getDate() const;
    void setDate(const Date &d);
    int getNumTeams() const;
    void setNumTeams(const int &n);
    void display() const;
    void populate();
    void addTeam(const std::string &n);
};

//*****************************************************************************************************

inline std::string Sport::getName() const {
    return name;
}

//*****************************************************************************************************

inline void Sport::setName(const std::string &n) {
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