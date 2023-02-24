//*****************************************************************************************************
//
//		This program reads in a list of student names from a file named "StudentNames.txt" and stores
//      them in an array of strings. It then displays the names, allows the user to search for a
//      specific name in the array, and provides the index of the name if it is found. The program
//      also sorts the names in ascending and descending order using the bubble sort algorithm and
//      displays the names in the sorted order. Finally, the program closes the input file and ends.
//
//*****************************************************************************************************

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

void readNames(ifstream &inputFile, string names[], int numNames);
void displayNames(const string names[], int numNames);
int searchNames(const string names[], int numNames, const string &name);
void displaySearchNames(const string names[], int numNames, const string &name);
void swapValues(string &a, string &b);
void bubbleSort(string names[], int numNames);
void bubbleSortDescending(string names[], int numNames);

//*****************************************************************************************************

int main() {
    const int NUM_NAMES = 10;
    string names[NUM_NAMES];
    string name;
    ifstream inputFile("StudentNames.txt");

    readNames(inputFile, names, NUM_NAMES);
    inputFile.close();

    cout << "---------------------------------\n"
         << "\tStudent Names \n"
         << "---------------------------------" << endl;

    displayNames(names, NUM_NAMES);

    cout << "\nFind a Students place in the list \n"
         << "Enter Student name (e.g., last name, first name): " << endl;
    getline(cin, name);

    searchNames(names, NUM_NAMES, name);
    displaySearchNames(names, NUM_NAMES, name);

    cout << "\n--------------------------------- \n"
         << " Student Names: Ascending Order \n"
         << "---------------------------------" << endl;

    bubbleSort(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);

    searchNames(names, NUM_NAMES, name);
    displaySearchNames(names, NUM_NAMES, name);

    cout << "\n--------------------------------- \n"
         << " Student Names: Descending Order \n"
         << "---------------------------------" << endl;

    bubbleSortDescending(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);

    searchNames(names, NUM_NAMES, name);
    displaySearchNames(names, NUM_NAMES, name);

    return 0;
}

//*****************************************************************************************************

void readNames(ifstream &inputFile, string names[], int numNames) {
    if (inputFile.is_open())
        for (int nameNumber = 0; nameNumber < numNames; ++nameNumber)
            getline(inputFile, names[nameNumber]);
    else
        cerr << "Error: Unable to open file" << endl;     // cerr is unbuffered and best for error handling
}

//*****************************************************************************************************

void displayNames(const string names[], int numNames) {
    for (int nameNumber = 0; nameNumber < numNames; ++nameNumber)
        cout << "\t" << nameNumber + 1 << "  " << names[nameNumber] << endl;
}

//*****************************************************************************************************

int searchNames(const string names[], int numNames, const string &name) {
    int index = 0,          // current index in the names array
        position = -1;      // holds the position of the found name in the array
    bool found = false;     // flag indicating whether the name has been found

    while ((index < numNames) && !found) {
        if (names[index] == name) {     // check if the current name is equal to the specified name
            found = true;               // set found flag to true
            position = index + 1;       // store the position of the found name
        }
        index++;     // increment index
    }

    return position;     // return the position of the found name
}

//*****************************************************************************************************

void displaySearchNames(const string names[], int numNames, const string &name) {
    if (searchNames(names, numNames, name) == -1)
        cout << searchNames(names, numNames, name)
             << "\nName Not Found" << endl;
    else
        cout << "\nName Found: " << searchNames(names, numNames, name) << endl;
}

//*****************************************************************************************************

void swapValues(string &a, string &b) {
    string temp = a;

    a = b;
    b = temp;
}

//*****************************************************************************************************

void bubbleSort(string names[], int numNames) {
    bool swap;       // boolean flag to track if any swaps were made in the current pass
    string temp;     // temporary variable to store a string value while swapping

    do {
        swap = false;                                              // set the flag to false as no swaps have been made yet
        for (int count = 0; count < (numNames - 1); ++count) {     // loop through all elements of the array, except the last one
            if (names[count] > names[count + 1]) {                 // if the current element is greater than the next element
                swapValues(names[count], names[count + 1]);        // swap the values
                swap = true;                                       // set the flag to true as a swap has been made
            }
        }
    } while (swap);     // continue looping as long as any swaps were made in the previous pass
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

*****************************************************************************************************

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

*/