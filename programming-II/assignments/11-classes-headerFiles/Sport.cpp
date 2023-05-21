//*****************************************************************************************************
//      Sport Class Implementation File
//
//      This class implementation file defines the methods (member functions) of the Sport class.
//
//      Other files required:
//          1.  Sport.h - header file for Sport class
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
    delete[] teamNames;     // destructors need to explicitly delete any dynamically allocated memory
    //cout << "\nSport object destroyed\n";
}

//*****************************************************************************************************

void Sport::display() const {
    Date d1 = getDate();     // getDate() returns a Date object (nextGame) which is assigned to d1

    cout << "\t\t" << setfill('.') << setw(30) << left 
         << "Sport Name " << " " << getName() 
         << "\n\t\t" << setw(30) << "Scheduled Date (M/D/YY) " << " ";

    d1.displayDate();      

    cout << "\n\n\t\t" << setfill('.') << setw(30) << left 
         << "Number of Teams " << " " << getNumTeams() << endl;

    for (int i = 0; i < getNumTeams(); ++i)
        cout << "\t\tTeam " << i + 1 << setw(24) << " " << " " << teamNames[i] << endl;
}

//*****************************************************************************************************

void Sport::populate() {
    char entry;

    cout << "\nEnter the name of the sport: ";
    getline(cin, name);     

    setName(name);     

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

    setNumTeams(numTeams);               
    teamNames = new string[numTeams];     

    cin.ignore();

    for (int i = 0; i < numTeams; ++i) {
        cout << "Enter the name of team " << i + 1 << ": ";
        getline(cin, teamNames[i]);     
    }
}

//*****************************************************************************************************

void Sport::addTeam(const string &n) {
    string *temp = new string[numTeams + 1];     

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