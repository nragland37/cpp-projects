//*****************************************************************************************************
//
//      This header file defines a class template called Dyad that stores two values and provides
//      methods for accessing and manipulating them.
//
//*****************************************************************************************************

#ifndef DYAD_H
#define DYAD_H

//*****************************************************************************************************

template <typename TYPE>
class Dyad {
private:
    TYPE val1;
    TYPE val2;

public:
    Dyad(TYPE v1 = 0, TYPE v2 = 0);
    TYPE getFirst() const;
    TYPE getSecond() const;
    void get2Values(TYPE &v1, TYPE &v2) const;
    void swapValues();
};

//*****************************************************************************************************

template <typename TYPE>
Dyad<TYPE>::Dyad(TYPE val1, TYPE val2) {
    this->val1 = val1;
    this->val2 = val2;
}

//*****************************************************************************************************

template <typename TYPE>
TYPE Dyad<TYPE>::getFirst() const {
    return val1;
}

//*****************************************************************************************************

template <typename TYPE>
TYPE Dyad<TYPE>::getSecond() const {
    return val2;
}

//*****************************************************************************************************

template <typename TYPE>
void Dyad<TYPE>::get2Values(TYPE &v1, TYPE &v2) const {
    v1 = val1;
    v2 = val2;
}

//*****************************************************************************************************

template <typename TYPE>
void Dyad<TYPE>::swapValues() {
    TYPE temp = val1;

    val1 = val2;
    val2 = temp;
}

//*****************************************************************************************************

#endif