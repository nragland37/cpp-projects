//*****************************************************************************************************
//      Sports Information Management  
//
//      This program is a sport information system that implements Object Oriented Programming (OOP) 
//      concepts that allows the user to add, display, and compare different sports based on their 
//      name, date, and team information.
//
//      Other files required:
//          1.  Date.cpp - implementation file for Date class (includes Date.h)
//          2.  Sport.cpp - implementation file for Sport class (includes Sport.h)
//
//*****************************************************************************************************

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#include "Date.h"      // change to "Date.cpp" in visual studio code
#include "Sport.h"     // change to "Sport.cpp" in visual studio code

//*****************************************************************************************************

void displaySports(Sport s[], int size);
bool testName(Sport s[], int size, const string &sportName);

//*****************************************************************************************************

int main() {
    int size;
    char ch,
        entry;
    Sport *s = nullptr;

    cout << "=====================================================================\n"
         << setw(44) << "Sport Information\n"
         << "=====================================================================" << endl;

    cout << "\nHow many Sports need to be processed: ";
    cin >> size;

    s = new Sport[size];

    cin.ignore();     // ignore the newline character in the buffer to prevent skipping getline() in populate function

    for (int i = 0; i < size; ++i)
        s[i].populate();     // populate function prompts user to enter Sport Name, Date, Number of Teams, and Team Names

    do {
        cout << "\n---------------------------------------------------------------------\n"
             << "a) Display all Sports\n"
             << "b) Add a team to an existing Sport\n"
             << "c) Display a particular Sport\n"
             << "d) Display the Sport that has the highest number of teams playing\n"
             << "e) Exit" << endl;

        cout << "Enter Your Choice: ";
        cin >> ch;

        cin.ignore();     // ignore newline character in buffer to prevent skipping getline() in switch statement
        
        switch (ch) {
            case 'a': {
                displaySports(s, size);
                break;
            }
            case 'b': {
                string team,
                    sportAdd;
                bool addTest;     // addTest is used to test if Sport Name exists

                do {
                    cout << "\nEnter Sport Name to add Team: ";
                    getline(cin, sportAdd);

                    addTest = testName(s, size, sportAdd);     // testName function tests if Sport Name exists

                    if (addTest == true) {
                        cout << "\nEnter Team Name: ";
                        getline(cin, team);

                        for (int i = 0; i < size; ++i)
                            if (sportAdd == s[i].getName())
                                s[i].addTeam(team);
                    } else {
                        cerr << "\n\tInvalid Name\n";     // cerr is unbuffered and best for error handling
                        cout << "\nBack to menu? (Y/N)" << endl;
                        cin >> entry;

                        if (entry == 'Y' || entry == 'y')
                            break;
                        else
                            cin.ignore();
                    }
                } while (addTest == false);
                break;     // break out of switch statement if Sport Name exists and Team Name is added
            }
            case 'c': {
                string s1;
                bool s1Test;

                do {
                    cout << "\nEnter Sport Name to Display: ";
                    getline(cin, s1);

                    s1Test = testName(s, size, s1);

                    if (s1Test == true) {
                        for (int i = 0; i < size; ++i) {
                            if (s1 == s[i].getName()) {
                                cout << "\n\tSport " << i + 1 << endl;
                                s[i].display();
                            }
                        }
                    } else {
                        cerr << "\n\tInvalid Name\n";
                        cout << "\nBack to menu? (Y/N)" << endl;
                        cin >> entry;

                        if (entry == 'Y' || entry == 'y')
                            break;
                        else
                            cin.ignore();
                    }
                } while (s1Test == false);
                break;     // break out of switch statement if Sport Name exists
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

                for (int i = 0; i < size; ++i) {     // test if multiple sports have the same number of teams
                    if (s[max].getNumTeams() == s[i].getNumTeams()) {
                        cout << "\n\tSport " << i + 1 << endl;
                        s[i].display();
                    }
                }
                break;     // break out of switch statement if multiple sports have the same number of teams
            }
            case 'e': {
                break;
            }
            default: {
                cerr << "\n\tError: Invalid Entry\n";
            }
        }
    } while (ch != 'e');     // break out of do-while loop if user enters 'e' to exit program

    delete[] s;
    s = nullptr;

    return 0;
}

//*****************************************************************************************************

void displaySports(Sport s[], int size) {
    cout << "\n---------------------------------------------------------------------\n";

    for (int i = 0; i < size; ++i) {
        cout << "\n\tSport " << i + 1 << endl;
        s[i].display();
    }
}

//*****************************************************************************************************

bool testName(Sport s[], int size, const string &sportName) {
    bool nameFound = false;

    for (int i = 0; i < size; ++i) {
        if (sportName == s[i].getName()) {
            nameFound = true;
            break;
        }
    }

    return nameFound;
}

//*****************************************************************************************************

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
Enter the name of team 2: Cubs

Enter the name of the sport: Hockey
Sport has a scheduled game? (Y/N)
Y
Next Scheduled Game
Enter Year: 1901

Invalid

