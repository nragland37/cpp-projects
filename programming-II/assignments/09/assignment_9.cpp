//****************************************************************************************************
// 		    File:                 assignment_9.cpp
//
//		    Student:              Nicholas Ragland
//
//		    Assignment:           Program #9
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  April 18, 2022
//
//****************************************************************************************************

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//****************************************************************************************************
const int NAME_SIZE = 20;
struct Translation {
    string american;
    string english;
};
struct Date {
    int month;
    int day;
    int year;
};
struct Person {
    char name[NAME_SIZE];
    double score;
    Date testTaken;
};

Translation* readTranslation(const string& fileName, int& num);
Person* readTesters(const string& fileName, int& num);
void testingOptions(const Translation translate[], int numT, Person people[], int numP);
void takeTest(const Translation translate[], int numT, Person& p);
void displayTesters(const Person people[], int numP);
void writeTesters(const string& fileName, const Person people[], int numP);
void displayTranslateAnswers(const Translation translate[], int numT);

//****************************************************************************************************

int main() {
    int numT = 0,
        numP = 0;
    string fileName;
    char studyEntry;
    Translation* translate = nullptr;
    Person* people = nullptr;

    cout << fixed << setprecision(1);

    translate = readTranslation("Translation.txt", numT);
    people = readTesters("Testers.txt", numP);
    displayTesters(people, numP);
    cout << "\n---------------------------------------------------" << endl;
    cout << "\tAmerican to English Translation Test" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "   Three people from this list will be randomly" << endl;
    cout << "            selected to take the test." << endl;
    cout << "\nWould you like to study before the test? (Y/N)" << endl;  // prompts user to study before test
    cin >> studyEntry;
    if (studyEntry == 'y' || studyEntry == 'Y') {
        displayTranslateAnswers(translate, numT);
        cout << "\nPress enter to continue..." << endl;
        cin.ignore();
        cin.get();
        cout << "Good Luck!" << endl;
    } else {
        cout << "\nGood Luck!" << endl;
    }
    testingOptions(translate, numT, people, numP);
    cout << "===================================================" << endl;
    cout << "\t\tUpdated Information" << endl;
    cout << "===================================================";
    displayTesters(people, numP);
    writeTesters("Testers.txt", people, numP);

    delete[] translate;
    translate = nullptr;
    delete[] people;
    people = nullptr;

    return 0;
}

//****************************************************************************************************

Translation* readTranslation(const string& fileName, int& num) {
    Translation* t = nullptr;
    ifstream f(fileName);
    if (f.is_open()) {
        f >> num;
        f.ignore();
        t = new Translation[num];
        for (int i = 0; i < num; ++i) {
            getline(f, t[i].american, ',');
            getline(f, t[i].english);
        }
        f.close();
    } else {
        cout << "File not found.";
    }
    return t;
}

//****************************************************************************************************

Person* readTesters(const string& fileName, int& num) {
    Person* p = nullptr;
    ifstream f(fileName);
    if (f.is_open()) {
        f >> num;
        f.ignore();
        p = new Person[num];
        for (int i = 0; i < num; ++i) {
            f.getline(p[i].name, NAME_SIZE);
            f >> p[i].score;
            f.ignore();
            f >> p[i].testTaken.month;
            f.ignore();
            f >> p[i].testTaken.day;
            f.ignore();
            f >> p[i].testTaken.year;
            f.ignore();
        }
        f.close();
    } else {
        cout << "File not found.";
    }
    return p;
}

//****************************************************************************************************

void testingOptions(const Translation translate[], int numT, Person people[], int numP) {
    const int numTests = 3;  // # of random tests ~ same people can be tested more than once
    int randomPerson = 0,
        month,
        day,
        year;
    short seed;
    seed = time(0);
    srand(seed);

    cout << "\n---------------------------------" << endl;
    cout << "        Enter Today's Date" << endl;
    cout << "---------------------------------" << endl;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter year: ";
    cin >> year;
    cout << "\n\n---------------------------------" << endl;
    cout << "            Questions" << endl;
    cout << "---------------------------------" << endl;
    cout << "   Five American words will be" << endl;
    cout << " randomly selected from the list." << endl;
    cout << "  Enter the English translation." << endl;
    for (int i = 0; i < numTests; ++i) {
        randomPerson = rand() % numP;  // (numP: 10) range: 0 - 9  // 0 - (numP - 1)
        people[randomPerson].testTaken.month = month;
        people[randomPerson].testTaken.day = day;
        people[randomPerson].testTaken.year = year;
        cout << "\n=================================" << endl;
        cout << setfill(' ') << setw(3) << left << "#"
             << setw(20) << left << "NAME"
             << "TEST TAKEN" << endl;
        cout << "---------------------------------" << endl;
        cout << setw(3) << left << randomPerson + 1
             << setw(20) << left << people[randomPerson].name
             << people[randomPerson].testTaken.month << "/"
             << people[randomPerson].testTaken.day << "/"
             << people[randomPerson].testTaken.year << endl;
        takeTest(translate, numT, people[randomPerson]);
    }
}

