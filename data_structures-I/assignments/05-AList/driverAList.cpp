//*****************************************************************************************************
//
//      This program tests the AList class by inserting, retrieving, updating, and removing data.
//
//      Other files required:
//        1.	 AList.h - header file for the AList class
//
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "AList.h"

//*****************************************************************************************************

void checkState(AList<short> &list);
void printResult(bool success, const char *action, const char *value, AList<short> &list);
void printNum(const char *title, short num);

//*****************************************************************************************************

int main() {
    AList<short> shortList(3);
    short num;

    checkState(shortList);

    printResult(shortList.updateAtIndex(25, 2), "updateAtIndex", "25", shortList);
    printResult(shortList.updateFront(30), "updateFront", "30", shortList);
    printResult(shortList.updateBack(35), "updateBack", "35", shortList);
    printResult(shortList.update(35), "update", "35", shortList);

    num = 35;
    printResult(shortList.retrieve(num), "retrieve", "35", shortList);
    printResult(shortList.retrieveAtIndex(num, 2), "retrieveAtIndex", "num", shortList);
    printResult(shortList.retrieveFront(num), "retrieveFront", "num", shortList);
    printResult(shortList.retrieveBack(num), "retrieveBack", "num", shortList);

    num = 35;
    printResult(shortList.remove(num), "remove", "35", shortList);
    printResult(shortList.removeAtIndex(num, 2), "removeAtIndex", "num", shortList);
    printResult(shortList.removeFront(num), "removeFront", "num", shortList);
    printResult(shortList.removeBack(num), "removeBack", "num", shortList);

    printResult(shortList.insertFront(5), "insertFront", "5", shortList);
    printNum("Inserted at front: ", 5);
    printResult(shortList.insertAtIndex(10, 1), "insertAtIndex", "10", shortList);
    printNum("Inserted at index 1: ", 10);
    printResult(shortList.insertBack(15), "insertBack", "15", shortList);
    printNum("Inserted at back: ", 15);
    printResult(shortList.insertFront(3), "insertFront", "3", shortList);
    printNum("Inserted at front: ", 3);
    printResult(shortList.insertAtIndex(1, 0), "insertAtIndex", "1", shortList);
    printNum("Inserted at index 0: ", 1);

    printResult(shortList.updateAtIndex(25, 2), "updateAtIndex", "25", shortList);
    printNum("Updated at index 2: ", 25);
    printResult(shortList.updateFront(30), "updateFront", "30", shortList);
    printNum("Updated at front: ", 30);
    printResult(shortList.updateBack(35), "updateBack", "35", shortList);
    printNum("Updated at back: ", 35);
    printResult(shortList.update(35), "update", "35", shortList);
    printNum("Updated value 35: ", 35);

    num = 35;
    printResult(shortList.retrieve(num), "retrieve", "35", shortList);
    printNum("Retrieved value 35: ", num);
    printResult(shortList.retrieveAtIndex(num, 2), "retrieveAtIndex", "num", shortList);
    printNum("Retrieved at index 2: ", num);
    printResult(shortList.retrieveFront(num), "retrieveFront", "num", shortList);
    printNum("Retrieved at front: ", num);
    printResult(shortList.retrieveBack(num), "retrieveBack", "num", shortList);
    printNum("Retrieved at back: ", num);

    num = 35;
    printResult(shortList.remove(num), "remove", "35", shortList);
    printNum("Removed value 35: ", num);
    printResult(shortList.removeAtIndex(num, 2), "removeAtIndex", "num", shortList);
    printNum("Removed at index 2: ", num);
    printResult(shortList.removeFront(num), "removeFront", "num", shortList);
    printNum("Removed at front: ", num);
    printResult(shortList.removeBack(num), "removeBack", "num", shortList);
    printNum("Removed at back: ", num);

    printResult(shortList.clear(), "clear", "num", shortList);

    return 0;
}

//*****************************************************************************************************

