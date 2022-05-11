#include <iostream>

using namespace std;

double* update(const double nums[], int size);

//****************************************************************************************************

int main() {
    const int SIZE = 3;
    double nums[SIZE] = {3.0, 5.5, 9.2};
    double* newNums = new double[SIZE];
    newNums = update(nums, SIZE);

    cout << "The array" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << nums[i] << endl;
    }
    cout << "\nThe updated array" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << newNums[i] << endl;
    }

    delete[] newNums;

    return 0;
}

//****************************************************************************************************

double* update(const double nums[], int size) {
    double* arr = new double[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = nums[i] * nums[0];
    }

    return arr;
}

/*

The array
3
5.5
9.2

The updated array
9
16.5
27.6

*/