//****************************************************************************************************

void takeTest(const Translation translate[], int numT, Person& p) {
    const int numQuestions = 5;  // # of questions ~ changing number of questions may result in 'double' avg
    int randomQuestion = 0,
        correct = 0;
    double avg = 0;
    string answer,
        guess;
    short seed;
    seed = time(0);
    srand(seed);

    cout << "\n---------------------------------" << endl;
    cout << setfill(' ') << setw(3) << left << "#"
         << setw(18) << left << "American"
         << "English" << endl;
    cout << "---------------------------------" << endl;
    for (int i = 0; i < numQuestions; ++i) {
        randomQuestion = rand() % numT;  // (numT: 20) range: 0 - 19  // 0 - (numT - 1)
        cout << setfill(' ') << setw(3) << left << randomQuestion + 1
             << setfill('.') << setw(18) << left << translate[randomQuestion].american;
        cin >> guess;
        answer = translate[randomQuestion].english;
        if (guess == answer) {
            cout << "\n\t    Correct!" << endl
                 << endl;
            correct++;
        } else {
            cout << "\n\t   Incorrect!" << endl;
            cout << "\nAnswer: " << translate[randomQuestion].english << endl
                 << endl;
        }
    }
    avg = (static_cast<double>(correct) / numQuestions) * 100;
    p.score = avg;
}

//****************************************************************************************************

void displayTesters(const Person people[], int numP) {
    cout << "\n---------------------------------------------------" << endl;
    cout << setfill(' ') << setw(3) << left << "#"
         << setw(20) << left << "NAME"
         << setw(15) << left << "SCORE %"
         << "TEST TAKEN" << endl;
    cout << "---------------------------------------------------" << endl;
    for (int i = 0; i < numP; ++i) {
        cout << setw(3) << left << i + 1
             << setw(20) << left << people[i].name
             << setw(15) << left << people[i].score
             << people[i].testTaken.month << "/"
             << people[i].testTaken.day << "/"
             << people[i].testTaken.year << endl;
    }
}

//****************************************************************************************************

void writeTesters(const string& fileName, const Person people[], int numP) {
    ofstream f(fileName);
    f << numP << endl;
    for (int i = 0; i < numP; ++i) {
        f << people[i].name << "\n"
          << people[i].score << ","
          << people[i].testTaken.month << "/" << people[i].testTaken.day
          << "/" << people[i].testTaken.year << endl;
    }
    f.close();
}

//****************************************************************************************************

void displayTranslateAnswers(const Translation translate[], int numT) {
    cout << "\n---------------------------------" << endl;
    cout << setw(3) << left << "#"
         << setw(18) << left << "American"
         << "English" << endl;
    cout << "---------------------------------" << endl;
    for (int i = 0; i < numT; ++i) {
        cout << setfill(' ') << setw(3) << left << i + 1
             << setfill('.') << setw(18) << left << translate[i].american
             << translate[i].english << endl;
    }
}

// comments made throughout sample output ~

