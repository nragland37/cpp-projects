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

Translation* readTranslation(const string& filename, int& num);
Person* readTesters(const string& filename, int& num);
void testingOptions(const Translation t[], int numT, Person people[], int numP);
void takeTest(const Translation t[], int numT, Person& p);
void displayTesters(const Person p[], int numP);
void writeTesters(const string& filename, const Person p[], int numP);

//****************************************************************************************************

int main() {

    return 0;
}

//****************************************************************************************************

Translation* readTranslation(const string& filename, int& num) {
}

//****************************************************************************************************

Person* readTesters(const string& filename, int& num) {
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

void writeTesters(const string& filename, const Person p[], int numP) {
}

/*


*/