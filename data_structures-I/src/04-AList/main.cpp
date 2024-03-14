//*****************************************************************************************************
//
//      This program demonstrates the use of the AList class by instantiating an array-based list of
//      short integers and performing its methods.
//
//      Other files required:
//        1.	 aList.h - header file for the AList class
//
//*****************************************************************************************************

#include "aList.h"

#include <iostream>
using namespace std;

//*****************************************************************************************************

void displayAList(bool success, AList<short> &shortList);
void checkState(AList<short> &shortList);

//*****************************************************************************************************

int main() {
    AList<short> shortList(3);
    short num;
    int i = 0;
    bool success;

    checkState(shortList);

    num = 10;
    success = shortList.insertFront(num);
    if (success)
        cout << "insert front: " << num << endl;
    displayAList(success, shortList);

    num = 20;
    success = shortList.insertAtIndex(num, i);
    if (success)
        cout << "insert index " << i << ": " << num << endl;
    displayAList(success, shortList);

    num = 30;
    success = shortList.insertBack(num);
    if (success)
        cout << "insert back: " << num << endl;
    displayAList(success, shortList);

    return 0;
}

//*****************************************************************************************************

void displayAList(bool success, AList<short> &shortList) {
    short min;
    int cap,
        numVal; 

    if (success) {
        shortList.display();
        shortList.getSmallest(min);
        cap = shortList.getCapacity();
        numVal = shortList.getNumValues();

        if (numVal > 0)
            cout << "capacity: " << cap 
                 << "\tnumVal: " << numVal 
                 << "\tsmallest: " << min << endl;
        else
            cout << "capacity: " << cap 
                 << "\tnumValues: " << numVal << endl;

        cout << endl;
    }
    
    checkState(shortList);
}

//*****************************************************************************************************

void checkState(AList<short> &shortList) {
    if (shortList.isFull())
        cerr << "list is full\n\n";
    else if (shortList.isEmpty())
        cerr << "list is empty\n\n";
}

//*****************************************************************************************************
/*

list is empty

insert front: 10
[0] 10
capacity: 3     numVal: 1       smallest: 10

insert index 0: 20
[0] 20
[1] 10
capacity: 3     numVal: 2       smallest: 10

insert back: 30
[0] 20
[1] 10
[2] 30
capacity: 3     numVal: 3       smallest: 10

list is full

*/