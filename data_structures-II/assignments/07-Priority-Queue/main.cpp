//*****************************************************************************************************
//
//      This program tests the priorityQueue class by creating a priority queue of stock objects and
//      performing various operations on the queue.
//
//      Other files required:
//          1.    priorityQueue.h - header file for the priorityQueue class
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

bool readStocks(ifstream &inFile, priorityQueue<Stock> &s);
void remove(priorityQueue<Stock> &s, int num);
void checkStock(const priorityQueue<Stock> &s);

//*****************************************************************************************************

int main() {
    ifstream file("Stock.txt");
    priorityQueue<Stock> s1;
    priorityQueue<Stock> s2(2);                    // restricted capacity (minimum 12)

    remove(s2, 5);                                 // error/empty list/resizing to minimum capacity

    if (readStocks(file, s1)) {
        s1.display();
        remove(s1, 5);
        checkStock(s1);

        s1.clear();                                // clear list
        checkStock(s1);
    }

    return 0;
}

//*****************************************************************************************************

bool readStocks(ifstream &inFile, priorityQueue<Stock> &s) {
    bool success = true;

    if (inFile.is_open()) {
        string name,
               symbol;
        double price;

        while (getline(inFile, name) && getline(inFile, symbol) && inFile >> price) {
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            s.enqueue(Stock(name, symbol, price));
        }
    } else {
        cerr << "\nError: file not found\n";
        success = false;
    }
    inFile.close();

    return success;
}

//*****************************************************************************************************

void remove(priorityQueue<Stock> &s, int num) {
    bool success = true;

    for (int i = 0; i < num && success; ++i) {
        Stock stock;
        checkStock(s);

        if (s.dequeue(stock)) {
            cout << "\n\nRemoved stock:"
                 << "\n----------------------------------" << endl;
            cout << stock;
            cout << "\n\nRemaining stocks:"
                 << "\n----------------------------------" << endl;
            s.display();
        } else {
            cerr << "Error: no stocks to remove\n\n";
            success = false;
        }
    }
}

//*****************************************************************************************************

void checkStock(const priorityQueue<Stock> &s) {
    cout << "\n----------------------------------"
         << "\n=========== Stock List ==========="
         << "\n----------------------------------"
         << "\nValues: " << s.getNumValues()
         << "\nCapacity: " << s.getCapacity() << endl;

    if (s.isFull())
        cerr << "Stock list full\n";
    else if (s.isEmpty())
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

*/