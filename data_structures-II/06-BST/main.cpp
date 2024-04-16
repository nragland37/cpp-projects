//*****************************************************************************************************
//
//      This program reads stock data from a file and instantiates a binary search tree to store the
//      stock objects. It then displays a menu of options to demonstrate the BST class methods.
//
//      Other files required:
//        1.    bst.h - header file for the BST class (includes node struct: node.h)
//        2.    stock.h - header file for the Stock class (includes implementation file: stock.cpp)
//        3.    Stock.txt - text file containing stock data
//
//*****************************************************************************************************

#include "bst.h"
#include "stock.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

//*****************************************************************************************************

bool readStocks(BST<Stock> &stockTree);
void traverseBST(BST<int> &intTree);
void displayMenu(BST<Stock> &stockTree);

//*****************************************************************************************************

int main() {
    BST<int> intTree;
    BST<Stock> stockTree;
    int randVal;

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < 10; ++i) {
        randVal = rand() % 5000 + 1;
        intTree.insert(randVal);
    }

    traverseBST(intTree);
    cout << "\nHeight: " << intTree.height() << endl;

    if (readStocks(stockTree))
        displayMenu(stockTree);

    return 0;
}

//*****************************************************************************************************

bool readStocks(BST<Stock> &stockTree) {
    ifstream inFile("Stock.txt");
    bool success = true;

    if (inFile.is_open()) {
        string name,
               symbol;
        double price;

        while (getline(inFile, name) && getline(inFile, symbol) && inFile >> price) {
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            Stock stock(name, symbol, price);
            stockTree.insert(stock);
        }
    } else {
        cerr << "\nError: file not found\n";
        success = false;
    }
    inFile.close();

    return success;
}   

//*****************************************************************************************************

void traverseBST(BST<int> &intTree) {
    cout << "In-order: " << endl;
    intTree.inOrder();

    cout << "\nPre-order: " << endl;
    intTree.preOrder();

    cout << "\nPost-order: " << endl;
    intTree.postOrder();
}

//*****************************************************************************************************

void displayMenu(BST<Stock> &stockTree) {
    ofstream outFile("Stock.txt");
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

                    // find_first_of returns position of the first character that matches
                    // if no such character is found, the function returns string::npos (not a position)
                    
                    // makes sure the symbol is not empty and is only one word
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
                stockTree.inOrder();
                break;
            case 'e':
                stockTree.inOrder(outFile);
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
449
563
1143
2716
3758
3763
3875
4221
4428
4593

Pre-order: 
3758
449
563
1143
2716
3763
4593
4428
3875
4221

Post-order: 
2716
1143
563
449
4221
3875
4428
4593
3763
3758

Height: 6

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

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: c

Enter stock name: Computer Science Club
Enter stock symbol: CSC
Enter stock price: 1010.10

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: b

Enter stock symbol: CSC
Stock price: 1010.1

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: a

Enter stock symbol: CSC
Stock name: Computer Science Club

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: e

****************************************************************************************************

In-order: 
642
1022
2651
2896
3133
3778
3846
4457
4739
4764

Pre-order: 
642
3846
3133
2896
1022
2651
3778
4739
4457
4764

Post-order: 
2651
1022
2896
3778
3133
4457
4764
4739
3846
642

Height: 6

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: A

Enter stock symbol: TEST
Error: stock not found

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: B

Enter stock symbol: TEST
Error: stock not found

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: C

Enter stock name: 
Error: invalid input

Enter stock name: Computer Science Club
Enter stock symbol: 
Error: invalid input

Enter stock symbol: CSC WBST
Error: invalid input

Enter stock symbol: CSC
Enter stock price: -100   
Error: invalid input

Enter stock price: a
Error: invalid input

Enter stock price: 1010.10

Menu Options:
a) Display a stock's name given its symbol
b) Display a stock's price given its symbol
c) Insert a new stock
d) Display all stocks
e) Quit
Enter your choice: e

****************************************************************************************************

In-order: 
693
1098
1352
1456
1740
1750
2081
2116
2234
2765

Pre-order: 
1456
1098
693
1352
2116
1740
1750
2081
2765
2234

Post-order: 
693
1352
1098
2081
1750
1740
2234
2765
2116
1456

Height: 5

Error: file not found

*/