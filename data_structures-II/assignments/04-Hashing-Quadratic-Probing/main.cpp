//*****************************************************************************************************
//
//      This program demonstrates the HashTable class by instantiating a hash table of Stock objects
//      and performing it's methods.
//
//      Other files required:
//        1.    stock.h - header file for the Stock class (includes stock.cpp)
//        2.    hashTable.h - header file for the HashTable class (includes htElement.h)
//
//*****************************************************************************************************

#include "hashTable.h"
#include "stock.h"

#include <iostream>
using namespace std;

//*****************************************************************************************************

void test(HashTable<Stock> &table, const Stock &itemToSearchAndRemove);

//*****************************************************************************************************

int main() {
    HashTable<Stock> stockTable(10);

    Stock google("Google", "GOOGL", 1500.50);
    Stock apple("Apple", "AAPL", 140.30);
    Stock microsoft("Microsoft", "MSFT", 220.10);
    Stock tesla("Tesla", "TSLA", 420.69);
    Stock amazon("Amazon", "AMZN", 3000.00);
    Stock googleCopy(google);
    Stock amazonCopy("Amazooooon", "AMZN", 9999.00);

    stockTable.insert(google);
    stockTable.insert(apple);
    stockTable.insert(microsoft);
    stockTable.insert(tesla);
    stockTable.insert(amazon);
    stockTable.insert(googleCopy);              // collision (not inserted)
    stockTable.insert(amazonCopy);              // collision (not inserted)

    stockTable.display();

    test(stockTable, apple);                    // found/removed
    test(stockTable, apple);                    // not found/not removed

    return 0;
}

//*****************************************************************************************************

void test(HashTable<Stock> &table, const Stock &item) {
    Stock *searchResult = table.search(item);

    cout << "\nSearching for " << item.getSymbol() << ":" << endl;

    if (searchResult) {
        cout << "Stock found!\n"
             << *searchResult << endl;
             
        delete searchResult;
        searchResult = nullptr;

        table.remove(item);
        cout << "\nAfter Removal of " << item.getSymbol() << ":" << endl;
        table.display();
    } else {
        cerr << "Stock not found!\n";
    }
}

//*****************************************************************************************************
/*

Amazon
AMZN
3000
Microsoft
MSFT
220.1
Google
GOOGL
1500.5
Apple
AAPL
140.3
Tesla
TSLA
420.69

Searching for AAPL:
Stock found!
Apple
AAPL
140.3

After Removal of AAPL:
Amazon
AMZN
3000
Microsoft
MSFT
220.1
Google
GOOGL
1500.5
Tesla
TSLA
420.69

Searching for AAPL:
Stock not found!

*/