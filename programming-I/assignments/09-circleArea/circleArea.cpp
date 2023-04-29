//*****************************************************************************************************
//      Circumference Calculation
//
//      This program is a simple circumference calculator for a circle.
//
//*****************************************************************************************************

#define _USE_MATH_DEFINES     // needed to define M_PI with math.h or cmath on some platforms
#include <cmath>              // library for math functions (sin(), cos(), tan(), pow(), sqrt(), etc.) and constants (M_PI, M_E, etc.)
#include <iostream>
using namespace std;

//*****************************************************************************************************

void greet();     // function prototype
float readRadius();
float findCircumf(float);
void printResult(float, float);
void signOff();

//*****************************************************************************************************

int main() {
    float radius,
        circumf;

    greet();

    radius = readRadius();             // radius is assigned the value returned by readRadius()
    circumf = findCircumf(radius);     // radius is passed by value to findCircumf() and circumf is assigned the value returned by findCircumf()
    
    printResult(radius, circumf);      // radius and circumf are passed by value to printResult() and the values are printed
    signOff();

    return 0;
}

//*****************************************************************************************************

void greet() {
    cout << "Welcome to the Circumference Calculation Program\n"
         << "Enter the radius and I'll find the circumference of the circle!" << endl;
}

//*****************************************************************************************************

float readRadius() {
    float posInput;     // positive input beecause radius must be positive

    do {
        cout << "\nPlease enter a positive radius: ";
        cin >> posInput;
    } while (posInput <= 0);     // while input is not positive, keep asking for input

    return posInput;     // return the positive input to main() and assign it to radius
}

//*****************************************************************************************************

float findCircumf(float radius) {
    float circumf;

    circumf = (2 * M_PI) * radius;

    return circumf;     // or return (2 * M_PI) * radius;
}

//*****************************************************************************************************

void printResult(float radius, float circumf) {
    cout << "\nYou entered the radius: " << radius
         << "\nThe circumference of the circle: " << circumf << endl;
}

//*****************************************************************************************************

void signOff() {
    cout << "\nHave A Great Day!" << endl;
}

//*****************************************************************************************************

/*

Welcome to the Circumference Calculation Program
Enter the radius and I'll find the circumference of the circle!

Please enter a positive radius: 0

Please enter a positive radius: -2.2

Please enter a positive radius: 3.21

You entered the radius: 3.21
The circumference of the circle: 20.169

Have A Great Day!

*/