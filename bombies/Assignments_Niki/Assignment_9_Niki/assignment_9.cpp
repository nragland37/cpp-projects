//****************************************************************************************************
// 		    File:                 assignment9.cpp
//
//		    Student:              Niki Portell
//
//		    Assignment:           Program #9
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  April 18, 2022
//
//          Description:          A program that enables people to learn how to translate from
//                                American to English.
//
//****************************************************************************************************

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct Translation {
    string american;
    string english;
};

struct Date {
    int day;
    int month;
    int year;
};

struct Person {
    char name[20];
    double score;
    Date testTaken;
};

Translation* readTranslation(const string& filename, int& num);
Person* readTesters(const string& filename, int& num);
void testingOptions(const Translation t[], int numT, Person people[], int numP);
void takeTest(const Translation t[], int numT, Person& p);
void displayTesters(const Person p[], int numP);
void writeTesters(const string& filename, const Person p[], int numP);

//****************************************************************************************************

int main() {
    Translation* ptr1 = nullptr;
    Person* ptr2 = nullptr;
    string filename;
    int numT = 0;
    int numP = 0;
    Person p;
    int personTesting = 0;

    ptr1 = readTranslation("Translation.txt", numT);
    ptr2 = readTesters("Testers.txt", numP);
    testingOptions(ptr1, numT, ptr2, numP);
    displayTesters(ptr2, numP);
    // cout << "Who is taking the test? (Choose a number between 1 and " << numP << ")";
    // cin >> personTesting;
    // p = ptr2[personTesting - 1];
    // takeTest(ptr1, numT, p);                       //if you wanted to chose who was taking the test
    writeTesters(filename, ptr2, numP);

    delete[] ptr1;
    delete[] ptr2;

    return 0;
}

//****************************************************************************************************

Translation* readTranslation(const string& filename, int& num) {
    Translation* p = nullptr;
    fstream f;

    f.open(filename, ios::in);
    if (f) {
        f >> num;
        f.ignore();
        p = new Translation[num];
        for (int i = 0; i < num; i++) {
            getline(f, p[i].american, ',');
            getline(f, p[i].english);
        }
    }
    f.close();

    return p;
}

//****************************************************************************************************

Person* readTesters(const string& filename, int& num) {
    Person* p = nullptr;
    fstream f;

    f.open(filename, ios::in);
    if (f) {
        f >> num;
        f.ignore();
        p = new Person[num];
        for (int i = 0; i < num; i++) {
            f.getline(p[i].name, 20);
            f >> p[i].score;
            f.ignore();
            f >> p[i].testTaken.month;
            f.ignore();
            f >> p[i].testTaken.day;
            f.ignore();
            f >> p[i].testTaken.year;
            f.ignore();
        }
    }
    f.close();
    return p;
}

//****************************************************************************************************

void testingOptions(const Translation t[], int numT, Person people[], int numP) {
    string temp;
    int randNum;

    cout << "Enter the date: XX/XX/XXXX ";
    cin >> temp;
    cin.ignore();
    for (int i = 0; i < 3; i++) {
        short seed = time(0);
        srand(seed);
        randNum = rand() % (numP - 1);
        takeTest(t, numT, people[randNum]);
        people[randNum].testTaken.month = stoi(temp.substr(0, 2));
        people[randNum].testTaken.day = stoi(temp.substr(3, 2));
        people[randNum].testTaken.year = stoi(temp.substr(6, 4));
    }
    cout << endl;
}

//****************************************************************************************************

void takeTest(const Translation t[], int numT, Person& p) {
    int randNum;
    string answer;
    int correctAns = 0;

    cout << "Tester: " << p.name << endl;

    for (int i = 0; i < 5; i++) {
        short seed = time(0);
        srand(seed);
        randNum = rand() % numT;
        cout << "Question " << i + 1 << ": " << t[randNum].american << " = ______________? ";
        getline(cin, answer);
        if (answer == t[randNum].english) {
            cout << endl
                 << "Correct!" << endl;
            correctAns++;
        } else {
            cout << endl
                 << "Incorrect." << endl;
        }
    }
    p.score = (static_cast<double>(correctAns) / 5) * 100;
    cout << "Your Score: " << p.score << endl;
}

//****************************************************************************************************

void displayTesters(const Person p[], int numP) {
    cout << fixed << left
         << setw(19) << "NAME" << setw(20) << "SCORE" << setw(15) << "DATE" << endl
         << "**************************************************" << endl;
    cout << fixed << left;
    for (int i = 0; i < numP; i++) {
        cout << setw(19) << p[i].name;
        cout << setw(20) << setprecision(1) << p[i].score
             << p[i].testTaken.month
             << "/" << p[i].testTaken.day
             << "/" << p[i].testTaken.year
             << endl;
    }
}

//****************************************************************************************************

void writeTesters(const string& filename, const Person p[], int numP) {
    fstream f;

    f.open("Testers.txt", ios::out);
    f << numP << endl;
    for (int i = 0; i < numP; i++) {
        f << p[i].name << endl;
        f << p[i].score << ",";
        f << p[i].testTaken.month << "/" << p[i].testTaken.day << "/" << p[i].testTaken.year << endl;
    }
    f.close();
}

//****************************************************************************************************

/*

Enter the date: XX/XX/XXXX 04/18/2022
Tester: Li Ying
Question 1: gas = ______________? a

Incorrect.
Question 2: last name = ______________? a

Incorrect.
Question 3: candy = ______________? a

Incorrect.
Question 4: candy = ______________? a

Incorrect.
Question 5: mailbox = ______________? a

Incorrect.
Your Score: 0
Tester: Fred Ring
Question 1: mailbox = ______________? a

Incorrect.
Question 2: sidewalk = ______________? a

Incorrect.
Question 3: sidewalk = ______________? a

Incorrect.
Question 4: sidewalk = ______________? a

Incorrect.
Question 5: elevator = ______________? a

Incorrect.
Your Score: 0
Tester: Kun Joom
Question 1: elevator = ______________? a

Incorrect.
Question 2: sweater = ______________? a

Incorrect.
Question 3: sweater = ______________? a

Incorrect.
Question 4: last name = ______________? a

Incorrect.
Question 5: last name = ______________? a

Incorrect.
Your Score: 0

NAME               SCORE               DATE
**************************************************
Steve Smith        56.6                11/11/2019
Sue Jones          10.0                11/11/2011
Li Ying            0.0                 4/18/2022
Kun Joom           0.0                 4/18/2022
Joe Bush           10.0                11/11/2021
Kim Long           0.0                 11/11/2011
Fred Ring          0.0                 4/18/2022
Frank Pearse       20.0                11/11/2011
Helen Hu           0.1                 11/11/2011
Mark James         0.0                 11/11/2021

*/