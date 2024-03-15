//*****************************************************************************************************
//
//      This header file updates the AList class to include additional methods for removing an item
//      and a range of items from the list. 
//
//*****************************************************************************************************

#ifndef ALIST_H
#define ALIST_H

//*****************************************************************************************************

#include <iostream>
#include <new>

//*****************************************************************************************************

template <typename T>
class AList {
private:
    T *list;
    int capacity;
    int numValues;

    void _resize();
    int _binarySearchRec(const T &item, int start, int end) const;

public:
    AList(int size = 10);
    ~AList();
    AList(const AList<T> &AList);
    void insert(const T &item);
    bool remove(const T &item);
    bool removeRange(int start, int end);
    bool isFull() const;
    bool isEmpty() const;
    int listSize() const;
    int listCap() const;
    void print(std::ostream &out = std::cout) const;
    int binarySearch(const T &item) const;
};

//*****************************************************************************************************

template <typename T>
AList<T>::AList(int size) {
    capacity = size < 2 ? 2 : size;
    numValues = 0;
    list = new T[capacity];
}

//*****************************************************************************************************

template <typename T>
AList<T>::~AList() {
    delete[] list;
    capacity = 0;
    numValues = 0;
}

//*****************************************************************************************************

template <typename T>
AList<T>::AList(const AList<T> &AList) {
    capacity = AList.capacity;
    numValues = AList.numValues;
    list = new T[capacity];

    for (int i = 0; i < numValues; ++i)
        list[i] = AList.list[i];
}

//*****************************************************************************************************

template <typename T>
void AList<T>::_resize() {
    T *newList;
    int newCapacity;

    newCapacity = capacity + 10;
    newList = new (std::nothrow) T[newCapacity];

    if (newList) {
        for (int i = 0; i < numValues; ++i)
            newList[i] = list[i];

        delete[] list;
        list = newList;
        capacity = newCapacity;
    } else {
        std::cerr << "memory allocation failed during resizing\n";
    }
}

//*****************************************************************************************************

template <typename T>
void AList<T>::insert(const T &item) {
    int i = numValues - 1;

    if (numValues == capacity)
        _resize();

    while (i >= 0 && item < list[i])                    // < ascending, > descending
    {
        list[i + 1] = list[i];
        --i;
    }

    list[i + 1] = item;
    ++numValues;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::remove(const T &item) {
    bool success = false;
    int i = binarySearch(item);

    while (i != -1) {
        while (i < numValues - 1) {
            list[i] = list[i + 1];
            ++i;
        }

        --numValues;
        success = true;

        i = binarySearch(item);                         // remove all instances of item
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::removeRange(int start, int end) {
    bool success = false;
    int range = (end - start) + 1;

    if (start >= 0 && end < numValues && range > 0) {
        while (end < numValues) {
            list[start] = list[end + 1];
            ++start;
            ++end;
        }

        numValues -= range;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::isFull() const {
    return (numValues == capacity);
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::isEmpty() const {
    return (numValues == 0);
}

//*****************************************************************************************************

template <typename T>
int AList<T>::listSize() const {
    return numValues;
}

//*****************************************************************************************************

template <typename T>
int AList<T>::listCap() const {
    return capacity;
}

//*****************************************************************************************************

template <typename T>
void AList<T>::print(std::ostream &out) const {
    for (int i = 0; i < numValues; ++i)
        out << list[i] << std::endl;
}

//*****************************************************************************************************

template <typename T>
int AList<T>::_binarySearchRec(const T &item, int start, int end) const {
    int mid = (start + end) / 2;

    if (start <= end) {
        if (item == list[mid])
            return mid;
        else if (item < list[mid])                          // < ascending, > descending
            return _binarySearchRec(item, start, mid - 1);
        else
            return _binarySearchRec(item, mid + 1, end);
    }

    return -1;
}

//*****************************************************************************************************

template <typename T>
int AList<T>::binarySearch(const T &item) const {
    return _binarySearchRec(item, 0, numValues - 1);
}

//*****************************************************************************************************

#endif