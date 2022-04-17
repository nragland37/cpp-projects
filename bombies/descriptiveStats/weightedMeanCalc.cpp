#include <iostream>

using namespace std;

void input(double values[], double weight[], int size);
double weightedMean(const double values[], const double weight[], int size);

//****************************************************************************************************

int main() {
    int size;
    double weightMean;

    cout << "How many values: ";
    cin >> size;

    double* values = new double[size];  // values
    double* weight = new double[size];  // weights

    input(values, weight, size);
    weightMean = weightedMean(values, weight, size);
    cout << "\nWeighted mean: " << weightMean << endl;

    delete[] values;
    delete[] weight;

    return 0;
}

//****************************************************************************************************

void input(double values[], double weight[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "\nEnter value " << i + 1 << ": ";
        cin >> values[i];
        cout << "Enter weight " << i + 1 << ": ";
        cin >> weight[i];
    }
}

//****************************************************************************************************

// Function to calculate weighted mean.
double weightedMean(const double values[], const double weight[], int size) {
    double sum = 0,
           numWeight = 0;

    for (int i = 0; i < size; ++i) {
        numWeight += values[i] * weight[i];
        sum += weight[i];
    }

    return numWeight / sum;
}