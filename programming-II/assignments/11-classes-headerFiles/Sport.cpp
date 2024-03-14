//*****************************************************************************************************
//      Sport Class Implementation File
//
//      This class implementation file defines the methods (member functions) of the Sport class.
//
//      Other files required:
//        1.  sport.h - header file for Sport class
//
//*****************************************************************************************************

#include "sport.h"
#include <iostream>
#include <iomanip>
#include <string>

//*****************************************************************************************************

Sport::Sport(const std::string &n) {
    setName(n);
    numTeams = 0;
    teamNames = nullptr;
}

//*****************************************************************************************************

Sport::~Sport() {
    delete[] teamNames;     // deallocate memory in destructor
    std::cout << "\nSport object destroyed\n";
}

//*****************************************************************************************************

void Sport::display() const {
    Date d1 = getDate();     // sport.h includes Date.h so Date class is available to Sport class

    std::cout << "\t\t" << std::setfill('.') << std::setw(30) << std::left
              << "Sport Name "
              << " " << getName()
              << "\n\t\t" << std::setw(30) << "Scheduled Date (M/D/YY) "
              << " ";

    d1.displayDate();

    std::cout << "\n\n\t\t" << std::setfill('.') << std::setw(30) << std::left
              << "Number of Teams "
              << " " << getNumTeams() << std::endl;

    for (int i = 0; i < getNumTeams(); ++i)
        std::cout << "\t\tTeam " << i + 1 << std::setw(24) << " "
                  << " " << teamNames[i] << std::endl;
}

//*****************************************************************************************************

void Sport::populate() {
    char entry;

    std::cout << "\nEnter the name of the sport: ";
    std::getline(std::cin, name);

    setName(name);

    std::cout << "Sport has a scheduled game? (Y/N)" << std::endl;
    std::cin >> entry;

    if (entry == 'Y' || entry == 'y') {
        std::cout << "\nNext Scheduled Game";
        nextGame.inputDate();
        setDate(nextGame);
    } else {
        std::cout << "\nDefault date will be set to January 1, 2000" << std::endl;
    }

    std::cout << "\nEnter the number of teams: ";
    std::cin >> numTeams;

    setNumTeams(numTeams);
    teamNames = new std::string[numTeams];

    std::cin.ignore();

    for (int i = 0; i < numTeams; ++i) {
        std::cout << "Enter the name of team " << i + 1 << ": ";
        std::getline(std::cin, teamNames[i]);
    }
}

//*****************************************************************************************************

void Sport::addTeam(const std::string &n) {
    std::string *temp = new std::string[numTeams + 1];

    for (int i = 0; i < numTeams; ++i)
        temp[i] = teamNames[i];

    temp[numTeams] = n;
    delete[] teamNames;
    teamNames = temp;
    numTeams++;
}

//*****************************************************************************************************
/*

numTeams++;
string* tempTNames = new string[numTeams];

for (int i = 0; i < numTeams - 1; i++) 
    tempTNames[i] = teamNames[i];

tempTNames[numTeams - 1] = n;
teamNames = new string[numTeams];
teamNames = tempTNames;

*/