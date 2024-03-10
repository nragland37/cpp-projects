//*****************************************************************************************************
//
//      This program demonstrates the use of the Queue class by instantiating a singly linked list 
//      queue of short integers and performing its methods.
//
//      Other files required:
//        1.	 queue.h - header file for the Queue class
//
//*****************************************************************************************************

#include "queue.h"

#include <iostream>
using namespace std;

//*****************************************************************************************************

void display(bool success, Queue<short> &shortQueue);
void checkState(Queue<short> &shortQueue);

//*****************************************************************************************************

int main() {
    Queue<short> shortQueue;
    short num;
    bool success;

    cout << "numValues: " << shortQueue.getNumValues() << endl;
    checkState(shortQueue);
    cout << endl;

    for (int i = 0; i < 10; i++) {
        num = 11 * (i + 2);
        success = shortQueue.enqueue(num);
        display(success, shortQueue);
    }

    cout << endl;

    for (int i = 0; i < 10; i++) {
        success = shortQueue.dequeue(num);
        cout << "dequeue " << num << endl;
        display(success, shortQueue);
    }

    return 0;
}

//*****************************************************************************************************

void display(bool success, Queue<short> &shortQueue) {
    short front,
        back;
    int numVal;

    if (success) {
        numVal = shortQueue.getNumValues();
        shortQueue.viewFront(front);
        shortQueue.viewRear(back);

        if (numVal > 0)
            cout << "numValues: " << numVal << "\tfront: " << front << "\tback: " << back << endl;
        else
            cout << "numValues: " << numVal << endl;
    } else {
        checkState(shortQueue);
    }
}

//*****************************************************************************************************

void checkState(Queue<short> &shortQueue) {
    if (shortQueue.isFull())
        cerr << "shortQueue is full" << endl;
    else if (shortQueue.isEmpty())
        cerr << "shortQueue is empty" << endl;
}

//*****************************************************************************************************
/*

numValues: 0
queue is empty

numValues: 1     front: 22       back: 22
numValues: 2     front: 22       back: 33
numValues: 3     front: 22       back: 44
numValues: 4     front: 22       back: 55
numValues: 5     front: 22       back: 66
numValues: 6     front: 22       back: 77
numValues: 7     front: 22       back: 88
numValues: 8     front: 22       back: 99
numValues: 9     front: 22       back: 110
numValues: 10    front: 22       back: 121

dequeue 22
numValues: 9    front: 33       back: 121
dequeue 33
numValues: 8    front: 44       back: 121
dequeue 44
numValues: 7    front: 55       back: 121
dequeue 55
numValues: 6    front: 66       back: 121
dequeue 66
numValues: 5    front: 77       back: 121
dequeue 77
numValues: 4    front: 88       back: 121
dequeue 88
numValues: 3    front: 99       back: 121
dequeue 99
numValues: 2    front: 110      back: 121
dequeue 110
numValues: 1    front: 121      back: 121
dequeue 121
numValues: 0

*/