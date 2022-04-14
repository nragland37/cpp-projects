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

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//****************************************************************************************************
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

Translation* readTranslation(const string& fileName, int& numT);
Person* readTesters(const string& fileName, int& numP);
void testingOptions(const Translation t[], int numT, Person people[], int numP);
void takeTest(const Translation t[], int numT, Person& p);
void displayTesters(const Person p[], int numP);
void writeTesters(const string& fileName, const Person p[], int numP);

//****************************************************************************************************

int main() {
    int numT = 0;
    int numP = 0;
    string fileName;

    Translation* t = readTranslation("Translation.txt",num);
    Person* people = readTesters("Testers.txt",num);

    return 0;
}

//****************************************************************************************************

Translation* readTranslation(const string& fileName, int& num) {
    fstream f;
    f.open(fileName, ios::in);

    if (f) {
        f >> num;
        f.ignore();
        Translation* t = new Translation[num];

        for (int i = 0; i < num; i++) {
            getline(f, t[i].american, ',');
            f.ignore();
            getline(f, t[i].english);
            f.ignore();
        }
        f.close();
    } else {
        cout << "File not found.";
    }
    return t;
}

//****************************************************************************************************

Person* readTesters(const string& fileName, int& num) {
    fstream f;
    f.open(fileName, ios::in);
    if (f) {
        f >> num;
        f.ignore();
        Person* people = new Employee[num];

        for (int i = 0; i < num; i++) {
            getline(f, people[i].name, ',');
            f >> people[i].age;
            f.ignore();
            f >> people[i].dateEmp.month;
            f.ignore();
            f >> people[i].dateEmp.day;
            f.ignore();
            f >> people[i].dateEmp.year;
            f.ignore();
        }
        f.close();
    } else {
        cout << "File not found.";
    }
    return p;
}

//****************************************************************************************************

void testingOptions(const Translation t[], int numT, Person people[], int numP) {
}

//****************************************************************************************************

void takeTest(const Translation t[], int numT, Person& p) {
}

//****************************************************************************************************

void displayTesters(const Person p[], int numP) {
}

//****************************************************************************************************

void writeTesters(const string& fileName, const Person p[], int numP) {
}

/*


*/