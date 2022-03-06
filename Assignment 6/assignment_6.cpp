//****************************************************************************************************
// 		    File:                 assignment_6.cpp
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
#include <string>

using namespace std;

int numberWords(const char* words, int size);
void sentenceData(const string sentence);

//****************************************************************************************************

int main() {
    const int SIZE = 50;
    int result;
    string sentence("This is a 101 SAMPLE to demonstrate string processing");

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

    cout << "------------------------------------------------------" << endl;
    cout << sentence << endl;
    cout << "------------------------------------------------------" << endl;
    sentenceData(sentence);

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

//****************************************************************************************************

void sentenceData(const string sentence) {
    int length = sentence.length(),
        alphaCount = 0,
        digitCount = 0,
        lowerCount = 0,
        upperCount = 0,
        first_s = sentence.find('s'),
        second_s = sentence.find('s', first_s + 1);

    for (int i = 0; i < length; ++i) {
        if (isalpha(sentence[i])) {
            alphaCount++;
        }
        if (isdigit(sentence[i])) {
            digitCount++;
        }
        if (islower(sentence[i])) {
            lowerCount++;
        }
        if (isupper(sentence[i])) {
            upperCount++;
        }
    }

    cout << "The size of the string: " << length << endl;
    cout << "The number of letters in the string: " << alphaCount << endl;
    cout << "The number of digits in the string: " << digitCount << endl;
    cout << "The number of lower case letters in the string: " << lowerCount << endl;
    cout << "The number of upper case letters in the string: " << upperCount << endl;
    cout << "The character that is at index 12 of the string: " << sentence.at(12) << endl;
    cout << "The last character of the string: " << sentence.back() << endl;
    cout << "The index of the first 's' in the string: " << first_s << endl;
    cout << "The index of the second 's' in the string: " << second_s << endl;
}

/*

Enter a line of words (less than 50 characters), ended by '.': 

Total words: 0

Enter a line of words (less than 50 characters), ended by '.': 
This contains a name,address, and phone number.
Total words: 8

Enter a line of words (less than 50 characters), ended by '.': 
This contains a name,,,,address,      and phone number.
Total words: 8
------------------------------------------------------
This is a 101 SAMPLE to demonstrate string processing
------------------------------------------------------
The size of the string: 53
The number of letters in the string: 42
The number of digits in the string: 3
The number of lower case letters in the string: 35
The number of upper case letters in the string: 7
The character that is at index 12 of the string: 1
The last character of the string: g
The index of the first 's' in the string: 3
The index of the second 's' in the string: 6

*/