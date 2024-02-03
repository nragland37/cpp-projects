//*****************************************************************************************************
//
//      This program implements various sorting algorithms on a list of stocks.
//
//      Other files required:
//          1.    stock.h - header file for the Stock class (includes implementation file: stock.cpp)
//          2.    sortedList.h - header file for the SortedList class
//          3.    Stock.txt - text file containing stock data
//
//*****************************************************************************************************

#include "sortedList.h"
#include "stock.h"

#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

//*****************************************************************************************************

bool readStocks(SortedList<Stock> &stockList, ifstream &inFile);
void checkStock(const SortedList<Stock> &stockList);
void displayRandom(SortedList<Stock> &stockList);
void displaySort(SortedList<Stock> &stockList, int sortType);

//*****************************************************************************************************

int main() {
    ifstream inFile("Stock.txt");
    SortedList<Stock> stockList;

    checkStock(stockList);                                                  // empty

    if (readStocks(stockList, inFile)) {
        checkStock(stockList);                                              // full
        stockList.insert(Stock("Computer Science Club", "CSC", 110101));    // resize
        checkStock(stockList);

        displayRandom(stockList);
        displaySort(stockList, 1);                                          // quick sort asc

        displayRandom(stockList);
        displaySort(stockList, 2);                                          // quick sort desc

        displayRandom(stockList);
        displaySort(stockList, 3);                                          // selection sort asc

        displayRandom(stockList);
        displaySort(stockList, 4);                                          // selection sort des

        displayRandom(stockList);
        displaySort(stockList, 5);                                          // heap sort asc

        displayRandom(stockList);
        displaySort(stockList, 6);                                          // heap sort desc
    }

    return 0;
}

//*****************************************************************************************************

bool readStocks(SortedList<Stock> &stockList, ifstream &inFile) {
    bool success = true;

    if (inFile.is_open()) {
        string name, 
               symbol;
        double price;

        while (getline(inFile, name) && getline(inFile, symbol) && inFile >> price) {
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            stockList.insert(Stock(name, symbol, price));
        }
    } else {
        cerr << "\nError: file not found\n";
        success = false;
    }
    inFile.close();

    return success;
}

//*****************************************************************************************************

void checkStock(const SortedList<Stock> &stockList) {
    cout << "\nvalues: " << stockList.getNumValues() << endl;
    cout << "capacity: " << stockList.getCapacity() << endl;

    if (stockList.isFull())
        cerr << "stock list full\n\n";
    else if (stockList.isEmpty())
        cerr << "stock list empty\n\n";
    else
        cout << "stock list neither full nor empty\n" << endl;
    stockList.display();
}

//*****************************************************************************************************

void displayRandom(SortedList<Stock> &stockList) {
    cout << "\nRandomise:\n" << endl;
    stockList.randomise();
    stockList.display();
}

//*****************************************************************************************************

void displaySort(SortedList<Stock> &stockList, int sortType) {
    if (sortType == 1) {
        cout << "\nQuick Sort Ascending:\n" << endl;
        stockList.quickSortA();
    } else if (sortType == 2) {
        cout << "\nQuick Sort Descending:\n" << endl;
        stockList.quickSortD();
    } else if (sortType == 3) {
        cout << "\nSelection Sort Ascending:\n" << endl;
        stockList.selectionSortA();
    } else if (sortType == 4) {
        cout << "\nSelection Sort Descending:\n" << endl;
        stockList.selectionSortD();
    } else if (sortType == 5) {
        cout << "\nHeap Sort Ascending:\n" << endl;
        stockList.heapSortA();
    } else if (sortType == 6) {
        cout << "\nHeap Sort Descending:\n" << endl;
        stockList.heapSortD();
    }
    stockList.display();
}

