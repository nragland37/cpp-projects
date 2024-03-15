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

std::ostream &operator<<(std::ostream &out, const Stock &stock) {
    out << stock.companyName << std::endl
        << stock.stockSymbol << std::endl
        << stock.stockPrice;

    return out;
}

//*****************************************************************************************************