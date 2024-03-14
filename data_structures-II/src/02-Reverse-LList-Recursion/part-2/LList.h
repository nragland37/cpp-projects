//*****************************************************************************************************
//
//      This header file defines a class template for a singly linked list with recursive methods.
//
//      Other files required:
//        1.    node.h - header file for the node struct of the linked list
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
    Node<T> *head;

    void _insertOrderRec(Node<T> *&head, const T &item);
    void _deleteNodeRec(Node<T> *&head, const T &item);
    void _display(Node<T> *head) const;

public:
    LList();
    ~LList();
    void insertOrder(const T &item);
    void deleteNode(const T &item);
    void display() const;
};

//*****************************************************************************************************

template <typename T>
LList<T>::LList() {
    head = nullptr;
}

//*****************************************************************************************************

template <typename T>
LList<T>::~LList() {
    Node<T> *pTemp = nullptr;

    while (head) {
        pTemp = head;
        head = head->next;
        delete pTemp;
    }

    head = nullptr;
}

//*****************************************************************************************************

template <typename T>
void LList<T>::_insertOrderRec(Node<T> *&pCur, const T &item) {
    if ((pCur == nullptr) || (item > pCur->value)) {
        Node<T> *pTemp = pCur;
        pCur = new (std::nothrow) Node<T>;
        pCur->value = item;
        pCur->next = pTemp;
    } else {
        _insertOrderRec(pCur->next, item);
    }
}

//*****************************************************************************************************

template <typename T>
void LList<T>::insertOrder(const T &item) {
    _insertOrderRec(head, item);
}

//*****************************************************************************************************

template <typename T>
void LList<T>::_deleteNodeRec(Node<T> *&pCur, const T &item) {
    if (pCur) {
        if (item == pCur->value) {
            Node<T> *pTemp = pCur;
            pCur = pCur->next;
            delete pTemp;
        } else {
            _deleteNodeRec(pCur->next, item);
        }
    }
}

//*****************************************************************************************************

template <typename T>
void LList<T>::deleteNode(const T &item) {
    _deleteNodeRec(head, item);
}

//*****************************************************************************************************

template <typename T>
void LList<T>::_display(Node<T> *head) const {
    if (head) {
        std::cout << head->value << std::endl;
        _display(head->next);
    }
}

//*****************************************************************************************************

template <typename T>
void LList<T>::display() const {
    _display(head);
}

//*****************************************************************************************************

#endif