//*****************************************************************************************************
//
//      This program demonstrates the LList class by instantiating a singly linked list of Stock 
//      objects and performing it's methods.
//
//      Other files required:
//          1.    LList.h - header file for the LList class
//          2.    stock.h - header file for the Stock class (includes implementation file: stock.cpp)
//
//*****************************************************************************************************

#include "LList.h"
#include "stock.h"

#include <iostream>
using namespace std;

//*****************************************************************************************************

void compareStocks(const Stock &s1, const Stock &s2);
void deleteStock(LList<Stock> &stockList, const Stock &s);

//*****************************************************************************************************

int main() {
    LList<Stock> stockList;

    Stock s1("Apple Inc.", "AAPL", 150.50);
    Stock s2("Microsoft Corp.", "MSFT", 230.20);
    Stock s3("Tesla, Inc.", "TSLA", 625.90);
    Stock s4("Amazon.com, Inc.", "AMZN", 3400.50);
    Stock s5("Facebook, Inc.", "FB", 350.50);
    Stock s6(s1);

    stockList.insertOrder(s1);
    stockList.insertOrder(s2);
    stockList.insertOrder(s3);
    stockList.insertOrder(s4);
    stockList.insertOrder(s5);
    stockList.insertOrder(s6);

    stockList.display();

    deleteStock(stockList, s3);
    deleteStock(stockList, s4);

    compareStocks(s1, s2);
    compareStocks(s1, s6);

    return 0;
}

//*****************************************************************************************************

void compareStocks(const Stock &s1, const Stock &s2) {
    string s1Name = s1.getName(), s2Name = s2.getName();

    cout << "\n===============================" << endl;
    cout << s1Name << "\t" << s2Name << endl;
    cout << s1.getSymbol() << "\t\t" << s2.getSymbol() << endl;
    cout << s1.getPrice() << "\t\t" << s2.getPrice() << endl;

    if (s1 == s2) {
        cout << "Stocks are equal\n" << endl;
    } else if (s1 != s2) {
        cout << "Stocks are not equal" << endl;

        if (s1 > s2) {
            cout << s1Name << " is greater than " << s2Name << endl;
        } else if (s1 < s2) {
            cout << s1Name << " is less than " << s2Name << endl;
        }
    }
}

//*****************************************************************************************************

void deleteStock(LList<Stock> &stockList, const Stock &s) {
    cout << "\nDeleting " << s.getName() << endl;
    cout << "===============================" << endl;
    stockList.deleteNode(s);
    stockList.display();
}

//*****************************************************************************************************
/*

Tesla, Inc.
TSLA
625.9
Microsoft Corp.
MSFT
230.2
Facebook, Inc.
FB
350.5
Amazon.com, Inc.
AMZN
3400.5
Apple Inc.
AAPL
150.5
Apple Inc.
AAPL
150.5

Deleting Tesla, Inc.
===============================
Microsoft Corp.
MSFT
230.2
Facebook, Inc.
FB
350.5
Amazon.com, Inc.
AMZN
3400.5
Apple Inc.
AAPL
150.5
Apple Inc.
AAPL
150.5

Deleting Amazon.com, Inc.
===============================
Microsoft Corp.
MSFT
230.2
Facebook, Inc.
FB
350.5
Apple Inc.
AAPL
150.5
Apple Inc.
AAPL
150.5

===============================
Apple Inc.      Microsoft Corp.
AAPL            MSFT
150.5           230.2
Stocks are not equal
Apple Inc. is less than Microsoft Corp.

===============================
Apple Inc.      Apple Inc.
AAPL            AAPL
150.5           150.5
Stocks are equal

*/