void checkState(AList<short> &list) {
    if (list.isFull())
        cerr << "List is full" << endl;
    else if (list.isEmpty())
        cerr << "List is empty" << endl;
}

//*****************************************************************************************************

void printResult(bool success, const char *action, const char *value, AList<short> &list) {
    short min;

    if (success) {
        list.display();
        list.getSmallest(min);

        if (list.getNumValues() > 0)
            cout << "capacity is " << list.getCapacity() << "\tnumValues is "
                 << list.getNumValues() << "\t smallest value is " << min << endl;
        else
            cout << "capacity is " << list.getCapacity() << "\tnumValues is "
                 << list.getNumValues() << endl;
    } else {
        cerr << "Unable to " << action << " value " << value << endl;
    }
    checkState(list);
}

//*****************************************************************************************************

void printNum(const char *title, short num) {
    cout << title << num << "\n" << endl;
}

//*****************************************************************************************************

/*

List is empty
Unable to updateAtIndex value 25
List is empty
Unable to updateFront value 30
List is empty
Unable to updateBack value 35
List is empty
Unable to update value 35
List is empty
Unable to retrieve value 35
List is empty
Unable to retrieveAtIndex value num
List is empty
Unable to retrieveFront value num
List is empty
Unable to retrieveBack value num
List is empty
Unable to remove value 35
List is empty
Unable to removeAtIndex value num
List is empty
Unable to removeFront value num
List is empty
Unable to removeBack value num
List is empty
[0] 5
capacity is 3   numValues is 1   smallest value is 5
Inserted at front: 5

[0] 5   [1] 10
capacity is 3   numValues is 2   smallest value is 5
Inserted at index 1: 10

[0] 5   [1] 10  [2] 15
capacity is 3   numValues is 3   smallest value is 5
List is full
Inserted at back: 15

[0] 3   [1] 5   [2] 10  [3] 15
capacity is 4   numValues is 4   smallest value is 3
List is full
Inserted at front: 3

[0] 1   [1] 3   [2] 5   [3] 10  [4] 15
capacity is 6   numValues is 5   smallest value is 1
Inserted at index 0: 1

[0] 1   [1] 3   [2] 25  [3] 10  [4] 15
capacity is 6   numValues is 5   smallest value is 1
Updated at index 2: 25

[0] 30  [1] 3   [2] 25  [3] 10  [4] 15
capacity is 6   numValues is 5   smallest value is 3
Updated at front: 30

[0] 30  [1] 3   [2] 25  [3] 10  [4] 35
capacity is 6   numValues is 5   smallest value is 3
Updated at back: 35

[0] 30  [1] 3   [2] 25  [3] 10  [4] 35
capacity is 6   numValues is 5   smallest value is 3
Updated value 35: 35

[0] 30  [1] 3   [2] 25  [3] 10  [4] 35
capacity is 6   numValues is 5   smallest value is 3
Retrieved value 35: 35

[0] 30  [1] 3   [2] 25  [3] 10  [4] 35
capacity is 6   numValues is 5   smallest value is 3
Retrieved at index 2: 25

[0] 30  [1] 3   [2] 25  [3] 10  [4] 35
capacity is 6   numValues is 5   smallest value is 3
Retrieved at front: 30

[0] 30  [1] 3   [2] 25  [3] 10  [4] 35
capacity is 6   numValues is 5   smallest value is 3
Retrieved at back: 35

[0] 30  [1] 3   [2] 25  [3] 10
capacity is 6   numValues is 4   smallest value is 3
Removed value 35: 35

[0] 30  [1] 3   [2] 10
capacity is 6   numValues is 3   smallest value is 3
Removed at index 2: 25

[0] 3   [1] 10
capacity is 6   numValues is 2   smallest value is 3
Removed at front: 30

[0] 3
capacity is 6   numValues is 1   smallest value is 3
Removed at back: 10

capacity is 6   numValues is 0
List is empty

*/