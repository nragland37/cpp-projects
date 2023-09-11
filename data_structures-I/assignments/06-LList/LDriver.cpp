//*****************************************************************************************************
//
//      This driver file tests the functions of the LList class.
//
//      Other files required:
//        1.	 LList.h - header file for the LList class
//
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "LList.h"

//*****************************************************************************************************

void checkListState(LList<short> &list);
void printResult(bool success, const char *action, const char *value, LList<short> &list);
void printNum(const char *title, short num);

//*****************************************************************************************************

int main() {
    LList<short> shortList;
    short num;

    cout << "numValues: " << shortList.getNumValues() << endl;
    checkListState(shortList);

    num = 1;
    printResult(shortList.remove(num), "remove", "1", shortList);
    printResult(shortList.retrieve(num), "retrieve", "1", shortList);
    printResult(shortList.viewFront(num), "viewFront", "num", shortList);
    printResult(shortList.viewRear(num), "viewRear", "num", shortList);

    printResult(shortList.insert(4), "insertFront", "2", shortList);
    printResult(shortList.insert(2), "insertFront", "4", shortList);
    printResult(shortList.insert(10), "insertFront", "10", shortList);
    printResult(shortList.insert(6), "insertFront", "6", shortList);
    printResult(shortList.insert(12), "insertFront", "12", shortList);

    printResult(shortList.insert(8), "insertFront", "8", shortList);
    printResult(shortList.insert(14), "insertFront", "14", shortList);
    printResult(shortList.insert(16), "insertFront", "16", shortList);
    printResult(shortList.insert(18), "insertFront", "18", shortList);
    printResult(shortList.insert(20), "insertFront", "20", shortList);

    num = 2;
    printResult(shortList.remove(num), "remove", "2", shortList);
    printNum("Removed: ", num);
    num = 10;
    printResult(shortList.remove(num), "remove", "10", shortList);
    printNum("Removed: ", num);
    num = 20;
    printResult(shortList.remove(num), "remove", "20", shortList);
    printNum("Removed: ", num);
    num = 4;
    printResult(shortList.retrieve(num), "retrieve", "4", shortList);
    printNum("Retrieved: ", num);
    num = 12;
    printResult(shortList.retrieve(num), "retrieve", "12", shortList);
    printNum("Retrieved: ", num);
    num = 18;
    printResult(shortList.retrieve(num), "retrieve", "18", shortList);
    printNum("Retrieved: ", num);

    num = 3;
    printResult(shortList.remove(num), "remove", "3", shortList);
    printResult(shortList.retrieve(num), "retrieve", "3", shortList);
    num = 13;
    printResult(shortList.remove(num), "remove", "13", shortList);
    printResult(shortList.retrieve(num), "retrieve", "13", shortList);
    num = 19;
    printResult(shortList.remove(num), "remove", "19", shortList);
    printResult(shortList.retrieve(num), "retrieve", "19", shortList);

    return 0;
}

//*****************************************************************************************************

void printResult(bool success, const char *action, const char *value, LList<short> &list) {
    short front,
        rear;

    if (success) {
        list.display();
        list.viewFront(front);
        list.viewRear(rear);

        cout << "numValues: " << list.getNumValues() << "\t front: " << front
             << "\t rear: " << rear << endl;
    } else {
        cerr << "Unable to " << action << " value " << value << endl;
    }
    checkListState(list);
    cout << endl;
}

//*****************************************************************************************************

void checkListState(LList<short> &list) {
    if (list.isFull())
        cout << "The list is full \n";
    else if (list.isEmpty())
        cout << "The list is empty \n";
}

//*****************************************************************************************************

void printNum(const char *title, short num) {
    cout << title << num << "\n" << endl;
}

//*****************************************************************************************************

/*

numValues: 0
The list is empty

Unable to remove value 1
The list is empty

Unable to retrieve value 1
The list is empty

Unable to viewFront value num
The list is empty

Unable to viewRear value num
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
