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
    int numbers[SIZE] = {10, 22, 34, 48, 59},
        *ptr = numbers;

    f1(numbers, SIZE);
    cin.get();
    f2(ptr, SIZE);
    cin.get();
    f3(numbers, SIZE);
    cout << endl;
    f4(numbers, SIZE);

    return 0;
}

//****************************************************************************************************

void f1(int nums[], int size) {
    cout << "-----------------------------" << endl;
    cout << "Values and Addresses ~ Array" << endl;
    cout << "-----------------------------" << endl;

    for (int i = 0; i < size; ++i) {
        cout << "\nValue of index " << i << ": "
             << nums[i] << " " << endl;
        cout << "Address of index " << i << ": "
             << &nums[i] << " " << endl;
    }
}

//****************************************************************************************************

void f2(int *ptr, int size) {
    cout << "-------------------------------" << endl;
    cout << "Values and Addresses ~ Pointer" << endl;
    cout << "-------------------------------" << endl;

    for (int i = 0; i < size; ++i) {
        cout << "\nValue of index " << i << ": "
             << *(ptr + i) << endl;
        cout << "Address of index " << i << ": "
             << ptr + i << " " << endl;
    }
}

//****************************************************************************************************

void f3(int nums[], int size) {
    const int SIZE = 3;
    int *p = nums,
        input;
    cout << "------------------------------------------------------------" << endl;
    cout << "Enter *three integer* values within the range of the index:" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (int i = 0; i < SIZE; ++i) {
        while (true) {
            cout << "\nEnter value: ";
            cin >> input;
            if (input >= 0 && input < size) {
                p = &nums[input];
                break;
            } else {
                cout << "\n*Invalid Entry*" << endl;
            }
        }
        cout << "Value of index " << input << ": "
             << *p << endl;
        cout << "Address of index " << input << ": "
             << p << " " << endl;
    }
}
//****************************************************************************************************

void f4(int nums[], int size) {
    const int SIZE = 2;
    int *p1 = nums,
        *p2 = nums,
        input1,
        input2;

    cout << "----------------------------------------------------------" << endl;
    cout << "Enter *two integer* values within the range of the index:" << endl;
    cout << "----------------------------------------------------------" << endl;

    while (true) {
        cout << "\nEnter value: ";
        cin >> input1;
        if (input1 >= 0 && input1 < size) {
            p1 = &nums[input1];
            break;
        } else {
            cout << "\n*Invalid Entry*" << endl;
        }
    }
    cout << "Value of index " << input1 << ": "
         << *p1 << endl;

    while (true) {
        cout << "\nEnter value: ";
        cin >> input2;
        if (input2 >= 0 && input2 < size) {
            p2 = &nums[input2];
            break;
        } else {
            cout << "\n*Invalid Entry*" << endl;
        }
    }
    cout << "Value of index " << input2 << ": "
         << *p2 << endl;

    cout << "\nThe sum of index " << input1 << " and " << input2 << " is " << *p1 + *p2 << endl;
}

/*

-----------------------------
Values and Addresses ~ Array
-----------------------------

Value of index 0: 10
Address of index 0: 0xeea55ffd40

Value of index 1: 22
Address of index 1: 0xeea55ffd44

Value of index 2: 34
Address of index 2: 0xeea55ffd48

Value of index 3: 48
Address of index 3: 0xeea55ffd4c

Value of index 4: 59
Address of index 4: 0xeea55ffd50

-------------------------------
Values and Addresses ~ Pointer
-------------------------------

Value of index 0: 10
Address of index 0: 0xeea55ffd40

Value of index 1: 22
Address of index 1: 0xeea55ffd44

Value of index 2: 34
Address of index 2: 0xeea55ffd48

Value of index 3: 48
Address of index 3: 0xeea55ffd4c

Value of index 4: 59
Address of index 4: 0xeea55ffd50

------------------------------------------------------------
Enter *three integer* values within the range of the index:
------------------------------------------------------------

Enter value: 5

*Invalid Entry*

Enter value: 6

*Invalid Entry*

Enter value: 7

*Invalid Entry*

Enter value: 0
Value of index 0: 10
Address of index 0: 0xeea55ffd40

Enter value: 1
Value of index 1: 22
Address of index 1: 0xeea55ffd44

Enter value: 2
Value of index 2: 34
Address of index 2: 0xeea55ffd48

----------------------------------------------------------
Enter *two integer* values within the range of the index:
----------------------------------------------------------

Enter value: 5

*Invalid Entry*

Enter value: 6

*Invalid Entry*

Enter value: 0
Value of index 0: 10

Enter value: 1
Value of index 1: 22

The sum of index 0 and 1 is 32

*/