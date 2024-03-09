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
    const int BUTTER = 1,
              EGG = 2,
              VANILLA = 2,
              FLOUR = 2,
              CHOC_CHIP = 2;
    const double BAKING_SODA = 0.75,
                 SUGAR = 1.5,
                 SALT = 0.25;
    int dozen,
        quantity;

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

    cout << "\nHow many dozens are you planning to make (Please give a multiple of four)?" << endl;
    cin >> dozen;

    quantity = dozen / 4;

    cout << "\n\n\t" << quantity * BUTTER << " cup butter\n"
         << "\t" << quantity * SUGAR << " cups white sugar\n"
         << "\t" << quantity * EGG << " eggs\n"
         << "\t" << quantity * VANILLA << " tsp vanilla extract\n"
         << "\t" << quantity * FLOUR << " cups all-purpose flour\n"
         << "\t" << quantity * BAKING_SODA << " baking soda\n"
         << "\t" << quantity * SALT << " tsp salt\n"
         << "\t" << quantity * CHOC_CHIP << " cups chocolate chips" << endl;

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