Enter Year(2022- ): 2024                                                      Leap Year
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

---------------------------------------------------------------------       Display all Sports

        Sport 1
                Sport Name ................... Baseball
                Scheduled Date (M/D/YY) ...... 7/8/2022

                Number of Teams .............. 2
                Team 1 ....................... Cardinals
                Team 2 ....................... Cubs

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

---------------------------------------------------------------------       Display highest number
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

---------------------------------------------------------------------       Display particular Sport
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
                Team 2 ....................... Cubs

---------------------------------------------------------------------       Display particular Sport
a) Display all Sports                                                       Invalid Name / back to menu (N)
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: c

Enter Sport Name to Display: Soccer

        Invalid Name

Back to menu? (Y/N)
N

Enter Sport Name to Display: Football

        Sport 3
                Sport Name ................... Football
                Scheduled Date (M/D/YY) ...... 1/1/2000

                Number of Teams .............. 2
                Team 1 ....................... Rams
                Team 2 ....................... Patriots

---------------------------------------------------------------------       Display particular Sport
a) Display all Sports                                                       Invalid Name / back to menu (Y)
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: c

Enter Sport Name to Display: Soccer

        Invalid Name

Back to menu? (Y/N)
Y

---------------------------------------------------------------------       Add team
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

---------------------------------------------------------------------      Display all Sports

        Sport 1
                Sport Name ................... Baseball
                Scheduled Date (M/D/YY) ...... 7/8/2022

                Number of Teams .............. 3
                Team 1 ....................... Cardinals
                Team 2 ....................... Cubs
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

---------------------------------------------------------------------       Display multiple highest numbers
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
                Team 2 ....................... Cubs
                Team 3 ....................... Yankees

        Sport 2
                Sport Name ................... Hockey
                Scheduled Date (M/D/YY) ...... 2/29/2024

                Number of Teams .............. 3
                Team 1 ....................... Blues
                Team 2 ....................... Penguins
                Team 3 ....................... Red Wings

---------------------------------------------------------------------      Invalid Choice
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: w

        Invalid Choice

---------------------------------------------------------------------       Add team
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: b

Enter Sport Name to add Team: Hockey

Enter Team Name: Stars

---------------------------------------------------------------------       Display highest number
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

---------------------------------------------------------------------       Add team
a) Display all Sports                                                       Invalid Name / back to menu (Y)
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: b

Enter Sport Name to add Team: Soccer

        Invalid Name

Back to menu? (Y/N)
Y

---------------------------------------------------------------------     Add Team
a) Display all Sports                                                     Invalid Name / back to menu (N)
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: b

Enter Sport Name to add Team: Soccer

        Invalid Name

Back to menu? (Y/N)
N

Enter Sport Name to add Team: Baseball

Enter Team Name: Red Sox

---------------------------------------------------------------------        Display all Sports
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: a

---------------------------------------------------------------------

        Sport 1
                Sport Name ................... Baseball
                Scheduled Date (M/D/YY) ...... 7/8/2022

                Number of Teams .............. 4
                Team 1 ....................... Cardinals
                Team 2 ....................... Cubs
                Team 3 ....................... Yankees
                Team 4 ....................... Red Sox

        Sport 2
                Sport Name ................... Hockey
                Scheduled Date (M/D/YY) ...... 2/29/2024

                Number of Teams .............. 4
                Team 1 ....................... Blues
                Team 2 ....................... Penguins
                Team 3 ....................... Red Wings
                Team 4 ....................... Stars

        Sport 3
                Sport Name ................... Football
                Scheduled Date (M/D/YY) ...... 1/1/2000

                Number of Teams .............. 2
                Team 1 ....................... Rams
                Team 2 ....................... Patriots

---------------------------------------------------------------------       Display multiple highest numbers
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: d

        Sport 1
                Sport Name ................... Baseball
                Scheduled Date (M/D/YY) ...... 7/8/2022

                Number of Teams .............. 4
                Team 1 ....................... Cardinals
                Team 2 ....................... Cubs
                Team 3 ....................... Yankees
                Team 4 ....................... Red Sox

        Sport 2
                Sport Name ................... Hockey
                Scheduled Date (M/D/YY) ...... 2/29/2024

                Number of Teams .............. 4
                Team 1 ....................... Blues
                Team 2 ....................... Penguins
                Team 3 ....................... Red Wings
                Team 4 ....................... Stars

---------------------------------------------------------------------       Exit
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: e


*****************************************************************************************************


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

Destructor called                                                            Destructor test

        Sport 2
                Sport Name ................... test
                Scheduled Date (M/D/YY) ...... 1/1/2000

                Number of Teams .............. 2
                Team 1 ....................... test
                Team 2 ....................... test

Destructor called                                                           Destructor test

---------------------------------------------------------------------
a) Display all Sports
b) Add a team to an existing Sport
c) Display a particular Sport
d) Display the Sport that has the highest number of teams playing
e) Exit
Enter Your Choice: e

Destructor called                                                           Destructor test

Destructor called

Destructor called

Destructor called

*/