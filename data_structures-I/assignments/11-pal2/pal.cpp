//*****************************************************************************************************
//
//      This program reads in a file of palindromes separated by # and determines if they are valid
//      palindromes using a stack and a queue to reverse the order and compare the characters.
//
//      Other files required:
//        1.	 stack.h - header file for the Stack class
//        2.	 queue.h - header file for the Queue class
//        3.	 palindromes.txt - file containing palindromes with punctuation and spaces
//
//*****************************************************************************************************

#include <cctype>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include "queue.h"
#include "stack.h"

//*****************************************************************************************************

bool testNdisplayPal(Stack<char> &s, Queue<char> &q);
char getPalType(bool hasSpace, bool hasPunct);
void displayPalResult(bool isValid, char palType);

//*****************************************************************************************************

int main() {
    Stack<char> s;
    Queue<char> q;
    bool isValid,
         hasPunct,
         hasSpace;
    int len;
    char palType;
    char pal[81];

    ifstream in("palindromes.txt");

    while (in.getline(pal, 80, '#')) {
        len = int(strlen(pal));
        hasSpace = false;
        hasPunct = false;

        for (int i = 0; i < len; ++i) {
            if (isalpha(pal[i])) {
                pal[i] = tolower(pal[i]);
                s.push(pal[i]);
                q.enqueue(pal[i]);
            } else if (isspace(pal[i])) {
                hasSpace = true;
            } else if (ispunct(pal[i])) {
                hasPunct = true;
            }
        }

        isValid = testNdisplayPal(s, q);
        palType = getPalType(hasSpace, hasPunct);

        displayPalResult(isValid, palType);
    }

    in.close();

    return 0;
}

//*****************************************************************************************************

bool testNdisplayPal(Stack<char> &s, Queue<char> &q) {
    char sTemp,
         qTemp;
    bool isValid = true;
    int numVal = s.getNumValues();

    while ((s.pop(sTemp)) && (q.dequeue(qTemp))) {
        if (sTemp != qTemp)
            isValid = false;

        cout << sTemp;
    }

    cout << setw(25 - numVal) << " ";

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