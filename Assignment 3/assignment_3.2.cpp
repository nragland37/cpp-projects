//****************************************************************************************************
// 			File:                 assignment_3.2.cpp
//
//			Student:              Nicholas Ragland
//
//			Assignment:           Program #3
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  February 14, 2022
//
//          This program displays the values and memory addresses of three variables, the memory 
//          addresses and assigned variables of two pointers, and the values and memory addresses at 
//          the locations to which the pointers point to. The program finds and displays the value 
//          of a variable using multiplication with a pointer, re-assigns a pointer with a different 
//          variable, and the sum of values that pointers were assigned.   
//         
//****************************************************************************************************

#include <iostream>

using namespace std;

//****************************************************************************************************

int main()
{
    int n1 = 10,
        n2 = 25,
        n3 = 50,
        sum = 0; // I know 'sum' doesn't need to be initialized to 0 but ever since 
                 // my confusion with initialization, im scared.  can exaplain/help? 

    int *p1 = &n1, // Is it better to initialize pointers to null then assign?
        *p2 = &n2; // e.g. int *p1 = nullp1, *p2 = nullp2; p1 = &n1; p2 = &n2;

    cout << "Three variables with their initialized values & memory addresses:" << endl
         << "n1 = " << n1 << endl
         << "Memory address: " << &n1 << endl
         << "\nn2 = " << n2 << endl
         << "Memory address: " << &n2 << endl
         << "\nn3 = " << n3 << endl
         << "Memory address: " << &n3 << endl;
    cin.get();
    cout << "\nTwo pointers with their memory addresses & assgined variables:" << endl
         << "p1" << endl
         << "Memory address: " << &p1 << endl
         << "p1 is pointing to n1" << endl
         << "\np2" << endl
         << "Memory address: " << &p2 << endl
         << "p2 is pointing to n2" << endl;
    cin.get();
    cout << "\nValue at the location to which 'p1' points: " << *p1 << endl
         << "Memory address to which 'p1' points: " << p1 << endl
         << "\nValue at the location to which 'p2' points: " << *p2 << endl
         << "Memory address to which 'p2' points: " << p2 << endl;
    cin.get();

    *p1 *= 2;
    cout << "\nThe value of 'n1' has been multiplied by two:" << endl
         << "n1 = " << n1 << endl;
    cin.get();

    sum = *p1 + *p2;
    cout << "\nThe sum of values to which 'p1' & 'p2' point:" << endl
         << "p1(20) + p2(25) = " << sum << endl;
    cin.get();

    p1 = &n3;
    cout << "\n'p1' is re-assigned to point to 'n3':" << endl
         << "Value at the location to which 'p1' points: " << *p1 << endl
         << "Memory address to which 'p1' points: " << p1 << endl;
    cin.get();

    sum = *p1 + *p2;
    cout << "\nThe sum of values to which 'p1' & 'p2' point:" << endl
         << "p1(50) + p2(25) = " << sum << endl;

    return 0;
}

/*

Three variables with their initialized values & memory addresses:
n1 = 10
Memory address: 0xe0e9ffbd8

n2 = 25
Memory address: 0xe0e9ffbd4

n3 = 50
Memory address: 0xe0e9ffbd0


Two pointers with their memory addresses & assgined variables:
p1
Memory address: 0xe0e9ffbc8
p1 is pointing to n1

p2
Memory address: 0xe0e9ffbc0
p2 is pointing to n2


Value at the location to which 'p1' points: 10
Memory address to which 'p1' points: 0xe0e9ffbd8

Value at the location to which 'p2' points: 25
Memory address to which 'p2' points: 0xe0e9ffbd4


The value of 'n1' has been multiplied by two:
n1 = 20


The sum of values to which 'p1' & 'p2' point:
p1(20) + p2(25) = 45


'p1' is re-assigned to point to 'n3':
Value at the location to which 'p1' points: 50
Memory address to which 'p1' points: 0xe0e9ffbd0


The sum of values to which 'p1' & 'p2' point:
p1(50) + p2(25) = 75

*/