//*****************************************************************************************************
//
//      This program demonstrates the use of the LList class by instantiating a singly linked list of
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

void checkListState(LList<short> &list);
void display(bool success, LList<short> &list);

//*****************************************************************************************************

int main() {
    LList<short> shortList;
    bool success;
    short num;

    cout << "numValues: " << shortList.getNumValues() << endl;
    checkListState(shortList);
    cout << endl;

    for (int i = 0; i < 10; ++i) {
        success = shortList.insert(2 * (i + 1));
        display(success, shortList);
    }

    cout << endl;

    for (int i = 0; i < 2; ++i) {
        num = (2 * (i + 1));
        success = shortList.retrieve(num);

        if (success)
            cout << "retrieved " << num << endl;

        display(success, shortList);
    }

    cout << endl;

    for (int i = 0; i < 11; ++i) {
        num = (2 * (10 - i));
        success = shortList.remove(num);

        if (success)
            cout << "removed " << num << endl;

        display(success, shortList);
    }

    return 0;
}

//*****************************************************************************************************

void display(bool success, LList<short> &list) {
    short front,
        rear;

    if (success) {
        list.display();
        list.viewFront(front);
        list.viewRear(rear);

        cout << "numValues: " << list.getNumValues()
             << "\t front: " << front
             << "\t rear: " << rear << endl;
    } else {
        checkListState(list);
    }
}

//*****************************************************************************************************

void checkListState(LList<short> &list) {
    if (list.isFull())
        cout << "The list is full \n";
    else if (list.isEmpty())
        cout << "The list is empty \n";
}

//*****************************************************************************************************
/*

numValues: 0
The list is empty 
Unable to remove value 1
The list is empty 

Unable to retrieve value 1
The list is empty 

Unable to viewFront value 
The list is empty 

Unable to viewRear value 
The list is empty 

4
numValues: 1     front: 4        rear: 4

2 -> 4
numValues: 2     front: 2        rear: 4

2 -> 4 -> 10
numValues: 3     front: 2        rear: 10

2 -> 4 -> 6 -> 10
numValues: 4     front: 2        rear: 10

2 -> 4 -> 6 -> 10 -> 12
numValues: 5     front: 2        rear: 12

2 -> 4 -> 6 -> 8 -> 10 -> 12
numValues: 6     front: 2        rear: 12

2 -> 4 -> 6 -> 8 -> 10 -> 12 -> 14
numValues: 7     front: 2        rear: 14

2 -> 4 -> 6 -> 8 -> 10 -> 12 -> 14 -> 16
numValues: 8     front: 2        rear: 16

2 -> 4 -> 6 -> 8 -> 10 -> 12 -> 14 -> 16 -> 18
numValues: 9     front: 2        rear: 18

2 -> 4 -> 6 -> 8 -> 10 -> 12 -> 14 -> 16 -> 18 -> 20
numValues: 10    front: 2        rear: 20

4 -> 6 -> 8 -> 10 -> 12 -> 14 -> 16 -> 18 -> 20
numValues: 9     front: 4        rear: 20

Removed: 2

4 -> 6 -> 8 -> 12 -> 14 -> 16 -> 18 -> 20
numValues: 8     front: 4        rear: 20

Removed: 10

4 -> 6 -> 8 -> 12 -> 14 -> 16 -> 18
numValues: 7     front: 4        rear: 18

Removed: 20

4 -> 6 -> 8 -> 12 -> 14 -> 16 -> 18
numValues: 7     front: 4        rear: 18

Retrieved: 4

4 -> 6 -> 8 -> 12 -> 14 -> 16 -> 18
numValues: 7     front: 4        rear: 18

Retrieved: 12

4 -> 6 -> 8 -> 12 -> 14 -> 16 -> 18
numValues: 7     front: 4        rear: 18

Retrieved: 18

Unable to remove value 3

Unable to retrieve value 3

Unable to remove value 13

Unable to retrieve value 13

Unable to remove value 19

Unable to retrieve value 19

*/
