//****************************************************************************************************
// 		    File:                 assignment10.2.cpp
//
//		    Student:              Niki Portell
//
//		    Assignment:           Program #10.2
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  April 25, 2022
//
//          Description:          A program that enables students to learn how to translate from
//                                American to English. The structures are not read into an array,
//                                but are updated in the file.
//
//****************************************************************************************************

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>  // need headers: #include <cstdlib> #include <ctime>

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
void testersUpdates(const Translation t[], int numT, const string& fileName);
void takeTest(const Translation t[], int numT, Person& p);
void displayTesters(const string& fileName);

//****************************************************************************************************

int main() {
    Translation* ptr1 = nullptr;
    int numT = 0;

    ptr1 = readTranslation("Translation.txt", numT);
    displayTesters("Testers.dat");
    testersUpdates(ptr1, numT, "Testers.dat");
    displayTesters("Testers.dat");
    // need delete [] ptr1;
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

void testersUpdates(const Translation t[], int numT, const string& fileName) {
    int numP = 0;
    string temp;
    int randNum;
    Person p;

    fstream f("Testers.dat", ios::in | ios::out | ios::binary);  // replace "Testers.dat" with "fileName" or remove "const string& fileName" from fnction parameters

    f.read(reinterpret_cast<char*>(&numP), sizeof(numP));

    cout << "Enter the date: (xx/xx/xxxx) ";
    cin >> temp;
    cin.ignore();

    for (int i = 0; i < 3; i++) {
        short seed = time(0);
        srand(seed);
        randNum = rand() % numP + 1;

        f.seekg(sizeof(Person) * (randNum - 1), ios::cur);  // cool way using ios::cur after the first read !!
        f.read(reinterpret_cast<char*>(&p), sizeof(p));

        takeTest(t, numT, p);

        f.seekp(sizeof(Person) * -1, ios::cur);

        p.testTaken.month = stoi(temp.substr(0, 2));
        p.testTaken.day = stoi(temp.substr(3, 2));
        p.testTaken.year = stoi(temp.substr(6, 4));

        f.write(reinterpret_cast<char*>(&p), sizeof(p));
        f.seekg(sizeof(numP) * 1, ios::beg);
    }
    f.close();
}

//****************************************************************************************************

void takeTest(const Translation t[], int numT, Person& p) {
    int randNum;
    string answer;
    int correctAns = 0;

    cout << "Tester: " << p.name << endl;

    for (int i = 0; i < 5; i++)  // needs 10 questions
    {
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

void displayTesters(const string& fileName) {
    int num = 0;
    Person p;

    fstream f("Testers.dat", ios::in | ios::binary);  // replace "Testers.dat" with "fileName" or remove "const string& fileName" from fnction parameters

    f.read(reinterpret_cast<char*>(&num), sizeof(num));

    cout << fixed << left << setw(20) << "Name" << setw(20) << "Score"
         << "Test Taken" << endl;
    cout << "**************************************************" << endl;

    for (int i = 0; i < num; i++) {
        f.read(reinterpret_cast<char*>(&p), sizeof(Person));
        cout << fixed << left
             << setw(20) << p.name
             << setw(20) << setprecision(2) << p.score
             << p.testTaken.month << "/"
             << p.testTaken.day << "/"
             << p.testTaken.year << endl;
    }
}

//****************************************************************************************************
