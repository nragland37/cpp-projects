//*****************************************************************************************************
//
//      This header file defines a class template for an array-based priority queue list using a max 
//      heap structure. 
//
//*****************************************************************************************************

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

//*****************************************************************************************************

#include <iostream>
#include <new>

//*****************************************************************************************************

template <typename T>
class PriorityQueue {
private:
    T *list;
    int capacity;
    int numValues;

    bool _resize(int size);
    void _heapify(int i);

public:
    PriorityQueue(int size = 12);
    ~PriorityQueue();
    bool enqueue(const T &value);
    bool dequeue(T &value);
    void display() const;
    int getNumValues() const;
    int getCapacity() const;
    bool isEmpty() const;
    bool isFull() const;
    void clear();
};

//*****************************************************************************************************

template <typename T>
PriorityQueue<T>::PriorityQueue(int size) {
    if (size < 12)
        size = 12;

    capacity = size;
    numValues = 0;
    list = new T[capacity];
}

//*****************************************************************************************************

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    delete[] list;
    capacity = 0;
    numValues = 0;
}

//*****************************************************************************************************

template <typename T>
bool PriorityQueue<T>::_resize(int size) {
    bool success = false;
    int newCapacity;
    T *newList = nullptr;

    newCapacity = capacity + size;
    newList = new (std::nothrow) T[newCapacity];

    if (newList) {
        for (int i = 0; i < numValues; ++i)
            newList[i] = list[i];

        delete[] list;
        list = newList;
        capacity = newCapacity;
        success = true;
    } else {
        std::cerr << "\nError: memory allocation failed\n";
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
void PriorityQueue<T>::_heapify(int i) {
    bool stop = false;
    int leftChild,
        rightChild,
        largest;
    T temp = list[i];

    leftChild = i * 2 + 1;

    while ((leftChild < numValues) && (!stop)) {
        rightChild = leftChild + 1;

        if (rightChild >= numValues)
            largest = leftChild;
        else if (list[leftChild] > list[rightChild])
            largest = leftChild;
        else
            largest = rightChild;

        if (list[largest] > temp) {
            list[i] = list[largest];
            i = largest;
            leftChild = i * 2 + 1;
        } else {
            stop = true;
        }
    }
    list[i] = temp;
}

//*****************************************************************************************************

template <typename T>
bool PriorityQueue<T>::enqueue(const T &value) {
    bool success = true;
    int child,
        parent;

    child = numValues;
    parent = (child - 1) / 2;

    if (numValues == capacity)
        success = _resize(10);

    if (success) {
        while ((child > 0) && (value > list[parent])) {
            list[child] = list[parent];
            child = parent;
            parent = (parent - 1) / 2;
        }
        list[child] = value;
        ++numValues;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool PriorityQueue<T>::dequeue(T &value) {
    bool success = false;

    if (numValues > 0) {
        value = list[0];
        list[0] = list[numValues - 1];
        --numValues;
        success = true;
        _heapify(0);
    }

    if (((capacity - numValues) >= 10) && ((capacity - 10) >= 12)) 
        success = _resize(-10);

    return success;
}

//*****************************************************************************************************

template <typename T>
void PriorityQueue<T>::display() const {
    for (int i = 0; i < numValues; ++i)
        std::cout << list[i] << std::endl;
}

//*****************************************************************************************************

template <typename T>
inline int PriorityQueue<T>::getNumValues() const {
    return numValues;
}

//*****************************************************************************************************

template <typename T>
inline int PriorityQueue<T>::getCapacity() const {
    return capacity;
}

//*****************************************************************************************************

template <typename T>
inline bool PriorityQueue<T>::isEmpty() const {
    return (numValues == 0);
}

//*****************************************************************************************************

template <typename T>
inline bool PriorityQueue<T>::isFull() const {
    return (numValues == capacity);
}

//*****************************************************************************************************

template <typename T>
inline void PriorityQueue<T>::clear() {
    numValues = 0;
}

//*****************************************************************************************************

#endif