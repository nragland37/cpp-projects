//*****************************************************************************************************
//
//      This program reads in a file of palindromes separated by # and instantiates an array-based 
//      list stack of characters to store the palindromes and determines if they are valid palindromes 
//      using three stacks to reverse the order and compare the characters. 
//      Palindromes are words or phrases that read the same forwards and backwards.
//
//      Other files required:
//        1.	 stack.h - header file for the Stack class
//        2.	 palindromes.txt - file containing palindromes with punctuation and spaces
//
//*****************************************************************************************************

#include "stack.h"

#include <cctype>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

//*****************************************************************************************************

void fillStack3(Stack<char> &charStack2, Stack<char> &charStack3);
bool testNdisplayPal(Stack<char> &charStack1, Stack<char> &charStack3);
char getPalType(bool hasSpace, bool hasPunct);
void displayPalResult(bool isValid, char palType);

//*****************************************************************************************************

int main() {
    Stack<char> charStack1,
                charStack2,
                charStack3;
    bool isValid,
        hasPunct,
        hasSpace;
    int len;
    char palType;
    char pal[81];

    ifstream in("palindromes.txt");

    if (in.is_open()) {
        while (in.getline(pal, 80, '#')) {
            len = int(strlen(pal));
            hasSpace = false;
            hasPunct = false;

            for (int i = 0; i < len; ++i) {
                if (isalpha(pal[i])) {
                    pal[i] = tolower(pal[i]);
                    charStack1.push(pal[i]);
                    charStack2.push(pal[i]);
                } else if (isspace(pal[i])) {
                    hasSpace = true;
                } else if (ispunct(pal[i])) {
                    hasPunct = true;
                }
            }

            fillStack3(charStack2, charStack3);

            isValid = testNdisplayPal(charStack1, charStack3);
            palType = getPalType(hasSpace, hasPunct);

            displayPalResult(isValid, palType);
        }
    } else {
        cerr << "file not found" << endl;
        return 1;
    }

    in.close();

    return 0;
}

//*****************************************************************************************************

void fillStack3(Stack<char> &charStack2, Stack<char> &charStack3) {
    char temp;

    while (charStack2.pop(temp))
        charStack3.push(temp);
}

//*****************************************************************************************************

bool testNdisplayPal(Stack<char> &charStack1, Stack<char> &charStack3) {
    char s1Temp,
        s3Temp;
    bool isValid = true;
    int i = charStack1.getNumValues();

    while ((charStack1.pop(s1Temp)) && (charStack3.pop(s3Temp))) {
        if (s1Temp != s3Temp)
            isValid = false;

        cout << s1Temp;
    }

    cout << setw(25 - i) << " ";

    return isValid;
}

//*****************************************************************************************************

char getPalType(bool hasSpace, bool hasPunct) {
    char palType = '1';

    if (hasPunct)
        palType = '3';
    else if (hasSpace)
        palType = '2';

    return palType;
}

//*****************************************************************************************************

void displayPalResult(bool isValid, char palType) {
    if (isValid)
        cout << "type " << palType << endl;
    else
        cout << "invalid" << endl;
}

//*****************************************************************************************************
/*

aha                      type 3
isitiitisi               type 3
deed                     type 1
srotor                   invalid
neveroddoreven           type 2
nolemonsnomelon          type 3
racecar                  type 2
cimoc                    invalid
wasitacaroracatisaw      type 3
yddad                    invalid

*/