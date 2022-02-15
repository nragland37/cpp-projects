//****************************************************************************************************
// 			File:                 assignment_3.1.cpp
//
//			Student:              Nicholas Ragland
//
//			Assignment:           Program #3
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  February 14, 2022
//
//          This program reads and displays ten student names and their places in a list from a file.
//          Prompts the user to enter a name and searches (Linear Search Algorithm) the list to find 
//          if name is present. If name is found, the program outputs the students place in the list. 
//          If name is not found, the program outputs -1. The program outputs two seperate lists 
//          of an ascending and descending order using a "Bubble Sort Algorithm" with the students 
//          place in both. Then the program sorts the list in ascending order using a "Selection Sort 
//          Algorithm", prompts the user to enter a name, and searches (Binary Search Algorithm) the 
//          list to find if name is present. If name is found, the program outputs the students place 
//          in the list. If name is not found, the program outputs -1. The program outputs another 
//          list in descenidng order using the "Selection Sort Algorithm" and repeats the process of 
//          the "linear Search Algorithm".   
//
//****************************************************************************************************

#include <fstream>
#include <iomanip>
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

//****************************************************************************************************

int main()
{
    ifstream inputFile("StudentNames.txt");

    const int NUM_NAMES = 10;

    string names[NUM_NAMES], name;

    readNames(inputFile, names, NUM_NAMES);
    cout << "---------------------------------" << endl;
    cout << "\t"
         << "Student Names" << endl;
    cout << "---------------------------------" << endl;
    displayNames(names, NUM_NAMES);

    cout << "\nFind a Students place in the list." << endl;
    cout << "Enter Student name (e.g., first name, last name): " << endl;
    getline(cin, name);
    linearSearchNames(names, NUM_NAMES, name);
    displayLinearSearchNames(names, NUM_NAMES, name);
    cin.get();

    cout << "\n---------------------------------" << endl;
    cout << setw(32) << "Student Names ~ Ascending Order" << endl;
    cout << "---------------------------------" << endl;
    bubbleSort(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);
    linearSearchNames(names, NUM_NAMES, name);
    displayLinearSearchNames(names, NUM_NAMES, name);
    cin.get();

    cout << "\n---------------------------------" << endl;
    cout << "Student Names ~ Descending Order" << endl;
    cout << "---------------------------------" << endl;
    bubbleSortDescending(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);
    linearSearchNames(names, NUM_NAMES, name);
    displayLinearSearchNames(names, NUM_NAMES, name);
    cin.get();

    selectionSort(names, NUM_NAMES);
    cout << "\n---------------------------------" << endl;
    cout << setw(32) << "Student Names ~ Ascending Order" << endl;
    cout << "---------------------------------" << endl;
    displayNames(names, NUM_NAMES);

    cout << "\nFind another Students place in the ascending list." << endl;
    cout << "Enter Student name (e.g., first name, last name): " << endl;
    getline(cin, name);
    binarySearchNames(names, NUM_NAMES, name);
    displayBinarySearchNames(names, NUM_NAMES, name);
    cin.get();

    cout << "\n---------------------------------" << endl;
    cout << "Student Names ~ Descending Order" << endl;
    cout << "---------------------------------" << endl;
    selectionSortDescending(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);
    linearSearchNames(names, NUM_NAMES, name);
    displayLinearSearchNames(names, NUM_NAMES, name);
    cin.get();

    inputFile.close();

    return 0;
}

//****************************************************************************************************

void readNames(ifstream &inputFile, string names[], int numNames)
{
    if (inputFile.is_open())
    {
        for (int nameNumber = 0; nameNumber < numNames; ++nameNumber)
        {
            getline(inputFile, names[nameNumber]);
        }
    }
    else
    {
        cout << "ERROR: Could not open file" << endl;
    }
}

//****************************************************************************************************

void displayNames(const string names[], int numNames)
{
    for (int nameNumber = 0; nameNumber < numNames; ++nameNumber)
    {
        cout << "\t" << nameNumber + 1 << "  " << names[nameNumber] << endl;
    }
}

