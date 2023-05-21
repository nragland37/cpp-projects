//*****************************************************************************************************
//
//      This program tests the AList class by inserting values, displaying the list and its smallest
//      value, and checking its empty/full status.
//
//      Other files required:
//        1.	 AList.h - header file for the AList class
//
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "AList.h"

//*****************************************************************************************************

int main() {
    short min;

    AList<short> shortList(3);

    if (shortList.isFull())
        cout << "The list is full\n" << endl;
    else if (shortList.isEmpty())
        cout << "The list is empty\n" << endl;
    else
        cout << "The list is neither full nor empty\n" << endl;

    if (shortList.insertFront(3)) {
        shortList.display();
        shortList.getSmallest(min);
        cout << "capacity is " << shortList.getCapacity() << "\tnumValues is "
             << shortList.getNumValues() << "\tsmallest value is " << min << endl;
    } else {
        cerr << "Unable to insert value 3" << endl;
    }

    if (shortList.isFull())
        cout << "The list is full\n" << endl;
    else if (shortList.isEmpty())
        cout << "The list is empty\n" << endl;
    else
        cout << "The list is neither full nor empty\n" << endl;

    if (shortList.insertAtIndex(5, 1)) {
        shortList.display();
        shortList.getSmallest(min);
        cout << "capacity is " << shortList.getCapacity() << "\tnumValues is "
             << shortList.getNumValues() << "\tsmallest value is " << min << endl;
    } else {
        cerr << "Unable to insert value 5 to index 1" << endl;
    }

    if (shortList.isFull())
        cout << "The list is full\n" << endl;
    else if (shortList.isEmpty())
        cout << "The list is empty\n" << endl;
    else
        cout << "The list is neither full nor empty\n" << endl;

    if (shortList.insertBack(4)) {
        shortList.display();
        shortList.getSmallest(min);
        cout << "capacity is " << shortList.getCapacity() << "\tnumValues is "
             << shortList.getNumValues() << "\tsmallest value is " << min << endl;
    } else {
        cerr << "Unable to insert value 4\n";
    }

    if (shortList.isFull())
        cout << "The list is full\n" << endl;
    else if (shortList.isEmpty())
        cout << "The list is empty\n" << endl;
    else
        cout << "The list is neither full nor empty\n" << endl;

    if (shortList.insertFront(1)) {
        shortList.display();
        shortList.getSmallest(min);
        cout << "capacity is " << shortList.getCapacity() << "\tnumValues is "
             << shortList.getNumValues() << "\tsmallest value is " << min << endl;
    } else {
        cerr << "Unable to insert value 1\n";
    }

    if (shortList.isFull())
        cout << "The list is full\n" << endl;
    else if (shortList.isEmpty())
        cout << "The list is empty\n" << endl;
    else
        cout << "The list is neither full nor empty\n" << endl;

    return 0;
}

//*****************************************************************************************************

/*

The list is empty

[0] 3
capacity is 3   numValues is 1  smallest value is 3
The list is neither full nor empty

[0] 3   [1] 5
capacity is 3   numValues is 2  smallest value is 3
The list is neither full nor empty

[0] 3   [1] 5   [2] 4
capacity is 3   numValues is 3  smallest value is 3
The list is full

[0] 1   [1] 3   [2] 5   [3] 4
capacity is 6   numValues is 4  smallest value is 1
The list is neither full nor empty

*/