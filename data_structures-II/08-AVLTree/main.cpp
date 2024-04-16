//*****************************************************************************************************
//
//      This program reads stock data from a file and instantiates an AVL tree to store the stock 
//      objects. It then displays a menu of options to demonstrate the AVLTree class methods.
//
//      Other files required:
//        1.    AVLTree.h - header file for the AVL class (includes node struct: node.h)
//        2.    stock.h - header file for the Stock class (includes implementation file: stock.cpp)
//        3.    Stock.txt - text file containing stock data
//
//*****************************************************************************************************

#include "AVLTree.h"
#include "stock.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

//*****************************************************************************************************

bool readStocks(AVLTree<Stock> &stockTree);
void traverseAVLTree(AVLTree<int> &intTree);
void displayMenu(AVLTree<Stock> &stockTree);

//*****************************************************************************************************

int main() {
    AVLTree<int> intTree;
    AVLTree<Stock> stockTree;
    int randVal;

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < 10; ++i) {
        randVal = rand() % 5000 + 1;
        intTree.insert(randVal);
    }

    traverseAVLTree(intTree);
    cout << "\nHeight: " << intTree.height() << endl;

    if (readStocks(stockTree))
        displayMenu(stockTree);

    return 0;
}

//*****************************************************************************************************

bool readStocks(AVLTree<Stock> &stockTree) {
    ifstream inFile("Stock.txt");
    bool success = true;

    if (inFile.is_open()) {
        string name,
            symbol;
        double price;

        while (getline(inFile, name) && getline(inFile, symbol) && inFile >> price) {
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            stockTree.insert(Stock(name, symbol, price));
        }
    } else {
        cerr << "\nError: file not found\n";
        success = false;
    }
    inFile.close();

    return success;
}

//*****************************************************************************************************

void traverseAVLTree(AVLTree<int> &intTree) {
    cout << "In-order: " << endl;
    intTree.inorder();

    cout << "\nPre-order: " << endl;
    intTree.preorder();

    cout << "\nPost-order: " << endl;
    intTree.postorder();
}

//*****************************************************************************************************

void displayMenu(AVLTree<Stock> &stockTree) {
    ofstream outFile("Stock_BF.txt");
    string name,
        symbol;
    double price;
    char choice;

    do {
        cout << "\nMenu Options:\n"
             << "a) Display a stock's name given its symbol\n"
             << "b) Display a stock's price given its symbol\n"
             << "c) Insert a new stock\n"
             << "d) Display all stocks\n"
             << "e) Quit\n"
             << "Enter your choice: ";
        cin >> choice;
        choice = tolower(choice);

        switch (choice) {
            case 'a':
            case 'b': {
                cout << "\nEnter stock symbol: ";
                cin >> symbol;

                Stock *pStock = stockTree.search(Stock("", symbol));

                if (pStock == nullptr)
                    cerr << "Error: stock not found\n";
                else if (choice == 'a')
                    cout << "Stock name: " << pStock->getName() << endl;
                else
                    cout << "Stock price: " << pStock->getPrice() << endl;

                delete pStock;
                pStock = nullptr;
            } break;
            case 'c':
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                do {
                    cout << "\nEnter stock name: ";
                    getline(cin, name);

                    if (name.empty())
                        cerr << "Error: invalid input\n";
                } while (name.empty());

                do {
                    cout << "Enter stock symbol: ";
                    getline(cin, symbol);

                    if (symbol.empty() || symbol.find_first_of(" \t\n\v\f\r") != string::npos)
                        cerr << "Error: invalid input\n\n";
                } while (symbol.empty() || symbol.find_first_of(" \t\n\v\f\r") != string::npos);

                cout << "Enter stock price: ";
                while (!(cin >> price) || price < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "Error: invalid input\n\n";

                    cout << "Enter stock price: ";
                }
                stockTree.insert(Stock(name, symbol, price));
                break;
            case 'd':
                cout << "\n\tStocks"
                     << "\n----------------------" << endl;
                stockTree.inorder();
                break;
            case 'e':
                stockTree.inorder(outFile);
                outFile.close();
                break;
            default:
                cerr << "\nError: invalid choice\n";
        }
    } while (choice != 'e');
}

//*****************************************************************************************************
/*

In-order: 
1308            (BF: 0)
2679            (BF: 0)
3074            (BF: 0)
3080            (BF: -1)
3308            (BF: 0)
3987            (BF: 0)
4111            (BF: 0)
4150            (BF: 0)
4358            (BF: -1)
4626            (BF: 0)

Pre-order: 
3080            (BF: -1)
2679            (BF: 0)
1308            (BF: 0)
3074            (BF: 0)
4150            (BF: 0)
3987            (BF: 0)
3308            (BF: 0)
4111            (BF: 0)
4358            (BF: -1)
4626            (BF: 0)

Post-order: 
1308            (BF: 0)
3074            (BF: 0)
2679            (BF: 0)
3308            (BF: 0)
4111            (BF: 0)
3987            (BF: 0)
4626            (BF: 0)
4358            (BF: -1)
4150            (BF: 0)
3080            (BF: -1)

Height: 4

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: a

Enter stock symbol: NVDA
Stock name: NVIDIA

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: b

Enter stock symbol: NVDA
Stock price: 548.58

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: c

Enter stock name: Computer Science Club
Enter stock symbol: CSC
Enter stock price: 10101.01

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: d

        Stocks
----------------------
Apple
AAPL
121.73          (BF: 0)
Advanced Micro Devices
AMD
84.51           (BF: -1)
Computer Science Club
CSC
10101           (BF: 0)
Intel
INTC
60.78           (BF: 1)
Motorola Inc.
MOT
17.49           (BF: 0)
Microsoft Corp.
MSFT
28.11           (BF: 0)
NVIDIA
NVDA
548.58          (BF: -1)
Sony
SNE
105.81          (BF: -1)
Tesla
TSLA
564.33          (BF: 0)

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: e

******************************************************************************************************

In-order: 
201             (BF: 0)
505             (BF: 0)
1564            (BF: 0)
3020            (BF: 0)
3388            (BF: 0)
4325            (BF: 1)
4353            (BF: 1)
4575            (BF: 0)
4913            (BF: 0)
4980            (BF: 0)

Pre-order: 
4353            (BF: 1)
3020            (BF: 0)
505             (BF: 0)
201             (BF: 0)
1564            (BF: 0)
4325            (BF: 1)
3388            (BF: 0)
4913            (BF: 0)
4575            (BF: 0)
4980            (BF: 0)

Post-order: 
201             (BF: 0)
1564            (BF: 0)
505             (BF: 0)
3388            (BF: 0)
4325            (BF: 1)
3020            (BF: 0)
4575            (BF: 0)
4980            (BF: 0)
4913            (BF: 0)
4353            (BF: 1)

Height: 4

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: 1

Error: invalid choice

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: k

Error: invalid choice

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: a

Enter stock symbol: 1
Error: stock not found

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: b

Enter stock symbol: abc
Error: stock not found

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: c

Enter stock name: 
Error: invalid input

Enter stock name: Computer Science Club
Enter stock symbol: 
Error: invalid input

Enter stock symbol: CS C
Error: invalid input

Enter stock symbol: CSC
Enter stock price: abc
Error: invalid input

Enter stock price: -10
Error: invalid input

Enter stock price: 1010.10

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: e

*/