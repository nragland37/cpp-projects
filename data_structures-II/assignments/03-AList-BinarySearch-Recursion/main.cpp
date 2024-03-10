//*****************************************************************************************************
//
//      This program tests the AList class on a list of integers and stocks.
//
//      Other files required:
//          1.    aList.h - header file for the AList class
//          2.    stock.h - header file for the Stock class (includes implementation file: stock.cpp)
//
//*****************************************************************************************************

#include "aList.h"
#include "stock.h"

#include <iostream>
using namespace std;

//*****************************************************************************************************

void searchStock(const AList<Stock> &stockList, const Stock &stockList);
void searchInt(const AList<int> &intList, const int &intList);
void checkStock(const AList<Stock> &stockList);
void checkInt(const AList<int> &intList);

//*****************************************************************************************************

int main() {
    AList<int> intList(10);
    AList<Stock> stockList(5);

    Stock s1("Apple Inc.", "AAPL", 150.10);
    Stock s2("Microsoft Corp.", "MSFT", 300.20);
    Stock s3("Google LLC", "GOOGL", 2800.50);
    Stock s4("Amazon Inc.", "AMZN", 3400.40);
    Stock s5("Facebook Inc.", "FB", 355.60);
    Stock s6("Tesla Inc.", "TSLA", 1100.70);
    Stock s7(s1);
    Stock s8("Webster University", "WBST", 100100100100.10);

    checkInt(intList);                      // empty

    for (int intList = 0; intList < 10; ++intList)
        if (intList % 2 == 0)
            intList.insert(intList);
        else
            intList.insert(intList * 10);

    checkInt(intList);                      // full
    intList.print();

    intList.insert(100);
    checkInt(intList);                      // resize
    intList.print();

    searchInt(intList, 10);
    searchInt(intList, 100);
    searchInt(intList, 20);                 // not found

    checkStock(stockList);                  // empty
    stockList.insert(s1);
    stockList.insert(s2);
    stockList.insert(s3);
    stockList.insert(s4);
    stockList.insert(s5);

    checkStock(stockList);                  // full
    stockList.print();

    stockList.insert(s6);
    stockList.insert(s7);
    checkStock(stockList);                  // resize
    stockList.print();

    searchStock(stockList, s1);             // original found
    searchStock(stockList, s7);             // copy found (notice same index as s1)
    searchStock(stockList, s6);
    searchStock(stockList, s3);
    searchStock(stockList, s8);             // not found

    return 0;
}

//*****************************************************************************************************

void searchStock(const AList<Stock> &stockList, const Stock &stockList) {
    int searchIndex = stockList.binarySearch(stockList);
    string sName = stockList.getName();

    if (searchIndex != -1)
        cout << sName << " at index: " << searchIndex << endl;
    else
        cerr << sName << " not found\n\n";
}

//*****************************************************************************************************

void searchInt(const AList<int> &intList, const int &intList) {
    int searchIndex = intList.binarySearch(intList);

    if (searchIndex != -1)
        cout << intList << " at index: " << searchIndex << endl;
    else
        cerr << intList << " not found\n\n";
}

//*****************************************************************************************************

void checkStock(const AList<Stock> &stockList) {
    cout << "values: " << stockList.listSize() << endl;
    cout << "capacity: " << stockList.listCap() << endl;

    if (stockList.isFull())
        cerr << "stock list full\n\n";
    else if (stockList.isEmpty())
        cerr << "stock list empty\n\n";
    else
        cout << "stock list neither full nor empty\n" << endl;
}

//*****************************************************************************************************

void checkInt(const AList<int> &intList) {
    cout << "values: " << intList.listSize() << endl;
    cout << "capacity: " << intList.listCap() << endl;

    if (intList.isFull())
        cerr << "integer list full\n\n";
    else if (intList.isEmpty())
        cerr << "integer list empty\n\n";
    else
        cout << "integer list neither full nor empty\n" << endl;
}

//*****************************************************************************************************
/*

values: 0
capacity: 10
integer list empty

values: 10
capacity: 10
integer list full

[0] 90
[1] 70
[2] 50
[3] 30
[4] 10
[5] 8
[6] 6
[7] 4
[8] 2
[9] 0

values: 11
capacity: 20
integer list neither full nor empty

[0] 100
[1] 90
[2] 70
[3] 50
[4] 30
[5] 10
[6] 8
[7] 6
[8] 4
[9] 2
[10] 0

10 at index: 5
100 at index: 0
20 not found

values: 0
capacity: 5
stock list empty

values: 5
capacity: 5
stock list full

[0] Microsoft Corp.
MSFT
300.2

[1] Google LLC
GOOGL
2800.5

[2] Facebook Inc.
FB
355.6

[3] Amazon Inc.
AMZN
3400.4

[4] Apple Inc.
AAPL
150.1


values: 7
capacity: 15
stock list neither full nor empty

[0] Tesla Inc.
TSLA
1100.7

[1] Microsoft Corp.
MSFT
300.2

[2] Google LLC
GOOGL
2800.5

[3] Facebook Inc.
FB
355.6

[4] Amazon Inc.
AMZN
3400.4

[5] Apple Inc.
AAPL
150.1

[6] Apple Inc.
AAPL
150.1


Apple Inc. at index: 5
Apple Inc. at index: 5
Tesla Inc. at index: 0
Google LLC at index: 2
Webster University not found

*/