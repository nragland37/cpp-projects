//*****************************************************************************************************
//
//      This driver file tests the functions of the Queue class.
//
//      Other files required:
//        1.	 queue.h - header file for the Queue class
//
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "queue.h"

//*****************************************************************************************************

void displayEnqueue(bool success, short value, Queue<short> &queue);
void displayDequeue(bool success, short value, Queue<short> &queue);
void checkState(Queue<short> &queue);

//*****************************************************************************************************

int main() {
    Queue<short> shortQueue;
    short num;
    bool success;

    cout << "numValues: " << shortQueue.getNumValues() << endl;

    checkState(shortQueue);

    if (shortQueue.viewFront(num))
        cout << "front: " << num << endl;
    else
        cerr << "unable to viewFront value" << endl;

    checkState(shortQueue);

    if (shortQueue.viewRear(num))
        cout << "back: " << num << endl;
    else
        cerr << "unable to viewRear value" << endl;

    checkState(shortQueue);

    success = shortQueue.dequeue(num);
    displayDequeue(success, num, shortQueue);

    num = 10;
    success = shortQueue.enqueue(num);
    displayEnqueue(success, num, shortQueue);
    num = 20;
    success = shortQueue.enqueue(num);
    displayEnqueue(success, num, shortQueue);
    num = 30;
    success = shortQueue.enqueue(num);
    displayEnqueue(success, num, shortQueue);
    num = 40;
    success = shortQueue.enqueue(num);
    displayEnqueue(success, num, shortQueue);
    num = 50;
    success = shortQueue.enqueue(num);
    displayEnqueue(success, num, shortQueue);
    num = 5;
    success = shortQueue.enqueue(num);
    displayEnqueue(success, num, shortQueue);
    num = 25;
    success = shortQueue.enqueue(num);
    displayEnqueue(success, num, shortQueue);
    num = 35;
    success = shortQueue.enqueue(num);
    displayEnqueue(success, num, shortQueue);
    num = 60;
    success = shortQueue.enqueue(num);
    displayEnqueue(success, num, shortQueue);
    num = 70;
    success = shortQueue.enqueue(num);
    displayEnqueue(success, num, shortQueue);
    num = 80;
    success = shortQueue.enqueue(num);
    displayEnqueue(success, num, shortQueue);

    success = shortQueue.dequeue(num);
    displayDequeue(success, num, shortQueue);
    success = shortQueue.dequeue(num);
    displayDequeue(success, num, shortQueue);
    success = shortQueue.dequeue(num);
    displayDequeue(success, num, shortQueue);
    success = shortQueue.dequeue(num);
    displayDequeue(success, num, shortQueue);
    success = shortQueue.dequeue(num);
    displayDequeue(success, num, shortQueue);
    success = shortQueue.dequeue(num);
    displayDequeue(success, num, shortQueue);
    success = shortQueue.dequeue(num);
    displayDequeue(success, num, shortQueue);
    success = shortQueue.dequeue(num);
    displayDequeue(success, num, shortQueue);
    success = shortQueue.dequeue(num);
    displayDequeue(success, num, shortQueue);
    success = shortQueue.dequeue(num);
    displayDequeue(success, num, shortQueue);
    success = shortQueue.dequeue(num);
    displayDequeue(success, num, shortQueue);

    return 0;
}

//*****************************************************************************************************

void displayEnqueue(bool success, short value, Queue<short> &queue) {
    short front,
        back;
    int numVal;

    if (success) {
        numVal = queue.getNumValues();
        queue.viewFront(front);
        queue.viewRear(back);

        if (numVal > 0)
            cout << "numValues: " << numVal << "\t front: " << front << "\t back: " << back << endl;
        else
            cout << "numValues: " << numVal << endl;
    } else {
        cerr << "unable to enqueue value " << value << endl;
    }

    checkState(queue);
}

//*****************************************************************************************************

void displayDequeue(bool success, short value, Queue<short> &queue) {
    short front,
        back;
    int numVal;

    if (success) {
        numVal = queue.getNumValues();
        queue.viewFront(front);
        queue.viewRear(back);

        if (numVal > 0)
            cout << "numValues: " << numVal << "\t front: " << front << "\t back: " << back << endl;
        else
            cout << "numValues: " << numVal << endl;

        cout << "dequeue value: " << value << endl;
    } else {
        cerr << "unable to dequeue value " << value << endl;
    }

    checkState(queue);
}

//*****************************************************************************************************

void checkState(Queue<short> &queue) {
    if (queue.isFull())
        cerr << "queue is full" << endl;
    else if (queue.isEmpty())
        cerr << "queue is empty" << endl;
}

//*****************************************************************************************************

/*

numValues: 0
queue is empty
unable to viewFront value
queue is empty
unable to viewRear value
queue is empty
unable to dequeue value 0
queue is empty
numValues: 1     front: 10       back: 10
numValues: 2     front: 10       back: 20
numValues: 3     front: 10       back: 30
numValues: 4     front: 10       back: 40
numValues: 5     front: 10       back: 50
numValues: 6     front: 10       back: 5
numValues: 7     front: 10       back: 25
numValues: 8     front: 10       back: 35
numValues: 9     front: 10       back: 60
numValues: 10    front: 10       back: 70
numValues: 11    front: 10       back: 80
numValues: 10    front: 20       back: 80
dequeue value: 10
numValues: 9     front: 30       back: 80
dequeue value: 20
numValues: 8     front: 40       back: 80
dequeue value: 30
numValues: 7     front: 50       back: 80
dequeue value: 40
numValues: 6     front: 5        back: 80
dequeue value: 50
numValues: 5     front: 25       back: 80
dequeue value: 5
numValues: 4     front: 35       back: 80
dequeue value: 25
numValues: 3     front: 60       back: 80
dequeue value: 35
numValues: 2     front: 70       back: 80
dequeue value: 60
numValues: 1     front: 80       back: 80
dequeue value: 70
numValues: 0
dequeue value: 80
queue is empty

*/