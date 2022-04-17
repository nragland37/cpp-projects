#include <iostream>

using namespace std;

void input(double values[], double weight[], int size);
double weightedMean(const double values[], const double weight[], int size);

//****************************************************************************************************

int main() {
    int size;
    // Take num array and corresponding weight
    // array and initialize it.
    cout << "How many values: ";
    cin >> size;

    double* values = new double[size];  // values
    double* weight = new double[size];  // weights

    input(values, weight, size);
    cout << "\nWeighted mean: " weightedMean(values, weight, size);

    delete[] values;
    delete[] weight;

    return 0;
}

//****************************************************************************************************

void input(double values[], double weight[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "\nEnter value " << i + 1 << ": ";
        cin >> values[i];
        cout << "Enter weight " << i + 1 << ":";
        cin >> weight[i];
    }
}

//****************************************************************************************************

// Function to calculate weighted mean.
double weightedMean(const double values[], const double weight[], int size) {
    double sum = 0,
           numWeight = 0;

    for (int i = 0; i < size; i++) {
        numWeight = numWeight + values[i] * weight[i];
        sum = sum + weight[i];
    }

    return numWeight / sum;
}