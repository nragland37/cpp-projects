//*****************************************************************************************************
//
//      This program reads stock data from a file and instantiates an array-based list priority queue 
//      to store the stock objects. It then performs it's methods to demonstrate the PriorityQueue 
//      class.
//
//      Other files required:
//          1.    priorityQueue.h - header file for the PriorityQueue class
//          2.    stock.h - header file for the Stock class (includes implementation file: stock.cpp)
//          3.    Stock.txt - text file containing stock data
//
//*****************************************************************************************************

#include "priorityQueue.h"
#include "stock.h"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

bool readStocks(ifstream &inFile, PriorityQueue<Stock> &stockList);
void remove(PriorityQueue<Stock> &stockList, int num);
void checkStock(const PriorityQueue<Stock> &stockList);

//*****************************************************************************************************

int main() {
    ifstream file("Stock.txt");
    PriorityQueue<Stock> stockList1;
    PriorityQueue<Stock> stockList2(2);                    // restricted capacity (minimum 12)

    remove(stockList2, 5);                                 // error/empty list/resizing to minimum capacity

    if (readStocks(file, stockList1)) {
        stockList1.display();
        remove(stockList1, 5);
        checkStock(stockList1);

        stockList1.clear();                                // clear list
        checkStock(stockList1);
    }

    return 0;
}

//*****************************************************************************************************

bool readStocks(ifstream &inFile, PriorityQueue<Stock> &stockList) {
    bool success = true;

    if (inFile.is_open()) {
        string name,
               symbol;
        double price;

        while (getline(inFile, name) && getline(inFile, symbol) && inFile >> price) {
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            stockList.enqueue(Stock(name, symbol, price));
        }
    } else {
        cerr << "\nError: file not found\n";
        success = false;
    }
    inFile.close();

    return success;
}

//*****************************************************************************************************

void remove(PriorityQueue<Stock> &stockList, int num) {
    bool success = true;

    for (int i = 0; i < num && success; ++i) {
        Stock stock;
        checkStock(stockList);

        if (stockList.dequeue(stock)) {
            cout << "\n\nRemoved stock:"
                 << "\n----------------------------------" << endl;
            cout << stock;
            cout << "\n\nRemaining stocks:"
                 << "\n----------------------------------" << endl;
            stockList.display();
        } else {
            cerr << "Error: no stocks to remove\n\n";
            success = false;
        }
    }
}

//*****************************************************************************************************

void checkStock(const PriorityQueue<Stock> &stockList) {
    cout << "\n----------------------------------"
         << "\n=========== Stock List ==========="
         << "\n----------------------------------"
         << "\nValues: " << stockList.getNumValues()
         << "\nCapacity: " << stockList.getCapacity() << endl;

    if (stockList.isFull())
        cerr << "Stock list full\n";
    else if (stockList.isEmpty())
        cerr << "Stock list empty\n";
    else
        cout << "Stock list neither full nor empty" << endl;
}

