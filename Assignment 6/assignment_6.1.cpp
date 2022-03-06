//****************************************************************************************************
// 		    File:                 assignment_6.1.cpp
//
//		    Student:              Nicholas Ragland
//
//		    Assignment:           Program #6
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  March 7, 2022
//
//****************************************************************************************************

#include <iostream>

using namespace std;

int numberWords(const char* words, int size);

//****************************************************************************************************

int main() {
    const int SIZE = 50;
    int result;

    char* words = new char[SIZE];

    for (int i = 0; i < 3; ++i) {
        cout << "Enter a line of words (less than 50 characters), ended by '.': " << endl;
        cin.getline(words, SIZE);
        result = numberWords(words, SIZE);
        cout << "Total words: " << result << endl;
        cin.get();
    }

    delete[] words;
    words = nullptr;

    return 0;
}

//****************************************************************************************************

int numberWords(const char* words, int size) {
    int total = 0;
    char lastChar = '\0';

    if (words[0] == '\0') {  //  PROBLEMS: space before first word(+1) / space after last word(+1) / only ',' or ' ' (+1)
        return 0;            //  IDEAS: work with isalpha()
    }

    for (int i = 0; i < size; ++i) {
        if (words[i] == ' ' || words[i] == ',') {
            total++;
            if (lastChar == ' ' || lastChar == ',') {
                total--;
            }
        }
        lastChar = words[i];
    }

    return total + 1;
}

/*

Enter a line of words (less than 50 characters), ended by '.':

Total words: 0

Enter a line of words (less than 50 characters), ended by '.': 
This contains a name,address, and phone number.
Total words: 8

Enter a line of words (less than 50 characters), ended by '.': 
This contains a name,,,,,address,     and phone number.
Total words: 8

*/