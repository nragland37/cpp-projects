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

#include <cstring>
#include <iostream>

using namespace std;

int numberWords(const char* words);

//****************************************************************************************************

int main() {
    const int SIZE = 50;
    int result,
        numInput = 3;

    char* words = new char[SIZE];

    for (int i = 0; i < numInput; ++i) {
        cout << "Enter a line of words (less than 50 characters), ended by '.': " << endl;
        cin.getline(words, SIZE);
        result = numberWords(words);
        cout << "Total words: " << result << endl
             << endl;
    }

    delete[] words;
    words = nullptr;

    return 0;
}

//****************************************************************************************************

int numberWords(const char* words) {
    int total = 0;
    int length = strlen(words);
    bool isLetter = false;

    for (int i = 0; i < length; ++i) {
        if (isalpha(words[i])) {
            isLetter = true;
        } else {
            if (isLetter == true) {
                total++;
                isLetter = false;
            }
        }
        if (words[i] == '.') {  // stops loop with '.' [incase user inputs after '.']
            break;
        }
    }

    return total;
}

/*

Enter a line of words (less than 50 characters), ended by '.':

Total words: 0

Enter a line of words (less than 50 characters), ended by '.':
This contains a name,address, and phone number.
Total words: 8

Enter a line of words (less than 50 characters), ended by '.':
,,,,,,,This      contains,, a name.
Total words: 4

//****************************************************************************************************

Enter a line of words (less than 50 characters), ended by '.':
,,, DEF,,, ABC,, 1234.
Total words: 2

Enter a line of words (less than 50 characters), ended by '.':       // user inputs after '.'
Hello, this is a test.  test
Total words: 5

Enter a line of words (less than 50 characters), ended by '.': 
     hi,, HEY,,  hello   ,, .
Total words: 3

*/