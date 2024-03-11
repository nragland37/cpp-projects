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

void displayStack(bool success, Stack<short> &stack);
void checkState(Stack<short> &stack);

//*****************************************************************************************************

int main() {
    Stack<short> shortStack(10);
    short num;
    bool success;

    checkState(shortStack);

    for (int i = 0; i < 10; ++i) {
        num = 10 * (i + 1);
        success = shortStack.push(num);

        if (success)
            cout << "pushed: " << num << endl;

        displayStack(success, shortStack);
    }

    for (int i = 0; i < 10; ++i) {
        success = shortStack.pop(num);

        if (success)
            cout << "popped: " << num << endl;

        displayStack(success, shortStack);
    }

    return 0;
}

//*****************************************************************************************************

void displayStack(bool success, Stack<short> &stack) {
    short num;
    int numVal;

    if (success) {
        numVal = stack.getNumValues();
        stack.peek(num);

        if (numVal > 0)
            cout << "numValues: " << numVal
                 << "\tpeeked: " << num << endl;
        else
            cout << "numValues: " << numVal << endl;
    }

    checkState(stack);
}

//*****************************************************************************************************

void checkState(Stack<short> &stack) {
    if (stack.isFull())
        cerr << "\nstack is full\n\n";
    else if (stack.isEmpty())
        cerr << "\nstack is empty\n\n";
}

//*****************************************************************************************************
/*

stack is empty

pushed: 10
numValues: 1    peeked: 10
pushed: 20
numValues: 2    peeked: 20
pushed: 30
numValues: 3    peeked: 30
pushed: 40
numValues: 4    peeked: 40
pushed: 50
numValues: 5    peeked: 50
pushed: 60
numValues: 6    peeked: 60
pushed: 70
numValues: 7    peeked: 70
pushed: 80
numValues: 8    peeked: 80
pushed: 90
numValues: 9    peeked: 90
pushed: 100
numValues: 10   peeked: 100

stack is full

popped: 100
numValues: 9    peeked: 90
popped: 90
numValues: 8    peeked: 80
popped: 80
numValues: 7    peeked: 70
popped: 70
numValues: 6    peeked: 60
popped: 60
numValues: 5    peeked: 50
popped: 50
numValues: 4    peeked: 40
popped: 40
numValues: 3    peeked: 30
popped: 30
numValues: 2    peeked: 20
popped: 20
numValues: 1    peeked: 10
popped: 10
numValues: 0

stack is empty

*/