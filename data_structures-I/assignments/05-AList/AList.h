//*****************************************************************************************************
//
//      This header file updates the AList class to include additional methods.
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
    bool removeFront(T &dataOut);
    bool removeBack(T &dataOut);
    bool removeAtIndex(T &dataOut, int index);
    bool remove(T &dataOut);
    bool retrieveFront(T &dataOut) const;
    bool retrieveBack(T &dataOut) const;
    bool retrieveAtIndex(T &dataOut, int index) const;
    bool retrieve(T &dataOut) const;
    bool updateFront(const T &dataIn);
    bool updateBack(const T &dataIn);
    bool updateAtIndex(const T &dataIn, int index);
    bool update(const T &dataIn);
    bool display() const;
    bool getSmallest(T &dataOut) const;
    int getCapacity() const;
    int getNumValues() const;
    bool isEmpty() const;
    bool isFull() const;
    bool clear();
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

    newCapacity = capacity + (capacity / 2);
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
        for (int i = numValues; i > 0; --i)
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
bool AList<T>::removeFront(T &dataOut) {
    bool success = false;

    if (numValues > 0) {
        dataOut = list[0];

        for (int i = 0; i < numValues - 1; ++i)
            list[i] = list[i + 1];

        numValues--;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::removeBack(T &dataOut) {
    bool success = false;

    if (numValues > 0) {
        dataOut = list[numValues - 1];
        numValues--;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::removeAtIndex(T &dataOut, int index) {
    bool success = false;

    if ((index >= 0) && (index < numValues)) {
        dataOut = list[index];

        for (int i = index; i < numValues - 1; ++i)
            list[i] = list[i + 1];

        numValues--;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::remove(T &dataOut) {
    bool success = false;

    for (int i = 0; i < (numValues) && (!success); ++i) {
        if (list[i] == dataOut) {
            dataOut = list[i];

            for (int j = i; j < numValues - 1; j++)
                list[j] = list[j + 1];

            numValues--;
            success = true;
        }
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::retrieveFront(T &dataOut) const {
    bool success = false;

    if (numValues > 0) {
        dataOut = list[0];
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::retrieveBack(T &dataOut) const {
    bool success = false;

    if (numValues > 0) {
        dataOut = list[numValues - 1];
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::retrieveAtIndex(T &dataOut, int index) const {
    bool success = false;

    if ((index >= 0) && (index < numValues)) {
        dataOut = list[index];
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::retrieve(T &dataOut) const {
    bool success = false;

    for (int i = 0; i < (numValues) && (!success); ++i)
        if (list[i] == dataOut) {
            dataOut = list[i];
            success = true;
        }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::updateFront(const T &dataIn) {
    bool success = false;

    if (numValues > 0) {
        list[0] = dataIn;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::updateBack(const T &dataIn) {
    bool success = false;

    if (numValues > 0) {
        list[numValues - 1] = dataIn;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::updateAtIndex(const T &dataIn, int index) {
    bool success = false;

    if ((index >= 0) && (index < numValues)) {
        list[index] = dataIn;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::update(const T &dataIn) {
    bool success = false;

    for (int i = 0; i < (numValues) && (!success); ++i)
        if (list[i] == dataIn) {
            list[i] = dataIn;
            success = true;
        }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool AList<T>::display() const {
    bool success = false;

    if (numValues > 0) {
        for (int i = 0; i < numValues; ++i)
            std::cout << "[" << i << "]  " << list[i] << std::endl;

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

template <typename T>
bool AList<T>::clear() {
    numValues = 0;
    return true;
}

//*****************************************************************************************************

#endif