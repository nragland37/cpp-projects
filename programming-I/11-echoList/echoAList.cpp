//*****************************************************************************************************
//      Array Sum Calculator
//
//      This program calculates the sum of 10 numbers entered by the user.
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

//*****************************************************************************************************

int main() {

    const int size_of_array = 10 ; // 10 is the size of "numbers" array...
    int numbers[ size_of_array ];
    int sum = 0; // Total sum of 10 numbers entered...

    cout << "Enter 10 numbers:" << endl;

    for (int i = 0; i < size_of_array; i++) {

        cin >> numbers[i];    
        sum = sum + numbers[i]; // number[i], stores the value of number in the array's, "i" is the index of the array...
    }

    cout << "\nSum is: " << sum << "\nThe list of numbers were: ";

    for ( int i = 0; i < size_of_array; i++ )

        cout << numbers[i] << " "; //Prints the all numbers entered by the user...

    return 0;
}

//*****************************************************************************************************
/*

Enter 10 numbers

Enter #1: 1
Enter #2: 2
Enter #3: 3
Enter #4: 4
Enter #5: 5
Enter #6: 6
Enter #7: 7
Enter #8: 8
Enter #9: 9
Enter #10: 10

Sum is: 55
The list of numbers were: 1 2 3 4 5 6 7 8 9 10

*****************************************************************************************************

Enter 10 numbers

Enter #1: 10
Enter #2: 9
Enter #3: 8
Enter #4: 7
Enter #5: 6
Enter #6: 5
Enter #7: 4
Enter #8: 3
Enter #9: 2
Enter #10: 1

Sum is: 55
The list of numbers were: 10 9 8 7 6 5 4 3 2 1

*/