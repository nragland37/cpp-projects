//*****************************************************************************************************
//
//      This header file defines a struct template that represents a node in a singly linked list.
//
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template <typename T>
struct Node {
    T value;
    Node<T> *next;

    Node();
    Node(const T &v, Node<T> *n = nullptr);
};

//*****************************************************************************************************

template <typename T>
Node<T>::Node() {
    value = T();     // T() - default initialization (0 for numbers, empty string for strings, etc.)
    next = nullptr;
}

//*****************************************************************************************************

template <typename T>
Node<T>::Node(const T &v, Node<T> *n) {
    value = v;
    next = n;
}

//*****************************************************************************************************

#endif