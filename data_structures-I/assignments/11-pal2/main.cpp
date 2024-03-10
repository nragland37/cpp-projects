//*****************************************************************************************************
//
//      This program reads in a file of palindromes separated by # and instantiates both an 
//      array-based list stack and a singly linked list queue of characters to store the palindromes.
//      It then determines if they are valid palindromes using the stack and queue to compare the 
//      characters.
//      Palindromes are words or phrases that read the same forwards and backwards.
//
//      Other files required:
//        1.	 stack.h - header file for the Stack class
//        2.	 queue.h - header file for the Queue class
//        3.	 palindromes.txt - file containing palindromes with punctuation and spaces
//
//*****************************************************************************************************

#include "queue.h"
#include "stack.h"

#include <cctype>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

//*****************************************************************************************************

bool testNdisplayPal(Stack<char> &charStack, Queue<char> &charQueue);
char getPalType(bool hasSpace, bool hasPunct);
void displayPalResult(bool isValid, char palType);

//*****************************************************************************************************

int main() {
    Stack<char> charStack;
    Queue<char> charQueue;
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
                charStack.push(pal[i]);
                charQueue.enqueue(pal[i]);
            } else if (isspace(pal[i])) {
                hasSpace = true;
            } else if (ispunct(pal[i])) {
                hasPunct = true;
            }
        }

        isValid = testNdisplayPal(charStack, charQueue);
        palType = getPalType(hasSpace, hasPunct);

        displayPalResult(isValid, palType);
    }

    in.close();

    return 0;
}

//*****************************************************************************************************

bool testNdisplayPal(Stack<char> &charStack, Queue<char> &charQueue) {
    char sTemp,
        qTemp;
    bool isValid = true;
    int numVal = charStack.getNumValues();

    while ((charStack.pop(sTemp)) && (charQueue.dequeue(qTemp))) {
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