/*

---------------------------------------------------
#  NAME                SCORE %        TEST TAKEN
---------------------------------------------------
1  Steve Smith         56.6           11/11/2019
2  Sue Jones           10.0           11/11/2011
3  Li Ying             0.0            11/11/2011
4  Kun Joom            20.0           11/11/2021
5  Joe Bush            10.0           11/11/2021
6  Kim Long            0.0            11/11/2011
7  Fred Ring           33.3           5/5/2019
8  Frank Pearse        20.0           11/11/2011
9  Helen Hu            0.1            11/11/2011
10 Mark James          0.0            11/11/2021

---------------------------------------------------
        American to English Translation Test
---------------------------------------------------
   Three people from this list will be randomly
            selected to take the test.

Would you like to study before the test? (Y/N)         //output for not studying
N

Good Luck!

//****************************************************************************************************

---------------------------------------------------
#  NAME                SCORE %        TEST TAKEN
---------------------------------------------------
1  Steve Smith         56.6           11/11/2019
2  Sue Jones           10.0           11/11/2011
3  Li Ying             0.0            11/11/2011
4  Kun Joom            20.0           11/11/2021
5  Joe Bush            10.0           11/11/2021
6  Kim Long            0.0            11/11/2011
7  Fred Ring           33.3           5/5/2019
8  Frank Pearse        20.0           11/11/2011
9  Helen Hu            0.1            11/11/2011
10 Mark James          0.0            11/11/2021

---------------------------------------------------
        American to English Translation Test
---------------------------------------------------
   Three people from this list will be randomly
            selected to take the test.

Would you like to study before the test? (Y/N)     // output for studying
Y

---------------------------------
#  American          English
---------------------------------
1  chips.............crisps
2  french fries......chips
3  sidewalk..........pavement
4  cookie............biscuit
5  apartment.........flat
6  elevator..........lift
7  gas...............petrol
8  soccer............football
9  movie.............film
10 sweater...........jumper
11 trunk.............boot
12 hood..............bonnet
13 last name.........surname
14 restroom..........toilet
15 cart..............trolley
16 candy.............sweet
17 vacation..........holiday
18 subway............underground
19 pants.............trousers
20 mailbox...........postbox

Press enter to continue...                      // program pauses until user is ready and presses enter

//****************************************************************************************************

---------------------------------------------------
#  NAME                SCORE %        TEST TAKEN
---------------------------------------------------
1  Steve Smith         56.6           11/11/2019
2  Sue Jones           10.0           11/11/2011
3  Li Ying             0.0            11/11/2011
4  Kun Joom            20.0           11/11/2021
5  Joe Bush            10.0           11/11/2021
6  Kim Long            0.0            11/11/2011
7  Fred Ring           33.3           5/5/2019
8  Frank Pearse        20.0           11/11/2011
9  Helen Hu            0.1            11/11/2011
10 Mark James          0.0            11/11/2021

---------------------------------------------------
        American to English Translation Test
---------------------------------------------------
   Three people from this list will be randomly
            selected to take the test.

Would you like to study before the test? (Y/N)
Y

---------------------------------
#  American          English
---------------------------------
1  chips.............crisps
2  french fries......chips
3  sidewalk..........pavement
4  cookie............biscuit
5  apartment.........flat
6  elevator..........lift
7  gas...............petrol
8  soccer............football
9  movie.............film
10 sweater...........jumper
11 trunk.............boot
12 hood..............bonnet
13 last name.........surname
14 restroom..........toilet
15 cart..............trolley
16 candy.............sweet
17 vacation..........holiday
18 subway............underground
19 pants.............trousers
20 mailbox...........postbox

Press enter to continue...

Good Luck!

---------------------------------
        Enter Today's Date
---------------------------------
Enter month: 4
Enter day: 14
Enter year: 2022


---------------------------------
            Questions
---------------------------------
   Five American words will be
 randomly selected from the list.
  Enter the English translation.

=================================
#  NAME                TEST TAKEN
---------------------------------
4  Kun Joom            4/14/2022

---------------------------------
#  American          English
---------------------------------
15 cart..............trolley                  // #s added to quickly lookup on 'translation' study guide

            Correct!

5  apartment.........flat

            Correct!

4  cookie............biscuit

            Correct!

17 vacation..........holiday

            Correct!

16 candy.............sweet

            Correct!


=================================
#  NAME                TEST TAKEN
---------------------------------
5  Joe Bush            4/14/2022

---------------------------------
#  American          English
---------------------------------
6  elevator..........lift

            Correct!

17 vacation..........holiday

            Correct!

5  apartment.........complex

           Incorrect!

Answer: flat                                  // incorrect answers ~ shows correct answer for learning

16 candy.............yumyum

           Incorrect!

Answer: sweet

8  soccer............football

            Correct!


=================================
#  NAME                TEST TAKEN
---------------------------------
9  Helen Hu            4/14/2022

---------------------------------
#  American          English
---------------------------------
20 mailbox...........postbox

            Correct!

3  sidewalk..........pavement

            Correct!

19 pants.............trousers

            Correct!

20 mailbox...........postbox

            Correct!

16 candy.............sweeties

           Incorrect!

Answer: sweet

===================================================
                Updated Information
===================================================
---------------------------------------------------
#  NAME                SCORE %        TEST TAKEN
---------------------------------------------------
1  Steve Smith         56.6           11/11/2019
2  Sue Jones           10.0           11/11/2011
3  Li Ying             0.0            11/11/2011
4  Kun Joom            100.0          4/14/2022
5  Joe Bush            60.0           4/14/2022
6  Kim Long            0.0            11/11/2011
7  Fred Ring           33.3           5/5/2019
8  Frank Pearse        20.0           11/11/2011
9  Helen Hu            80.0           4/14/2022
10 Mark James          0.0            11/11/2021


//****************************************************************************************************

10                         //updated file
Steve Smith
56.6,11/11/2019
Sue Jones
10,11/11/2011
Li Ying
0,11/11/2011
Kun Joom
100,4/14/2022
Joe Bush
60,4/14/2022
Kim Long
0,11/11/2011
Fred Ring
33.3,5/5/2019
Frank Pearse
20,11/11/2011
Helen Hu
80,4/14/2022
Mark James
0,11/11/2021

*/