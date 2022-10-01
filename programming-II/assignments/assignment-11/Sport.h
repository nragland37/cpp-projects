//****************************************************************************************************
// 		    File:                 Sport.h
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

#ifndef SPORT_H
#define SPORT_H

#include <string>

#include "Date.h"

//****************************************************************************************************

class Sport {
   private:
    std::string name;
    Date nextGame;
    int numTeams;
    std::string* teamNames;

   public:
    Sport(const std::string& n = "");
    ~Sport();
    std::string getName() const;
    void setName(const std::string& n);
    Date getDate() const;
    void setDate(const Date& d);
    int getNumTeams() const;
    void setNumTeams(const int& n);
    void display() const;
    void populate();
    void addTeam(const std::string& n);
};

//****************************************************************************************************

inline std::string Sport::getName() const {
    return name;
}

//****************************************************************************************************

inline void Sport::setName(const std::string& n) {
    name = n;
}

//****************************************************************************************************

inline Date Sport::getDate() const {
    return nextGame;
}

//****************************************************************************************************

inline void Sport::setDate(const Date& d) {
    nextGame = d;
}

//****************************************************************************************************
inline int Sport::getNumTeams() const {
    return numTeams;
}

//****************************************************************************************************

inline void Sport::setNumTeams(const int& n) {
    numTeams = n;
}

#endif