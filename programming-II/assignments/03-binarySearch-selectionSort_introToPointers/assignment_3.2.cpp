//*****************************************************************************************************
//      Pointer Variables and Pointer Arithmetic Example
//      
//      This program demonstrates the use of pointers and pointer arithmetic to manipulate and perform
//      operations
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

    cout << "Three variables: n1 n2 n3\n"
         << "n1 = " << n1
         << "\nMemory address: " << &n1     // memory address of the variable n1
         << "\n\nn2 = " << n2
         << "\nMemory address: " << &n2
         << "\n\nn3 = " << n3
         << "\nMemory address: " << &n3 << endl;

    cout << "\nTwo pointers: p1 p2\n"
         << "p1\n"
         << "Memory address: " << &p1     // memory address of the pointer p1 variable (not the value it points to)
         << "\np1 is pointing to n1\n\n"
         << "p2\n"
         << "Memory address: " << &p2
         << "\np2 is pointing to n2" << endl;

    cout << "\nValue at the address (n1) to which p1 points\n"
         << "*p1 = " << *p1     // dereference of the pointer p1 variable (value stored in the memory location it points to (same as n1))
         << "\nMemory address (n1) to which p1 points\n"
         << "p1 = " << p1     // memory address of the value p1 points to (same as &n1)
         << "\n\nValue at the address (n2) to which p2 points\n"
         << "*p2 = " << *p2
         << "\nMemory address (n2) to which p2 points\n"
         << "p2 = " << p2 << endl;

    *p1 *= 2;

    cout << "\nValue of n1 has been multiplied by two using pointer arithmetic (*p1 *= 2)\n"     // dereference p1 and multiply by 2 (same as n1 *= 2)
         << "n1 = " << n1 << endl;

    sum = *p1 + *p2;

    cout << "\nSum of values (n1 n2) to which p1 p2 point using pointer arithmetic (sum = *p1 + *p2)\n"     // dereference p1 and p2 and add them together (same as n1 + n2)
         << "p1(20) + p2(25) = " << sum << endl;

    p1 = &n3;     // re-assign p1 to point to n3 and hold the memory address of n3

    cout << "\np1 re-assigned pointing to n3\n"
         << "Value at the address (n3) to which p1 points\n"
         << "*p1 = " << *p1     // dereference p1 (same as n3 since p1 re-assigned to n3)
         << "\nMemory address (n3) to which p1 points\n"
         << "p1 = " << p1 << endl;

    sum = *p1 + *p2;

    cout << "\nSum of values (n3 n2) to which p1 p2 point using pointer arithmetic (sum = *p1 + *p2)\n"     // dereference p1 (reassigned to n3) and p2 and add them together (same as n3 + n2)
         << "p1(50) + p2(25) = " << sum << endl;

    return 0;
}

//*****************************************************************************************************

/*

Three variables: n1 n2 n3
n1 = 10
Memory address: 0xc1be3ff978

n2 = 25
Memory address: 0xc1be3ff974

n3 = 50
Memory address: 0xc1be3ff970

Two pointers: p1 p2
p1
Memory address: 0xc1be3ff968
p1 is pointing to n1

p2
Memory address: 0xc1be3ff960
p2 is pointing to n2

Value at the address (n1) to which p1 points
*p1 = 10
Memory address (n1) to which p1 points
p1 = 0xc1be3ff978

Value at the address (n2) to which p2 points
*p2 = 25
Memory address (n2) to which p2 points
p2 = 0xc1be3ff974

Value of n1 has been multiplied by two using pointer arithmetic (*p1 *= 2)
n1 = 20

Sum of values (n1 n2) to which p1 p2 point using pointer arithmetic (sum = *p1 + *p2)
p1(20) + p2(25) = 45

p1 re-assigned pointing to n3
Value at the address (n3) to which p1 points
*p1 = 50
Memory address (n3) to which p1 points
p1 = 0xc1be3ff970

Sum of values (n3 n2) to which p1 p2 point using pointer arithmetic (sum = *p1 + *p2)
p1(50) + p2(25) = 75

*/