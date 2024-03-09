//*****************************************************************************************************
//      Pointer and Array Manipulation
//
//      This program demonstrates various uses of arrays and pointers, including printing the values
//      and addresses of array elements, getting user input to access specific array elements, and
//      performing pointer arithmetic to add the values of two array elements.
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

//*****************************************************************************************************

void f1(int nums[], int size);
void f2(int *ptr, int size);
void f3(int nums[], int size);
void f4(int nums[], int size);

//*****************************************************************************************************

int main() {
    const int SIZE = 5;
    int numbers[SIZE] = {10, 22, 34, 48, 59};
    int *ptr = numbers;     // ptr points to the first element in the array

    f1(numbers, SIZE);
    f2(ptr, SIZE);
    f3(numbers, SIZE);
    f4(numbers, SIZE);

    return 0;
}

//*****************************************************************************************************

void f1(int nums[], int size) {
    cout << "-----------------------------\n"
         << " Values and Addresses: Array\n"
         << "-----------------------------" << endl;

    for (int i = 0; i < size; ++i)
        cout << "\nValue of index " << i << ": " << nums[i]
             << "\nAddress of index " << i << ": " << &nums[i] << endl;
}

//*****************************************************************************************************

void f2(int *ptr, int size) {
    cout << "\n-------------------------------\n"
         << " Values and Addresses: Pointer\n"
         << "-------------------------------" << endl;

    for (int i = 0; i < size; ++i)
        cout << "\nValue of index " << i << ": " << *(ptr + i)
             << "\nAddress of index " << i << ": " << ptr + i << endl;
}

//*****************************************************************************************************

void f3(int nums[], int size) {
    const int SIZE = 3;
    int *p = nums;
    int input;

    cout << "\n------------------------------------------------------------\n"
         << "  Enter three integer values within the range of the index\n"
         << "------------------------------------------------------------" << endl;

    for (int i = 0; i < SIZE; ++i) {
        while (true) {
            cout << "\nEnter value: ";
            cin >> input;

            if (input >= 0 && input < size) {
                p = &nums[input];
                break;
            } else {
                cerr << "\nError: Invalid Entry\n";
            }
        }

        cout << "Value of index " << input << ": " << *p
             << "\nAddress of index " << input << ": " << p << endl;
    }
}

//*****************************************************************************************************

void f4(int nums[], int size) {
    int *p1 = nums,
        *p2 = nums;
    int input1,
        input2;

    cout << "\n----------------------------------------------------------\n"
         << "  Enter two integer values within the range of the index\n"
         << "----------------------------------------------------------" << endl;

    while (true) {
        cout << "\nEnter value: ";
        cin >> input1;

        if (input1 >= 0 && input1 < size) {
            p1 = &nums[input1];
            break;
        } else {
            cerr << "\nError: Invalid Entry\n";
        }
    }

    cout << "Value of index " << input1 << ": " << *p1 << endl;

    while (true) {
        cout << "\nEnter value: ";
        cin >> input2;

        if (input2 >= 0 && input2 < size) {
            p2 = &nums[input2];
            break;
        } else {
            cerr << "\nError: Invalid Entry\n";
        }
    }

    cout << "Value of index " << input2 << ": " << *p2
         << "\n\nThe sum of index " << input1 << " and " << input2 << " is " << *p1 + *p2 << endl;
}

//*****************************************************************************************************
/*

-----------------------------
 Values and Addresses: Array
-----------------------------

Value of index 0: 10
Address of index 0: 0x83351ffc60

Value of index 1: 22
Address of index 1: 0x83351ffc64

Value of index 2: 34
Address of index 2: 0x83351ffc68

Value of index 3: 48
Address of index 3: 0x83351ffc6c

Value of index 4: 59
Address of index 4: 0x83351ffc70

-------------------------------
 Values and Addresses: Pointer
-------------------------------

Value of index 0: 10
Address of index 0: 0x83351ffc60

Value of index 1: 22
Address of index 1: 0x83351ffc64

Value of index 2: 34
Address of index 2: 0x83351ffc68

Value of index 3: 48
Address of index 3: 0x83351ffc6c

Value of index 4: 59
Address of index 4: 0x83351ffc70

------------------------------------------------------------
  Enter three integer values within the range of the index
------------------------------------------------------------

Enter value: 6

Error: Invalid Entry

Enter value: 7

Error: Invalid Entry

Enter value: 0
Value of index 0: 10
Address of index 0: 0x83351ffc60

Enter value: 1
Value of index 1: 22
Address of index 1: 0x83351ffc64

Enter value: 2
Value of index 2: 34
Address of index 2: 0x83351ffc68

----------------------------------------------------------
  Enter two integer values within the range of the index
----------------------------------------------------------

Enter value: 5

Error: Invalid Entry

Enter value: 6

Error: Invalid Entry

Enter value: 0
Value of index 0: 10

Enter value: 1
Value of index 1: 22

The sum of index 0 and 1 is 32

*/