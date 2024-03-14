//*****************************************************************************************************
//
//      This header file defines a class template for a doubly linked list.
//
//      Other files required:
//        1.	 node.h - header file for the Node struct
//
//*****************************************************************************************************

#ifndef DLLIST_H
#define DLLIST_H

//*****************************************************************************************************

#include "node.h"
#include <iostream>
#include <new>

//*****************************************************************************************************

template <typename T>
class DLList {
private:
    Node<T> *front;
    Node<T> *rear;

public:
    DLList();
    ~DLList();
    bool insert(const T &dataIn);
    bool remove(T &dataOut);
    bool retrieve(T &dataOut) const;
    bool viewFront(T &dataOut) const;
    bool viewRear(T &dataOut) const;
    void display() const;
    void displayReverse() const;
    int getNumValues() const;
    bool isEmpty() const;
    bool isFull() const;
};

//*****************************************************************************************************

template <typename T>
DLList<T>::DLList() {
    front = nullptr;
    rear = nullptr;
}

//*****************************************************************************************************

template <typename T>
DLList<T>::~DLList() {
    Node<T> *pCur = rear;
    Node<T> *pPrev = nullptr;

    while (pCur) {
        pPrev = pCur->prev;
        delete pCur;
        pCur = pPrev;
    }

    front = nullptr;
    rear = nullptr;
}

//*****************************************************************************************************

template <typename T>
bool DLList<T>::insert(const T &dataIn) {
    bool success = false;
    Node<T> *pBefore = nullptr;
    Node<T> *pAfter = front;
    Node<T> *pNew;

    while ((pAfter) && (pAfter->data < dataIn))
        pAfter = pAfter->next;

    pBefore = (pAfter ? pAfter->prev : rear);

    pNew = new (std::nothrow) Node<T>(dataIn, pAfter, pBefore);

    if (pNew) {
        if (pBefore)
            pBefore->next = pNew;
        else
            front = pNew;

        if (pAfter)
            pAfter->prev = pNew;
        else
            rear = pNew;

        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool DLList<T>::remove(T &dataOut) {
    bool success = false;
    Node<T> *pDel = front;

    while ((pDel) && (pDel->data < dataOut))
        pDel = pDel->next;

    if ((pDel) && (pDel->data == dataOut)) {
        dataOut = pDel->data;

        if (pDel->prev)
            (pDel->prev)->next = pDel->next;
        else
            front = pDel->next;

        if (pDel->next)
            (pDel->next)->prev = pDel->prev;
        else
            rear = pDel->prev;

        delete pDel;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool DLList<T>::retrieve(T &dataOut) const {
    bool success = false;
    Node<T> *pCur = front;

    while ((pCur) && (pCur->data < dataOut))
        pCur = pCur->next;

    if ((pCur) && (pCur->data == dataOut)) {
        dataOut = pCur->data;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool DLList<T>::viewFront(T &dataOut) const {
    bool success = false;

    if (front) {
        dataOut = front->data;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool DLList<T>::viewRear(T &dataOut) const {
    bool success = false;

    if (rear) {
        dataOut = rear->data;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
void DLList<T>::display() const {
    Node<T> *pCur = front;

    while (pCur) {
        std::cout << pCur->data;

        pCur = pCur->next;
    }

    std::cout << std::endl;
}

//*****************************************************************************************************

template <typename T>
void DLList<T>::displayReverse() const {
    Node<T> *pCur = rear;

    while (pCur) {
        std::cout << pCur->data;

        pCur = pCur->prev;
    }

    std::cout << std::endl;
}

//*****************************************************************************************************

template <typename T>
int DLList<T>::getNumValues() const {
    int numVal = 0;
    Node<T> *pCur = front;

    while (pCur) {
        numVal++;
        pCur = pCur->next;
    }

    return numVal;
}

//*****************************************************************************************************

template <typename T>
bool DLList<T>::isEmpty() const {
    return (front == nullptr);
}

//*****************************************************************************************************

template <typename T>
bool DLList<T>::isFull() const {
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

#endif