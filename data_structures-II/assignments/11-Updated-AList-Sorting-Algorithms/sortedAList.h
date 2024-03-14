//*****************************************************************************************************
//
//      This header file updates the sortedAList class to include the following sorting algorithms:
//      selection, quick, heap sort
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
class sortedAList {
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
    void _heapifyA(int n, int root);
    void _heapifyD(int n, int root);

public:
    sortedAList(int size = 10);
    ~sortedAList();
    void insert(const T &item);
    void randomise();
    void selectionSortA();
    void selectionSortD();
    void quickSortA();
    void quickSortD();
    void heapSortA();
    void heapSortD();
    void display() const;
    int getNumValues() const;
    int getCapacity() const;
    bool isFull() const;
    bool isEmpty() const;
};

//*****************************************************************************************************

template <typename T>
sortedAList<T>::sortedAList(int size) {
    capacity = (size < 10) ? 10 : size;
    numValues = 0;
    list = new T[capacity];
}

//*****************************************************************************************************

template <typename T>
sortedAList<T>::~sortedAList() {
    delete[] list;
    capacity = 0;
    numValues = 0;
}

//*****************************************************************************************************

template <typename T>
void sortedAList<T>::_resize() {
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
void sortedAList<T>::_swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

//*****************************************************************************************************

template <typename T>
void sortedAList<T>::insert(const T &item) {
    if (numValues == capacity)
        _resize();
    list[numValues] = item;
    ++numValues;
}

//*****************************************************************************************************

template <typename T>
void sortedAList<T>::randomise() {
    static bool seeded = false;     // static initializes only once per program

    if (!seeded) {     // seed srand() only once for all objects
        srand(static_cast<unsigned>(time(0)));
        seeded = true;
    }

    for (int i = 0; i < numValues; ++i)
        _swap(list[i], list[rand() % numValues]);
}

//*****************************************************************************************************
// selection sort algorithm (time complexity: O(n^2)

template <typename T>
void sortedAList<T>::selectionSortA() {     // min index - ascending
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
void sortedAList<T>::selectionSortD() {     // max index - descending
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
int sortedAList<T>::_partitionA(int first, int last) {     // smallest index - ascending
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
int sortedAList<T>::_partitionD(int first, int last) {     // largest index - descending
    T pivot = list[(first + last) / 2];
    _swap(list[first], list[(first + last) / 2]);
    int largeIndex = first;
    int index;

    for (int i = first + 1; i <= last; ++i) {
        index = i;

        if (list[index] > pivot) {
            ++largeIndex;
            _swap(list[index], list[largeIndex]);
        }
    }
    _swap(list[first], list[largeIndex]);

    return largeIndex;
}

//*****************************************************************************************************

template <typename T>
void sortedAList<T>::quickSortA() {
    _quickSortA(0, numValues - 1);
}

//*****************************************************************************************************
// quick sort algorithm (time complexity: O(n log n)

template <typename T>
void sortedAList<T>::_quickSortA(int first, int last) {
    int pivotIndex;

    if (first < last) {
        pivotIndex = _partitionA(first, last);

        _quickSortA(first, pivotIndex - 1);
        _quickSortA(pivotIndex + 1, last);
    }
}

//*****************************************************************************************************

template <typename T>
void sortedAList<T>::quickSortD() {
    _quickSortD(0, numValues - 1);
}

//*****************************************************************************************************

template <typename T>
void sortedAList<T>::_quickSortD(int first, int last) {
    int pivotIndex;

    if (first < last) {
        pivotIndex = _partitionD(first, last);

        _quickSortD(first, pivotIndex - 1);
        _quickSortD(pivotIndex + 1, last);
    }
}

//*****************************************************************************************************

template <typename T>
void sortedAList<T>::_heapifyA(int n, int root) {     // max heap - largest element at root
    int largest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;

    if (l < n && list[l] > list[largest])
        largest = l;

    if (r < n && list[r] > list[largest])
        largest = r;

    if (largest != root) {
        _swap(list[root], list[largest]);
        _heapifyA(n, largest);
    }
}

//*****************************************************************************************************

template <typename T>
void sortedAList<T>::_heapifyD(int n, int root) {     // min heap - smallest element at root
    int smallest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;

    if ((l < n) && (list[l] < list[smallest]))
        smallest = l;

    if (r < n && list[r] < list[smallest])
        smallest = r;

    if (smallest != root) {
        _swap(list[root], list[smallest]);
        _heapifyD(n, smallest);
    }
}

//*****************************************************************************************************
// heap sort algorithm (time complexity: O(n log n)

template <typename T>
void sortedAList<T>::heapSortA() {
    int n = numValues;

    for (int i = n / 2 - 1; i >= 0; --i)
        _heapifyA(n, i);

    for (int i = n - 1; i >= 0; --i) {
        _swap(list[0], list[i]);
        _heapifyA(i, 0);
    }
}

//*****************************************************************************************************

template <typename T>
void sortedAList<T>::heapSortD() {
    int n = numValues;

    for (int i = n / 2 - 1; i >= 0; --i)
        _heapifyD(n, i);

    for (int i = n - 1; i >= 0; --i) {
        _swap(list[0], list[i]);
        _heapifyD(i, 0);
    }
}

//*****************************************************************************************************

template <typename T>
void sortedAList<T>::display() const {
    for (int i = 0; i < numValues; ++i)
        std::cout << list[i] << std::endl;
}

//*****************************************************************************************************

template <typename T>
inline int sortedAList<T>::getNumValues() const {
    return numValues;
}
//*****************************************************************************************************

template <typename T>
inline int sortedAList<T>::getCapacity() const {
    return capacity;
}

//*****************************************************************************************************

template <typename T>
inline bool sortedAList<T>::isFull() const {
    return (numValues == capacity);
}

//*****************************************************************************************************

template <typename T>
inline bool sortedAList<T>::isEmpty() const {
    return (numValues == 0);
}

//*****************************************************************************************************

#endif