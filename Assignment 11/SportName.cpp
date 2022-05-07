//****************************************************************************************************
// 		    File:                 SportName.cpp
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

#include <iomanip>
#include <iostream>
#include <string>

#include "Date.cpp"
#include "Sport.cpp"

using namespace std;

//****************************************************************************************************

void displaySports(Sport s[], int size);

//****************************************************************************************************

int main() {
    int size;
    char ch;

    cout << "=====================================================================\n"
         << setw(44) << "Sport Information\n"
         << "=====================================================================" << endl;

    cout << "\nHow many Sports need to be processed: ";
    cin >> size;
    Sport* s = new Sport[size];
    for (int i = 0; i < size; ++i) {
        s[i].populate();
    }

    do {
        cout << "\n---------------------------------------------------------------------\n";
        cout << "a) Display all Sports\n"
             << "b) Add a team to an existing Sport\n"
             << "c) Display a particular Sport\n"
             << "d) Display the Sport that has the highest number of teams playing\n"
             << "e) Exit\n"
             << "Enter Your Choice: ";
        cin >> ch;
        cin.ignore();
        switch (ch) {
            case 'a': {
                displaySports(s, size);
                break;
            }
            case 'b': {
                string team,
                    sportAdd;
                cout << "\nEnter Sport Name to add Team: ";
                getline(cin, sportAdd);
                cout << "\nEnter Team Name: ";
                getline(cin, team);
                for (int i = 0; i < size; ++i) {
                    if (sportAdd == s[i].getName())
                        s[i].addTeam(team);
                }
                break;
            }
            case 'c': {
                string s1;
                cout << "\nEnter Sport Name to Display: ";
                getline(cin, s1);
                for (int i = 0; i < size; ++i) {
                    if (s1 == s[i].getName()) {
                        cout << "\n\tSport " << i + 1 << endl;
                        s[i].display();
                        break;
                    }
                }
                break;
            }
            case 'd': {
                int temp = s[0].getNumTeams();
                int max = 0;
                for (int i = 1; i < size; ++i) {
                    if (temp < s[i].getNumTeams()) {
                        temp = s[i].getNumTeams();
                        max = i;
                    }
                }
                for (int i = 0; i < size; ++i) {  // in case of multiple highest numbers
                    if (s[max].getNumTeams() == s[i].getNumTeams()) {
                        cout << "\n\tSport " << i + 1 << endl;
                        s[i].display();
                    }
                }
                break;
            }
        }
    } while (ch != 'e');
    delete[] s;
    return 0;
}

//****************************************************************************************************

void displaySports(Sport s[], int size) {
    cout << "\n---------------------------------------------------------------------\n";
    for (int i = 0; i < size; ++i) {
        cout << "\n\tSport " << i + 1 << endl;
        s[i].display();
    }
}

