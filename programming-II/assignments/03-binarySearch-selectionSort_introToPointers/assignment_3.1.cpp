//*****************************************************************************************************
//
//		This program reads in student names from a file "StudentNames.txt", and then performs several
//      operations on the names. First, it displays all the names that were read in. Then, it prompts
//      the user to enter a student name, and performs a linear search to find the name's position in
//      the list (if it exists). It also sorts the names in ascending order using the bubble sort
//      algorithm, and then again in descending order using the bubble sort algorithm. Then it uses
//      the selection sort algorithm to sort the names in ascending order and also implements binary
//      search algorithm to find the position of a student name in the sorted list. Finally, it sorts
//      the names in descending order using the selection sort algorithm and again performs a linear
//      search to find the position of a student name in the list.
//
//*****************************************************************************************************

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void readNames(ifstream &inputFile, string names[], int numNames);
void displayNames(const string names[], int numNames);
int linearSearchNames(const string names[], int numNames, const string &name);
void displayLinearSearchNames(const string names[], int numNames, const string &name);
void swapValues(string &a, string &b);
void bubbleSort(string names[], int numNames);
void bubbleSortDescending(string names[], int numNames);
int binarySearchNames(const string names[], int numNames, const string &name);
void displayBinarySearchNames(const string names[], int numNames, const string &name);
void selectionSort(string names[], int numNames);
void selectionSortDescending(string names[], int numNames);

//*****************************************************************************************************

int main() {
    const int NUM_NAMES = 10;
    string names[NUM_NAMES],
        name;
    ifstream inputFile("StudentNames.txt");

    readNames(inputFile, names, NUM_NAMES);
    inputFile.close();

    cout << "--------------------------------- \n"
         << "\t"
         << "Student Names \n"
         << "---------------------------------" << endl;
    displayNames(names, NUM_NAMES);

    cout << "\n"
         << "Find a Students place in the list \n"
         << "Enter Student name (e.g., last name, first name): " << endl;
    getline(cin, name);

    displayLinearSearchNames(names, NUM_NAMES, name);

    cin.get();
    cout << "\n"
         << "--------------------------------- \n"
         << " Student Names: Ascending Order \n"
         << "---------------------------------" << endl;
    bubbleSort(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);
    displayLinearSearchNames(names, NUM_NAMES, name);

    cin.get();
    cout << "\n"
         << "--------------------------------- \n"
         << " Student Names: Descending Order \n"
         << "---------------------------------" << endl;
    bubbleSortDescending(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);
    displayLinearSearchNames(names, NUM_NAMES, name);

    cin.get();
    cout << "\n"
         << "--------------------------------- \n"
         << " Student Names: Ascending Order \n"
         << "---------------------------------" << endl;
    selectionSort(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);

    cout << "\n"
         << "Find another Students place in the ascending list \n"
         << "Enter Student name (e.g., last name, first name): " << endl;
    getline(cin, name);

    displayBinarySearchNames(names, NUM_NAMES, name);

    cin.get();
    cout << "\n"
         << "--------------------------------- \n"
         << " Student Names: Descending Order \n"
         << "---------------------------------" << endl;
    selectionSortDescending(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);
    displayLinearSearchNames(names, NUM_NAMES, name);

    return 0;
}

//*****************************************************************************************************

void readNames(ifstream &inputFile, string names[], int numNames) {
    if (inputFile.is_open()) {
        for (int nameNumber = 0; nameNumber < numNames; ++nameNumber) {
            getline(inputFile, names[nameNumber]);
        }
    } else {
        cerr << "Error: Unable to open file" << endl;  // cerr is unbuffered and best for error handling
    }
}

//*****************************************************************************************************

void displayNames(const string names[], int numNames) {
    for (int nameNumber = 0; nameNumber < numNames; ++nameNumber) {
        cout << "\t" << nameNumber + 1 << "  " << names[nameNumber] << endl;
    }
}

//*****************************************************************************************************

