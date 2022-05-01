// CPP code to calculate expected value
#include <iostream>
using namespace std;

// Function to calculate expectation
float calc_Expectation(float value[], float size) {
    float prb = 0;
    // calculating expectation overall
    float sum = 0;
    char entry;

    cout << "Probability of event (decimal ): ";
    cin >> prb;
    for (int i = 0; i < size; i++) {
        cout << "Value of event " << i + 1 << ": ";
        cin >> value[i];
        cout << "Same probability for event " << i + 1 << "? (Y/N):";
        cin >> entry;
        if (entry == 'n' || entry == 'N') {
            cout << "Probability of event " << i + 1 << " (decimal): ";
            cin >> prb;
        }
        sum += value[i] * prb;
    }
    // returning expectation as sum
    return sum;
}

int main() {
    int size;
    float expect,
        n = 6.0;

    cout << "How many 'value of events': ";
    cin >> size;

    float *value = new float[size];

    // Function for calculating expectation
    expect = calc_Expectation(value, size);

    // Display expectation of given array
    cout << "\nExpected value: "
         << expect << "\n";
    return 0;
}