//*****************************************************************************************************
/*

values: 0
capacity: 10
stock list empty



values: 10
capacity: 10
stock list full

Motorola Inc.
MOT
17.49
Microsoft Corp.
MSFT
28.11
Tesla
TSLA
564.33
Intel
INTC
60.78
Sony
SNE
105.81
Advanced Micro Devices
AMD
84.51
NVIDIA
NVDA
548.58
Apple
AAPL
121.73
Qualcomm
QCOM
146.1
Alphabet Inc. Class A
GOOGL
2805.12


values: 11
capacity: 20
stock list neither full nor empty

Motorola Inc.
MOT
17.49
Microsoft Corp.
MSFT
28.11
Tesla
TSLA
564.33
Intel
INTC
60.78
Sony
SNE
105.81
Advanced Micro Devices
AMD
84.51
NVIDIA
NVDA
548.58
Apple
AAPL
121.73
Qualcomm
QCOM
146.1
Alphabet Inc. Class A
GOOGL
2805.12
Computer Science Club
CSC
110101


Randomise:

Alphabet Inc. Class A
GOOGL
2805.12
Advanced Micro Devices
AMD
84.51
Intel
INTC
60.78
Sony
SNE
105.81
NVIDIA
NVDA
548.58
Microsoft Corp.
MSFT
28.11
Qualcomm
QCOM
146.1
Computer Science Club
CSC
110101
Tesla
TSLA
564.33
Apple
AAPL
121.73
Motorola Inc.
MOT
17.49


Quick Sort Ascending:

Apple
AAPL
121.73
Advanced Micro Devices
AMD
84.51
Computer Science Club
CSC
110101
Alphabet Inc. Class A
GOOGL
2805.12
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
Qualcomm
QCOM
146.1
Sony
SNE
105.81
Tesla
TSLA
564.33


Randomise:

Tesla
TSLA
564.33
Apple
AAPL
121.73
Computer Science Club
CSC
110101
Microsoft Corp.
MSFT
28.11
Intel
INTC
60.78
Alphabet Inc. Class A
GOOGL
2805.12
NVIDIA
NVDA
548.58
Advanced Micro Devices
AMD
84.51
Qualcomm
QCOM
146.1
Motorola Inc.
MOT
17.49
Sony
SNE
105.81


Quick Sort Descending:

Tesla
TSLA
564.33
Sony
SNE
105.81
Qualcomm
QCOM
146.1
NVIDIA
NVDA
548.58
Microsoft Corp.
MSFT
28.11
Motorola Inc.
MOT
17.49
Intel
INTC
60.78
Alphabet Inc. Class A
GOOGL
2805.12
Computer Science Club
CSC
110101
Advanced Micro Devices
AMD
84.51
Apple
AAPL
121.73


Randomise:

Advanced Micro Devices
AMD
84.51
Apple
AAPL
121.73
Computer Science Club
CSC
110101
Sony
SNE
105.81
Intel
INTC
60.78
Tesla
TSLA
564.33
Motorola Inc.
MOT
17.49
Qualcomm
QCOM
146.1
NVIDIA
NVDA
548.58
Alphabet Inc. Class A
GOOGL
2805.12
Microsoft Corp.
MSFT
28.11


Selection Sort Ascending:

Apple
AAPL
121.73
Advanced Micro Devices
AMD
84.51
Computer Science Club
CSC
110101
Alphabet Inc. Class A
GOOGL
2805.12
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
Qualcomm
QCOM
146.1
Sony
SNE
105.81
Tesla
TSLA
564.33


Randomise:

Intel
INTC
60.78
Sony
SNE
105.81
Computer Science Club
CSC
110101
NVIDIA
NVDA
548.58
Motorola Inc.
MOT
17.49
Apple
AAPL
121.73
Alphabet Inc. Class A
GOOGL
2805.12
Advanced Micro Devices
AMD
84.51
Tesla
TSLA
564.33
Qualcomm
QCOM
146.1
Microsoft Corp.
MSFT
28.11


Selection Sort Descending:

Tesla
TSLA
564.33
Sony
SNE
105.81
Qualcomm
QCOM
146.1
NVIDIA
NVDA
548.58
Microsoft Corp.
MSFT
28.11
Motorola Inc.
MOT
17.49
Intel
INTC
60.78
Alphabet Inc. Class A
GOOGL
2805.12
Computer Science Club
CSC
110101
Advanced Micro Devices
AMD
84.51
Apple
AAPL
121.73


Randomise:

Microsoft Corp.
MSFT
28.11
Tesla
TSLA
564.33
Advanced Micro Devices
AMD
84.51
Sony
SNE
105.81
Alphabet Inc. Class A
GOOGL
2805.12
Qualcomm
QCOM
146.1
Intel
INTC
60.78
Apple
AAPL
121.73
Motorola Inc.
MOT
17.49
Computer Science Club
CSC
110101
NVIDIA
NVDA
548.58


Heap Sort Ascending:

Apple
AAPL
121.73
Advanced Micro Devices
AMD
84.51
Computer Science Club
CSC
110101
Alphabet Inc. Class A
GOOGL
2805.12
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
Qualcomm
QCOM
146.1
Sony
SNE
105.81
Tesla
TSLA
564.33


Randomise:

Motorola Inc.
MOT
17.49
Qualcomm
QCOM
146.1
Apple
AAPL
121.73
Computer Science Club
CSC
110101
Microsoft Corp.
MSFT
28.11
Intel
INTC
60.78
Tesla
TSLA
564.33
NVIDIA
NVDA
548.58
Advanced Micro Devices
AMD
84.51
Alphabet Inc. Class A
GOOGL
2805.12
Sony
SNE
105.81


Heap Sort Descending:

Tesla
TSLA
564.33
Sony
SNE
105.81
Qualcomm
QCOM
146.1
NVIDIA
NVDA
548.58
Microsoft Corp.
MSFT
28.11
Motorola Inc.
MOT
17.49
Intel
INTC
60.78
Alphabet Inc. Class A
GOOGL
2805.12
Computer Science Club
CSC
110101
Advanced Micro Devices
AMD
84.51
Apple
AAPL
121.73

*/