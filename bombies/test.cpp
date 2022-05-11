#include <iostream>
#include <string>

using namespace std;

void sentenceAnalysis(const string sentence, int size);

int main() {
    string sentence = "This is a 101 SAMPLE to demonstrate string processing.";
    int size = sentence.size();

    cout << sentence << endl;

    sentenceAnalysis(sentence, size);

    return 0;
}

//****************************************************************************************************

void sentenceAnalysis(const string sentence, int size) {
    int totalLetters = 0;
    int totalDigits = 0;
    int totalLower = 0;
    int totalUpper = 0;
    int firstS;
    int secondS;

    cout << "The size of the string: " << sentence.size() << endl;

    for (int i = 0; i < size; i++) {
        if (isalpha(sentence[i])) {
            totalLetters++;
        }
    }
    cout << "The number of letters in the string: " << totalLetters << endl;

    for (int i = 0; i < size; i++) {
        if (isdigit(sentence[i])) {
            totalDigits++;
        }
    }

    cout << "The number of digits in the string: " << totalDigits << endl;

    for (int i = 0; i < size; i++) {
        if (islower(sentence[i])) {
            totalLower++;
        }
    }

    cout << "The number of lower case letters in the string: " << totalLower << endl;

    for (int i = 0; i < size; i++) {
        if (isupper(sentence[i])) {
            totalUpper++;
        }
    }

    cout << "The number of upper case letters in the string: " << totalUpper << endl;

    cout << "The character that is at index 12 of the string: " << sentence.at(12) << endl;
    cout << "The last character of the string: " << sentence.back() << endl;

    firstS = sentence.find('s', 0);
    cout << "The indext of the first 's' in the string: " << firstS << endl;
    cout << "The index of the second 's' in the string: " << sentence.find('s', firstS + 1);
}

//****************************************************************************************************
/*

This is a 101 SAMPLE to demonstrate string processing.
The size of the string: 54
The number of letters in the string: 42
The number of digits in the string: 3
The number of lower case letters in the string: 35
The number of upper case letters in the string: 7
The character that is at index 12 of the string: 1
The last character of the string: .
The indext of the first 's' in the string: 3
The index of the second 's' in the string: 6

*/