//*****************************************************************************************************
//
//      This header file defines a class template for a binary search tree (BST) with recursive
//      methods. Includes in-order, pre-order, and post-order traversal methods for displaying the
//      tree in various orders.
//
//      Other files required:
//        1.    node.h - header file for the Node struct for use in the BST class
//
//*****************************************************************************************************

#ifndef BST_H
#define BST_H

//*****************************************************************************************************

#include "node.h"
#include <iostream>

//*****************************************************************************************************

template <typename T>
class BST {
private:
    Node<T> *root;

    int _max(int a, int b) const;
    void _deleteTree(Node<T> *&root);
    void _insert(Node<T> *&root, const T &item);
    void _inOrder(Node<T> *root, std::ostream &out) const;
    void _preOrder(Node<T> *root, std::ostream &out) const;
    void _postOrder(Node<T> *root, std::ostream &out) const;
    T *_search(Node<T> *root, const T &item) const;
    int _height(Node<T> *root) const;
    // Node<T> *_findMin(Node<T> *root);

public:
    BST();
    ~BST();
    void destroy();
    void insert(const T &item);
    void inOrder(std::ostream &out = std::cout) const;
    void preOrder(std::ostream &out = std::cout) const;
    void postOrder(std::ostream &out = std::cout) const;
    T *search(const T &item) const;
    int height() const;
};

//*****************************************************************************************************

template <typename T>
BST<T>::BST() {
    root = nullptr;
}

//*****************************************************************************************************

template <typename T>
BST<T>::~BST() {
    _deleteTree(root);
}

//*****************************************************************************************************

template <typename T>
int BST<T>::_max(int a, int b) const {
    return (a > b) ? a : b;
}

//*****************************************************************************************************

template <typename T>
void BST<T>::destroy() {
    _deleteTree(root);
}

//*****************************************************************************************************

template <typename T>
void BST<T>::_deleteTree(Node<T> *&root) {
    if (root != nullptr) {
        _deleteTree(root->left);
        _deleteTree(root->right);
        delete root;
        root = nullptr;
    }
}

//*****************************************************************************************************

template <typename T>
void BST<T>::insert(const T &item) {
    _insert(root, item);
}

//*****************************************************************************************************

template <typename T>
void BST<T>::_insert(Node<T> *&root, const T &item) {
    if (root == nullptr)
        root = new Node<T>(item);
    else if (item < root->value)
        _insert(root->left, item);
    else if (item > root->value)
        _insert(root->right, item);
    else
        std::cerr << "\nError: duplicate value\n";
}

//*****************************************************************************************************

template <typename T>
void BST<T>::inOrder(std::ostream &out) const {
    _inOrder(root, out);
}

//*****************************************************************************************************

template <typename T>
void BST<T>::_inOrder(Node<T> *root, std::ostream &out) const {
    if (root != nullptr) {
        _inOrder(root->left, out);
        out << root->value << std::endl;
        _inOrder(root->right, out);
    }
}

//*****************************************************************************************************

template <typename T>
void BST<T>::preOrder(std::ostream &out) const {
    _preOrder(root, out);
}

//*****************************************************************************************************

template <typename T>
void BST<T>::_preOrder(Node<T> *root, std::ostream &out) const {
    if (root != nullptr) {
        out << root->value << std::endl;
        _preOrder(root->left, out);
        _preOrder(root->right, out);
    }
}

//*****************************************************************************************************

template <typename T>
void BST<T>::postOrder(std::ostream &out) const {
    _postOrder(root, out);
}

//*****************************************************************************************************

template <typename T>
void BST<T>::_postOrder(Node<T> *root, std::ostream &out) const {
    if (root != nullptr) {
        _postOrder(root->left, out);
        _postOrder(root->right, out);
        out << root->value << std::endl;
    }
}

//*****************************************************************************************************

template <typename T>
T *BST<T>::search(const T &item) const {
    return _search(root, item);
}

//*****************************************************************************************************

template <typename T>
T *BST<T>::_search(Node<T> *root, const T &item) const {
    T *result = nullptr;

    if (root != nullptr) {
        if (item > root->value)
            result = _search(root->right, item);
        else if (item < root->value)
            result = _search(root->left, item);
        else
            result = new T(root->value);
    }

    return result;
}

//*****************************************************************************************************

template <typename T>
int BST<T>::height() const {
    return _height(root);
}

//*****************************************************************************************************

template <typename T>
int BST<T>::_height(Node<T> *root) const {
    int result = 0;

    if (root != nullptr)
        result = 1 + _max(_height(root->left), _height(root->right));

    return result;
}

//*****************************************************************************************************

// template <typename T>
// Node<T> *_findMin(Node<T> *root) {
//     Node<T> *result = nullptr;

//     if (root) {
//         if (root->left == nullptr)
//             result = root;
//         else
//             result = _findMin(root->left);
//     }
//     return result;
// }

//*****************************************************************************************************

#endif