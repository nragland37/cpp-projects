//*****************************************************************************************************
//
//      This header file defines a templated struct that represents a node in a doubly linked list.
//
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node();
    Node(const T &d, Node<T> *n = nullptr, Node<T> *p = nullptr);
};

//*****************************************************************************************************

template <typename T>
Node<T>::Node() {
    data = T();     // T() - default initialization (0 for numbers, empty string for strings, etc.)
    next = nullptr;
    prev = nullptr;
}

//*****************************************************************************************************

template <typename T>
Node<T>::Node(const T &d, Node<T> *n, Node<T> *p) {
    data = d;
    next = n;
    prev = p;
}

//*****************************************************************************************************

#endif