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

void displayInserts(AList<short> &shortList);
void displayUpdates(AList<short> &shortList);
void displayRetrieves(AList<short> &shortList);
void displayRemoves(AList<short> &shortList);
void displayAList(bool success, AList<short> &shortList);
void checkState(AList<short> &shortList);

//*****************************************************************************************************

int main() {
    AList<short> shortList(3);

    checkState(shortList);

    displayInserts(shortList);
    displayUpdates(shortList);
    displayRetrieves(shortList);
    displayRemoves(shortList);

    return 0;
}

//*****************************************************************************************************

void displayInserts(AList<short> &shortList) {
    short num;
    int i = 0;
    bool success;

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
    
    num = 40;
    success = shortList.insertBack(num);
    if (success)
        cout << "insert back: " << num << endl;
    displayAList(success, shortList);

    num = 50;
    success = shortList.insertBack(num);
    if (success)
        cout << "insert back: " << num << endl;
    displayAList(success, shortList);
}

//*****************************************************************************************************

void displayUpdates(AList<short> &shortList) {
    short num;
    int i = 1;
    bool success;

    num = 1;
    success = shortList.updateFront(num);
    if (success)
        cout << "\nupdate front: " << num << endl;
    displayAList(success, shortList);

    num = 2;
    success = shortList.updateAtIndex(num, i);
    if (success)
        cout << "update index " << i << ": " << num << endl;
    displayAList(success, shortList);

    num = 4;
    success = shortList.updateBack(num);
    if (success)
        cout << "update back: " << num << endl;
    displayAList(success, shortList);

    num = 30;
    success = shortList.update(num);
    if (success)
        cout << "update value " << num << ": " << num << endl;
    displayAList(success, shortList);
}

//*****************************************************************************************************

void displayRetrieves(AList<short> &shortList) {
    short num;
    int i = 2;
    bool success;

    success = shortList.retrieveFront(num);
    if (success)
        cout << "\nretrieve front: " << num << endl;
    displayAList(success, shortList);

    success = shortList.retrieveBack(num); 
    if (success)
        cout << "retrieve back: " << num << endl;
    displayAList(success, shortList);

    success = shortList.retrieveAtIndex(num, i); 
    if (success)
        cout << "retrieve index " << i << ": " << num << endl;
    displayAList(success, shortList);

    success = shortList.retrieve(num);
    if (success)
        cout << "retrieve value " << num << ": " << num << endl;
    displayAList(success, shortList);
}

//*****************************************************************************************************

void displayRemoves(AList<short> &shortList) {
    short num;
    bool success;

    success = shortList.removeFront(num);
    if (success)
        cout << "\nremove front: " << num << endl;
    displayAList(success, shortList);

    success = shortList.removeAtIndex(num, 0);
    if (success)
        cout << "remove index 0: " << num << endl;
    displayAList(success, shortList);

    success = shortList.removeBack(num);
    if (success)
        cout << "remove back: " << num << endl;
    displayAList(success, shortList);

    num = 30;
    success = shortList.remove(num);
    if (success)
        cout << "remove value " << num << ": " << num << endl;
    displayAList(success, shortList);

    num = 40;
    success = shortList.remove(num);
    if (success)
        cout << "remove value " << num << ": " << num << endl;
    displayAList(success, shortList);
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
[0]  10
capacity: 3     numVal: 1       smallest: 10

insert index 0: 20
[0]  20
[1]  10
capacity: 3     numVal: 2       smallest: 10

insert back: 30
[0]  20
[1]  10
[2]  30
capacity: 3     numVal: 3       smallest: 10

list is full

insert back: 40
[0]  20
[1]  10
[2]  30
[3]  40
capacity: 4     numVal: 4       smallest: 10

list is full

insert back: 50
[0]  20
[1]  10
[2]  30
[3]  40
[4]  50
capacity: 6     numVal: 5       smallest: 10


update front: 1
[0]  1
[1]  10
[2]  30
[3]  40
[4]  50
capacity: 6     numVal: 5       smallest: 1

update index 1: 2
[0]  1
[1]  2
[2]  30
[3]  40
[4]  50
capacity: 6     numVal: 5       smallest: 1

update back: 4
[0]  1
[1]  2
[2]  30
[3]  40
[4]  4
capacity: 6     numVal: 5       smallest: 1

update value 30: 30
[0]  1
[1]  2
[2]  30
[3]  40
[4]  4
capacity: 6     numVal: 5       smallest: 1


retrieve front: 1
[0]  1
[1]  2
[2]  30
[3]  40
[4]  4
capacity: 6     numVal: 5       smallest: 1

retrieve back: 4
[0]  1
[1]  2
[2]  30
[3]  40
[4]  4
capacity: 6     numVal: 5       smallest: 1

retrieve index 2: 30
[0]  1
[1]  2
[2]  30
[3]  40
[4]  4
capacity: 6     numVal: 5       smallest: 1

retrieve value 30: 30
[0]  1
[1]  2
[2]  30
[3]  40
[4]  4
capacity: 6     numVal: 5       smallest: 1


remove front: 1
[0]  2
[1]  30
[2]  40
[3]  4
capacity: 6     numVal: 4       smallest: 2

remove index 0: 2
[0]  30
[1]  40
[2]  4
capacity: 6     numVal: 3       smallest: 4

remove back: 4
[0]  30
[1]  40
capacity: 6     numVal: 2       smallest: 30

remove value 30: 30
[0]  40
capacity: 6     numVal: 1       smallest: 40

remove value 40: 40
capacity: 6     numValues: 0

list is empty

*/