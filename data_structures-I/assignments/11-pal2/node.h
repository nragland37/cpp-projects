//*****************************************************************************************************
//
//      This header file defines a templated struct that represents a node in a linked list.
//
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename TYPE>
struct Node {
    TYPE data;
    Node<TYPE> *next;
    Node<TYPE> *prev;

    Node();
    Node(const TYPE &d, Node<TYPE> *n = nullptr, Node<TYPE> *p = nullptr);
};

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node() {
    data = TYPE();                // default initialization for both user-defined and built-in types
    next = nullptr;
    prev = nullptr;
}

//*****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node(const TYPE &d, Node<TYPE> *n, Node<TYPE> *p) {
    data = d;
    next = n;
    prev = p;
}

//*****************************************************************************************************

#endif