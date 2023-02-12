//*****************************************************************************************************
//
//		This program demonstrates the use of pointers. It shows the difference between dereferencing
//        a pointer and referencing a pointer, as well as the use of pointer arithmetic. The program
//        uses two pointers (p1 and p2) that point to two variables (n1 and n2), and uses pointer
//        arithmetic to manipulate the values to which the pointers point. The program also shows the
//        re-assignment of a pointer to a different variable, and demonstrates the use of pointers for
//        summing the values of multiple variables.
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

//*****************************************************************************************************

int main() {
    int n1 = 10,
        n2 = 25,
        n3 = 50,
        sum;

    int *p1 = &n1,     // pointer p1 points to n1 and holds the memory address of n1
        *p2 = &n2;

    cout << "Three variables: n1 n2 n3 \n"
         << "n1 = " << n1 << "\n"
         << "Memory address: " << &n1 << "\n\n"     // memory address of the variable n1
         << "n2 = " << n2 << "\n"
         << "Memory address: " << &n2 << "\n\n"
         << "n3 = " << n3 << "\n"
         << "Memory address: " << &n3 << endl;

    cout << "\n"
         << "Two pointers: p1 p2 \n"
         << "p1 \n"
         << "Memory address: " << &p1 << "\n"     // memory address of the pointer p1 variable (not the value it points to)
         << "p1 is pointing to n1 \n\n"
         << "p2 \n"
         << "Memory address: " << &p2 << "\n"
         << "p2 is pointing to n2" << endl;

    cout << "\n"
         << "Value at the address (n1) to which p1 points \n"
         << "*p1 = " << *p1 << "\n"     // dereference of the pointer p1 variable (value stored in the memory location it points to (same as n1))
         << "Memory address (n1) to which p1 points \n"
         << "p1 = " << p1 << "\n\n"     // memory address of the value p1 points to (same as &n1)
         << "Value at the address (n2) to which p2 points \n"
         << "*p2 = " << *p2 << "\n"
         << "Memory address (n2) to which p2 points \n"
         << "p2 = " << p2 << endl;

    *p1 *= 2;

    cout << "\n"
         << "Value of n1 has been multiplied by two using pointer arithmetic"
         << " (*p1 *= 2) \n"     // dereference p1 and multiply by 2 (same as n1 *= 2)
         << "n1 = " << n1 << endl;

    sum = *p1 + *p2;

    cout << "\n"
         << "Sum of values (n1 n2) to which p1 p2 point using pointer arithmetic"
         << " (sum = *p1 + *p2) \n"     // dereference p1 and p2 and add them together (same as n1 + n2)
         << "p1(20) + p2(25) = " << sum << endl;

    p1 = &n3;     // re-assign p1 to point to n3 and hold the memory address of n3

    cout << "\n"
         << "p1 re-assigned pointing to n3 \n"
         << "Value at the address (n3) to which p1 points \n"
         << "*p1 = " << *p1 << "\n"     // dereference p1 (same as n3 since p1 re-assigned to n3)
         << "Memory address (n3) to which p1 points \n"
         << "p1 = " << p1 << endl;

    sum = *p1 + *p2;

    cout << "\n"
         << "Sum of values (n3 n2) to which p1 p2 point using pointer arithmetic"
         << " (sum = *p1 + *p2) \n"     // dereference p1 (reassigned to n3) and p2 and add them together (same as n3 + n2)
         << "p1(50) + p2(25) = " << sum << endl;

    return 0;
}

//*****************************************************************************************************

/*

Three variables: n1 n2 n3
n1 = 10
Memory address: 0xef9b5ffde8

n2 = 25
Memory address: 0xef9b5ffde4

n3 = 50
Memory address: 0xef9b5ffde0

Two pointers: p1 p2
p1
Memory address: 0xef9b5ffdd8
p1 is pointing to n1

p2
Memory address: 0xef9b5ffdd0
p2 is pointing to n2

Value at the address (n1) to which p1 points
*p1 = 10
Memory address (n1) to which p1 points
p1 = 0xef9b5ffde8

Value at the address (n2) to which p2 points
*p2 = 25
Memory address (n2) to which p2 points
p2 = 0xef9b5ffde4

Value of n1 has been multiplied by two using pointer arithmetic (*p1 *= 2)
n1 = 20

Sum of values (n1 n2) to which p1 p2 point using pointer arithmetic (sum = *p1 + *p2)
p1(20) + p2(25) = 45

p1 re-assigned pointing to n3
Value at the address (n3) to which p1 points
*p1 = 50
Memory address (n3) to which p1 points
p1 = 0xef9b5ffde0

Sum of values (n3 n2) to which p1 p2 point using pointer arithmetic (sum = *p1 + *p2)
p1(50) + p2(25) = 75

*/