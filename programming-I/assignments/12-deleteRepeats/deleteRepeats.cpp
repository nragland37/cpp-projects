//*****************************************************************************************************
//      Delete Repeats in Array
//
//		The program will read a list of characters from the user and then delete all the repeated
//      characters in the list.
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

//*****************************************************************************************************

const int SIZE_LIMIT = 1024;     // global constant (can be used anywhere in the program)

void readArray(char[], int &);
void deleteRepeats(char[], int &);
void printArray(char[], int);

//*****************************************************************************************************

int main() {
    char array[SIZE_LIMIT];     // array of characters (char) with a size limit of 1024 (SIZE_LIMIT)
    char answer;                // answer to repeat the program
    int size;                   // not the size of the array,
                                // but the number of elements in the array (the size of the array is SIZE_LIMIT)
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
        cin >> array[i];     // array[i] is the i-th element of the array (input is assigned to the i-th element of the array)
}

//*****************************************************************************************************

void deleteRepeats(char array[], int &size) {
    for (int i = 0; i < size - 1; i++) {                          // size - 1 because size (the last element) is the only element that can't be compared
        for (int j = i + 1; j < size; j++) {                      // j = i + 1 because we are comparing i with i + 1
            while (array[i] == array[j]) {                        // while loop because we need to delete all the repeats of the same element
                cout << "\nFound duplicates at " << i + 1         // i + 1 because we are printing the index of the element
                     << " and " << j + 1 << " : " << array[i]     // j + 1 because we are printing the index of the element
                     << " and " << array[j] << endl;              // array[i] and array[j] are the same element
                for (int k = j + 1; k < size; k++)                // k = j + 1 because we are comparing j with j + 1
                    array[k - 1] = array[k];                      // k - 1 because we are deleting the element at j and shifting all the elements to the left

                array[--size] = 0;           // --size because we are deleting the element at j and shifting all the elements to the left
                printArray(array, size);     // print the array after deleting the repeats
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