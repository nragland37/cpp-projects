#include <iostream>
using namespace std;

const int SIZE_LIMIT = 1024;

void readArray(char[], int &);
void deleteRepeats(char[], int &);
void printArray(char[], int);

//****************************************************************************************************

int main() {
    char array[SIZE_LIMIT],
        answer;

    int size = 5;

    do {
        size = 0;
        readArray(array, size);
        cout << endl;
        deleteRepeats(array, size);
        cout << endl;
        cout << "The array after delete repeats";
        printArray(array, size);
        cout << endl;
        cout << "Repeat? ";
        cin >> answer;

    } while (answer != 'n' && answer != 'N');

    return 0;
}

//****************************************************************************************************

void readArray(char array[], int &size) {
    cout << "What is the size: ";
    cin >> size;

    while (size > SIZE_LIMIT) {
        cout << endl;

        cout << "Please enter size lower than 1024" << endl
             << endl;

        cout << "What is the size: ";
        cin >> size;
    }

    cout << "Enter the array: " << endl;

    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
}

//****************************************************************************************************

void deleteRepeats(char array[], int &size) {
    for (int i = 0; i < size - 1; i++)  // for each char but the last
    {
        for (int j = i + 1; j < size; j++)  // for each char after it
        {
            // if they are equal
            while (array[i] == array[j]) {
                cout << "Found duplicates at " << i + 1
                     << " and " << j + 1 << " : " << array[i]
                     << " and " << array[j] << endl;

                // delete the duplicate
                // move all remaining char 1 to the left
                for (int k = j + 1; k < size; k++) {
                    array[k - 1] = array[k];
                }

                array[--size] = 0;

                printArray(array, size);
            }
        }
    }
}

//****************************************************************************************************

void printArray(char array[], int size) {
    cout << endl;

    cout << "Updated array: ";

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
}

//****************************************************************************************************
/*

What is the size: 10
Enter the array:
a g g g e n g g e e

Found duplicates at 2 and 3 : g and g

Updated array: a g g e n g g e e
Found duplicates at 2 and 3 : g and g

Updated array: a g e n g g e e
Found duplicates at 2 and 5 : g and g

Updated array: a g e n g e e
Found duplicates at 2 and 5 : g and g

Updated array: a g e n e e
Found duplicates at 3 and 5 : e and e

Updated array: a g e n e
Found duplicates at 3 and 5 : e and e

Updated array: a g e n

The array after delete repeats
Updated array: a g e n

Repeat? Y
What is the size: 10
Enter the array:
a g e n g g e e h h

Found duplicates at 2 and 5 : g and g

Updated array: a g e n g e e h h
Found duplicates at 2 and 5 : g and g

Updated array: a g e n e e h h
Found duplicates at 3 and 5 : e and e

Updated array: a g e n e h h
Found duplicates at 3 and 5 : e and e

Updated array: a g e n h h
Found duplicates at 5 and 6 : h and h

Updated array: a g e n h

The array after delete repeats
Updated array: a g e n h

Repeat? N

*/