//****************************************************************************************************
// 		    File:                 Sport.cpp
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

#include "Sport.h"

#include <iomanip>
#include <iostream>
#include <string>

#include "Date.h"

using namespace std;

//****************************************************************************************************
Sport::Sport(const string& n) {
    name = n;
    numTeams = 0;
    teamNames = nullptr;
}

//****************************************************************************************************

Sport::~Sport() {
    delete[] teamNames;
    // cout << "\nDestructor called" << endl; // deallocate memory ~ test: passed
}

//****************************************************************************************************

void Sport::display() const {
    Date d1 = getDate();
    cout << "\t\t" << setfill('.') << setw(30) << left << "Sport Name "
         << " "
         << getName() << endl;
    cout << "\t\t" << setfill('.') << setw(30) << left << "Scheduled Date (M/D/YY) "
         << " ";
    d1.displayDate();
    cout << endl
         << endl;
    cout << "\t\t" << setfill('.') << setw(30) << left << "Number of Teams "
         << " "
         << getNumTeams() << endl;
    for (int i = 0; i < getNumTeams(); ++i) {
        cout << "\t\t"
             << "Team " << i + 1 << setfill('.') << setw(24) << left
             << " "
             << " "
             << teamNames[i] << endl;
    }
}

//****************************************************************************************************

void Sport::populate() {
    char entry;

    cin.ignore();
    cout << "Enter the name of the sport: ";
    getline(cin, name);
    setName(name);

    cout << "Sport has a scheduled game? (Y/N)" << endl;
    cin >> entry;
    if (entry == 'Y' || entry == 'y') {
        cout << "Next Scheduled Game";
        nextGame.inputDate();
        setDate(nextGame);
    } else {
        cout << "\nDefault date will be set to January 1, 2000." << endl
             << endl;
    }
    cout << "Enter the number of teams: ";
    cin >> numTeams;
    setNumTeams(numTeams);

    teamNames = new string[numTeams];
    cin.ignore();
    for (int i = 0; i < numTeams; ++i) {
        cout << "Enter the name of team " << i + 1 << ": ";
        getline(cin, teamNames[i]);
    }
}

//****************************************************************************************************

void Sport::addTeam(const string& n) {
    string* temp = new string[numTeams + 1];
    for (int i = 0; i < numTeams; ++i) {
        temp[i] = teamNames[i];
    }
    temp[numTeams] = n;
    delete[] teamNames;
    teamNames = temp;
    numTeams++;
}

    /*

    numTeams++;
    string* tempTNames = new string[numTeams];
    for (int i = 0; i < numTeams - 1; i++) {
        tempTNames[i] = teamNames[i];
    }
    tempTNames[numTeams - 1] = n;
    teamNames = new string[numTeams];
    teamNames = tempTNames;
    
    */