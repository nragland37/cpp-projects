//*****************************************************************************************************
//
//      This header file defines a templated class for a stack data structure implemented using a
//      dynamically allocated array to store the elements of the stack.
//
//*****************************************************************************************************

#ifndef STACK_H
#define STACK_H

//*****************************************************************************************************

template <typename TYPE>
class Stack {
private:
    TYPE *stack;
    int top;
    int capacity;

public:
    Stack(int cap = 100);
    ~Stack();
    bool push(const TYPE &dataIn);
    bool pop(TYPE &dataOut);
    bool peek(TYPE &dataOut) const;
    int getNumValues() const;
    bool isFull() const;
    bool isEmpty() const;
};

//*****************************************************************************************************

template <typename TYPE>
Stack<TYPE>::Stack(int cap) {
    capacity = cap;
    top = -1;
    stack = new TYPE[capacity];
}

//*****************************************************************************************************

template <typename TYPE>
Stack<TYPE>::~Stack() {
    delete[] stack;
    stack = nullptr;
    capacity = 0;
    top = -1;
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::push(const TYPE &dataIn) {
    bool success = false;

    if ((top + 1) < capacity) {
        top++;
        stack[top] = dataIn;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::pop(TYPE &dataOut) {
    bool success = false;

    if (top >= 0) {
        dataOut = stack[top];
        top--;
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::peek(TYPE &dataOut) const {
    bool success = false;

    if (top >= 0) {
        dataOut = stack[top];
        success = true;
    }

    return success;
}

//*****************************************************************************************************

template <typename TYPE>
int Stack<TYPE>::getNumValues() const {
    return (top + 1);
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::isFull() const {
    return ((top + 1) == capacity);
}

//*****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE>::isEmpty() const {
    return (top < 0);
}

//*****************************************************************************************************

#endif