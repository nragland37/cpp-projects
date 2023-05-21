//*****************************************************************************************************
//
//		File:					node.h
//
//		Student:				Nicholas Ragland
//
//		Assignment:				Assignment #12
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					May 3, 2023
//
//      This header file defines a templated struct that represents a node in a singly or doubly
//      linked list.
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
    data = 0;
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