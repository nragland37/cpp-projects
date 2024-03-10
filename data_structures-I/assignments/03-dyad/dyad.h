//*****************************************************************************************************
//
//      This header file defines a class template for a dyad, which is a pair of values of the same 
//      type.
//
//*****************************************************************************************************

#ifndef DYAD_H
#define DYAD_H

//*****************************************************************************************************

template <typename T>
class Dyad {
private:
    T val1;
    T val2;

public:
    Dyad(T v1 = 0, T v2 = 0);
    T getFirst() const;
    T getSecond() const;
    void get2Values(T &v1, T &v2) const;
    void swapValues();
};

//*****************************************************************************************************

template <typename T>
Dyad<T>::Dyad(T val1, T val2) {
    this->val1 = val1;
    this->val2 = val2;
}

//*****************************************************************************************************

template <typename T>
T Dyad<T>::getFirst() const {
    return val1;
}

//*****************************************************************************************************

template <typename T>
T Dyad<T>::getSecond() const {
    return val2;
}

//*****************************************************************************************************

template <typename T>
void Dyad<T>::get2Values(T &v1, T &v2) const {
    v1 = val1;
    v2 = val2;
}

//*****************************************************************************************************

template <typename T>
void Dyad<T>::swapValues() {
    T temp = val1;

    val1 = val2;
    val2 = temp;
}

//*****************************************************************************************************

#endif