//*****************************************************************************************************
//
//      The implementation of the Stock class header file.
//
//      Other files required:
//        1.    stock.h - header file for the Stock class
//
//*****************************************************************************************************

#include "stock.h"
#include <iostream>

//*****************************************************************************************************

Stock::Stock(const std::string &name, const std::string &symbol, double price) {
    companyName = name;
    stockSymbol = symbol;
    stockPrice = price;
}

//*****************************************************************************************************

Stock::Stock(const Stock &s) {
    companyName = s.companyName;
    stockSymbol = s.stockSymbol;
    stockPrice = s.stockPrice;
}

//*****************************************************************************************************

void Stock::display() const {
    std::cout << companyName << std::endl;
    std::cout << stockSymbol << std::endl;
    std::cout << stockPrice << std::endl;
}

//*****************************************************************************************************
