//*****************************************************************************************************
//
//      This header file defines a class template for a singly linked list.
//
//      Other files required:
//        1.	 node.h - header file for the AList class
//
//*****************************************************************************************************

#ifndef LLIST_H
#define LLIST_H

//*****************************************************************************************************

#include "node.h"
#include <iostream>
#include <new>

//*****************************************************************************************************

template <typename T>
class LList {
private:
    Node<T> *front;

public:
    LList();
    ~LList();
    bool insert(const T &dataIn);
    bool remove(T &dataOut);
    bool retrieve(T &dataOut) const;
    bool viewFront(T &dataOut) const;
    bool viewRear(T &dataOut) const;
    void display() const;
    int getNumValues() const;
    bool isEmpty() const;
    bool isFull() const;
};

//*****************************************************************************************************

template <typename T>
LList<T>::LList() {
    front = nullptr;
}

//*****************************************************************************************************

template <typename T>
LList<T>::~LList() {
    Node<T> *pCur = nullptr;

    while (front) {
        pCur = front;
        front = front->next;
        delete pCur;
    }
}

//*****************************************************************************************************

template <typename T>
bool LList<T>::insert(const T &dataIn) {
    bool success = false;
    Node<T> *pBefore = nullptr;
    Node<T> *pCur = front;
    Node<T> *pNew;

    while ((pCur) && (pCur->data < dataIn)) {
        pBefore = pCur;
        pCur = pCur->next;
    }

    pNew = new (std::nothrow) Node<T>(dataIn, pCur);

    if (pNew) {
        if (pBefore)
            pBefore->next = pNew;
        else
            front = pNew;

        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool LList<T>::remove(T &dataOut) {
    bool success = false;
    Node<T> *pBefore = nullptr;
    Node<T> *pCur = front;

    while ((pCur) && (pCur->data < dataOut)) {
        pBefore = pCur;
        pCur = pCur->next;
    }

    if ((pCur) && (pCur->data == dataOut)) {
        dataOut = pCur->data;

        if (pBefore)
            pBefore->next = pCur->next;
        else
            front = pCur->next;

        delete pCur;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool LList<T>::retrieve(T &dataOut) const {
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
bool LList<T>::viewFront(T &dataOut) const {
    bool success = false;

    if (front) {
        dataOut = front->data;
        success = true;
    } 

    return success;
}

//*****************************************************************************************************

template <typename T>
bool LList<T>::viewRear(T &dataOut) const {
    bool success = false;
    Node<T> *pCur = front;

    while ((pCur) && (pCur->next))
        pCur = pCur->next;

    if (pCur) {
        dataOut = pCur->data;
        success = true;
    } 

    return success;
}

//*****************************************************************************************************

template <typename T>
void LList<T>::display() const {
    Node<T> *pCur = front;

    while (pCur) {
        std::cout << pCur->data;

        if (pCur->next)
            std::cout << " -> ";

        pCur = pCur->next;
    }

    std::cout << std::endl;
}

//*****************************************************************************************************

template <typename T>
int LList<T>::getNumValues() const {
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
bool LList<T>::isEmpty() const {
    return (front == nullptr);
}

//*****************************************************************************************************

template <typename T>
bool LList<T>::isFull() const {
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