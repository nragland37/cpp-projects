//*****************************************************************************************************
//
//      This header file defines a templated struct that represents a node in a linked list.
//
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename T>
struct Node {
    T data;
    Node<T> *next;

    Node();
    Node(const T &d, Node<T> *n = nullptr);
};

//*****************************************************************************************************

template <typename T>
Node<T>::Node() {
    data = T();     // default initialization for both user-defined and built-in types
    next = nullptr;
}

//*****************************************************************************************************

template <typename T>
Node<T>::Node(const T &d, Node<T> *n) {
    data = d;
    next = n;
}

//*****************************************************************************************************

#endif