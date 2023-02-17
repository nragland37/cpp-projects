//*****************************************************************************************************
//
//		The "Hello, World!" program is often used as a first program for people learning to code due
//      to its simplicity, clear output, standardization, and familiarity across different programming
//      languages.
//
//*****************************************************************************************************

#define _USE_MATH_DEFINES     // makes certain constants available in cmath (M_PI, M_E, etc.) (some compilers require this to be defined)
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
    cout << "Welcome to the Circumference Calculation Program \n"
         << "Enter the radius and I'll find the circumference of the circle! \n" << endl;
}

//*****************************************************************************************************

float readRadius() {
    float posInput;     // positive input beecause radius must be positive

    do {
        cout << "Please enter a positive radius: ";
        cin >> posInput;

        cout << endl;
    } while (posInput <= 0);     // while input is not positive, keep asking for input

    return posInput;     // return the positive input to main() and assign it to radius
}

//*****************************************************************************************************

float findCircumf(float radius) {
    float circumf;

    circumf = (2 * M_PI) * radius;     // circumf = (2 * pi) * radius

    return circumf;     // or return (2 * M_PI) * radius;
}

//*****************************************************************************************************

void printResult(float radius, float circumf) {
    cout << "You entered the radius: " << radius << "\n"
         << "The circumference of the circle: " << circumf << "\n" << endl;
}

//*****************************************************************************************************

void signOff() {
    cout << "Have A Great Day!" << endl;
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