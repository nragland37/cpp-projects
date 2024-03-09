//*****************************************************************************************************
//      String Processing
//
//      This program takes a string and uses various string functions to extract and display
//      information about the string such as the length, number of letters, digits, upper and lower
//      case letters, specific characters and indexes of certain characters.
//
//*****************************************************************************************************

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

void sentenceData(const string sentence);

//*****************************************************************************************************

int main() {
    string sentence("This is a 101 SAMPLE to demonstrate string processing");

    cout << "------------------------------------------------------\n"
         << sentence
         << "\n------------------------------------------------------" << endl;
    sentenceData(sentence);

    return 0;
}

//*****************************************************************************************************

void sentenceData(const string sentence) {
    int length,
        alphaCount = 0,
        digitCount = 0,
        lowerCount = 0,
        upperCount = 0,
        first_s,
        second_s;

    length = sentence.length();                     // get the length of the string
    first_s = sentence.find('s');                   // find the first 's' in the string
    second_s = sentence.find('s', first_s + 1);     // find the second 's' in the string

    for (int i = 0; i < length; ++i) {     // bool return types: isalpha(), isdigit(), islower(), isupper()
        if (isalpha(sentence[i]))
            alphaCount++;
        if (isdigit(sentence[i]))
            digitCount++;
        if (islower(sentence[i]))
            lowerCount++;
        if (isupper(sentence[i]))
            upperCount++;
    }

    cout << "The size of the string: " << length
         << "\nThe number of letters in the string: " << alphaCount
         << "\nThe number of digits in the string: " << digitCount
         << "\nThe number of lower case letters in the string: " << lowerCount
         << "\nThe number of upper case letters in the string: " << upperCount
         << "\nThe character that is at index 12 of the string: " << sentence.at(12)     // at() is the same as []
         << "\nThe first character of the string: " << sentence.front()                  // front() is the same as [0]
         << "\nThe last character of the string: " << sentence.back()                    // back() is the same as [length - 1]
         << "\nThe index of the first 's' in the string: " << first_s
         << "\nThe index of the second 's' in the string: " << second_s << endl;
}

//*****************************************************************************************************
/*

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