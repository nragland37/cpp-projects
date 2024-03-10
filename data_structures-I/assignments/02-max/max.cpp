//*****************************************************************************************************
//
//      This program demonstrates the use of function templates and function overloading which is used 
//      when the operations need to be different for different types of data.
//
//*****************************************************************************************************

#include <cstring>
#include <iostream>
#include <typeinfo>
using namespace std;

//*****************************************************************************************************

template <typename T>
void getData(T &a, T &b);
void getData(char a[], char b[]);

template <typename T>
T findMax(T a, T b);
char *findMax(char a[], char b[]);

template <typename T>
void displayMax(T a, T b, T max);

//*****************************************************************************************************

int main() {
    int aInt,
        maxInt,
        bInt;
    double aDouble,
        bDouble,
        maxDouble;
    char aChar,
        bChar,
        maxChar;
    char aArray[100],
        bArray[100];
    char *maxArray;

    getData(aInt, bInt);
    getData(aDouble, bDouble);
    getData(aChar, bChar);
    getData(aArray, bArray);

    maxInt = findMax(aInt, bInt);
    maxDouble = findMax(aDouble, bDouble);
    maxChar = findMax(aChar, bChar);
    maxArray = findMax(aArray, bArray);

    displayMax(aInt, bInt, maxInt);
    displayMax(aDouble, bDouble, maxDouble);
    displayMax(aChar, bChar, maxChar);
    displayMax(aArray, bArray, maxArray);

    return 0;
}

//*****************************************************************************************************

template <typename T>
void getData(T &a, T &b) {
    cout << "\nEnter two " << typeid(T).name() << "s" << endl;

    cout << "First: ";
    cin >> a;

    cout << "Second: ";
    cin >> b;
}

//*****************************************************************************************************

void getData(char a[], char b[]) {
    cout << "\nEnter two c-strings" << endl;

    cout << "First: ";
    cin.ignore();
    cin.getline(a, 100);

    cout << "Second: ";
    cin.getline(b, 100);
}

//*****************************************************************************************************

template <typename T>
T findMax(T a, T b) {
    T max = a;

    if (max < b)
        max = b;

    return max;
}

//*****************************************************************************************************

char *findMax(char a[], char b[]) {
    char *max = a;

    if (strcmp(a, b) < 0)
        max = b;

    return max;
}

//*****************************************************************************************************

template <typename T>
void displayMax(T a, T b, T max) {
    cout << "\nType: " << typeid(T).name()
         << "\nFirst: " << a
         << "\nSecond: " << b
         << "\nMax: " << max << endl;
}

//*****************************************************************************************************
/*

Enter two ints
First: 1
Second: 2

Enter two doubles
First: 1.5
Second: 2.5

Enter two chars
First: a
Second: b

Enter two c-strings
First: apple
Second: orange

Type: int
First: 1
Second: 2
Max: 2

Type: double
First: 1.5
Second: 2.5
Max: 2.5

Type: char
First: a
Second: b
Max: b

Type: char *
First: apple
Second: orange
Max: orange

*/