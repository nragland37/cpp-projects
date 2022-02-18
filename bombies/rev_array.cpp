#include <iostream>

using namespace std;

const int LIST_LEN = 10;

void print_array(int list[LIST_LEN]) {
    for (int i = 0; i < LIST_LEN; ++i) {
        cout << list[i] << " ";
    }
}

void swap(int list[LIST_LEN], int i, int j) {
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

int main() {
    int list[LIST_LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Initial array: ";
    print_array(list);
    cout << endl;

    for (int i = 0; i < LIST_LEN / 2; ++i) {
        swap(list, i, LIST_LEN - i - 1);
    }

    cout << "Reversed_array: ";
    print_array(list);
    cout << endl;
}