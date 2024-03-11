//*****************************************************************************************************
//
//      This header file defines a class template for an array-based list.
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

    bool _resize();

public:
    AList(int cap = 5);
    ~AList();
    bool insertFront(const T &dataIn);
    bool insertBack(const T &dataIn);
    bool insertAtIndex(const T &dataIn, int index);
    bool display() const;
    bool getSmallest(T &dataOut) const;
    int getCapacity() const;
    int getNumValues() const;
    bool isEmpty() const;
    bool isFull() const;
};

//*****************************************************************************************************

template <typename T>
AList<T>::AList(int cap) {
    if (cap < 2)
        cap = 2;

    capacity = cap;
    numValues = 0;
    list = new T[capacity];
}

//*****************************************************************************************************

template <typename T>
AList<T>::~AList() {
    delete[] list;
    list = nullptr;
    capacity = 0;
    numValues = 0;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::_resize() {
    bool success = false;
    T *newList;
    int newCapacity;

    newCapacity = capacity * 2;
    newList = new (std::nothrow) T[newCapacity];

    if (newList) {
        for (int i = 0; i < numValues; ++i)
            newList[i] = list[i];

        delete[] list;
        list = newList;
        capacity = newCapacity;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::insertFront(const T &dataIn) {
    bool success = true;

    if (numValues == capacity)
        success = _resize();

    if (success) {
        for (int i = numValues; i > 0; i--)
            list[i] = list[i - 1];

        list[0] = dataIn;
        numValues++;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::insertBack(const T &dataIn) {
    bool success = true;

    if (numValues == capacity)
        success = _resize();

    if (success) {
        list[numValues] = dataIn;
        numValues++;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::insertAtIndex(const T &dataIn, int index) {
    bool success = false;

    if ((index >= 0) && (index <= numValues)) {
        success = true;

        if (numValues == capacity)
            success = _resize();

        if (success) {
            for (int i = numValues; i > index; --i)
                list[i] = list[i - 1];

            list[index] = dataIn;
            numValues++;
        }
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::display() const {
    bool success = false;

    if (numValues > 0) {
        for (int i = 0; i < numValues; ++i)
            std::cout << "[" << i << "] " << list[i] << std::endl;

        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::getSmallest(T &dataOut) const {
    bool success = false;

    if (numValues > 0) {
        dataOut = list[0];

        for (int i = 1; i < numValues; ++i)
            if (list[i] < dataOut)
                dataOut = list[i];

        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
int AList<T>::getCapacity() const {
    return capacity;
}

//*****************************************************************************************************

template <typename T>
int AList<T>::getNumValues() const {
    return numValues;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::isEmpty() const {
    return (numValues == 0);
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::isFull() const {
    return (numValues == capacity);
}

//*****************************************************************************************************

#endif