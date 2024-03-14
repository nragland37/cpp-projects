//*****************************************************************************************************
//
//      This header file defines a class template for an array-based list using a stack structure.
//      Last-in, first-out (LIFO) 
//
//*****************************************************************************************************

#ifndef STACK_H
#define STACK_H

//*****************************************************************************************************

template <typename T>
class Stack {
private:
    T *stack;
    int top;
    int capacity;

public:
    Stack(int cap = 100);
    ~Stack();
    bool push(const T &dataIn);
    bool pop(T &dataOut);
    bool peek(T &dataOut) const;
    int getNumValues() const;
    bool isFull() const;
    bool isEmpty() const;
};

//*****************************************************************************************************

template <typename T>
Stack<T>::Stack(int cap) {
    capacity = cap;
    top = -1;
    stack = new T[capacity];
}

//*****************************************************************************************************

template <typename T>
Stack<T>::~Stack() {
    delete[] stack;
    stack = nullptr;
    capacity = 0;
    top = -1;
}

//*****************************************************************************************************

template <typename T>
bool Stack<T>::push(const T &dataIn) {
    bool success = false;

    if ((top + 1) < capacity) {
        top++;
        stack[top] = dataIn;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool Stack<T>::pop(T &dataOut) {
    bool success = false;

    if (top >= 0) {
        dataOut = stack[top];
        top--;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
bool Stack<T>::peek(T &dataOut) const {
    bool success = false;

    if (top >= 0) {
        dataOut = stack[top];
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename T>
int Stack<T>::getNumValues() const {
    return (top + 1);
}

//*****************************************************************************************************

template <typename T>
bool Stack<T>::isFull() const {
    return ((top + 1) == capacity);
}

//*****************************************************************************************************

template <typename T>
bool Stack<T>::isEmpty() const {
    return (top < 0);
}

//*****************************************************************************************************

#endif