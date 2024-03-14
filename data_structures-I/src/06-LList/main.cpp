//*****************************************************************************************************
//
//      This program demonstrates the use of the LList class by instantiating a singly linked shortList of
//      short integers and performing its methods.
//
//      Other files required:
//        1.	 LList.h - header file for the LList class
//
//*****************************************************************************************************

#include "LList.h"

#include <iostream>
using namespace std;

//*****************************************************************************************************

void displayLList(bool success, LList<short> &shortList);
void checkState(LList<short> &shortList);

//*****************************************************************************************************

int main() {
    LList<short> shortList;
    bool success;
    short num;

    checkState(shortList);

    for (int i = 0; i < 5; ++i) {
        num = 10 * (i + 1);
        success = shortList.insert(num);

        if (success)
            cout << "inserted " << num << endl;

        displayLList(success, shortList);
    }

    cout << endl;

    for (int i = 0; i < 2; ++i) {
        num = 10 * (i + 1);
        success = shortList.retrieve(num);

        if (success)
            cout << "retrieved " << num << endl;

        displayLList(success, shortList);
    }

    cout << endl;

    for (int i = 0; i < 5; ++i) {
        num = (10 * (5 - i));
        success = shortList.remove(num);

        if (success)
            cout << "removed " << num << endl;

        displayLList(success, shortList);
    }

    return 0;
}

//*****************************************************************************************************

void displayLList(bool success, LList<short> &shortList) {
    short front,
        rear;
    int numVal;

    if (success) {
        shortList.display();
        shortList.viewFront(front);
        shortList.viewRear(rear);
        numVal = shortList.getNumValues();

        if (numVal > 0)
            cout << "numValues: " << numVal
                 << "\tfront: " << front
                 << "\trear: " << rear << endl;
        else
            cout << "numValues: " << numVal << endl;
    }

    checkState(shortList);
}

//*****************************************************************************************************

void checkState(LList<short> &shortList) {
    if (shortList.isFull())
        cout << "\nlist is full\n\n";
    else if (shortList.isEmpty())
        cout << "\nlist is empty\n\n";
}

//*****************************************************************************************************
/*

list is empty 

inserted 10
10
numValues: 1    front: 10       rear: 10
inserted 20
10 -> 20
numValues: 2    front: 10       rear: 20
inserted 30
10 -> 20 -> 30
numValues: 3    front: 10       rear: 30
inserted 40
10 -> 20 -> 30 -> 40
numValues: 4    front: 10       rear: 40
inserted 50
10 -> 20 -> 30 -> 40 -> 50
numValues: 5    front: 10       rear: 50

retrieved 10
10 -> 20 -> 30 -> 40 -> 50
numValues: 5    front: 10       rear: 50
retrieved 20
10 -> 20 -> 30 -> 40 -> 50
numValues: 5    front: 10       rear: 50

removed 50
10 -> 20 -> 30 -> 40
numValues: 4    front: 10       rear: 40
removed 40
10 -> 20 -> 30
numValues: 3    front: 10       rear: 30
removed 30
10 -> 20
numValues: 2    front: 10       rear: 20
removed 20
10
numValues: 1    front: 10       rear: 10
removed 10

numValues: 0

list is empty

*/
