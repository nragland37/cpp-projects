//*****************************************************************************************************
//
//      This header file defines a class template for managing a self-balancing binary search tree 
//      (AVL tree). Self-balancing is achieved by maintaining a balance factor for each node in the
//      tree. The tree is rebalanced after each insertion and deletion operation.
//
//      Other files required:
//        1.    node.h - header file for the Node struct for use in the BST class
//
//*****************************************************************************************************

#ifndef AVLTREE_H
#define AVLTREE_H

//*****************************************************************************************************

#include "node.h"
#include <iostream>

//*****************************************************************************************************

template <typename T>
class AVLTree {
private:
    Node<T> *root;

    int _max(int a, int b) const;
    void _deleteTree(Node<T> *&r);
    void _insert(Node<T> *&r, const T &item);
    void _inOrder(Node<T> *root, std::ostream &out) const;
    void _preOrder(Node<T> *root, std::ostream &out) const;
    void _postOrder(Node<T> *root, std::ostream &out) const;
    T *_search(Node<T> *r, const T &item) const;
    int _height(Node<T> *root) const;
    int _getBalance(Node<T> *r) const;
    void _rotateLeft(Node<T> *&k1);
    void _rotateRight(Node<T> *&k1);
    void _updatebFactors(Node<T> *r);

public:
    AVLTree();
    ~AVLTree();
    void destroy();
    void insert(const T &item);
    void inorder(std::ostream &out = std::cout) const;
    void preorder(std::ostream &out = std::cout) const;
    void postorder(std::ostream &out = std::cout) const;
    T *search(const T &item) const;
    int height() const;
};

//*****************************************************************************************************

template <typename T>
AVLTree<T>::AVLTree() {
    root = nullptr;
}

//*****************************************************************************************************

template <typename T>
AVLTree<T>::~AVLTree() {
    destroy();
}

//*****************************************************************************************************

template <typename T>
int AVLTree<T>::_max(int a, int b) const {
    return (a > b) ? a : b;
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::destroy() {
    _deleteTree(root);
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::_deleteTree(Node<T> *&r) {
    if (r) {
        _deleteTree(r->left);
        _deleteTree(r->right);
        delete r;
        r = nullptr;
    }
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::insert(const T &item) {
    _insert(root, item);
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::_insert(Node<T> *&r, const T &item) {
    if (!r) {
        r = new Node<T>;

        r->value = item;
        r->left = nullptr;
        r->right = nullptr;
    } else {
        if (item < r->value)
            _insert(r->left, item);
        else
            _insert(r->right, item);
    }

    r->bFactor = _getBalance(r);

    if (r->bFactor > 1) {
        if (r->left->bFactor > 0) {
            _rotateRight(r);
        } else {
            _rotateLeft(r->left);
            _rotateRight(r);
        }
        _updatebFactors(r);
    } else if (r->bFactor < -1) {
        if (r->right->bFactor < 0) {
            _rotateLeft(r);
        } else {
            _rotateRight(r->right);
            _rotateLeft(r);
        }
        _updatebFactors(r);
    }
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::inorder(std::ostream &out) const {
    _inOrder(root, out);
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::_inOrder(Node<T> *r, std::ostream &out) const {
    if (r) {
        _inOrder(r->left, out);
        out << r->value << "\t\t(BF: " << r->bFactor << ")" << std::endl;
        _inOrder(r->right, out);
    }
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::preorder(std::ostream &out) const {
    _preOrder(root, out);
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::_preOrder(Node<T> *r, std::ostream &out) const {
    if (r) {
        out << r->value << "\t\t(BF: " << r->bFactor << ")" << std::endl;
        _preOrder(r->left, out);
        _preOrder(r->right, out);
    }
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::postorder(std::ostream &out) const {
    _postOrder(root, out);
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::_postOrder(Node<T> *r, std::ostream &out) const {
    if (r) {
        _postOrder(r->left, out);
        _postOrder(r->right, out);
        out << r->value << "\t\t(BF: " << r->bFactor << ")" << std::endl;
    }
}

//*****************************************************************************************************

template <typename T>
T *AVLTree<T>::search(const T &item) const {
    return _search(root, item);
}

//*****************************************************************************************************

template <typename T>
T *AVLTree<T>::_search(Node<T> *r, const T &item) const {
    T *result = nullptr;

    if (r) {
        if (item > r->value)
            result = _search(r->right, item);
        else if (item < r->value)
            result = _search(r->left, item);
        else
            result = new T(r->value);
    }

    return result;
}

//*****************************************************************************************************

template <typename T>
int AVLTree<T>::height() const {
    return _height(root);
}

//*****************************************************************************************************

template <typename T>
int AVLTree<T>::_height(Node<T> *r) const {
    int result = 0;

    if (r)
        result = 1 + _max(_height(r->left), _height(r->right));

    return result;
}

//*****************************************************************************************************

template <typename T>
int AVLTree<T>::_getBalance(Node<T> *r) const {
    int result = 0;

    if (r)
        result = _height(r->left) - _height(r->right);

    return result;
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::_rotateLeft(Node<T> *&k1) {
    Node<T> *k2 = k1->right;

    k1->right = k2->left;
    k2->left = k1;
    k1 = k2;
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::_rotateRight(Node<T> *&k1) {
    Node<T> *k2 = k1->left;

    k1->left = k2->right;
    k2->right = k1;
    k1 = k2;
}

//*****************************************************************************************************

template <typename T>
void AVLTree<T>::_updatebFactors(Node<T> *r) {
    if (r) {
        r->bFactor = _getBalance(r);
        _updatebFactors(r->left);
        _updatebFactors(r->right);
    }
}

//*****************************************************************************************************

#endif