int linearSearchNames(const string names[], int numNames, const string &name) {
    int index = 0,
        position = -1;
    bool found = false;

    while ((index < numNames) && !found) {
        if (names[index] == name) {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}

//*****************************************************************************************************

void displayLinearSearchNames(const string names[], int numNames, const string &name) {
    int result;

    result = linearSearchNames(names, numNames, name);
    if (result == -1) {
        cout << result
             << "\n"
             << "Name Not Found" << endl;
    } else {
        cout << "\n"
             << "Name Found: " << result + 1 << endl;
    }
}

//*****************************************************************************************************

void swapValues(string &a, string &b) {
    string temp = a;

    a = b;
    b = temp;
}

//*****************************************************************************************************

void bubbleSort(string names[], int numNames) {
    bool swap;
    string temp;

    do {
        swap = false;
        for (int count = 0; count < (numNames - 1); ++count) {
            if (names[count] > names[count + 1]) {
                swapValues(names[count], names[count + 1]);
                swap = true;
            }
        }
    } while (swap);
}

//*****************************************************************************************************

void bubbleSortDescending(string names[], int numNames) {
    bool swap;
    string temp;

    do {
        swap = false;
        for (int count = 0; count < (numNames - 1); ++count) {
            if (names[count] < names[count + 1]) {
                swapValues(names[count], names[count + 1]);
                swap = true;
            }
        }
    } while (swap);
}

//*****************************************************************************************************

int binarySearchNames(const string names[], int numNames, const string &name) {  // binary search algorithm (time complexity: O(log n))
    int first = 0,                                                               // first index of the array
        last = numNames - 1,                                                     // last index of the array
        middle,                                                                  // middle index of the array
        position = -1;                                                           // position with -1 indicates that the name was not found
    bool found = false;                                                          // flag to indicate if the name was found

    while (!found && (first <= last)) {     // loop until the name is found or the first index is greater than the last index
        middle = (first + last) / 2;        // calculate the middle index of the array
        if (names[middle] == name) {        // check if the name at the middle index matches the searched name
            found = true;                   // if yes, set the boolean variable found to true
            position = middle;              // set the position to the middle index
        } else if (names[middle] > name) {  // if the name at the middle index is greater than the searched name
            last = middle - 1;              // set the last index to the middle - 1
        } else {                            // if the name at the middle index is less than the searched name
            first = middle + 1;             // set the first index to the middle + 1
        }
    }
    return position;  // return the position of the searched name in the array
}

//*****************************************************************************************************

void displayBinarySearchNames(const string names[], int numNames, const string &name) {
    int result;

    result = binarySearchNames(names, numNames, name);
    if (result == -1) {
        cout << result
             << "\n"
             << "Name Not Found" << endl;
    } else {
        cout << "\n"
             << "Name Found: " << result + 1 << endl;
    }
}

//*****************************************************************************************************

void selectionSort(string names[], int numNames) {  // selection sort algorithm (time complexity: O(n^2))
    int minIndex;                                   // index of the minimum value
    string minValue;                                // minimum value

    for (int startScan = 0; startScan < (numNames - 1); ++startScan) {  // outer loop to iterate through the array
        minIndex = startScan;                                           // set the initial minimum index as the current startScan index
        minValue = names[minIndex];                                     // set the initial minimum value as the value at the current startScan index
        for (int index = startScan + 1; index < numNames; ++index) {    // inner loop to compare the current minimum value with the rest of the array
            if (names[index] < minValue) {                              // if a value smaller than the current minimum value is found
                minValue = names[index];                                // update the minimum value to the new smaller value
                minIndex = index;                                       // update the minimum index to the index of the new smaller value
            }
        }
        names[minIndex] = names[startScan];  // swap the current startScan value with the minimum value found
        names[startScan] = minValue;         // update the value at the current startScan index with the minimum value found
    }
}

//*****************************************************************************************************

void selectionSortDescending(string names[], int numNames) {
    int maxIndex;
    string maxValue;

    for (int startScan = 0; startScan < (numNames - 1); ++startScan) {
        maxIndex = startScan;
        maxValue = names[maxIndex];
        for (int index = startScan + 1; index < numNames; ++index) {
            if (names[index] > maxValue) {
                maxValue = names[index];
                maxIndex = index;
            }
        }
        names[maxIndex] = names[startScan];
        names[startScan] = maxValue;
    }
}

//*****************************************************************************************************

/*

---------------------------------
        Student Names
---------------------------------
        1  Smith, John
        2  Song, Mona
        3  Jones, Trevor
        4  Li, Na
        5  Zhang, Xiu Ying
        6  Saleem, Mohammad
        7  Lloyd, Arthur
        8  Jones, Rhys
        9  Evans, Olivia
        10  Davies, Emily

Find a Students place in the list.
Enter Student name (e.g., last name, first name):
Ragland, Nicholas
-1
Name Not Found


---------------------------------
 Student Names: Ascending Order
---------------------------------
        1  Davies, Emily
        2  Evans, Olivia
        3  Jones, Rhys
        4  Jones, Trevor
        5  Li, Na
        6  Lloyd, Arthur
        7  Saleem, Mohammad
        8  Smith, John
        9  Song, Mona
        10  Zhang, Xiu Ying
-1
Name Not Found


---------------------------------
 Student Names: Descending Order
---------------------------------
        1  Zhang, Xiu Ying
        2  Song, Mona
        3  Smith, John
        4  Saleem, Mohammad
        5  Lloyd, Arthur
        6  Li, Na
        7  Jones, Trevor
        8  Jones, Rhys
        9  Evans, Olivia
        10  Davies, Emily
-1
Name Not Found


---------------------------------
 Student Names: Ascending Order
---------------------------------
        1  Davies, Emily
        2  Evans, Olivia
        3  Jones, Rhys
        4  Jones, Trevor
        5  Li, Na
        6  Lloyd, Arthur
        7  Saleem, Mohammad
        8  Smith, John
        9  Song, Mona
        10  Zhang, Xiu Ying

Find another Students place in the ascending list.
Enter Student name (e.g., last name, first name):
Ragland, Nicholas
-1
Name Not Found


---------------------------------
 Student Names: Descending Order
---------------------------------
        1  Zhang, Xiu Ying
        2  Song, Mona
        3  Smith, John
        4  Saleem, Mohammad
        5  Lloyd, Arthur
        6  Li, Na
        7  Jones, Trevor
        8  Jones, Rhys
        9  Evans, Olivia
        10  Davies, Emily
-1
Name Not Found

//*****************************************************************************************************

---------------------------------
        Student Names
---------------------------------
        1  Smith, John
        2  Song, Mona
        3  Jones, Trevor
        4  Li, Na
        5  Zhang, Xiu Ying
        6  Saleem, Mohammad
        7  Lloyd, Arthur
        8  Jones, Rhys
        9  Evans, Olivia
        10  Davies, Emily

Find a Students place in the list.
Enter Student name (e.g., last name, first name):
Smith, John

Name Found: 1


---------------------------------
 Student Names: Ascending Order
---------------------------------
        1  Davies, Emily
        2  Evans, Olivia
        3  Jones, Rhys
        4  Jones, Trevor
        5  Li, Na
        6  Lloyd, Arthur
        7  Saleem, Mohammad
        8  Smith, John
        9  Song, Mona
        10  Zhang, Xiu Ying

Name Found: 8


---------------------------------
 Student Names: Descending Order
---------------------------------
        1  Zhang, Xiu Ying
        2  Song, Mona
        3  Smith, John
        4  Saleem, Mohammad
        5  Lloyd, Arthur
        6  Li, Na
        7  Jones, Trevor
        8  Jones, Rhys
        9  Evans, Olivia
        10  Davies, Emily

Name Found: 3


---------------------------------
 Student Names: Ascending Order
---------------------------------
        1  Davies, Emily
        2  Evans, Olivia
        3  Jones, Rhys
        4  Jones, Trevor
        5  Li, Na
        6  Lloyd, Arthur
        7  Saleem, Mohammad
        8  Smith, John
        9  Song, Mona
        10  Zhang, Xiu Ying

Find another Students place in the ascending list.
Enter Student name (e.g., last name, first name):
Song, Mona

Name Found: 9


---------------------------------
 Student Names: Descending Order
---------------------------------
        1  Zhang, Xiu Ying
        2  Song, Mona
        3  Smith, John
        4  Saleem, Mohammad
        5  Lloyd, Arthur
        6  Li, Na
        7  Jones, Trevor
        8  Jones, Rhys
        9  Evans, Olivia
        10  Davies, Emily

Name Found: 2

*/