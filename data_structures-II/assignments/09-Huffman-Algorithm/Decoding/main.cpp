//*****************************************************************************************************
//
//      This program reads stock data from a file and creates a Huffman tree to decode a pre-set
//      sequence. It then displays the stocks present in that sequence.
//
//      Other files required:
//        1.    node.h - header file for the Node struct
//        2.    stock.h - header file for the Stock class (includes implementation file: stock.cpp)
//        3.    HuffmanStocks.txt - text file containing stock data
//
//        NOTE: Decoding only. No encoding.
//
//*****************************************************************************************************

#include "node.h"
#include "stock.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

//*****************************************************************************************************

int readStocks(const string &fileName, Stock *&stocks, double *&freqs);
Node<Stock> *createHuffmanTree(Stock stocks[], double freqs[], int size);
void printArray(int path[], int pathLen, Node<Stock> *leaf);
void printPaths(Node<Stock> *node, int path[], int pathLen, int lr);
void displayStockList(Node<Stock> *rootPtr, const string &sentence);

//*****************************************************************************************************

int main() {
    const string fileName = "HuffmanStocks.txt";
    const string sentence = "000100110011100111100111111011011101111";
    Stock *stocks = nullptr;
    double *freqs = nullptr;
    Node<Stock> *root = nullptr;
    int numStocks;
    int path[10];

    numStocks = readStocks(fileName, stocks, freqs);

    if (numStocks > 0) {
        root = createHuffmanTree(stocks, freqs, numStocks);
        printPaths(root, path, 0, -1);
        cout << endl;
        displayStockList(root, sentence);
    } else {
        cerr << "\nError: no stocks found\n";
    }

    delete[] stocks;
    stocks = nullptr;
    delete[] freqs;
    freqs = nullptr;

    return 0;
}

//*****************************************************************************************************

