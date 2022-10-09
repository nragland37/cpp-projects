#include <iostream>
#include <string>

using namespace std;

void sentenceData(const string sentence);

//****************************************************************************************************

int main() {
    string sentence("This is a 101 SAMPLE to demonstrate string processing");

    cout << "------------------------------------------------------" << endl;
    cout << sentence << endl;
    cout << "------------------------------------------------------" << endl;
    sentenceData(sentence);

    return 0;
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
    cout << "The first character of the string: " << sentence.front() << endl;
    cout << "The last character of the string: " << sentence.back() << endl;
    cout << "The index of the first 's' in the string: " << first_s << endl;
    cout << "The index of the second 's' in the string: " << second_s << endl;
}

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