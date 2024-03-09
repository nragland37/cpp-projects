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
    const int SIZE = 10;
    int nums[SIZE];
    int sum = 0;

    cout << "Enter 10 numbers:" << endl;

    for (int i = 0; i < SIZE; i++) {
        cin >> nums[i];
        
        sum += nums[i];
    }

    cout << "\nSum is: " << sum << "\nThe list of numbers were: ";

    for (int i = 0; i < SIZE; i++)
        cout << nums[i] << " ";

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