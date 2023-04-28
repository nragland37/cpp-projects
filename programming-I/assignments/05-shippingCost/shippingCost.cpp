//*****************************************************************************************************
//      Online Purchase Cost Calculator
//
//      This program calculates the total cost of an online purchase based on the item's price and
//      weight.
//
//*****************************************************************************************************

#include <iomanip>     // library for setprecision(), fixed, setfill(), setw(), left, right, showpoint, etc. (manipulators for output)
#include <iostream>
using namespace std;

//*****************************************************************************************************

int main() {
    const float TAXRATE = 4.225 / 100,
                LESS_ONE_LB = 10,
                LESS_FIVE_LB = 7,
                LESS_EIGHT_LB = 5,
                LESS_TEN_LB = 3,
                LESS_TWENTY_LB = 2,
                ABOVE_TWENTY = 1;
    float price,
        tax,
        shipping,
        totalCost,
        weight;

    cout << "Calculate the total cost of an online purchase" << endl;

    cout << "\nEnter the item's price: ";
    cin >> price;

    cout << "Enter the item's weight: ";
    cin >> weight;

    if (weight < 1)
        shipping = LESS_ONE_LB * weight;     // shipping = 10 * weight (if weight < 1)
    else if (weight < 5)
        shipping = LESS_FIVE_LB * weight;     // shipping = 7 * weight (if weight < 5)
    else if (weight < 8)
        shipping = LESS_EIGHT_LB * weight;     // shipping = 5 * weight (if weight < 8)
    else if (weight < 10)
        shipping = LESS_TEN_LB * weight;     // shipping = 3 * weight (if weight < 10)
    else if (weight < 20)
        shipping = LESS_TWENTY_LB * weight;     // shipping = 2 * weight (if weight < 20)
    else
        shipping = ABOVE_TWENTY * weight;     // shipping = 1 * weight (if weight >= 20)

    tax = price * TAXRATE;                  // tax = price * 4.225%
    totalCost = price + tax + shipping;     // totalCost = price + tax + shipping

    cout << "\nTotal price: " << fixed << setprecision(2) << totalCost << endl;     // setprecision() sets the number of decimal places to display
                                                                                    // fixed sets the number of decimal places to display to 2
    return 0;
}

//*****************************************************************************************************

/*

Calculate the total cost of an online purchase

Enter the item's price: 10
Enter the item's weight: 50

Total price: 60.42

*****************************************************************************************************

Calculate the total cost of an online purchase

Enter the item's price: 900
Enter the item's weight: 45.50

Total price: 983.53

*/