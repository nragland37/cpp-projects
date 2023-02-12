//*****************************************************************************************************
//
//		The program defines a class "Sport" that stores information about a sport event including its
//      name, date of the next game, number of teams, and names of the teams. The class has functions
//      for accessing and modifying the stored information, as well as functions for displaying the
//      information and populating the names of the teams.
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
    std::string name;
    Date nextGame;     // use Date class to store date of next game
    int numTeams;
    std::string *teamNames;     // use dynamic array to store names of teams (array size is numTeams)

   public:
    Sport(const std::string &n = "");     // initialize name to empty string if no argument is passed
    ~Sport();
    std::string getName() const;     // const used to indicate that the function does not modify the object
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