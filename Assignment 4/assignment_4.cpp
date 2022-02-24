//****************************************************************************************************
// 		    File:                 assignment_4.cpp
//
//		    Student:              Nicholas Ragland
//
//		    Assignment:           Program #4
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  February 21, 2022
//
//          ..........
//
//****************************************************************************************************

#include <iostream>

using namespace std;

void f1(int nums[], int size);
void f2(int *ptr, int size);
void f3(int nums[], int size);
void f4(int nums[], int size);

//****************************************************************************************************

int main() {
    const int SIZE = 5;
    int numbers[SIZE] = {10, 22, 34, 48, 59};
    int *ptr = nullptr;
    ptr = &numbers[0];

    f1(numbers, SIZE);
    cin.get();
    f2(ptr, SIZE);
    cin.get();
    f3(numbers, SIZE);
    f4(numbers, SIZE);

    return 0;
}

//****************************************************************************************************

void f1(int nums[], int size) {
    cout << "---------------------------------" << endl;
    cout << "Values and Addresses ~ Array" << endl;
    cout << "---------------------------------" << endl;

    for (int i = 0; i < size; ++i) {
        cout << "Value of index " << i << ": "
             << nums[i] << " " << endl;
        cout << "Address of index " << i << ": "
             << &nums[i] << " " << endl;
    }
}

//****************************************************************************************************

void f2(int *ptr, int size) {
    cout << "---------------------------------" << endl;
    cout << "Values and Addresses ~ Pointer" << endl;
    cout << "---------------------------------" << endl;

    for (int i = 0; i < size; ++i) {
        cout << "Value of index " << i << ": "
             << *(ptr + i) << endl;
        cout << "Address of index " << i << ": "
             << ptr + i << " " << endl;
    }
}

//****************************************************************************************************

void f3(int nums[], int size) {
    int *p = nullptr,
        input;
    cout << "-------------------------------------------------" << endl;
    cout << "Enter two *integer* values within the range of the index:" << endl;

    for (int i = 0; i < 3; ++i) {
        do {
            cin >> input;
            cout << "input:" << input;
        } while (input >= nums[0] && input <= nums[4]);
    }
}
//****************************************************************************************************

void f4(int nums[], int size) {
    int *p1 = nullptr,
        *p2 = nullptr,
        num1,
        num2;
    cout << "-------------------------------------------------" << endl;
    cout << "Enter two *integer* values within the range of the index:" << endl;
    cin >> num1 >> num2;

    while (num1 < nums[0] || num2 < nums[0] ||
           num1 > nums[4] || num2 > nums[4]) {
        cout << "\n*Invalid Entry*" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Enter two *integer* values within the range of the index: " << endl;
        cin >> num1 >> num2;
    }
}
/*
    for (int i = 0; i < SIZE; ++i) {
        cin >> nums[size];

        while (nums[size] < nums[0] || nums[size] > nums[4]) {
            cout << "\n*Invalid Entry*" << endl;
            cout << "Enter three *integer* values within the range of the index: " << endl;
            cin >> nums[size];
        }

        p = &nums[size];
        cout << "Value of index " << i << ": "
             << *(p + i) << endl;
        cout << "Address of index " << i << ": "
             << p + i << " " << endl;
    }

*/