//*****************************************************************************************************
/*

----------------------------------
=========== Stock List ===========
----------------------------------
Values: 0
Capacity: 12
Stock list empty
Error: no stocks to remove


Error: file not found

*******************************************************************************************************

----------------------------------
=========== Stock List ===========
----------------------------------
Values: 0
Capacity: 12
Stock list empty
Error: no stocks to remove

Amazon.com Inc.
AMZN
3222.9
Netflix
NFLX
628.44
Alphabet Inc. Class A
GOOGL
2805.12
Tesla
TSLA
564.33
Qualcomm
QCOM
146.1
NVIDIA
NVDA
548.58
Oracle
ORCL
94.52
Apple
AAPL
121.73
Sony
SNE
105.81
Intel
INTC
60.78
Walmart
WMT
142.51
Microsoft Corp.
MSFT
28.11
Facebook
FB
333.02
Cisco Systems
CSCO
54.6
Advanced Micro Devices
AMD
84.51
Motorola Inc.
MOT
17.49

----------------------------------
=========== Stock List ===========
----------------------------------
Values: 16
Capacity: 22
Stock list neither full nor empty


Removed stock:
----------------------------------
Amazon.com Inc.
AMZN
3222.9


Remaining stocks:
----------------------------------
Alphabet Inc. Class A
GOOGL
2805.12
Netflix
NFLX
628.44
NVIDIA
NVDA
548.58
Tesla
TSLA
564.33
Qualcomm
QCOM
146.1
Facebook
FB
333.02
Oracle
ORCL
94.52
Apple
AAPL
121.73
Sony
SNE
105.81
Intel
INTC
60.78
Walmart
WMT
142.51
Microsoft Corp.
MSFT
28.11
Motorola Inc.
MOT
17.49
Cisco Systems
CSCO
54.6
Advanced Micro Devices
AMD
84.51

----------------------------------
=========== Stock List ===========
----------------------------------
Values: 15
Capacity: 22
Stock list neither full nor empty


Removed stock:
----------------------------------
Alphabet Inc. Class A
GOOGL
2805.12


Remaining stocks:
----------------------------------
Netflix
NFLX
628.44
Tesla
TSLA
564.33
NVIDIA
NVDA
548.58
Apple
AAPL
121.73
Qualcomm
QCOM
146.1
Facebook
FB
333.02
Oracle
ORCL
94.52
Advanced Micro Devices
AMD
84.51
Sony
SNE
105.81
Intel
INTC
60.78
Walmart
WMT
142.51
Microsoft Corp.
MSFT
28.11
Motorola Inc.
MOT
17.49
Cisco Systems
CSCO
54.6

----------------------------------
=========== Stock List ===========
----------------------------------
Values: 14
Capacity: 22
Stock list neither full nor empty


Removed stock:
----------------------------------
Netflix
NFLX
628.44


Remaining stocks:
----------------------------------
Tesla
TSLA
564.33
Qualcomm
QCOM
146.1
NVIDIA
NVDA
548.58
Apple
AAPL
121.73
Walmart
WMT
142.51
Facebook
FB
333.02
Oracle
ORCL
94.52
Advanced Micro Devices
AMD
84.51
Sony
SNE
105.81
Intel
INTC
60.78
Cisco Systems
CSCO
54.6
Microsoft Corp.
MSFT
28.11
Motorola Inc.
MOT
17.49

----------------------------------
=========== Stock List ===========
----------------------------------
Values: 13
Capacity: 22
Stock list neither full nor empty


Removed stock:
----------------------------------
Tesla
TSLA
564.33


Remaining stocks:
----------------------------------
NVIDIA
NVDA
548.58
Qualcomm
QCOM
146.1
Facebook
FB
333.02
Apple
AAPL
121.73
Walmart
WMT
142.51
Microsoft Corp.
MSFT
28.11
Oracle
ORCL
94.52
Advanced Micro Devices
AMD
84.51
Sony
SNE
105.81
Intel
INTC
60.78
Cisco Systems
CSCO
54.6
Motorola Inc.
MOT
17.49

----------------------------------
=========== Stock List ===========
----------------------------------
Values: 12
Capacity: 12
Stock list full


Removed stock:
----------------------------------
NVIDIA
NVDA
548.58


Remaining stocks:
----------------------------------
Facebook
FB
333.02
Qualcomm
QCOM
146.1
Oracle
ORCL
94.52
Apple
AAPL
121.73
Walmart
WMT
142.51
Microsoft Corp.
MSFT
28.11
Motorola Inc.
MOT
17.49
Advanced Micro Devices
AMD
84.51
Sony
SNE
105.81
Intel
INTC
60.78
Cisco Systems
CSCO
54.6

----------------------------------
=========== Stock List ===========
----------------------------------
Values: 11
Capacity: 12
Stock list neither full nor empty

----------------------------------
=========== Stock List ===========
----------------------------------
Values: 0
Capacity: 12
Stock list empty

*/