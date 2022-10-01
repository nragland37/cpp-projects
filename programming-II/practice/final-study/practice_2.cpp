#include <iostream>
using namespace std;

double total(double values[], int num);

main() {
    int num;
    double totals;
    double* values = nullptr;
    cin >> num;
    values = new double[num];
    for (int i = 0; i < num; ++i) {
        cout << "Enter value " << i << endl;
        cin >> values[i];
    }

    totals = total(values, num);
    cout << "Total: " << totals << endl;
    return 0;
}

double total(double values[], int num) {
    double total = 0;
    for (int i = 0; i < num; ++i) {
        total = total + values[i];
    }
    return total;
}