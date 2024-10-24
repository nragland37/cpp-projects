//*****************************************************************************************************
//      Chocolate Chip Cookies Recipe - Scaling Ingredients
//
//      This program is a simple recipe for making Chocolate Chip Cookies that can be scaled to any
//      number of dozens.
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

//*****************************************************************************************************

int main() {

     // These are the ingredients required to bake (minimum) 4 dozen of Chocolate Chip Cookies.
    const int BUTTER = 1,
              EGG = 2,
              VANILLA = 2,
              FLOUR = 2,
              CHOC_CHIP = 2;

    const double BAKING_SODA = 0.75, // double datatype used here becuase of decimal values.
                 SUGAR = 1.5,
                 SALT = 0.25;
                 
    int dozen,
          quantity_of_cookies;


    cout << "Chocolate Chip Cookies - 4 dozen cookies" << endl;
    cout << "\n\t" << BUTTER << " cup butter\n"
         << "\t" << SUGAR << " cups white sugar\n"
         << "\t" << EGG << " eggs\n"
         << "\t" << VANILLA << " tsp vanilla extract\n"
         << "\t" << FLOUR << " cups all-purpose flour\n"
         << "\t" << BAKING_SODA << " baking soda\n"
         << "\t" << SALT << " tsp salt\n"
         << "\t" << CHOC_CHIP << " cups chocolate chips" << endl;


    cout << "\nPreheat oven to 350 F. In a large bowl, mix butter, sugar, eggs, and vanilla\n"
         << "until light and fluffy. In a separate bowl, combine flour, baking soda, and\n"
         << "salt; stir into the butter mixture until well-blended stir in chocolate chips.\n"
         << "Drop by rounded teaspoons onto ungreased cookie sheets. Bake 8-10 minutes until\n"
         << "just set. Cool slightly on cookie sheets before transferring to cooling racks\n"
         << "to cool completely." << endl;


    cout << "\nHow many dozens are you planning to make (Please give a number greater or equal than 4 and also to be multiple of four)?" << endl;
    cin >> dozen;

     // Quantity of cookies will be returned in dozen, you can multiply dozens by 12. ( example : 2 dozen of cookies * 12 = 24 cookies )...
    quantity_of_cookies = dozen / 4;

    cout << "\n\n\t" << quantity_of_cookies * BUTTER << " cup butter\n"
         << "\t" << quantity_of_cookies * SUGAR << " cups white sugar\n"
         << "\t" << quantity_of_cookies * EGG << " eggs\n"
         << "\t" << quantity_of_cookies * VANILLA << " tsp vanilla extract\n"
         << "\t" << quantity_of_cookies * FLOUR << " cups all-purpose flour\n"
         << "\t" << quantity_of_cookies * BAKING_SODA << " baking soda\n"
         << "\t" << quantity_of_cookies * SALT << " tsp salt\n"
         << "\t" << quantity_of_cookies * CHOC_CHIP << " cups chocolate chips" << endl << endl;

    return 0;
}

//*****************************************************************************************************
/*

Chocolate Chip Cookies - 4 dozen cookies

        1 cup butter
        1.5 cups white sugar
        2 eggs
        2 tsp vanilla extract
        2 cups all-purpose flour
        0.75 baking soda
        0.25 tsp salt
        2 cups chocolate chips

Preheat oven to 350 F. In a large bowl, mix butter, sugar, eggs, and vanilla
until light and fluffy. In a separate bowl, combine flour, baking soda, and
salt; stir into the butter mixture until well-blended stir in chocolate chips.
Drop by rounded teaspoons onto ungreased cookie sheets. Bake 8-10 minutes until
just set. Cool slightly on cookie sheets before transferring to cooling racks
to cool completely.

How many dozens are you planning to make (Please give a multiple of four)?
12


        3 cup butter
        4.5 cups white sugar
        6 eggs
        6 tsp vanilla extract
        6 cups all-purpose flour
        2.25 baking soda
        0.75 tsp salt
        6 cups chocolate chips

*/