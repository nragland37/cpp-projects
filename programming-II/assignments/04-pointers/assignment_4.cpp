//*****************************************************************************************************
//
//		This program creates an array of integers, and uses a pointer and array notation to display
//      the values and memory addresses of each element in the array. The program also allows the user
//      to input values and display the value and memory address at that index.
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

void f1(int nums[], int size);
void f2(int *ptr, int size);
void f3(int nums[], int size);
void f4(int nums[], int size);

//*****************************************************************************************************

int main() {
    const int SIZE = 5;
    int numbers[SIZE] = {10, 22, 34, 48, 59},
        *ptr = numbers;     // pointer ptr points to the first element in the array numbers

    f1(numbers, SIZE);
    f2(ptr, SIZE);
    f3(numbers, SIZE);
    f4(numbers, SIZE);

    return 0;
}

//*****************************************************************************************************

void f1(int nums[], int size) {
    cout << "----------------------------- \n"
         << " Values and Addresses: Array \n"
         << "-----------------------------" << endl;

    for (int i = 0; i < size; ++i) {
        cout << "\n"
             << "Value of index " << i << ": "
             << nums[i] << " " << endl;     // array notation to get the value at that index
        cout << "Address of index " << i << ": "
             << &nums[i] << " " << endl;     // array notation to get the address of that index
    }
}

//*****************************************************************************************************

void f2(int *ptr, int size) {
    cout << "\n"
         << "------------------------------- \n"
         << " Values and Addresses: Pointer \n"
         << "-------------------------------" << endl;

    for (int i = 0; i < size; ++i) {
        cout << "\n"
             << "Value of index " << i << ": "
             << *(ptr + i) << endl;     // dereference pointer ptr and add i to the address to get the value at that index
        cout << "Address of index " << i << ": "
             << ptr + i << " " << endl;     // add i to the address to get the address of that index
    }
}

//*****************************************************************************************************

void f3(int nums[], int size) {
    const int SIZE = 3;
    int *p = nums,     // pointer p points to the first element in the array nums
        input;

    cout << "\n"
         << "------------------------------------------------------------ \n"
         << "  Enter three integer values within the range of the index \n"
         << "------------------------------------------------------------" << endl;
    for (int i = 0; i < SIZE; ++i) {
        while (true) {
            cout << "\n"
                 << "Enter value: ";
            cin >> input;

            if (input >= 0 && input < size) {
                p = &nums[input];
                break;
            } else {
                cerr << "\n"
                     << "Error: Invalid Entry" << endl;     // cerr is unbuffered and best for error handling
            }
        }
        cout << "Value of index " << input << ": "
             << *p << endl;
        cout << "Address of index " << input << ": "
             << p << " " << endl;
    }
}

//*****************************************************************************************************

void f4(int nums[], int size) {
    const int SIZE = 2;
    int *p1 = nums,
        *p2 = nums,
        input1,
        input2;

    cout << "\n"
         << "---------------------------------------------------------- \n"
         << "  Enter two integer values within the range of the index \n"
         << "----------------------------------------------------------" << endl;
    while (true) {
        cout << "\n"
             << "Enter value: ";
        cin >> input1;

        if (input1 >= 0 && input1 < size) {
            p1 = &nums[input1];     // pointer p1 points to the address of the value at index input1
            break;
        } else {
            cerr << "\n"
                 << "Error: Invalid Entry" << endl;
        }
    }

    cout << "Value of index " << input1 << ": "
         << *p1 << endl;     // dereference pointer p1 to get the value at that index

    while (true) {
        cout << "\n"
             << "Enter value: ";
        cin >> input2;

        if (input2 >= 0 && input2 < size) {
            p2 = &nums[input2];
            break;
        } else {
            cerr << "\n"
                 << "Error: Invalid Entry" << endl;
        }
    }

    cout << "Value of index " << input2 << ": "
         << *p2 << endl;     // dereference pointer p2 to get the value at that index

    cout << "\n"
         << "The sum of index " << input1 << " and " << input2 << " is " << *p1 + *p2 << endl;     // dereference pointer p1 and p2 to get the value at that index and add them together (pointer arithmetic)
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