#include "Sport.h"

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void Sport::display() const {
    cout << fixed << left << "Sport: " << name << endl;
    cout << "Date of the next game: " << nextGame.month << "/" << nextGame.day << "/" << nextGame.year << endl;
    cout << "Teams:" << endl;
    cout << "*********" << endl;
    for (int i = 0; i < numTeams; i++) {
        cout << teamNames[i] << endl;
    }
    cout << endl;
}

//****************************************************************************************************

void Sport::populate() {
    string name;
    Date nextGame;
    int currentYear = 2022;

    cout << "Enter Sport: " << endl;
    getline(cin, name);
    setName(name);
    cout << endl;

    cout << "Enter date of next game: " << endl;
    cout << "Enter month: (1-12)";
    cin >> nextGame.month;
    cout << "Enter day: (1-31)";
    cin >> nextGame.day;
    cout << "Enter year: ";
    cin >> nextGame.year;
    if (nextGame.month < 1 || nextGame.month > 12 || nextGame.day < 1 ||
        nextGame.day > 31 || nextGame.year < currentYear) {
        nextGame.month = 1;
        nextGame.day = 1;
        nextGame.year = 2000;
    }
    setDate(nextGame);
    cout << endl;

    cout << "Enter the number of teams: ";
    cin >> numTeams;
    cin.ignore();
    getNumTeams();
    teamNames = new string[numTeams];
    for (int i = 0; i < numTeams; i++) {
        cout << "Enter the team name: ";
        cin >> teamNames[i];
    }
    cin.ignore();
    cout << endl;
}

//****************************************************************************************************

void Sport::addTeam(const string& n) {
    numTeams++;
    string* tempTNames = new string[numTeams];
    for (int i = 0; i < numTeams - 1; i++) {
        tempTNames[i] = teamNames[i];
    }
    tempTNames[numTeams - 1] = n;
    teamNames = new string[numTeams];
    teamNames = tempTNames;
}

//****************************************************************************************************

Sport::Sport(const string& n) {
    setName(n);
    nextGame.month = 1;
    nextGame.day = 1;
    nextGame.year = 2000;
    numTeams = 0;
    teamNames = nullptr;
}

//****************************************************************************************************

Sport::~Sport() {
    delete[] teamNames;
    cout << "**Delete Team Names**";
}

//****************************************************************************************************