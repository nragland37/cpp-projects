#include <iostream>

using namespace std;

int main() {
    int n;
    n = 10;
    int* ptr;
    ptr = &n;
    cout << n << endl;                 // 10
    cout << *ptr << endl;              // 10
    cout << &n << endl;                // address on n
    cout << &ptr << endl;              // address of ptr
    cout << ptr << endl;               // address of n / value assigned to ptr is address of n
    cout << *ptr + 1 << endl;          // 11
    n = 12;                            // reassigned
    cout << *ptr << endl;              // 12
    *ptr = *ptr + 8;                   // updates where ptr is pointing (12+8) = 20
    cout << n << " " << *ptr << endl;  // 20 20

    double d = 11.5;
    double* ptr2 = &d;
    *ptr2 += 8.5;                          // updates where ptr2 is pointing (11.5+8.5) = 20
    cout << d << endl;                     // 20
    cout << *ptr2 << endl;                 // 20
    *ptr2 = *ptr2 + *ptr2;                 // updates where ptr2 is pointing (20+20) 40
    cout << ptr2 << " " << *ptr2 << endl;  // address of d / 40
    d = *ptr2 + 10;                        // assigns d (40+10) 50
    cout << ptr2 << " " << *ptr2 << endl
         << endl;  // address of d / 50

    char* ptr4;
    char ch = 'A';
    ptr4 = &ch;
    cout << *ptr4 << endl
         << endl;  // A

    const int SIZE = 4;
    int numbers[SIZE] = {8, 10, 12, 14};
    cout << numbers[0] << endl;   // 8
    cout << numbers[2] << endl;   // 12
    cout << &numbers[0] << endl;  // address of location [0] in array
    cout << &numbers[2] << endl;  // address of location [2] in array
    int* ptr1 = numbers;          // initializes ptr1 to first address of array
    cout << *ptr1 << endl;        // 8
    ptr1 = &numbers[0];           // assgins ptr1 to address of [0]
    cout << *ptr1 << endl;        // 8
    cout << *ptr1 + 1 << endl;    // adds to value of address(8+1) = 9
    cout << *(ptr1 + 1) << endl;  // moves pointer ~ 10
    cout << *(ptr1 + 2) << endl;  // 12
    cout << *(ptr1 + 3) << endl   // 14
         << endl;

    int total = 0;
    ptr1 = numbers;         // assign to first value of array = 8
    cout << *ptr1 << endl;  // 8
    *ptr1 = numbers[2];     // changes the value of the pointer [0] becomes [2] == 8 replaced with 12
    cout << *ptr1 << endl;  // 10
    ptr1 = &numbers[0];
    cout << *ptr1 << endl
         << endl;  // 12
    for (int i = 0; i < SIZE; ++i) {
        total += *ptr1;
        cout << *ptr1 << endl;  // 12..10..12..14
        cout << total << endl;  // 12..22..34..48
        ++ptr1;                 // increments +1 in addresses of array
    }

    double d2[3] = {1.1, 3.3, 5.5};
    double* ptr3 = &d2[0];
    ptr1 = &numbers[0];
    double bigTotal = 0;
    for (int i = 0; i < 3; ++i) {
        bigTotal += *ptr1 + *ptr3;
        ++ptr1;
        ptr3 = ptr3 + 1;
    }
    cout << bigTotal << endl; //43.9
    ptr1 = new int;
    *ptr1 = 10;
    cout << *ptr1 + 20 << endl; //30
    ptr1 = new int[3];
    *ptr1 = 5;
    *(ptr1 + 1) = 10;
    ptr1[2] = 15;
    delete[] ptr1;

    int num[3] = {8, 10, 12};
    const int* p1 = &num[2];
    // int* const p2 = &num[0];
    cout << *p1 << endl; //12
    // cout << *p2 << endl;
    // p1 = &num[1];
    // p2 = &num[2];
    //*p1 = 20;
    //*p2 = 25;
    const int values[3] = {1, 9, 8};
    // int* p3 = &values[1];
    const int* p4 = &values[1];
    // int* const p5 = &values[1];
    const int* const p6 = &values[1];
    return 0;
}

/*

10
10
0xcec49ffb04
0xcec49ffaf8
0xcec49ffb04
11
12
20 20
20
20
0xcec49ffaf0 40
0xcec49ffaf0 50

A

8
12
0xcec49ffad0
0xcec49ffad8
8
8
9
10
12
14

8
12
12

12
12
10
22
12
34
14
48
43.9
30
12

*/