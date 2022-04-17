//****************************************************************************************************
// 		    File:                 assignment_10.1.cpp
//
//		    Student:              Nicholas Ragland
//
//		    Assignment:           Program #10
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  April 25, 2022
//
//****************************************************************************************************

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//****************************************************************************************************
const int NAME_SIZE = 20;

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

Person* readTesters(const string& fileName, int& num);
void writeTesters(const string& fileName, Person people[], int numP);

//****************************************************************************************************

int main() {
    int numP = 0;
    string fileName;

    Person* people = readTesters("Testers.txt", numP);
    writeTesters("Testers.dat", people, numP);

    delete[] people;
    people = nullptr;

    return 0;
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

void writeTesters(const string& fileName, Person people[], int numP) {
    ofstream f(fileName, ios::binary);
    f.write(reinterpret_cast<char*>(&numP), sizeof(int));
    f.write(reinterpret_cast<char*>(&people), sizeof(Person));
    f.close();
}

/*



*/