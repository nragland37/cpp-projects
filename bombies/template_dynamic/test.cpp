#include <iostream>

using namespace std;

template <class T>
T* insertValue(T* originalArray, int positionToInsertAt, T ValueToInsert, int sizeOArray) {
    T* newArray = nullptr;
    newArray = new T[sizeOArray + 1];
    for (int i = 0; i <= sizeOArray; ++i) {
        if (i < positionToInsertAt) {
            newArray[i] = originalArray[i];
        }

        if (i == positionToInsertAt) {
            newArray[i] = ValueToInsert;
        }

        if (i > positionToInsertAt) {
            newArray[i] = originalArray[i - 1];
        }
    }
    return newArray;
}

int main() {
    int int_size,
        char_size,
        int_position_insert,
        char_position_insert,
        new_int_value;

    char new_char_value;

    cout << "integer array size: ";
    cin >> int_size;

    int* int_array = nullptr;
    int_array = new int[int_size];

    cout << "\n'enter values for int array'" << endl;
    for (int i = 0; i < int_size; ++i) {
        cout << "index " << i << ": ";
        cin >> int_array[i];
    }

    cout << "\n`int array`" << endl;
    for (int i = 0; i < int_size; ++i) {
        cout << int_array[i] << " ";
    }

    cout << endl
         << endl;

    cout << "new integer value: ";
    cin >> new_int_value;
    cout << "enter position to insert new integer value (0 - " << int_size << "}: ";
    cin >> int_position_insert;

    int* new_intArray = insertValue(int_array, int_position_insert, new_int_value, int_size);
    cout << "'new int array'" << endl;
    for (int i = 0; i < int_size + 1; ++i) {
        cout << new_intArray[i] << " ";
    }
    cout << endl
         << endl;
    delete[] new_intArray;
    new_intArray = nullptr;

    cout << "char array size: ";
    cin >> char_size;

    char* char_array = nullptr;
    char_array = new char[char_size];

    cout << "\n'enter values for char array'" << endl;
    for (int i = 0; i < char_size; ++i) {
        cout << "index " << i << ": ";
        cin >> char_array[i];
    }
    cout << "\n`char array`" << endl;
    for (int i = 0; i < char_size; ++i) {
        cout << char_array[i] << " ";
    }

    cout << endl
         << endl;

    cout << "new char value: ";
    cin >> new_char_value;
    cout << "enter position to insert new integer value (0 - " << char_size << "): ";
    cin >> char_position_insert;

    char* new_charArray = insertValue(char_array, char_position_insert, new_char_value, char_size);
    cout << "'new char array'" << endl;
    for (int i = 0; i < char_size + 1; ++i) {
        cout << new_charArray[i] << " ";
    }

    delete[] new_charArray;
    new_charArray = nullptr;

    return 0;
}

/*

integer array size: 5

'enter values for int array'
index 0: 1
index 1: 2
index 2: 3
index 3: 4
index 4: 5

`int array`
1 2 3 4 5

new integer value: 6
enter position to insert new integer value (0 - 5}: 5
'new int array'
1 2 3 4 5 6

char array size: 3

'enter values for char array'
index 0: p
index 1: o
index 2: p

`char array`
p o p

new char value: o
enter position to insert new integer value (0 - 3): 3
'new char array'
p o p o

//****************************************************************************************************

integer array size: 4

'enter values for int array'
index 0: 1
index 1: 2
index 2: 3
index 3: 4

`int array`
1 2 3 4

new integer value: 1000
enter position to insert new integer value (0 - 4}: 2
'new int array'
1 2 1000 3 4

char array size: 5

'enter values for char array'
index 0: h
index 1: e
index 2: l
index 3: l
index 4: o

`char array`
h e l l o

new char value: Q
enter position to insert new integer value (0 - 5): 3
'new char array'
h e l Q l o

*/