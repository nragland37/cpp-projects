//*****************************************************************************************************
//      Sorting and Searching Student Names
//
//      This program reads in a list of student names from a file, allows the user to search for a
//      specific name using linear search and binary search, sorts the names in ascending and
//      descending order using bubble sort and selection sort, and displays the sorted lists and
//      search results.
//
//      Other files required:
//        1.  StudentNames.txt - contains the names of 10 students
//
//*****************************************************************************************************

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

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
    string names[NUM_NAMES];
    string name;
    ifstream inputFile("StudentNames.txt");

    readNames(inputFile, names, NUM_NAMES);
    inputFile.close();

    cout << "---------------------------------\n"
         << "\tStudent Names\n"
         << "---------------------------------" << endl;

    displayNames(names, NUM_NAMES);

    cout << "\nFind a Students place in the list\n"
         << "Enter Student name (e.g., last name, first name): " << endl;
    getline(cin, name);

    displayLinearSearchNames(names, NUM_NAMES, name);

    cout << "\n---------------------------------\n"
         << " Student Names: Ascending Order\n"
         << "---------------------------------" << endl;

    bubbleSort(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);
    displayLinearSearchNames(names, NUM_NAMES, name);

    cout << "\n---------------------------------\n"
         << " Student Names: Descending Order\n"
         << "---------------------------------" << endl;

    bubbleSortDescending(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);
    displayLinearSearchNames(names, NUM_NAMES, name);

    cout << "\n---------------------------------\n"
         << " Student Names: Ascending Order\n"
         << "---------------------------------" << endl;

    selectionSort(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);

    cout << "\nFind another Students place in the ascending list\n"
         << "Enter Student name (e.g., last name, first name): " << endl;
    getline(cin, name);

    displayBinarySearchNames(names, NUM_NAMES, name);

    cout << "\n---------------------------------\n"
         << " Student Names: Descending Order\n"
         << "---------------------------------" << endl;

    selectionSortDescending(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);
    displayLinearSearchNames(names, NUM_NAMES, name);

    return 0;
}

//*****************************************************************************************************

void readNames(ifstream &inputFile, string names[], int numNames) {
    if (inputFile.is_open())
        for (int nameNumber = 0; nameNumber < numNames; ++nameNumber)
            getline(inputFile, names[nameNumber]);
    else
        cerr << "Error: Unable to open file\n";
}

//*****************************************************************************************************

void displayNames(const string names[], int numNames) {
    for (int nameNumber = 0; nameNumber < numNames; ++nameNumber)
        cout << "\t" << nameNumber + 1 << "  " << names[nameNumber] << endl;
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
    int position = linearSearchNames(names, numNames, name);

    if (position == -1)
        cerr << position << "\nName Not Found\n";
    else
        cout << "\nName Found: " << position + 1 << endl;
}

//*****************************************************************************************************

void swapValues(string &a, string &b) {
    string temp = a;

    a = b;
    b = temp;
}

//*****************************************************************************************************
// bubble sort algorithm (time complexity: O(n^2))

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
// binary search algorithm (time complexity: O(log n))

int binarySearchNames(const string names[], int numNames, const string &name) {
    int first = 0,
        last = numNames - 1,
        middle,
        position = -1;
    bool found = false;

    while (!found && (first <= last)) {
        middle = (first + last) / 2;

        if (names[middle] == name) {
            found = true;
            position = middle;
        } else if (names[middle] > name) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }
    }

    return position;
}

//*****************************************************************************************************

void displayBinarySearchNames(const string names[], int numNames, const string &name) {
    int position = binarySearchNames(names, numNames, name);

    if (position == -1)
        cerr << position << "\nName Not Found\n";
    else
        cout << "\nName Found: " << position + 1 << endl;
}

//*****************************************************************************************************
// selection sort algorithm (time complexity: O(n^2))

void selectionSort(string names[], int numNames) {
    int minIndex;
    string minValue;

    for (int startScan = 0; startScan < (numNames - 1); ++startScan) {
        minIndex = startScan;
        minValue = names[minIndex];

        for (int index = startScan + 1; index < numNames; ++index) {
            if (names[index] < minValue) {
                minValue = names[index];
                minIndex = index;
            }
        }

        names[minIndex] = names[startScan];
        names[startScan] = minValue;
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