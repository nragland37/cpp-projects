//*****************************************************************************************************
//
//      This header file defines a Stock class with overloaded comparison and output operators to 
//      facilitate easy comparison and display of stock information.
//
//*****************************************************************************************************

#ifndef STOCK_H
#define STOCK_H

//*****************************************************************************************************

#include <string>

//*****************************************************************************************************

class Stock {
private:
    std::string companyName;
    std::string stockSymbol;
    double stockPrice;

    friend std::ostream &operator<<(std::ostream &out, const Stock &stock);

public:
    Stock(const std::string &name = "", const std::string &symbol = "", double price = 0);
    Stock(const Stock &s);
    std::string getName() const;
    std::string getSymbol() const;
    double getPrice() const;
    bool operator==(const Stock &rhs) const;
    bool operator!=(const Stock &rhs) const;
    bool operator>(const Stock &rhs) const;
    bool operator<(const Stock &rhs) const;
    int hash(int size) const;
};

//*****************************************************************************************************

inline std::string Stock::getName() const {
    return companyName;
}

//*****************************************************************************************************

inline std::string Stock::getSymbol() const {
    return stockSymbol;
}

//*****************************************************************************************************

inline double Stock::getPrice() const {
    return stockPrice;
}

//*****************************************************************************************************

inline bool Stock::operator==(const Stock &rhs) const {
    return (stockSymbol == rhs.stockSymbol);
}

//*****************************************************************************************************

inline bool Stock::operator!=(const Stock &rhs) const {
    return (stockSymbol != rhs.stockSymbol);
}

//*****************************************************************************************************

inline bool Stock::operator>(const Stock &rhs) const {
    return (stockSymbol > rhs.stockSymbol);
}

//*****************************************************************************************************

inline bool Stock::operator<(const Stock &rhs) const {
    return (stockSymbol < rhs.stockSymbol);
}

//*****************************************************************************************************

#endif