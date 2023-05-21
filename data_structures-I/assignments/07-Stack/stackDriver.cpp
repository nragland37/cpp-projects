//*****************************************************************************************************
//
//      This driver file tests the functions of the Stack class.
//
//      Other files required:
//        1.	 stack.h - header file for the Stack class
//
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "stack.h"

//*****************************************************************************************************

void checkState(Stack<short> &stack);
void printResult(bool success, const char *action, const char *value, Stack<short> &stack);
void printNum(const char *title, short num);

//*****************************************************************************************************

int main() {
    Stack<short> shortStack(10);
    short num;
    bool success;

    cout << "numValues: " << shortStack.getNumValues() << endl;
    checkState(shortStack);

    success = shortStack.pop(num);
    printResult(success, "pop", "", shortStack);
    success = shortStack.peek(num);
    printResult(success, "peek", "", shortStack);

    success = shortStack.push(10);
    printResult(success, "push", "10", shortStack);
    success = shortStack.push(20);
    printResult(success, "push", "20", shortStack);
    success = shortStack.push(30);
    printResult(success, "push", "30", shortStack);
    success = shortStack.push(40);
    printResult(success, "push", "40", shortStack);
    success = shortStack.push(50);
    printResult(success, "push", "50", shortStack);
    success = shortStack.push(5);
    printResult(success, "push", "5", shortStack);
    success = shortStack.push(25);
    printResult(success, "push", "25", shortStack);
    success = shortStack.push(55);
    printResult(success, "push", "55", shortStack);
    success = shortStack.push(60);
    printResult(success, "push", "60", shortStack);
    success = shortStack.push(70);
    printResult(success, "push", "70", shortStack);
    success = shortStack.push(80);
    printResult(success, "push", "80", shortStack);

    success = shortStack.pop(num);
    printResult(success, "pop", "", shortStack);
    printNum("popped value: ", num);
    success = shortStack.pop(num);
    printResult(success, "pop", "", shortStack);
    printNum("popped value: ", num);
    success = shortStack.pop(num);
    printResult(success, "pop", "", shortStack);
    printNum("popped value: ", num);
    success = shortStack.pop(num);
    printResult(success, "pop", "", shortStack);
    printNum("popped value: ", num);
    success = shortStack.pop(num);
    printResult(success, "pop", "", shortStack);
    printNum("popped value: ", num);
    success = shortStack.pop(num);
    printResult(success, "pop", "", shortStack);
    printNum("popped value: ", num);
    success = shortStack.pop(num);
    printResult(success, "pop", "", shortStack);
    printNum("popped value: ", num);
    success = shortStack.pop(num);
    printResult(success, "pop", "", shortStack);
    printNum("popped value: ", num);
    success = shortStack.pop(num);
    printResult(success, "pop", "", shortStack);
    printNum("popped value: ", num);
    success = shortStack.pop(num);
    printResult(success, "pop", "", shortStack);
    printNum("popped value: ", num);

    return 0;
}

//*****************************************************************************************************

void printResult(bool success, const char *action, const char *value, Stack<short> &stack) {
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
        cerr << "unable to " << action << " value " << value << endl;
    }

    checkState(stack);
}

//*****************************************************************************************************

void checkState(Stack<short> &stack) {
    if (stack.isFull())
        cerr << "stack is full" << endl;
    else if (stack.isEmpty())
        cerr << "stack is empty" << endl;
}

//*****************************************************************************************************

void printNum(const char *title, short num) {
    cout << title << num << endl;
}

//*****************************************************************************************************

/*

numValues: 0
stack is empty
unable to pop value
stack is empty
unable to peek value
stack is empty
numValues: 1     peeked value: 10
numValues: 2     peeked value: 20
numValues: 3     peeked value: 30
numValues: 4     peeked value: 40
numValues: 5     peeked value: 50
numValues: 6     peeked value: 5
numValues: 7     peeked value: 25
numValues: 8     peeked value: 55
numValues: 9     peeked value: 60
numValues: 10    peeked value: 70
stack is full
unable to push value 80
stack is full
numValues: 9     peeked value: 60
popped value: 70
numValues: 8     peeked value: 55
popped value: 60
numValues: 7     peeked value: 25
popped value: 55
numValues: 6     peeked value: 5
popped value: 25
numValues: 5     peeked value: 50
popped value: 5
numValues: 4     peeked value: 40
popped value: 50
numValues: 3     peeked value: 30
popped value: 40
numValues: 2     peeked value: 20
popped value: 30
numValues: 1     peeked value: 10
popped value: 20
numValues: 0
stack is empty
popped value: 10

*/