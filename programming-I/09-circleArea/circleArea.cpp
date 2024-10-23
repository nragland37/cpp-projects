//*****************************************************************************************************
//      Circumference Calculation
//
//      This program is a simple circumference calculator for a circle.
//
//*****************************************************************************************************

#define _USE_MATH_DEFINES     // needed to define M_PI with math.h or cmath on some platforms
#include <cmath>
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
    float radius;
    float circumf;

    greet(); // Intro of the program...

    radius = readRadius(); // Gets the radius from the user and if user enters a negative number, the loop keeps executing until the positive number is entered...

    circumf = findCircumf(radius); // Function to calculate the circumference of a circle...

    printResult(radius, circumf); // Displays the result...
    signOff(); // Outro of the program....

    return 0;
}

//*****************************************************************************************************

void greet() {

    cout << "Welcome to the Circumference Calculation Program\n"
         << "Enter the radius and I'll find the circumference of the circle!" << endl;

}

//*****************************************************************************************************

float readRadius() { 
    float radiusInput;

    do {

        cout << "\nPlease enter a positive radius: ";
        cin >>radiusInput;

    } while (radiusInput <= 0);

    return radiusInput;
}

//*****************************************************************************************************

float findCircumf(float radius) {
    float circumf; // circumference

    circumf = (2 * M_PI) * radius;

    return circumf;     // return (2 * M_PI) * radius;
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