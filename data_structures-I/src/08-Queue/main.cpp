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

void displayQueue(bool success, Queue<short> &shortQueue);
void checkState(Queue<short> &shortQueue);

//*****************************************************************************************************

int main() {
    Queue<short> shortQueue;
    short num;
    bool success;

    checkState(shortQueue);

    for (int i = 0; i < 10; ++i) {
        num = 10 * (i + 1);
        success = shortQueue.enqueue(num);

        if (success)
            cout << "enqueued: " << num << endl;

        displayQueue(success, shortQueue);
    }

    cout << endl;

    for (int i = 0; i < 10; ++i) {
        success = shortQueue.dequeue(num);

        if (success)
            cout << "dequeued: " << num << endl;

        displayQueue(success, shortQueue);
    }

    return 0;
}

//*****************************************************************************************************

void displayQueue(bool success, Queue<short> &shortQueue) {
    short front,
        back;
    int numVal;

    if (success) {
        numVal = shortQueue.getNumValues();
        shortQueue.viewFront(front);
        shortQueue.viewRear(back);

        if (numVal > 0)
            cout << "numValues: " << numVal
                 << "\tfront: " << front
                 << "\tback: " << back << endl;
        else
            cout << "numValues: " << numVal << endl;
    }

    checkState(shortQueue);
}

//*****************************************************************************************************

void checkState(Queue<short> &shortQueue) {
    if (shortQueue.isFull())
        cerr << "\nqueue is full\n\n";
    else if (shortQueue.isEmpty())
        cerr << "\nqueue is empty\n\n";
}

//*****************************************************************************************************
/*

queue is empty

enqueued: 10
numValues: 1    front: 10       back: 10
enqueued: 20
numValues: 2    front: 10       back: 20
enqueued: 30
numValues: 3    front: 10       back: 30
enqueued: 40
numValues: 4    front: 10       back: 40
enqueued: 50
numValues: 5    front: 10       back: 50
enqueued: 60
numValues: 6    front: 10       back: 60
enqueued: 70
numValues: 7    front: 10       back: 70
enqueued: 80
numValues: 8    front: 10       back: 80
enqueued: 90
numValues: 9    front: 10       back: 90
enqueued: 100
numValues: 10   front: 10       back: 100

dequeued: 10
numValues: 9    front: 20       back: 100
dequeued: 20
numValues: 8    front: 30       back: 100
dequeued: 30
numValues: 7    front: 40       back: 100
dequeued: 40
numValues: 6    front: 50       back: 100
dequeued: 50
numValues: 5    front: 60       back: 100
dequeued: 60
numValues: 4    front: 70       back: 100
dequeued: 70
numValues: 3    front: 80       back: 100
dequeued: 80
numValues: 2    front: 90       back: 100
dequeued: 90
numValues: 1    front: 100      back: 100
dequeued: 100
numValues: 0

queue is empty

*/