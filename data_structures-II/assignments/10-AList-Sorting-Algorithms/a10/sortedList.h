//*****************************************************************************************************
//
//      This header file defines a SortedList class with members and methods for sorting a list of
//      items using various sorting algorithms.
//
//*****************************************************************************************************

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

//*****************************************************************************************************

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <new>

//*****************************************************************************************************

template <typename T>
class SortedList {
private:
    T *list;
    int capacity;
    int numValues;

    void _resize();
    void _swap(T &a, T &b);
    int _partitionA(int first, int last);
    int _partitionD(int first, int last);
    void _quickSortA(int first, int last);
    void _quickSortD(int first, int last);

public:
    SortedList(int size = 10);
    ~SortedList();
    void insert(const T &item);
    void randomise();
    void selectionSortA();
    void selectionSortD();
    void quickSortA();
    void quickSortD();
    void display() const;
    int getNumValues() const;
    int getCapacity() const;
    bool isFull() const;
    bool isEmpty() const;
};

//*****************************************************************************************************

template <typename T>
SortedList<T>::SortedList(int size) {
    if (size < 10)
        size = 10;

    capacity = size;
    numValues = 0;
    list = new T[capacity];
}

//*****************************************************************************************************

template <typename T>
SortedList<T>::~SortedList() {
    delete[] list;
    capacity = 0;
    numValues = 0;
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::_resize() {
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
void SortedList<T>::_swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::insert(const T &item) {
    if (numValues == capacity)
        _resize();

    list[numValues] = item;
    ++numValues;
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::randomise() {
    static bool seeded = false;                     // static initializes only once per program 

    if (!seeded) {                                  // seed srand() only once for all objects
        srand(static_cast<unsigned>(time(0)));
        seeded = true;
    }

    for (int i = 0; i < numValues; ++i)
        _swap(list[i], list[rand() % numValues]);
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::selectionSortA() {
    int minIndex;

    for (int i = 0; i < numValues - 1; ++i) {
        minIndex = i;

        for (int j = i + 1; j < numValues; ++j)
            if (list[j] < list[minIndex])
                minIndex = j;
        _swap(list[i], list[minIndex]);
    }
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::selectionSortD() {
    int maxIndex;

    for (int i = 0; i < numValues - 1; ++i) {
        maxIndex = i;

        for (int j = i + 1; j < numValues; ++j)
            if (list[j] > list[maxIndex])
                maxIndex = j;
        _swap(list[i], list[maxIndex]);
    }
}

//*****************************************************************************************************

template <typename T>
int SortedList<T>::_partitionA(int first, int last) {
    T pivot = list[(first + last) / 2];
    _swap(list[first], list[(first + last) / 2]);
    int smallIndex = first;
    int index;

    for (int i = first + 1; i <= last; ++i) {
        index = i;

        if (list[index] < pivot) {
            ++smallIndex;
            _swap(list[index], list[smallIndex]);
        }
    }
    _swap(list[first], list[smallIndex]);

    return smallIndex;
}

//*****************************************************************************************************

template <typename T>
int SortedList<T>::_partitionD(int first, int last) {
    T pivot = list[(first + last) / 2];
    _swap(list[first], list[(first + last) / 2]);
    int smallIndex = first;
    int index;

    for (int i = first + 1; i <= last; ++i) {
        index = i;

        if (list[index] > pivot) {
            ++smallIndex;
            _swap(list[index], list[smallIndex]);
        }
    }
    _swap(list[first], list[smallIndex]);

    return smallIndex;
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::quickSortA() {
    _quickSortA(0, numValues - 1);
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::_quickSortA(int first, int last) {
    int pivotIndex;

    if (first < last) {
        pivotIndex = _partitionA(first, last);

        _quickSortA(first, pivotIndex - 1);
        _quickSortA(pivotIndex + 1, last);
    }
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::quickSortD() {
    _quickSortD(0, numValues - 1);
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::_quickSortD(int first, int last) {
    int pivotIndex;

    if (first < last) {
        pivotIndex = _partitionD(first, last);

        _quickSortD(first, pivotIndex - 1);
        _quickSortD(pivotIndex + 1, last);
    }
}

//*****************************************************************************************************

template <typename T>
void SortedList<T>::display() const {
    for (int i = 0; i < numValues; ++i)
        std::cout << list[i] << std::endl;
    std::cout << std::endl;
}

//*****************************************************************************************************

template <typename T>
inline int SortedList<T>::getNumValues() const {
    return numValues;
}
//*****************************************************************************************************

template <typename T>
inline int SortedList<T>::getCapacity() const {
    return capacity;
}

//*****************************************************************************************************

template <typename T>
inline bool SortedList<T>::isFull() const {
    return (numValues == capacity);
}

//*****************************************************************************************************

template <typename T>
inline bool SortedList<T>::isEmpty() const {
    return (numValues == 0);
}

//*****************************************************************************************************

#endif