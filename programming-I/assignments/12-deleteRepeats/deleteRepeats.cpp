//*****************************************************************************************************
//      Delete Repeats in Array
//
//      This program reads a list of characters from the user and then delete all the repeated
//      characters in the list.
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

//*****************************************************************************************************

const int SIZE_LIMIT = 1024;

void readArray(char[], int &);
void deleteRepeats(char[], int &);
void printArray(char[], int);

//*****************************************************************************************************

int main() {
    char array[SIZE_LIMIT];
    char answer;
    int size;

    do {
        size = 0;

        readArray(array, size);
        deleteRepeats(array, size);

        cout << "\n\nThe array after delete repeats";
        printArray(array, size);

        cout << "\n\nRepeat? (y/n): ";
        cin >> answer;
    
    } while (answer != 'n' && answer != 'N');

    return 0;
}

//*****************************************************************************************************

void readArray(char array[], int &size) {
    cout << "\nWhat is the size: ";
    cin >> size;

    while (size > SIZE_LIMIT || size < 0) {
        cerr << "\nInvalid size. Please enter a size between 0 and " << SIZE_LIMIT;

        cout << "\n\nWhat is the size: ";
        cin >> size;
    }

    cout << "Enter the array (one character at a time): " << endl;

    for (int i = 0; i < size; i++)
        cin >> array[i];
}

//*****************************************************************************************************

void deleteRepeats(char array[], int &size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            while (array[i] == array[j]) {
                cout << "\nFound duplicates at " << i + 1
                     << " and " << j + 1 << " : " << array[i]
                     << " and " << array[j] << endl;

                for (int k = j + 1; k < size; k++)
                    array[k - 1] = array[k];

                array[--size] = 0;
                printArray(array, size);
            }
        }
    }
}

//*****************************************************************************************************

void printArray(char array[], int size) {
    cout << "\nUpdated array: ";

    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
}

//*****************************************************************************************************
/*

What is the size: 10
Enter the array (one character at a time):
1
1
1
1
1
1
1
1
1
1

Found duplicates at 1 and 2 : 1 and 1

Updated array: 1 1 1 1 1 1 1 1 1
Found duplicates at 1 and 2 : 1 and 1

Updated array: 1 1 1 1 1 1 1 1
Found duplicates at 1 and 2 : 1 and 1

Updated array: 1 1 1 1 1 1 1
Found duplicates at 1 and 2 : 1 and 1

Updated array: 1 1 1 1 1 1
Found duplicates at 1 and 2 : 1 and 1

Updated array: 1 1 1 1 1
Found duplicates at 1 and 2 : 1 and 1

Updated array: 1 1 1 1
Found duplicates at 1 and 2 : 1 and 1

Updated array: 1 1 1
Found duplicates at 1 and 2 : 1 and 1

Updated array: 1 1
Found duplicates at 1 and 2 : 1 and 1

Updated array: 1

The array after delete repeats
Updated array: 1

Repeat? (y/n): n

*****************************************************************************************************

What is the size: 5000

Invalid size. Please enter a size between 0 and 1024

What is the size: -20

Invalid size. Please enter a size between 0 and 1024

What is the size: 10
Enter the array (one character at a time):
a
a
a
t
5
0
3
j
n
a

Found duplicates at 1 and 2 : a and a

Updated array: a a t 5 0 3 j n a
Found duplicates at 1 and 2 : a and a

Updated array: a t 5 0 3 j n a
Found duplicates at 1 and 8 : a and a

Updated array: a t 5 0 3 j n

The array after delete repeats
Updated array: a t 5 0 3 j n

Repeat? (y/n): y

What is the size: 5
Enter the array (one character at a time):
1
2
3
1
2

Found duplicates at 1 and 4 : 1 and 1

Updated array: 1 2 3 2
Found duplicates at 2 and 4 : 2 and 2

Updated array: 1 2 3

The array after delete repeats
Updated array: 1 2 3

Repeat? (y/n): n

*/