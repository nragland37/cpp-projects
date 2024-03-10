//*****************************************************************************************************
//
//      This program demonstrates the use of the Stack class by instantiating an array-based list
//      stack of short integers and performing its methods. 
//
//      Other files required:
//        1.	 stack.h - header file for the Stack class
//
//*****************************************************************************************************

#include "stack.h"

#include <iostream>
using namespace std;

//*****************************************************************************************************

void checkState(Stack<short> &stack);
void display(bool success, Stack<short> &stack);
void printNum(const char *title, short num);

//*****************************************************************************************************

int main() {
    Stack<short> shortStack(10);
    short num = 0;
    bool success;

    cout << "numValues: " << shortStack.getNumValues() << endl;
    checkState(shortStack);
    cout << endl;

    for (int i = 0; i < 11; i++) {
        success = shortStack.push(11 * (i + 1));
        display(success, shortStack);
    }

    cout << endl;

    for (int i = 0; i < 11; i++) {
        success = shortStack.pop(num);
        display(success, shortStack);
    }

    return 0;
}

//*****************************************************************************************************

void display(bool success, Stack<short> &stack) {
    short num;
    int numVal;

    if (success) {
        numVal = stack.getNumValues();
        stack.peek(num);

        if (numVal > 0)
            cout << "numValues: " << numVal << "\t peeked value: " << num << endl;
        else
            cout << "numValues: " << numVal << endl;
    } else {
        checkState(stack);
    }
}

//*****************************************************************************************************

void checkState(Stack<short> &stack) {
    if (stack.isFull())
        cerr << "stack is full" << endl;
    else if (stack.isEmpty())
        cerr << "stack is empty" << endl;
}

//*****************************************************************************************************
/*

numValues: 0
stack is empty

numValues: 1     peeked value: 11
numValues: 2     peeked value: 22
numValues: 3     peeked value: 33
numValues: 4     peeked value: 44
numValues: 5     peeked value: 55
numValues: 6     peeked value: 66
numValues: 7     peeked value: 77
numValues: 8     peeked value: 88
numValues: 9     peeked value: 99
numValues: 10    peeked value: 110
stack is full

numValues: 9     peeked value: 99
numValues: 8     peeked value: 88
numValues: 7     peeked value: 77
numValues: 6     peeked value: 66
numValues: 5     peeked value: 55
numValues: 4     peeked value: 44
numValues: 3     peeked value: 33
numValues: 2     peeked value: 22
numValues: 1     peeked value: 11
numValues: 0
stack is empty

*/