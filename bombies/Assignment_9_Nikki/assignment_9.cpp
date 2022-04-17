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

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Translation
{
    string american;
    string english;
};

struct Date
{
    int day;
    int month;
    int year;
};

struct Person
{
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
    cout << "Who is taking the test? (Choose a number between 1 and " << numP << ")";
    cin >> personTesting;
    p = ptr2[personTesting - 1];
    takeTest(ptr1, numT, p); 
    writeTesters(filename, ptr2, numP);

    delete[]ptr1;
    delete[]ptr2;

    return 0;
}

//****************************************************************************************************

Translation* readTranslation(const string& filename, int& num)
{
    Translation* p = nullptr;
    fstream f;

    f.open(filename, ios::in);
    if (f)
    {
        f >> num;
        f.ignore();
        p = new Translation[num];
        for (int i = 0; i < num; i++)
        {
            getline(f, p[i].american, ',');
            getline(f, p[i].english);
        }
    }
    f.close();

    return p;
}

//****************************************************************************************************

Person* readTesters(const string& filename, int& num)
{
    Person* p = nullptr;
    fstream f;

    f.open(filename, ios::in);
    if (f)
    {
        f >> num;
        f.ignore();
        p = new Person[num];
        for (int i = 0; i < num; i++)
        {
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

void testingOptions(const Translation t[], int numT, Person people[], int numP)
{
    string temp;
    Person p;
    int randNum;
   
    cout << "Enter the date: XX/XX/XXXX ";
    cin >> temp;
    for (int i = 0; i < 3; i++)
    {
        short seed = time(0);
        srand(seed);
        randNum = rand() % (numP - 1);
        p = people[randNum];
        takeTest(t, numT, p);
        p.testTaken.month = stoi(temp.substr(0, 2));
        p.testTaken.day = stoi(temp.substr(3, 2));
        p.testTaken.year = stoi(temp.substr(6, 4));
    }
    cout << endl;
}

//****************************************************************************************************

void takeTest(const Translation t[], int numT, Person& p)
{
    int randNum;
    string answer;
    int correctAns = 0;

    for (int i = 0; i < 5; i++)
    {
        short seed = time(0);
        srand(seed);
        randNum = rand() % numT;
        cout << "Question " << i + 1 << ": " << t[randNum].american << " = ______________? ";
        cin >> answer;
        if(answer == t[randNum].english)
        {
            cout << endl << "Correct!" << endl;
            correctAns++;
        }
        else
        {
            cout << endl << "Incorrect." << endl;
        }
    }
    p.score = (static_cast<double>(correctAns) / 5) * 100;
    cout << "Your Score: " << p.score << endl;
}

//****************************************************************************************************

void displayTesters(const Person p[], int numP)
{
    cout << fixed << left
         << setw(19) << "NAME" << setw(20) << "SCORE" << "DATE" << endl
         << "**************************************************" << endl;
    for (int i = 0; i < numP; i++)
    {
        cout << setw(19) << p[i].name << setw(20) << setprecision(1) << p[i].score 
             << p[i].testTaken.month << "/" 
             << p[i].testTaken.day << "/" 
             << p[i].testTaken.year << endl;
    }
}

//****************************************************************************************************

void writeTesters(const string& filename, const Person p[], int numP)
{
    fstream f;

    f.open("Testers.txt", ios::out);
    f << numP << endl;
    for (int i = 0; i < numP; i++)
    {
        f << p[i].name << endl << p[i].score << "," << p[i].testTaken.month 
          << "/" << p[i].testTaken.day << "/" << p[i].testTaken.year << endl;
    }
    f.close();
}

//****************************************************************************************************

/*

Enter the date: XX/XX/XXXX 04/15/2022
Question 1: cookie = ______________? biscuit

Correct!
Question 2: trunk = ______________? boot

Correct!
Question 3: cookie = ______________? biscuit

Correct!
Question 4: vacation = ______________? trip

Incorrect.
Question 5: elevator = ______________? lift

Correct!
Your Score: 80
Question 1: sidewalk = ______________? walkway

Incorrect.
Question 2: candy = ______________? sweet

Correct!
Question 3: movie = ______________? film

Correct!
Question 4: french fries = ______________? crisps

Incorrect.
Question 5: gas = ______________? petrol

Correct!
Your Score: 60
Question 1: sidewalk = ______________? street

Incorrect.
Question 2: apartment = ______________? townhouse

Incorrect.
Question 3: restroom = ______________? loo

Incorrect.
Question 4: cookie = ______________? biscuit

Correct!
Question 5: sweater = ______________? shirt

Incorrect.
Your Score: 20

NAME               SCORE               DATE
**************************************************
Steve Smith????????56.6                11/11/2019
Sue Jones??????????10.0                11/11/2011
Li Ying????????????0.0                 11/11/2011
Kun Joom???????????20.0                11/11/2021
Joe Bush???????????10.0                11/11/2021
Kim Long???????????0.0                 11/11/2011
Fred Ring??????????33.3                5/5/2019
Frank Pearse???????20.0                11/11/2011
Helen Hu???????????0.1                 11/11/2011
Mark James?????????0.0                 11/11/2021
Who is taking the test? (Choose a number between 1 and 10)5
Question 1: french fries = ______________? chips

Correct!
Question 2: trunk = ______________? boot

Correct!
Question 3: mailbox = ______________? box

Incorrect.
Question 4: gas = ______________? petrol

Correct!
Question 5: mailbox = ______________? mailslot

Incorrect.
Your Score: 60.0

*/