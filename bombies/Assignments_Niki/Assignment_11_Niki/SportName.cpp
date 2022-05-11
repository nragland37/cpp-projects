//****************************************************************************************************
// 		    File:                 assignment11.cpp
//
//		    Student:              Niki Portell
//
//		    Assignment:           Program #11
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  May 6, 2022
//
//          Description:          A program that manages information about a sport.
//
//****************************************************************************************************
#include <iostream>

#include "Sport.cpp"

using namespace std;

int main() {
    int numSports;
    Sport* sports = nullptr;
    string teamName;
    string addToSport;
    string newTeam;
    string userChoice;
    string mostTeams;
    string* teams = nullptr;
    int i = 0;
    int highest;

    cout << "How many sports need to be processed? ";
    cin >> numSports;
    cin.ignore();
    sports = new Sport[numSports];

    for (int i = 0; i < numSports; i++) {
        sports[i].populate();
    }

    for (int i = 0; i < numSports; i++) {
        sports[i].display();
    }

    cout << endl;
    cout << "For which sport would you like to enter a new team? ";
    getline(cin, addToSport);

    for (int i = 0; i < numSports; i++) {
        if (sports[i].getName() == addToSport) {
            cout << "Enter the team's name: ";
            getline(cin, newTeam);
            sports[i].addTeam(newTeam);
            break;
        }
    }

    cout << endl;
    cout << "Which sport would you like to display?: " << endl;
    getline(cin, userChoice);
    cout << endl;

    for (int i = 0; i < numSports; i++) {
        if (sports[i].getName() == userChoice) {
            sports[i].display();
            break;
        }
    }

    cout << "The sport with the highest number of teams: ";
    highest = sports[0].getNumTeams();

    for (int i = 1; i < numSports; i++) {
        if (sports[i].getNumTeams() > highest) {
            highest = sports[i].getNumTeams();
        }
        cout << sports[i].getName() << endl;
    }

    delete[] sports;

    return 0;
}