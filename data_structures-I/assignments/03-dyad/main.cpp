//*****************************************************************************************************
//      
//      This program demonstrates the use of the Dyad class by instantiating objects of type int,
//      double, and char and performing its methods.
//
//      Other files required:
//        1.	 dyad.h - header file for the Dyad class
//
//*****************************************************************************************************

#include "dyad.h"

#include <iostream>
using namespace std;

//*****************************************************************************************************

int main() {
    int firstInt,
        secondInt;
    double firstDouble,
        secondDouble;
    char firstChar,
        secondChar;

    Dyad<int> dyadInt(1, 2);
    Dyad<double> dyadDouble(1.5, 2.5);
    Dyad<char> dyadChar('A', 'B');

    cout << "First int: " << dyadInt.getFirst()
         << "\nSecond int: " << dyadInt.getSecond() << endl;

    dyadInt.swapValues();
    dyadInt.get2Values(firstInt, secondInt);

    cout << "\nFirst int after swap: " << firstInt
         << "\nSecond int after swap: " << secondInt
         << "\n\nFirst double : " << dyadDouble.getFirst()
         << "\nSecond double: " << dyadDouble.getSecond() << endl;

    dyadDouble.swapValues();
    dyadDouble.get2Values(firstDouble, secondDouble);

    cout << "\nFirst double after swap: " << firstDouble
         << "\nSecond double after swap: " << secondDouble
         << "\n\nFirst char: " << dyadChar.getFirst()
         << "\nSecond char: " << dyadChar.getSecond() << endl;

    dyadChar.swapValues();
    dyadChar.get2Values(firstChar, secondChar);

    cout << "\nFirst char after swap: " << firstChar
         << "\nSecond char after swap: " << secondChar << endl;

    return 0;
}

//*****************************************************************************************************
/*

First int: 1
Second int: 2

First int after swap: 2
Second int after swap: 1

First double: 1.5
Second double: 2.5

First double after swap: 2.5
Second double after swap: 1.5

First char: A
Second char: B

First char after swap: B
Second char after swap: A

*/