//****************************************************************************************************

int linearSearchNames(const string names[], int numNames, const string &name)
{
    int index = 0;
    int position = -1;
    bool found = false;
    while ((index < numNames) && !found)
    {
        if (names[index] == name)
        {
            found = true;
            position = index + 1;
        }
        index++;
    }
    return position;
}

//****************************************************************************************************

void displayLinearSearchNames(const string names[], int numNames, const string &name)
{
    if (linearSearchNames(names, numNames, name) == -1)
    {
        cout << linearSearchNames(names, numNames, name) << " \nName Not Found" << endl;
    }
    else
    {
        cout << "\nName Found: " << linearSearchNames(names, numNames, name) << endl;
    }
}

//****************************************************************************************************

void swapValues(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

//****************************************************************************************************

void bubbleSort(string names[], int numNames)
{
    bool swap;
    string temp;
    do
    {
        swap = false;
        for (int count = 0; count < (numNames - 1); ++count)
        {
            if (names[count] > names[count + 1])
            {
                swapValues(names[count], names[count + 1]);
                swap = true;
            }
        }
    } while (swap);
}

//****************************************************************************************************

void bubbleSortDescending(string names[], int numNames)
{
    bool swap;
    string temp;
    do
    {
        swap = false;
        for (int count = 0; count < (numNames - 1); ++count)
        {
            if (names[count] < names[count + 1])
            {
                swapValues(names[count], names[count + 1]);
                swap = true;
            }
        }
    } while (swap);
}

//****************************************************************************************************

int binarySearchNames(const string names[], int numNames, const string &name)
{
    int first = 0;
    int last = numNames - 1;
    int middle;
    int position = -1;
    bool found = false;
    while (!found && (first <= last))
    {
        middle = (first + last) / 2;
        if (names[middle] == name)
        {
            found = true;
            position = middle + 1;
        }
        else if (names[middle] > name)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return position;
}

//****************************************************************************************************

void displayBinarySearchNames(const string names[], int numNames, const string &name)
{
    if (binarySearchNames(names, numNames, name) == -1)
    {
        cout << binarySearchNames(names, numNames, name) << " \nName Not Found" << endl;
    }
    else
    {
        cout << "\nName Found: " << binarySearchNames(names, numNames, name) << endl;
    }
}

//****************************************************************************************************

void selectionSort(string names[], int numNames)
{
    int minIndex;
    string minValue;
    for (int startScan = 0; startScan < (numNames - 1); ++startScan)
    {
        minIndex = startScan;
        minValue = names[minIndex];
        for (int index = startScan + 1; index < numNames; ++index)
        {
            if (names[index] < minValue)
            {
                minValue = names[index];
                minIndex = index;
            }
        }
        names[minIndex] = names[startScan];
        names[startScan] = minValue;
    }
}

//****************************************************************************************************

void selectionSortDescending(string names[], int numNames)
{
    int maxIndex;
    string maxValue;
    for (int startScan = 0; startScan < (numNames - 1); ++startScan)
    {
        maxIndex = startScan;
        maxValue = names[maxIndex];
        for (int index = startScan + 1; index < numNames; ++index)
        {
            if (names[index] > maxValue)
            {
                maxValue = names[index];
                maxIndex = index;
            }
        }
        names[maxIndex] = names[startScan];
        names[startScan] = maxValue;
    }
}

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
Enter Student name (e.g., first name, last name):
Nicholas, Ragland
-1 
Name Not Found


---------------------------------  
 Student Names ~ Ascending Order   
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
Student Names ~ Descending Order   
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
 Student Names ~ Ascending Order   
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
Enter Student name (e.g., first name, last name):
Nicholas, Ragland
-1 
Name Not Found


---------------------------------  
Student Names ~ Descending Order   
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

//****************************************************************************************************

---------------------------------
 Student Names ~ Ascending Order
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
Student Names ~ Descending Order
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
 Student Names ~ Ascending Order
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
Enter Student name (e.g., first name, last name):    
Song, Mona

Name Found: 9


---------------------------------
Student Names ~ Descending Order
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