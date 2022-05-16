#include <fstream>
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int numbers[SIZE] = {1, 5, 8, 2, 9};

    fstream f;

    f.open("Data.txt", ios::out);
    for (int i = 0; i < SIZE; ++i) {
        f << numbers[i] << endl;
    }
    f.close();
    int num = 100;

    f.open("Data.txt", ios::in);
    if (f.is_open()) {
        f.close();
        f.open("Data.txt", ios::app);
        f << "Length of array: " << SIZE << endl;
        double avg;
        int sum = 0;
        for (int i = 0; i < SIZE; ++i) {
            sum += numbers[i];
        }
        avg = (static_cast<double>(sum) / SIZE);
        f << "average of array: " << avg << endl;
        int largest = numbers[0];
        for (int i = 0; i < SIZE; ++i) {
            if (largest < numbers[i]) {
                largest = numbers[i];
            }
        }
        f << "largest # of array: " << largest << endl;
    } else {
        cout << "file does not exist";
    }
    f.close();

    return 0;
}