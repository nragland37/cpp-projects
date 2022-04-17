#include <cmath>
#include <iostream>

using namespace std;

void input(double values[], int size);
double calculateSD(double values[], int size);

//****************************************************************************************************

int main() {
    int size;
    double standardDev;

    cout << "How many values: ";
    cin >> size;

    double* values = new double[size];
    input(values, size);
    standardDev = calculateSD(values, size);
    cout << "\nStandard Deviation: " << standardDev << endl;

    return 0;
}

//****************************************************************************************************

void input(double values[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "\nEnter value " << i + 1 << ": ";
        cin >> values[i];
    }
}

//****************************************************************************************************

double calculateSD(double values[], int size) {
    double sum = 0,
           mean,
           standardDeviation = 0;

    for (int i = 0; i < size; ++i) {
        sum += values[i];
    }

    mean = sum / size;

    for (int i = 0; i < size; ++i) {
        standardDeviation += pow(values[i] - mean, 2);
    }

    return sqrt(standardDeviation / (size - 1));
}