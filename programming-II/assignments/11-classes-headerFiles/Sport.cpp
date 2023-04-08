//*****************************************************************************************************
//      Sport Class Implementation File
//
//		This class implementation file defines the methods (member functions) of the Sport class.
//
//      Other files required:
//		  1.	 Sport.h - header file for Sport class
//
//*****************************************************************************************************

#include <iomanip>
#include <iostream>
using namespace std;

#include "Sport.h"     // include Sport.h to use Sport class

//*****************************************************************************************************

Sport::Sport(const string &n) {     // default constructor sets name to empty string, number of teams to 0, and teamNames to nullptr
    setName(n);                     // set name to n (default is empty string and is set in the header file)
    numTeams = 0;
    teamNames = nullptr;
}

//*****************************************************************************************************

Sport::~Sport() {
    delete[] teamNames;     // dynamically allocated memory must be added to the destructor to prevent memory leaks
    // cout << "\nDestructor called" << endl;
}

//*****************************************************************************************************

void Sport::display() const {
    Date d1 = getDate();     // create a Date object to use the displayDate function

    cout << "\t\t" << setfill('.') << setw(30) << left << "Sport Name "
         << " " << getName() << endl;
    cout << "\t\t" << setfill('.') << setw(30) << left << "Scheduled Date (M/D/YY) "
         << " ";

    d1.displayDate();

    cout << "\n\n\t\t" << setfill('.') << setw(30) << left << "Number of Teams "
         << " " << getNumTeams() << endl;

    for (int i = 0; i < getNumTeams(); ++i)
        cout << "\t\tTeam " << i + 1 << setfill('.') << setw(24) << left
             << " "
             << " " << teamNames[i] << endl;
}

//*****************************************************************************************************

void Sport::populate() {
    char entry;

    cout << "\nEnter the name of the sport: ";
    getline(cin, name);     // get the name of the sport and store it in the name variable

    setName(name);     // set the name variable to the name of the sport

    cout << "Sport has a scheduled game? (Y/N)" << endl;
    cin >> entry;

    if (entry == 'Y' || entry == 'y') {
        cout << "\nNext Scheduled Game";
        nextGame.inputDate();
        setDate(nextGame);
    } else {
        cout << "\nDefault date will be set to January 1, 2000" << endl;
    }
    cout << "\nEnter the number of teams: ";
    cin >> numTeams;

    setNumTeams(numTeams);                // set the number of teams to the number of teams entered by the user
    teamNames = new string[numTeams];     // dynamically allocate memory for the teamNames array

    cin.ignore();

    for (int i = 0; i < numTeams; ++i) {
        cout << "Enter the name of team " << i + 1 << ": ";
        getline(cin, teamNames[i]);     // get the name of the team and store it in the teamNames array
    }
}

//*****************************************************************************************************

void Sport::addTeam(const string &n) {
    string *temp = new string[numTeams + 1];     // numTeams + 1 because we are adding a team

    for (int i = 0; i < numTeams; ++i)     // copy the team names from the teamNames array to the temp array
        temp[i] = teamNames[i];
    temp[numTeams] = n;     // add the new team name to the end of the temp array
    delete[] teamNames;     // delete the teamNames array
    teamNames = temp;       // set the teamNames array to the temp array
    numTeams++;             // increment the number of teams
}

//*****************************************************************************************************

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