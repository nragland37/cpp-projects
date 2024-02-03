//*****************************************************************************************************
//
//      This driver file tests the functions of the Stock class.
//
//      Other files required:
//          1.	 stock.h - header file for the Stock class
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
    cout << s1.getName() << " vs " << s2.getName() << endl;
    cout << s1.getSymbol() << "\t\t" << s2.getSymbol() << endl;
    cout << s1.getPrice() << "\t\t" << s2.getPrice() << endl;

    if (s1 == s2)                                           // tests == operator overload
        cout << "\nThe stocks are the same." << endl;
    else if (s1 != s2)                                      // tests != operator overload
        cout << "\nThe stocks are different." << endl;
}

//*****************************************************************************************************
/*

===============================
Company Name: Apple Inc.
Stock Symbol: AAPL
Price: $150.25
===============================
Company Name: Microsoft Corp.
Stock Symbol: MSFT
Price: $280.75
===============================
Company Name: Apple Inc.
Stock Symbol: AAPL
Price: $150.25

===============================
Apple Inc. vs Microsoft Corp.
-------------------------------
AAPL            MSFT
150.25          280.75

The stocks are different.

===============================
Apple Inc. vs Apple Inc.
-------------------------------
AAPL            AAPL
150.25          150.25

The stocks are the same.

*/
