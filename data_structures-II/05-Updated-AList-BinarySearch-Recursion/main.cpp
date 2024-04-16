//*****************************************************************************************************
//
//      This program reads stock data from a file and instantiates an array-based list to store the
//      stock objects. It then performs it's methods to demonstrate the AList class.
//
//      Other files required:
//        1.    aList.h - header file for the AList class
//        2.    stock.h - header file for the Stock class (includes implementation file: stock.cpp)
//        3.    Stock.txt - text file containing stock data
//
//*****************************************************************************************************

#include "aList.h"
#include "stock.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

//*****************************************************************************************************

void searchStock(const AList<Stock> &stockList, const Stock &s);
void checkStock(const AList<Stock> &stockList);
void removeStock(AList<Stock> &stockList, const Stock &s);
void removeStockRange(AList<Stock> &stockList, int start, int end);
void readStocks(ifstream &inFile, AList<Stock> &stockList);

//*****************************************************************************************************

int main() {
    AList<Stock> stockList(8);
    ifstream inFile("Stock.txt");
    ofstream outFile("Stock_updated.txt");

    checkStock(stockList);                  // empty
    removeStock(stockList, Stock());        // fail remove
    removeStockRange(stockList, 0, 2);      // fail remove range
    searchStock(stockList, Stock());        // fail search

    readStocks(inFile, stockList);
    checkStock(stockList);                  // full

    Stock s1("Disney", "DIS", 81.25);       // original
    Stock s2(s1);                           // copy
    Stock s3("Apple", "AAPL");              // copy from file
    Stock s4(s3);                           // copy of copy from file
    Stock s5("Best Buy", "BBY", 69.25);
    Stock s6("GameStop", "GME", 17.18);
    Stock s7("Verizon", "VZ", 33.28);

    stockList.insert(s1);
    stockList.insert(s2);
    stockList.insert(s3);
    stockList.insert(s4);
    stockList.insert(s5);
    stockList.insert(s6);
    stockList.insert(s7);

    checkStock(stockList);
    searchStock(stockList, s1);             // search original
    searchStock(stockList, s2);             // search copy (returns original index)

    removeStock(stockList, s4);             // remove all instances of value
    removeStock(stockList, s1);
    checkStock(stockList);
 
    removeStockRange(stockList, 4, 6);      // remove range
    checkStock(stockList);

    stockList.print(outFile);
    outFile.close();

    return 0;
}

//*****************************************************************************************************

void searchStock(const AList<Stock> &stockList, const Stock &s) {
    int searchIndex = stockList.binarySearch(s);
    string sName = s.getName();

    if (searchIndex != -1)
        cout << sName << " at index: " << searchIndex << endl;
    else
        cerr << "item not found\n";
}

//*****************************************************************************************************

void checkStock(const AList<Stock> &stockList) {
    cout << "\nvalues: " << stockList.listSize() << endl;
    cout << "capacity: " << stockList.listCap() << endl;

    if (stockList.isFull())
        cerr << "stock list full\n";
    else if (stockList.isEmpty())
        cerr << "stock list empty\n";

    stockList.print();
}

//*****************************************************************************************************

void removeStock(AList<Stock> &stockList, const Stock &s) {
    if (stockList.remove(s))
        cout << "removed: " << s.getName() << endl;
    else
        cerr << "item not removed\n";
}

//*****************************************************************************************************

void removeStockRange(AList<Stock> &stockList, int start, int end) {
    if (stockList.removeRange(start, end))
        cout << "range " << start << " to " << end << " removed" << endl;
    else
        cerr << "range not removed\n";
}

//*****************************************************************************************************

void readStocks(ifstream &inFile, AList<Stock> &stockList) {
    if (inFile.is_open()) {
        string name,
               symbol;
        double price;

        while (getline(inFile, name) && getline(inFile, symbol) && inFile >> price) {
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            Stock s(name, symbol, price);
            stockList.insert(s);
        }
    } else {
        cerr << "Error: file not found\n";
        exit(1);
    }

    inFile.close();
}

//*****************************************************************************************************
/*

values: 0
capacity: 8
stock list empty
item not removed
range not removed
item not found

values: 8
capacity: 8
stock list full
Apple
AAPL
121.73
Advanced Micro Devices
AMD
84.51
Intel
INTC
60.78
Motorola Inc.
MOT
17.49
Microsoft Corp.
MSFT
28.11
NVIDIA
NVDA
548.58
Sony
SNE
105.81
Tesla
TSLA
564.33

values: 15
capacity: 18
Apple
AAPL
121.73
Apple
AAPL
0
Apple
AAPL
0
Advanced Micro Devices
AMD
84.51
Best Buy
BBY
69.25
Disney
DIS
81.25
Disney
DIS
81.25
GameStop
GME
17.18
Intel
INTC
60.78
Motorola Inc.
MOT
17.49
Microsoft Corp.
MSFT
28.11
NVIDIA
NVDA
548.58
Sony
SNE
105.81
Tesla
TSLA
564.33
Verizon
VZ
33.28
Disney at index: 5
Disney at index: 5
removed: Apple
removed: Disney

values: 10
capacity: 18
Advanced Micro Devices
AMD
84.51
Best Buy
BBY
69.25
GameStop
GME
17.18
Intel
INTC
60.78
Motorola Inc.
MOT
17.49
Microsoft Corp.
MSFT
28.11
NVIDIA
NVDA
548.58
Sony
SNE
105.81
Tesla
TSLA
564.33
Verizon
VZ
33.28
range 4 to 6 removed

values: 7
capacity: 18
Advanced Micro Devices
AMD
84.51
Best Buy
BBY
69.25
GameStop
GME
17.18
Intel
INTC
60.78
Sony
SNE
105.81
Tesla
TSLA
564.33
Verizon
VZ
33.28

*/