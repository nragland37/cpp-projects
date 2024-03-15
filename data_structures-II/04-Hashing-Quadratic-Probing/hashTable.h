//*****************************************************************************************************
//
//      This header file defines a class template for a hash table with quadratic probing to resolve 
//      collisions when inserting and removing items.
//
//      Other files required:
//        1.    htElement.h - header file for the HTElement struct
//
//*****************************************************************************************************

#ifndef HASHTABLE_H
#define HASHTABLE_H

//*****************************************************************************************************

#include "htElement.h"
#include <iostream>

//*****************************************************************************************************

template <typename T>
class HashTable {
private:
    HTElement<T> *table;
    int size;
    int count;

    int _hash(const T &item) const;
    int _probe(const T &item) const;

public:
    HashTable(int size = 10);
    ~HashTable();
    void remove(const T &item);
    void insert(const T &item);
    void display() const;
    T *search(const T &item) const;
};

//*****************************************************************************************************

template <typename T>
HashTable<T>::HashTable(int size) {
    table = new HTElement<T>[size];
    this->size = size;
    count = 0;
}

//*****************************************************************************************************

template <typename T>
HashTable<T>::~HashTable() {
    delete[] table;
    table = nullptr;
}

//*****************************************************************************************************

template <typename T>
int HashTable<T>::_hash(const T &item) const {
    return item.hash(size);
}

//*****************************************************************************************************

template <typename T>
int HashTable<T>::_probe(const T &item) const {
    int index = _hash(item);
    int hashIndex = index;
    int i = 0;

    while ((table[index].status == 1 || table[index].status == -1) && (table[index].item != item)) {
        index = (hashIndex + (i * i)) % size;
        ++i;
    }

    return index;
}

//*****************************************************************************************************

template <typename T>
void HashTable<T>::remove(const T &item) {
    int index = _probe(item);

    if (table[index].status == 1) {
        table[index].status = -1;
        --count;
    }
}

//*****************************************************************************************************

template <typename T>
void HashTable<T>::insert(const T &item) {
    int index = _probe(item);

    if (table[index].status != 1) {
        table[index].item = item;
        table[index].status = 1;
        count++;
    }
}

//*****************************************************************************************************

template <typename T>
void HashTable<T>::display() const {
    for (int i = 0; i < size; ++i)
        if (table[i].status == 1)
            std::cout << table[i].item << std::endl;
}

//*****************************************************************************************************

template <typename T>
T *HashTable<T>::search(const T &item) const {
    int index = _probe(item);
    T *copy = nullptr;

    if (table[index].status == 1)
        copy = new T(table[index].item);

    return copy;
}

//*****************************************************************************************************

#endif