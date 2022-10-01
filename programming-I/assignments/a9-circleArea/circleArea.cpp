//****************************************************************************************************
// 			File:                 circleArea.cpp
//
//			Student:              Nicholas Ragland
//
//			Assignment:           Program #9
//
//          Course Name:          Programming 1
//
//          Course Number:        COSC 1550 - 03
//
//          Due:                  November 11, 2021
//
//          This program takes a positive number from the user as the radius of a circle and
//			calculates its circumference.
//
//****************************************************************************************************

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

void greet();
float readRadius();
float findCircumf(float);
void printResult(float, float);
void signOff();

//****************************************************************************************************
int main() {
    float radius,
        circumf;

    greet();
    radius = readRadius();
    circumf = findCircumf(radius);
    printResult(radius, circumf);
    signOff();

    return 0;
}
//****************************************************************************************************
void greet() {
    cout << "Welcome to the Circumference Calculation Program" << endl;
    cout << "Enter the radius and I'll find the circumference of the circle!" << endl;
    cout << endl;
}
//****************************************************************************************************
float readRadius() {
    float posInput;

    do {
        cout << "Please enter a positive radius: ";
        cin >> posInput;

        cout << endl;
    } while (posInput <= 0);

    return posInput;
}
//****************************************************************************************************
float findCircumf(float radius) {
    float circumf;

    circumf = (2 * M_PI) * radius;

    return circumf;
}
//****************************************************************************************************
void printResult(float radius, float circumf) {
    cout << "You entered the radius: " << radius << endl;
    cout << "The circumference of the circle: " << circumf << endl;
    cout << endl;
}
//****************************************************************************************************
void signOff() {
    cout << "Have A Great Day!" << endl;
}
//****************************************************************************************************
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