//*****************************************************************************************************
//
//      This header file defines a class template for a singly linked list using a queue structure.
//      First-in, first-out (FIFO)
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

template <typename T>
class Queue {
private:
    Node<T> *front;
    Node<T> *back;
    int numValues;

public:
    Queue();
    ~Queue();
    bool enqueue(const T &dataIn);
    bool dequeue(T &dataOut);
    bool viewFront(T &dataOut) const;
    bool viewRear(T &dataOut) const;
    int getNumValues() const;
    bool isFull() const;
    bool isEmpty() const;
};

//*****************************************************************************************************

template <typename T>
Queue<T>::Queue() {
    front = nullptr;
    back = nullptr;
    numValues = 0;
}

//*****************************************************************************************************

template <typename T>
Queue<T>::~Queue() {
    Node<T> *pCur = nullptr;

    while (front) {
        pCur = front;
        front = front->next;
        delete pCur;
    }

    back = nullptr;
    numValues = 0;
}

//*****************************************************************************************************

template <typename T>
bool Queue<T>::enqueue(const T &dataIn) {
    bool success = false;
    Node<T> *pNew = new (std::nothrow) Node<T>(dataIn);

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

template <typename T>
bool Queue<T>::dequeue(T &dataOut) {
    bool success = false;
    Node<T> *pCur = front;

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

template <typename T>
bool Queue<T>::viewFront(T &dataOut) const {
    bool success = false;

    if (front) {
        dataOut = front->data;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool Queue<T>::viewRear(T &dataOut) const {
    bool success = false;

    if (back) {
        dataOut = back->data;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
int Queue<T>::getNumValues() const {
    return numValues;
}

//*****************************************************************************************************

template <typename T>
bool Queue<T>::isFull() const {
    bool success = true;
    Node<T> *pNew = nullptr;

    pNew = new (std::nothrow) Node<T>;

    if (pNew) {
        delete pNew;
        success = false;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool Queue<T>::isEmpty() const {
    return (numValues == 0);
}

//*****************************************************************************************************

#endif