/*

=====================================================================
                          Sport Information
=====================================================================

How many Sports need to be processed: 3
Enter the name of the sport: Baseball
Sport has a scheduled game? (Y/N)
Y
Next Scheduled Game
Enter Year: 2022
Enter Month: 7
Enter Day: 8
Enter the number of teams: 2
Enter the name of team 1: Cardinals
Enter the name of team 2: Cub

Enter the name of the sport: Hockey
Sport has a scheduled game? (Y/N)
Y
Next Scheduled Game
Enter Year: 1901

 Invalid
Enter Year(2022- ): 2024              // Leap Year

Enter Month: 15

 Invalid
Enter Month(1-12): 2

Enter Day: -13

 Invalid
Enter Day(1-29): 29

Enter the number of teams: 3
Enter the name of team 1: Blues
Enter the name of team 2: Penguins
Enter the name of team 3: Red Wings

Enter the name of the sport: Football
Sport has a scheduled game? (Y/N)
N

Default date will be set to January 1, 2000.

Enter the number of teams: 2
Enter the name of team 1: Rams
Enter the name of team 2: Patriots

---------------------------------------------------------------------
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: a

---------------------------------------------------------------------      // Display all Sports

        Sport 1
                Sport Name ................... Baseball
                Scheduled Date (M/D/YY) ...... 7/8/2022

                Number of Teams .............. 2
                Team 1 ....................... Cardinals
                Team 2 ....................... Cub

        Sport 2
                Sport Name ................... Hockey
                Scheduled Date (M/D/YY) ...... 2/29/2024

                Number of Teams .............. 3
                Team 1 ....................... Blues
                Team 2 ....................... Penguins
                Team 3 ....................... Red Wings

        Sport 3
                Sport Name ................... Football
                Scheduled Date (M/D/YY) ...... 1/1/2000

                Number of Teams .............. 2
                Team 1 ....................... Rams
                Team 2 ....................... Patriots

---------------------------------------------------------------------      // Display highest number
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: d

        Sport 2
                Sport Name ................... Hockey
                Scheduled Date (M/D/YY) ...... 2/29/2024

                Number of Teams .............. 3
                Team 1 ....................... Blues
                Team 2 ....................... Penguins
                Team 3 ....................... Red Wings

---------------------------------------------------------------------      // Display particular Sport
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: c

Enter Sport Name to Display: Baseball

        Sport 1
                Sport Name ................... Baseball
                Scheduled Date (M/D/YY) ...... 7/8/2022

                Number of Teams .............. 2
                Team 1 ....................... Cardinals
                Team 2 ....................... Cub

---------------------------------------------------------------------      // Add team
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: b

Enter Sport Name to add Team: Baseball

Enter Team Name: Yankees

---------------------------------------------------------------------
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: a

---------------------------------------------------------------------     // Display all Sports

        Sport 1
                Sport Name ................... Baseball
                Scheduled Date (M/D/YY) ...... 7/8/2022

                Number of Teams .............. 3
                Team 1 ....................... Cardinals
                Team 2 ....................... Cub
                Team 3 ....................... Yankees

        Sport 2
                Sport Name ................... Hockey
                Scheduled Date (M/D/YY) ...... 2/29/2024

                Number of Teams .............. 3
                Team 1 ....................... Blues
                Team 2 ....................... Penguins
                Team 3 ....................... Red Wings

        Sport 3
                Sport Name ................... Football
                Scheduled Date (M/D/YY) ...... 1/1/2000

                Number of Teams .............. 2
                Team 1 ....................... Rams
                Team 2 ....................... Patriots

---------------------------------------------------------------------      // Display multiple highest numbers
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: d

        Sport 1
                Sport Name ................... Baseball
                Scheduled Date (M/D/YY) ...... 7/8/2022

                Number of Teams .............. 3
                Team 1 ....................... Cardinals
                Team 2 ....................... Cub
                Team 3 ....................... Yankees

        Sport 2
                Sport Name ................... Hockey
                Scheduled Date (M/D/YY) ...... 2/29/2024

                Number of Teams .............. 3
                Team 1 ....................... Blues
                Team 2 ....................... Penguins
                Team 3 ....................... Red Wings

---------------------------------------------------------------------      // Invalid Choice
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: w

        Invalid Choice

---------------------------------------------------------------------      // Add team
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: b

Enter Sport Name to add Team: Hockey

Enter Team Name: Stars

---------------------------------------------------------------------      // Display highest number
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: d

        Sport 2
                Sport Name ................... Hockey
                Scheduled Date (M/D/YY) ...... 2/29/2024

                Number of Teams .............. 4
                Team 1 ....................... Blues
                Team 2 ....................... Penguins
                Team 3 ....................... Red Wings
                Team 4 ....................... Stars

---------------------------------------------------------------------      // Exit
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: e


//****************************************************************************************************


=====================================================================
                          Sport Information
=====================================================================

How many Sports need to be processed: 2
Enter the name of the sport: test
Sport has a scheduled game? (Y/N)
n

Default date will be set to January 1, 2000.

Enter the number of teams: 2
Enter the name of team 1: test
Enter the name of team 2: test

Enter the name of the sport: test
Sport has a scheduled game? (Y/N)
n

Default date will be set to January 1, 2000.

Enter the number of teams: 2
Enter the name of team 1: test
Enter the name of team 2: test

---------------------------------------------------------------------
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: a

---------------------------------------------------------------------

        Sport 1
                Sport Name ................... test
                Scheduled Date (M/D/YY) ...... 1/1/2000

                Number of Teams .............. 2
                Team 1 ....................... test
                Team 2 ....................... test

Destructor called                                                           // Destructor test

        Sport 2
                Sport Name ................... test
                Scheduled Date (M/D/YY) ...... 1/1/2000

                Number of Teams .............. 2
                Team 1 ....................... test
                Team 2 ....................... test

Destructor called                                                          // Destructor test

---------------------------------------------------------------------
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: e

Destructor called                                                          // Destructor test

Destructor called

Destructor called

Destructor called

*/