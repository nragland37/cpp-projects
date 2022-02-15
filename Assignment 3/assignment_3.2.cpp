//****************************************************************************************************
// 		  File:                 assignment_3.2.cpp
//
//		  Student:              Nicholas Ragland
//
//		  Assignment:           Program #3
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
        sum = 0; 

    int *p1 = &n1, 
        *p2 = &n2; 

    cout << "Three variables:" << endl
         << "'n1' = " << n1 << endl
         << "Memory address: " << &n1 << endl
         << "\n'n2' = " << n2 << endl
         << "Memory address: " << &n2 << endl
         << "\n'n3' = " << n3 << endl
         << "Memory address: " << &n3 << endl;
    cin.get();
    cout << "\nTwo pointers:" << endl
         << "'p1'" << endl
         << "Memory address: " << &p1 << endl
         << "'p1' is pointing to 'n1'" << endl
         << "\n'p2'" << endl
         << "Memory address: " << &p2 << endl
         << "'p2' is pointing to 'n2'" << endl;
    cin.get();
    cout << "\nValue at the address to which 'p1' points: " << *p1 << endl
         << "Memory address to which 'p1' points: " << p1 << endl
         << "\nValue at the address to which 'p2' points: " << *p2 << endl
         << "Memory address to which 'p2' points: " << p2 << endl;
    cin.get();

    *p1 *= 2;
    cout << "\nValue of 'n1' has been multiplied by two:" << endl
         << "n1 = " << n1 << endl;
    cin.get();

    sum = *p1 + *p2;
    cout << "\nSum of values to which 'p1' & 'p2' point:" << endl
         << "p1(20) + p2(25) = " << sum << endl;
    cin.get();

    p1 = &n3;
    cout << "\n('p1' re-assigned pointing to 'n3')" << endl
         << "Value at the address to which 'p1' points: " << *p1 << endl
         << "Memory address to which 'p1' points: " << p1 << endl;
    cin.get();

    sum = *p1 + *p2;
    cout << "\nSum of values to which 'p1' & 'p2' point:" << endl
         << "p1(50) + p2(25) = " << sum << endl;

    return 0;
}

/*

Three variables:
'n1' = 10
Memory address: 0x5f751ffbc8

'n2' = 25
Memory address: 0x5f751ffbc4

'n3' = 50
Memory address: 0x5f751ffbc0


Two pointers:
'p1'
Memory address: 0x5f751ffbb8
'p1' is pointing to 'n1'

'p2'
Memory address: 0x5f751ffbb0
'p2' is pointing to 'n2'


Value at the address to which 'p1' points: 10
Memory address to which 'p1' points: 0x5f751ffbc8

Value at the address to which 'p2' points: 25
Memory address to which 'p2' points: 0x5f751ffbc4


Value of 'n1' has been multiplied by two: 
n1 = 20


Sum of values to which 'p1' & 'p2' point: 
p1(20) + p2(25) = 45


('p1' re-assigned pointing to 'n3')       
Value at the address to which 'p1' points: 50
Memory address to which 'p1' points: 0x5f751ffbc0


Sum of values to which 'p1' & 'p2' point: 
p1(50) + p2(25) = 75

*/