#include <iostream>
using namespace std;

double percent(double a, double b);

int main() {
    double a,
        b;

    cout << "Percentage Difference Calculator" << endl;
    cout << "\nValue 1: ";
    cin >> a;
    cout << "Value 2: ";
    cin >> b;
    cout << "\nDifference: " << percent(a, b) << "%";

    return 0;
}

double percent(double a, double b) {
    double result = 0;
    result = ((a - b) / ((a + b) / 2)) * 100;

    return result;
}
