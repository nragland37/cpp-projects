//*****************************************************************************************************
//
//		This program is a simulation of a menu ordering system for a restaurant called "Pizza Palace".
//      The menu consists of 4 items: Pizza, Soda, Chicken Nuggets, and Breadsticks. The program
//      displays the menu options and prompts the user to enter the letter of the item they would like
//      to order. The program then keeps track of the number of items ordered and the running total
//      for the order. The user can continue ordering items until they choose to exit the program by
//      entering 'E'. The final total for the order is displayed at the end of the program.
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

    cout << "===================================================== \n"     // \n is a new line character
         << "\t\t" << "Welcome to Pizza Palace \n"                         // tab character to indent the text
         << "=====================================================" << endl;

    cout << fixed << setprecision(2) << right;

    do {
        cout << "----------------------------------------------------- \n\n"
             << "\t" << "A" << "\t" << "Pizza" << setw(26) << PIZZA << "\n"
             << "\t" << "B" << "\t" << "Soda" << setw(27) << SODA << "\n"
             << "\t" << "C" << "\t" << "Chicken Nuggets" << setw(16) << CHICKEN_NUGGETS << "\n"
             << "\t" << "D" << "\t" << "Breadsticks" << setw(20) << BREADSTICKS << "\n"
             << "\t" << "E" << "\t" << "Exit" << "\n" << endl;

        cout << "Please enter the next menu item Letter: ";
        cin >> itemLetter;

        cout << endl;

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
                cout << "Thank you! Enjoy! \n" << endl;
                break;
            default:
                cout << "Please pick a valid option \n" << endl;
        }

        if (itemLetter == 'A' || itemLetter == 'B' || itemLetter == 'C' || itemLetter == 'D')
            numItems++;     // if the user enters a valid menu item, the number of items will increase by 1

        cout << "Number of items so far: " << setprecision(0) << numItems << endl;

        if (itemLetter == 'A' || itemLetter == 'B' || itemLetter == 'C' || itemLetter == 'D')
            total += menuItem;

        cout << "Your total so far: " << setprecision(2) << total << "\n" << endl;

    } while (itemLetter != 'E');     // while the user does not enter 'E' for exit the program will continue
    
    cout << "Your total is " << total << endl;
    
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

Number of items so far: 1
Your total so far: 15.50

-----------------------------------------------------

        A       Pizza                     15.50
        B       Soda                       2.00
        C       Chicken Nuggets            7.00
        D       Breadsticks                9.75
        E       Exit

Please enter the next menu item Letter: S

Please pick a valid option

Number of items so far: 1
Your total so far: 15.50

-----------------------------------------------------

        A       Pizza                     15.50
        B       Soda                       2.00
        C       Chicken Nuggets            7.00
        D       Breadsticks                9.75
        E       Exit

Please enter the next menu item Letter: d

Please pick a valid option

Number of items so far: 1
Your total so far: 15.50

-----------------------------------------------------

        A       Pizza                     15.50
        B       Soda                       2.00
        C       Chicken Nuggets            7.00
        D       Breadsticks                9.75
        E       Exit

Please enter the next menu item Letter: D

Number of items so far: 2
Your total so far: 25.25

-----------------------------------------------------

        A       Pizza                     15.50
        B       Soda                       2.00
        C       Chicken Nuggets            7.00
        D       Breadsticks                9.75
        E       Exit

Please enter the next menu item Letter: C

Number of items so far: 3
Your total so far: 32.25

-----------------------------------------------------

        A       Pizza                     15.50
        B       Soda                       2.00
        C       Chicken Nuggets            7.00
        D       Breadsticks                9.75
        E       Exit

Please enter the next menu item Letter: E

Thank you! Enjoy!

Number of items so far: 3
Your total so far: 32.25

Your total is 32.25

*/