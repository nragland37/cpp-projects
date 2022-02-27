//****************************************************************************************************
// 		    File:                 assignment_5.cpp
//
//		    Student:              Nicholas Ragland
//
//		    Assignment:           Program #5
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  February 28, 2022
//
//          ..........
//
//****************************************************************************************************

#include <iostream>
#include <string>

using namespace std;

void input(string names[], int matches[], int size);
void display(const string names[], const int matches[], int size);
void displayMostMatches(const string names[], const int matches[], int size);
double mean(const int matches[], int num);
void sortStudents(string names[], int matches[], int size);

//****************************************************************************************************

int main() {
    int size;
    double average;

    do {
        cout << "How many students were surveyed?" << endl;
        cin >> size;
    } while (size < 0 || size > 5000);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max());
    string *names = new string[size];
    int *matches = new int[size];

    input(names, matches, size);
    cout << "\n---------------------------------" << endl;
    cout << "Student Names and Matches Played" << endl;
    cout << "---------------------------------" << endl;
    display(names, matches, size);

    cout << "\n------------------------------------" << endl;
    cout << "Student Name who Played Most Matches" << endl;
    cout << "--------------------------------------" << endl;
    displayMostMatches(names, matches, size);

    cout << "\n------------------------------------" << endl;
    cout << "Average Matches Played for Students" << endl;
    cout << "--------------------------------------" << endl;
    average = mean(matches, size);
    cout << "Average Matches: " << average << endl;

    cout << "\n---------------------------------------------------" << endl;
    cout << "Student Names and Matches Played ~ Ascending Order" << endl;
    cout << "---------------------------------------------------" << endl;
    sortStudents(names, matches, size);
    display(names, matches, size);

    delete[] names;
    names = nullptr;
    delete[] matches;
    matches = nullptr;

    return 0;
}

//****************************************************************************************************

void input(string names[], int matches[], int size) {
    int nums;

    for (int i = 0; i < size; ++i) {
        cout << "Enter name of student " << i + 1 << ": ";
        getline(cin, names[i]);
        while (true) {
            cout << "Enter number of matches for " << names[i] << " : ";
            cin >> nums;
            if (nums > 0) {
                break;
            } else {
                cout << "\n*Invalid Entry*" << endl;
            }
        }
    }
}

//****************************************************************************************************

void display(const string names[], const int matches[], int size) {
    for (int i = 0; i < size; ++size) {
        cout << size + 1 << "  " << names[i] << " Matches: " << matches[i];
    }
}

//****************************************************************************************************

void displayMostMatches(const string names[], const int matches[], int size) {
}

//****************************************************************************************************

double mean(const int matches[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++size) {
        sum = +matches[i];
    }

    return sum / size;
}

//****************************************************************************************************

void sortStudents(string names[], int matches[], int size) {
    int minIndex,
        minValueMatches;
    string minValueNames;
    for (int startScan = 0; startScan < (size - 1); ++startScan) {
        minIndex = startScan;
        minValueNames = names[minIndex];
        minValueMatches = matches[minIndex];
        for (int index = startScan + 1; index < size; ++index) {
            if (names[index] < minValueNames) {
                minValueNames = names[index];
                minValueMatches = matches[index];
                minIndex = index;
            }
        }
        names[minIndex] = names[startScan];
        names[startScan] = minValueNames;
        matches[minIndex] = matches[startScan];
        matches[startScan] = minValueMatches;
    }
}

/*

*/