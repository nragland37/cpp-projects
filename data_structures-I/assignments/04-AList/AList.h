//*****************************************************************************************************
//
//      This header file defines a class template AList, which implements an array-based list data
//      structure with various methods for inserting and retrieving data.
//
//*****************************************************************************************************

#ifndef AList_H
#define AList_H

//*****************************************************************************************************

#include <new>

//*****************************************************************************************************

template <typename TYPE>
class AList {
private:
    TYPE *list;
    int capacity;
    int numValues;

    bool _resize();

public:
    AList(int cap = 5);
    ~AList();
    bool insertFront(const TYPE &dataIn);
    bool insertBack(const TYPE &dataIn);
    bool insertAtIndex(const TYPE &dataIn, int index);
    bool display() const;
    bool getSmallest(TYPE &dataOut) const;
    int getCapacity() const;
    int getNumValues() const;
    bool isEmpty() const;
    bool isFull() const;
};

//*****************************************************************************************************

template <typename TYPE>
AList<TYPE>::AList(int cap) {
    if (cap < 2)
        cap = 2;

    capacity = cap;
    numValues = 0;
    list = new TYPE[capacity];
}

//*****************************************************************************************************

template <typename TYPE>
AList<TYPE>::~AList() {
    delete[] list;
    list = nullptr;
    capacity = 0;
    numValues = 0;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::_resize() {
    bool success = false;
    TYPE *newList;
    int newCapacity;

    newCapacity = capacity * 2;
    newList = new (std::nothrow) TYPE[newCapacity];

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

template <typename TYPE>
bool AList<TYPE>::insertFront(const TYPE &dataIn) {
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

template <typename TYPE>
bool AList<TYPE>::insertBack(const TYPE &dataIn) {
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

template <typename TYPE>
bool AList<TYPE>::insertAtIndex(const TYPE &dataIn, int index) {
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

template <typename TYPE>
bool AList<TYPE>::display() const {
    bool success = false;

    if (numValues > 0) {
        for (int i = 0; i < numValues; ++i)
            std::cout << "[" << i << "] " << list[i] << "\t";

        std::cout << std::endl;

        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::getSmallest(TYPE &dataOut) const {
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

template <typename TYPE>
int AList<TYPE>::getCapacity() const {
    return capacity;
}

//*****************************************************************************************************

template <typename TYPE>
int AList<TYPE>::getNumValues() const {
    return numValues;
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::isEmpty() const {
    return (numValues == 0);
}

//*****************************************************************************************************

template <typename TYPE>
bool AList<TYPE>::isFull() const {
    return (numValues == capacity);
}

//*****************************************************************************************************

#endif