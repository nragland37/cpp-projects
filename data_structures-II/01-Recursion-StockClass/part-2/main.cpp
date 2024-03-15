//*****************************************************************************************************   
//
//      This program demonstrates the Stock class by instantiating Stock objects and performing it's 
//      methods.
//
//      Other files required:
//        1.	 stock.h - header file for the Stock class
//
//*****************************************************************************************************

#include "stock.h"

#include <iostream>
using namespace std;

//*****************************************************************************************************

void compareStocks(const Stock &s1, const Stock &s2);

//*****************************************************************************************************

int main() {
    Stock apple("Apple Inc.", "AAPL", 150.25);
    Stock microsoft("Microsoft Corp.", "MSFT", 280.75);
    Stock appleCopy(apple);

    apple.display();
    microsoft.display();
    appleCopy.display();

    compareStocks(apple, microsoft);
    compareStocks(apple, appleCopy);

    return 0;
}

//*****************************************************************************************************

void compareStocks(const Stock &s1, const Stock &s2) {
    cout << "\n===============================" << endl;
    cout << s1.getName() << "\t" << s2.getName() << endl;
    cout << s1.getSymbol() << "\t\t" << s2.getSymbol() << endl;
    cout << s1.getPrice() << "\t\t" << s2.getPrice() << endl;

    if (s1 == s2)                                       // tests == operator overload
        cout << "\nThe stocks are the same." << endl;
    else if (s1 != s2)                                  // tests != operator overload
        cout << "\nThe stocks are different." << endl;
}

//*****************************************************************************************************
/*

Apple Inc.
AAPL
150.25
Microsoft Corp.
MSFT
280.75
Apple Inc.
AAPL
150.25

===============================
Apple Inc.      Microsoft Corp.
AAPL            MSFT
150.25          280.75

The stocks are different.

===============================
Apple Inc.      Apple Inc.
AAPL            AAPL
150.25          150.25

The stocks are the same.

*/
