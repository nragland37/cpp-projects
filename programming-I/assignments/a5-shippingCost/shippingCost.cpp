//****************************************************************************************************
// 			File:                 shippingCost.cpp
//
//			Student:              Nicholas Ragland
//
//			Assignment:           Program #5
//
//          Course Name:          Programming 1
//
//          Course Number:        COSC 1550 - 03
//
//          Due:                  September 30, 2021
//
//          This program calculates the total cost of an online purchase based on the item's price
//			and weight.
//
//****************************************************************************************************

#include <iomanip>
#include <iostream>
using namespace std;

//****************************************************************************************************
int main() {
    float price,
        tax,
        shipping,
        totalCost,
        weight;

    const float TAXRATE = 4.225 / 100,
                LESS_ONE_LB = 10,
                LESS_FIVE_LB = 7,
                LESS_EIGHT_LB = 5,
                LESS_TEN_LB = 3,
                LESS_TWENTY_LB = 2,
                ABOVE_TWENTY = 1;

    cout << "Calculate the total cost of an online purchase." << endl
         << endl;

    cout << "Enter the item's price: ";
    cin >> price;

    cout << endl;

    cout << "Enter the item's weight: ";
    cin >> weight;

    if (weight < 1)
        shipping = LESS_ONE_LB * weight;

    else if (weight < 5)
        shipping = LESS_FIVE_LB * weight;

    else if (weight < 8)
        shipping = LESS_EIGHT_LB * weight;

    else if (weight < 10)
        shipping = LESS_TEN_LB * weight;

    else if (weight < 20)
        shipping = LESS_TWENTY_LB * weight;

    else
        shipping = ABOVE_TWENTY * weight;

    tax = price * TAXRATE;
    totalCost = price + tax + shipping;

    cout << endl;

    cout << "Total price: " << fixed << setprecision(2) << totalCost << endl;

    return 0;
}

//****************************************************************************************************
/*

Calculate the total cost of an online purchase.

Enter the item's price: 10

Enter the item's weight: 50

Total price: 60.4225

*/