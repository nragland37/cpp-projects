//*****************************************************************************************************
//      Counting Words in C-Strings
//
//      This program takes a user input c-string and counts the number of words ending with a period 
//      and ignores any punctuation, spaces, numbers, special characters, mispelled words, etc.
//
//*****************************************************************************************************

#include <cctype>     // library for isalpha() (character function)
#include <cstring>
#include <iostream>
using namespace std;

//*****************************************************************************************************

int numberWords(const char *words, int length);

//*****************************************************************************************************

int main() {
    const int SIZE = 50;
    int result,
        numInput = 3,
        length;
    char *words = nullptr;

    words = new char[SIZE];

    for (int i = 0; i < numInput; ++i) {
        cout << "\nEnter a line of words (less than 50 characters), ended by '.': " << endl;
        cin.getline(words, SIZE);     // cin.getline() is used for c-strings (getline() is used for strings)

        length = strlen(words);

        while (words[length - 1] != '.') {
            cerr << "ERROR: Input must end with a period '.'\n";     // cerr is unbuffered and best for error handling
            cout << "\nEnter a line of words (less than 50 characters), ended by '.': " << endl;
            cin.getline(words, SIZE);

            length = strlen(words);
        }

        result = numberWords(words, length);
        cout << "Total words: " << result << endl;
    }

    delete[] words;      // must always delete dynamic memory to avoid memory leaks
    words = nullptr;     // not necessary, but good practice to set the pointer to nullptr after deleting it

    return 0;
}

//*****************************************************************************************************

int numberWords(const char *words, int length) {
    int total = 0;
    bool isLetter = false;

    for (int i = 0; i < length; ++i) {
        if (isalpha(words[i])) {           // isalpha() checks if a character is a letter in the array
            isLetter = true;               // if the character is a letter, isLetter is set to true
        } else if (isLetter == true) {     // if the character is not a letter and the previous character was a letter, the word is counted
            total++;
            isLetter = false;     // isLetter is set to false so that the next word can be counted
        }

        if (words[i] == '.')
            break;
    }

    return total;
}

//*****************************************************************************************************

/*

Enter a line of words (less than 50 characters), ended by '.':

ERROR: Input must end with a period '.'

Enter a line of words (less than 50 characters), ended by '.':
.
Total words: 0

Enter a line of words (less than 50 characters), ended by '.':
This contains a name,address, and phone number.
Total words: 8

Enter a line of words (less than 50 characters), ended by '.':
,,,,,,,This      contains,, a name.
Total words: 4

*****************************************************************************************************

Enter a line of words (less than 50 characters), ended by '.':
,,, DEF,,, ABC,, 1234.
Total words: 2

Enter a line of words (less than 50 characters), ended by '.':
Hello, this is a test.  test
ERROR: Input must end with a period '.'

Enter a line of words (less than 50 characters), ended by '.':
Hello, this is a test.
Total words: 5

Enter a line of words (less than 50 characters), ended by '.':
     hi,, HEY,,  hello   ,, .
Total words: 3

*/