int readStocks(const string &fileName, Stock *&stocks, double *&freqs) {
    ifstream inFile(fileName);
    string name,
        symbol;
    double price;
    int size = 0;

    if (inFile.is_open()) {
        inFile >> size;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');

        stocks = new Stock[size];
        freqs = new double[size];

        for (int i = 0; i < size; ++i) {
            getline(inFile, name);
            getline(inFile, symbol);
            inFile >> price;
            inFile >> freqs[i];
            stocks[i] = Stock(name, symbol, price);
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } else {
        cerr << "\nError: file not found\n";
    }
    inFile.close();

    return size;
}

//*****************************************************************************************************

Node<Stock> *createHuffmanTree(Stock stocks[], double freqs[], int size) {
    int index1,
        index2;
    double freq1,
           freq2;
    Node<Stock> **elements = new Node<Stock> *[size];

    for (int i = 0; i < size; ++i) {
        elements[i] = new Node<Stock>;
        elements[i]->value = stocks[i];
        elements[i]->frequency = freqs[i];
        elements[i]->left = nullptr;
        elements[i]->right = nullptr;
    }

    while (size > 1) {
        index1 = index2 = 0;
        freq1 = freq2 = numeric_limits<double>::max();

        for (int i = 0; i < size; ++i) {
            if (elements[i]->frequency < freq1) {
                freq2 = freq1;
                index2 = index1;
                freq1 = elements[i]->frequency;
                index1 = i;
            } else if ((elements[i]->frequency < freq2) && (i != index1)) {
                freq2 = elements[i]->frequency;
                index2 = i;
            }
        }

        Node<Stock> *newNode = new Node<Stock>;
        newNode->left = elements[index1];
        newNode->right = elements[index2];
        newNode->frequency = freq1 + freq2;

        elements[min(index1, index2)] = newNode;

        for (int i = max(index1, index2); i < size - 1; ++i)
            elements[i] = elements[i + 1];

        --size;
    }

    Node<Stock> *root = elements[0];

    delete[] elements;
    elements = nullptr;

    return root;
}

//*****************************************************************************************************

void printArray(int path[], int pathLen, Node<Stock> *leaf) {
    cout << leaf->value << "\t\t\t\t";

    for (int i = 0; i < pathLen; ++i)
        cout << path[i] << " ";
    cout << endl;
}

//*****************************************************************************************************

void printPaths(Node<Stock> *node, int path[], int pathLen, int lr) {
    if (node) {
        if (lr != -1) {
            path[pathLen] = lr;
            ++pathLen;
        }

        if ((!node->left) && (!node->right)) {
            printArray(path, pathLen, node);
        } else {
            printPaths(node->left, path, pathLen, 0);
            printPaths(node->right, path, pathLen, 1);
        }
    }
}

//*****************************************************************************************************

void displayStockList(Node<Stock> *rootPtr, const string &sentence) {
    Node<Stock> *pCur = rootPtr;

    for (char c : sentence) {
        if (c == '0')
            pCur = pCur->left;
        else if (c == '1')
            pCur = pCur->right;

        if ((pCur) && (!pCur->left) && (!pCur->right)) {
            cout << pCur->value.getName() << endl;
            pCur = rootPtr;
        }
    }
}

//*****************************************************************************************************
/*
    const string sentence = "000100110011100111100111111011011101111";


Home Depot Inc
HD
279.57                          0 0 
Coca-Cola Co
KO
53.85                           0 1 0 
Cisco Systems Inc
CSCO
42.54                           0 1 1 0 
Caterpillar Inc
CAT
173.19                          0 1 1 1 0 
Boeing Co
BA
202.4                           0 1 1 1 1 0 
Johnson & Johnson
JNJ
150.85                          0 1 1 1 1 1 
Goldman Sachs Group Inc
GS
222.38                          1 0 
Apple Inc
AAPL
120.3                           1 1 0 
Intel Corp
INTC 
46.19                           1 1 1 0 
American Express Co
AXP
118.67                          1 1 1 1 

Home Depot Inc
Coca-Cola Co
Cisco Systems Inc
Caterpillar Inc
Boeing Co
Johnson & Johnson
Goldman Sachs Group Inc
Apple Inc
Intel Corp
American Express Co

****************************************************************************************************

    const string sentence = "000000000010110";


Home Depot Inc
HD
279.57                          0 0 
Coca-Cola Co
KO
53.85                           0 1 0 
Cisco Systems Inc
CSCO
42.54                           0 1 1 0 
Caterpillar Inc
CAT
173.19                          0 1 1 1 0 
Boeing Co
BA
202.4                           0 1 1 1 1 0 
Johnson & Johnson
JNJ
150.85                          0 1 1 1 1 1 
Goldman Sachs Group Inc
GS
222.38                          1 0 
Apple Inc
AAPL
120.3                           1 1 0 
Intel Corp
INTC 
46.19                           1 1 1 0 
American Express Co
AXP
118.67                          1 1 1 1 

Home Depot Inc
Home Depot Inc
Home Depot Inc
Home Depot Inc
Home Depot Inc
Goldman Sachs Group Inc
Apple Inc

****************************************************************************************************

    const string sentence = "";
    

Home Depot Inc
HD
279.57                          0 0 
Coca-Cola Co
KO
53.85                           0 1 0 
Cisco Systems Inc
CSCO
42.54                           0 1 1 0 
Caterpillar Inc
CAT
173.19                          0 1 1 1 0 
Boeing Co
BA
202.4                           0 1 1 1 1 0 
Johnson & Johnson
JNJ
150.85                          0 1 1 1 1 1 
Goldman Sachs Group Inc
GS
222.38                          1 0 
Apple Inc
AAPL
120.3                           1 1 0 
Intel Corp
INTC 
46.19                           1 1 1 0 
American Express Co
AXP
118.67                          1 1 1 1

****************************************************************************************************

Error: no stocks found

****************************************************************************************************

Error: file not found

Error: no stocks found

*/