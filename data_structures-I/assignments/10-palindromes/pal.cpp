//*****************************************************************************************************
//
//      This program reads in a file of palindromes separated by # and determines if they are valid
//      palindromes using three stacks to reverse the order and compare the characters.
//
//      Other files required:
//        1.	 stack.h - header file for the Stack class
//        2.	 palindromes.txt - file containing palindromes with punctuation and spaces
//
//*****************************************************************************************************

#include <cctype>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include "stack.h"

//*****************************************************************************************************

void fillStack3(Stack<char> &s2, Stack<char> &s3);
bool testNdisplayPal(Stack<char> &s1, Stack<char> &s3);
char getPalType(bool hasSpace, bool hasPunct);
void displayPalResult(bool isValid, char palType);

//*****************************************************************************************************

int main() {
    Stack<char> s1,
                s2,
                s3;
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
                    s1.push(pal[i]);
                    s2.push(pal[i]);
                } else if (isspace(pal[i])) {
                    hasSpace = true;
                } else if (ispunct(pal[i])) {
                    hasPunct = true;
                }
            }

            fillStack3(s2, s3);

            isValid = testNdisplayPal(s1, s3);
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

void fillStack3(Stack<char> &s2, Stack<char> &s3) {
    char temp;

    while (s2.pop(temp))
        s3.push(temp);
}

//*****************************************************************************************************

bool testNdisplayPal(Stack<char> &s1, Stack<char> &s3) {
    char s1Temp,
         s3Temp;
    bool isValid = true;
    int i = s1.getNumValues();

    while ((s1.pop(s1Temp)) && (s3.pop(s3Temp))) {
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