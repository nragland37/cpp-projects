//*****************************************************************************************************
//
//      This header file defines a templated class for a queue data structure implemented using a
//      linked list to store the elements of the queue.
//
//      Other files required:
//        1.	 node.h - header file for the Node struct
//
//*****************************************************************************************************

#ifndef QUEUE_H
#define QUEUE_H

//*****************************************************************************************************

#include "node.h"
#include <new>

//*****************************************************************************************************

template <typename TYPE>
class Queue {
private:
    Node<TYPE> *front;
    Node<TYPE> *back;
    int numValues;

public:
    Queue();
    ~Queue();
    bool enqueue(const TYPE &dataIn);
    bool dequeue(TYPE &dataOut);
    bool viewFront(TYPE &dataOut) const;
    bool viewRear(TYPE &dataOut) const;
    int getNumValues() const;
    bool isFull() const;
    bool isEmpty() const;
};

//*****************************************************************************************************

template <typename TYPE>
Queue<TYPE>::Queue() {
    front = nullptr;
    back = nullptr;
    numValues = 0;
}

//*****************************************************************************************************

template <typename TYPE>
Queue<TYPE>::~Queue() {
    Node<TYPE> *pCur = nullptr;

    while (front) {
        pCur = front;
        front = front->next;
        delete pCur;
    }

    back = nullptr;
    numValues = 0;
}

//*****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::enqueue(const TYPE &dataIn) {
    bool success = false;
    Node<TYPE> *pNew = new (nothrow) Node<TYPE>(dataIn);

    if (pNew) {
        if (back)
            back->next = pNew;
        else
            front = pNew;

        back = pNew;
        numValues++;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::dequeue(TYPE &dataOut) {
    bool success = false;
    Node<TYPE> *pCur = front;

    if (front) {
        dataOut = pCur->data;
        front = front->next;
        delete pCur;
        numValues--;

        if (numValues == 0)
            back = nullptr;

        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::viewFront(TYPE &dataOut) const {
    bool success = false;

    if (front) {
        dataOut = front->data;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::viewRear(TYPE &dataOut) const {
    bool success = false;

    if (back) {
        dataOut = back->data;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
int Queue<TYPE>::getNumValues() const {
    return numValues;
}

//*****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::isFull() const {
    bool success = true;
    Node<TYPE> *pNew = nullptr;

    pNew = new (std::nothrow) Node<TYPE>;

    if (pNew) {
        delete pNew;
        success = false;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE>::isEmpty() const {
    return (numValues == 0);
}

//*****************************************************************************************************

#endif