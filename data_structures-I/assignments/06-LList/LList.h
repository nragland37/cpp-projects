//*****************************************************************************************************
//
//      This header file defines a templated class and represents a linked list of nodes with various
//      functions that can be performed on the list.
//
//      Other files required:
//        1.	 node.h - header file for the AList class
//
//*****************************************************************************************************

#ifndef LLIST_H
#define LLIST_H

//*****************************************************************************************************

#include "node.h"
#include <new>

//*****************************************************************************************************

template <typename TYPE>
class LList {
private:
    Node<TYPE> *front;

public:
    LList();
    ~LList();
    bool insert(const TYPE &dataIn);
    bool remove(TYPE &dataOut);
    bool retrieve(TYPE &dataOut) const;
    bool viewFront(TYPE &dataOut) const;
    bool viewRear(TYPE &dataOut) const;
    void display() const;
    int getNumValues() const;
    bool isEmpty() const;
    bool isFull() const;
};

//*****************************************************************************************************

template <typename TYPE>
LList<TYPE>::LList() {
    front = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
LList<TYPE>::~LList() {
    Node<TYPE> *pCur = nullptr;

    while (front) {
        pCur = front;
        front = front->next;
        delete pCur;
    }
}

//*****************************************************************************************************

template <typename TYPE>
bool LList<TYPE>::insert(const TYPE &dataIn) {
    bool success = false;
    Node<TYPE> *pBefore = nullptr;
    Node<TYPE> *pCur = front;
    Node<TYPE> *pNew;

    while ((pCur) && (pCur->data < dataIn)) {
        pBefore = pCur;
        pCur = pCur->next;
    }

    pNew = new (std::nothrow) Node<TYPE>(dataIn, pCur);

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

template <typename TYPE>
bool LList<TYPE>::remove(TYPE &dataOut) {
    bool success = false;
    Node<TYPE> *pBefore = nullptr;
    Node<TYPE> *pCur = front;

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

template <typename TYPE>
bool LList<TYPE>::retrieve(TYPE &dataOut) const {
    bool success = false;
    Node<TYPE> *pCur = front;

    while ((pCur) && (pCur->data < dataOut))
        pCur = pCur->next;

    if ((pCur) && (pCur->data == dataOut)) {
        dataOut = pCur->data;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList<TYPE>::viewFront(TYPE &dataOut) const {
    bool success = false;

    if (front) {
        dataOut = front->data;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList<TYPE>::viewRear(TYPE &dataOut) const {
    bool success = false;
    Node<TYPE> *pCur = front;

    while ((pCur) && (pCur->next))
        pCur = pCur->next;

    if (pCur) {
        dataOut = pCur->data;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
void LList<TYPE>::display() const {
    Node<TYPE> *pCur = front;

    while (pCur) {
        std::cout << pCur->data;

        if (pCur->next)
            std::cout << " -> ";

        pCur = pCur->next;
    }

    std::cout << std::endl;
}

//*****************************************************************************************************

template <typename TYPE>
int LList<TYPE>::getNumValues() const {
    int numVal = 0;
    Node<TYPE> *pCur = front;

    while (pCur) {
        numVal++;
        pCur = pCur->next;
    }

    return numVal;
}

//*****************************************************************************************************

template <typename TYPE>
bool LList<TYPE>::isEmpty() const {
    return (front == nullptr);
}

//*****************************************************************************************************

template <typename TYPE>
bool LList<TYPE>::isFull() const {
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

#endif