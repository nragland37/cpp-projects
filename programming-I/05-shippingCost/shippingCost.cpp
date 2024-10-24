//*****************************************************************************************************
//      Online Purchase Cost Calculator
//
//      This program calculates the total cost of an item purchased online by taking the price and weight of item from the user and additionally adding the taxes along shipping cost.
//
//*****************************************************************************************************

#include <iomanip>
#include <iostream>
using namespace std;

//*****************************************************************************************************
int main() {

    //rates...
    const float TAXRATE = 4.225 / 100;
    const float LESS_THAN_ONE_LBS = 10;
    const float LESS_THAN_FIVE_LBS = 7;
    const float LESS_THAN_EIGHT_LBS = 5;
    const float LESS_THAN_TEN_LBS = 3;
    const float LESS_THAN_TWENTY_LBS = 2;
    const float ABOVE_THAN_TWENTY_LBS = 1;

    //components to calculate the cost of an item...
    float price_of_item;
    float tax_on_item;
    float shipping_cost_of_item;
    float totalCost_of_item;
    float weight_of_item;

    cout << "Calculate the total cost of an online purchase" << endl;

    cout << "\nEnter the item's price: ";
    cin >> price_of_item;

    cout << "Enter the item's weight: ";
    cin >> weight_of_item;

// to calculate the shipping cost of an item...
    if ( weight_of_item < 1 )

        shipping_cost_of_item = LESS_THAN_ONE_LBS * weight_of_item;

    else if ( weight_of_item < 5 )
        shipping_cost_of_item = LESS_THAN_FIVE_LBS * weight_of_item;

    else if ( weight_of_item < 8 )
        shipping_cost_of_item = LESS_THAN_EIGHT_LBS * weight_of_item;

    else if ( weight_of_item < 10 )
        shipping_cost_of_item = LESS_THAN_TEN_LBS * weight_of_item;

    else if ( weight_of_item < 20 )
         shipping_cost_of_item = LESS_THAN_TWENTY_LBS * weight_of_item;

    else
        shipping_cost_of_item = ABOVE_THAN_TWENTY_LBS * weight_of_item;

// to calculate the tax on an item
    tax_on_item = price_of_item * TAXRATE;

// to calculate the total cost of an item by having the sum of all the components...
    totalCost_of_item = price_of_item + tax_on_item + shipping_cost_of_item;

// Display Output...
    cout << "\nTotal price: " << fixed << setprecision(2) << totalCost_of_item << endl;
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