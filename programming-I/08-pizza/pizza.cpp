//*****************************************************************************************************
//      Pizza Palace Menu Order System
//
//      This program is a simple pizza ordering program that will calculate the total cost of the
//      order.
//
//*****************************************************************************************************

#include <iomanip>
#include <iostream>
using namespace std;

//*****************************************************************************************************

int main() {
    const double PIZZA = 15.50,
                 SODA = 2.00,
                 CHICKEN_NUGGETS = 7.00,
                 BREADSTICKS = 9.75;
    double numItems = 0,
           menuItem,
           total = 0;
    char itemLetter;

    cout << "=====================================================\n"
         << "\t\tWelcome to Pizza Palace\n"
         << "=====================================================" << endl;

    cout << fixed << setprecision(2) << right;

    do {
        cout << "-----------------------------------------------------\n\n"
             << "\tA\tPizza" << setw(26) << PIZZA
             << "\n\tB\tSoda" << setw(27) << SODA
             << "\n\tC\tChicken Nuggets" << setw(16) << CHICKEN_NUGGETS
             << "\n\tD\tBreadsticks" << setw(20) << BREADSTICKS
             << "\n\tE\tExit" << endl;

        cout << "\nPlease enter the next menu item Letter: ";
        cin >> itemLetter;

        switch (itemLetter) {
            case 'A':
                menuItem = PIZZA;
                break;
            case 'B':
                menuItem = SODA;
                break;
            case 'C':
                menuItem = CHICKEN_NUGGETS;
                break;
            case 'D':
                menuItem = BREADSTICKS;
                break;
            case 'E':
                break;
            default:
                cerr << "\nPlease pick a valid option\n";
        }

        if (itemLetter == 'A' || itemLetter == 'B' || itemLetter == 'C' || itemLetter == 'D')
            numItems++;

        cout << "\nNumber of items: " << setprecision(0) << numItems << endl;

        if (itemLetter == 'A' || itemLetter == 'B' || itemLetter == 'C' || itemLetter == 'D')
            total += menuItem;

        cout << "Total: " << setprecision(2) << total << endl;

    } while (itemLetter != 'E');

    cout << "\nThank you! Enjoy!" << endl;

    return 0;
}

//*****************************************************************************************************
/*

=====================================================
                Welcome to Pizza Palace
=====================================================
-----------------------------------------------------

        A       Pizza                     15.50
        B       Soda                       2.00
        C       Chicken Nuggets            7.00
        D       Breadsticks                9.75
        E       Exit

Please enter the next menu item Letter: A

Number of items: 1
Total: 15.50
-----------------------------------------------------

        A       Pizza                     15.50
        B       Soda                       2.00
        C       Chicken Nuggets            7.00
        D       Breadsticks                9.75
        E       Exit

Please enter the next menu item Letter: S

Please pick a valid option

Number of items: 1
Total: 15.50
-----------------------------------------------------

        A       Pizza                     15.50
        B       Soda                       2.00
        C       Chicken Nuggets            7.00
        D       Breadsticks                9.75
        E       Exit

Please enter the next menu item Letter: d

Please pick a valid option

Number of items: 1
Total: 15.50
-----------------------------------------------------

        A       Pizza                     15.50
        B       Soda                       2.00
        C       Chicken Nuggets            7.00
        D       Breadsticks                9.75
        E       Exit

Please enter the next menu item Letter: D

Number of items: 2
Total: 25.25
-----------------------------------------------------

        A       Pizza                     15.50
        B       Soda                       2.00
        C       Chicken Nuggets            7.00
        D       Breadsticks                9.75
        E       Exit

Please enter the next menu item Letter: C

Number of items: 3
Total: 32.25
-----------------------------------------------------

        A       Pizza                     15.50
        B       Soda                       2.00
        C       Chicken Nuggets            7.00
        D       Breadsticks                9.75
        E       Exit

Please enter the next menu item Letter: E

Number of items: 3
Total: 32.25

Thank you! Enjoy!

*/