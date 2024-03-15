//*****************************************************************************************************       
//
//      This program demonstrates recursion by computing the value of a number raised to a power and
//      reversing a number using recursion.
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

//*****************************************************************************************************

int f(int a, int b);
void reverse(int n);

//*****************************************************************************************************

int main() {
    cout << f(5, 3) << endl; 
    cout << f(5, 4) << endl;
    reverse(6543);

    return 0;
}

//*****************************************************************************************************

int f(int a, int b) {
    int result;

    if (b == 0)                             // stopping condition
        result = 1;
    else if (b % 2 == 0)                    // even
        result = f(a * a, b / 2);
    else                                    // odd
        result = f(a * a, b / 2) * (a + 1);

    return result;
}

//*****************************************************************************************************
/*

EXPLANATION:

This recursive function takes two integer parameters, a and b, passed by value.
-   An integer variable `result` is declared to hold and return the computed value 
-   If `b` is 0, the function returns 1 (stopping condition)
-   If `b` is even, recursively calls itself with modified arguments: f(a * a, b / 2)
-   If `b` is odd, recursively calls itself with modified arguments: f(a * a, b / 2) * (a + 1)
-   The function continues to call itself until it reaches the stopping condition (b == 0)
-   Once the stopping condition is met, the recursion starts to "unwind", 
    processing results from the call stack in the reverse order they were added
-   Only calls with an odd 'b' modify the returned result by multiplying with (a + 1)
-   Finally, the function returns the final result


STEP-BY-STEP:

f(5, 3) -> f(25, 1) -> f(625, 0) -> 1 -> 26 -> 156
***************************************************************
b: 3 (odd) | a: 5
    Calls f(25, 1) (5^2 = 25; 3/2 = 1)
        b: 1 (odd) | a: 25
            Calls f(625, 0) (25^2 = 625; 1/2 = 0)

                b: 0 (stopping condition) | a: 625
                returns 1

        Result: 1 * (25 + 1) = 26
Final Result: 26 * (5 + 1) = 156


f(5, 4) -> f(25, 2) -> f(625, 1) -> f(390625, 0) -> 1 -> 626
***************************************************************
b: 4 (even) | a: 5
    Calls f(25, 2) (5^2 = 25; 4/2 = 2)
        b: 2 (even) | a: 25
            Calls f(625, 1) (25^2 = 625; 2/2 = 1)
                b: 1 (odd) | a: 625
                    Calls f(390625, 0) (625^2 = 390625; 1/2 = 0)

                        b: 0 (stopping condition) | a: 390625
                        returns 1 

                Final Result: 1 * (625 + 1) = 626 
            
*/
//*****************************************************************************************************

void reverse(int n) {
    if (n < 10) {            // stopping condition
        cout << n;
    } else {
        cout << n % 10;      // 6543 % 10 = 3 (last digit)
        reverse(n / 10);     // 6543 / 10 = 654 (remaining digits)
    }
}

//*****************************************************************************************************
/*

156
626
3456

*/