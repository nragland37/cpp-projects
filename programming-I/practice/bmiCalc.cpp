//****************************************************************************************************

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

//****************************************************************************************************
int main() {
    int feetHeightInInches,
        pounds,
        feet;

    double feetHeightInMeters,
        weightInKilo,
        inches,
        inchesHeightInMeters,
        totalHeightInMeters,
        bmi;

    const double kG_PER_POUND = 0.4536,
                 METERS_PER_INCH = 0.0254,
                 INCHES_PER_FOOT = 12,
                 EXPONENT = 2.0;

    cout << "Enter \"Weight\" in pounds and \"Height\" in feet and inches." << endl
         << endl;

    cout << "\"Weight\"" << endl;
    cout << "Pounds: ";
    cin >> pounds;

    cout << endl;

    cout << "\"Height\"" << endl;
    cout << "Feet: ";
    cin >> feet;
    cout << "Inches: ";
    cin >> inches;

    weightInKilo = pounds * kG_PER_POUND;
    inchesHeightInMeters = inches * METERS_PER_INCH;
    feetHeightInInches = feet * INCHES_PER_FOOT;
    feetHeightInMeters = feetHeightInInches * METERS_PER_INCH;
    totalHeightInMeters = feetHeightInMeters + inchesHeightInMeters;
    bmi = weightInKilo / pow(totalHeightInMeters, EXPONENT);

    cout << endl;

    cout << "BMI: " << fixed << setprecision(1) << bmi << endl;

    if (bmi > 30.0) {
        cout << "~ Obesity ~";
    } else if (bmi > 29.9) {
        cout << "~ Overweight ~";
    } else if (bmi > 25.0) {
        cout << "~ Overweight ~";
    } else if (bmi > 24.9) {
        cout << "~ Normal weight ~";
    } else if (bmi > 18.5) {
        cout << "~ Normal weight ~";
    } else {
        cout << "~ Underweight ~";
    }

    cout << endl
         << endl
         << endl;

    cout << "\t"
         << "\t"
         << "\"BMI Categories\"" << endl
         << "\t"
         << "Obesity = BMI of 30 or greater" << endl
         << "\t"
         << "Overweight = 25 ~ 29.9" << endl
         << "\t"
         << "Normal weight = 18.5 ~ 24.9" << endl
         << "\t"
         << "Underweight = < 18.5" << endl;

    cout << endl
         << endl;

    cout << "BMI is a number calculated from a persons weight and height." << endl
         << "BMI provides a fairly reliable indicator of body fatness for" << endl
         << "most people and is used to screen for weight categories that may" << endl
         << "lead to health problems." << endl;

    return 0;
}

//****************************************************************************************************