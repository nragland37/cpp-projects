//****************************************************************************************************
// 			File:                 assignment_2.2.cpp
//
//			Student:              Nicholas Ragland
//
//			Assignment:           Program #2
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  February 7, 2021
//
//          This program reads and displays ten student names and their places in a list from a file.
//          Prompts the user to enter a name then searches the list to find if name is present.
//          If name is found, the program outputs the students place in the list. If name is not 
//          found, the program outputs -1. The program then outputs an ascending and desending order 
//          of the names in two seperate lists. 
//
//****************************************************************************************************

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void readNames(ifstream &inputFile, string names[], int numNames);
void displayNames(const string names[], int numNames);
int searchNames(const string names[], int numNames, const string &name);
void swapValues(string &a, string &b);
void bubbleSort(string names[], int numNames);
void bubbleSortDescending(string names[], int numNames);

//****************************************************************************************************

int main()
{
    ifstream inputFile("StudentNames.txt");

    const int NUM_NAMES = 10;

    string names[NUM_NAMES],
        name;

    readNames(inputFile, names, NUM_NAMES);
    cout << "---------------------------------" << endl;
    cout << "\t"
         << "Student Names" << endl;
    cout << "---------------------------------" << endl;
    displayNames(names, NUM_NAMES);

    cout << "\nFind a Students place in the list." << endl;
    cin.get();
    cout << "Enter Student name (e.g., first name, last name): " << endl;
    getline(cin, name);
    searchNames(names, NUM_NAMES, name);
    if (searchNames(names, NUM_NAMES, name) == -1)
    {
        cout << searchNames(names, NUM_NAMES, name) << " \nName Not Found" << endl;
    }
    else
        cout << "\nName Found: " << searchNames(names, NUM_NAMES, name) << endl;

    cout << "\n---------------------------------" << endl;
    cout << setw(32) << "Student Names ~ Ascending Order" << endl;
    cout << "---------------------------------" << endl;
    bubbleSort(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);

    cout << "\n---------------------------------" << endl;
    cout << "Student Names ~ Descending Order" << endl;
    cout << "---------------------------------" << endl;
    bubbleSortDescending(names, NUM_NAMES);
    displayNames(names, NUM_NAMES);

    inputFile.close();

    return 0;
}

//****************************************************************************************************

void readNames(ifstream &inputFile, string names[], int numNames)
{
    if (inputFile.is_open())
        for (int nameNumber = 0; nameNumber < numNames; ++nameNumber)
        {
            getline(inputFile, names[nameNumber]);
        }
    else
        cout << "ERROR: Could not open file" << endl;
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

int searchNames(const string names[], int numNames, const string &name)
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

/*

---------------------------------
        Student Names
---------------------------------
        Smith, John
        Song, Mona
        Jones, Trevor
        Li, Na
        Zhang, Xiu Ying
        Saleem, Mohammad
        Lloyd, Arthur
        Jones, Rhys
        Evans, Olivia
        Davies, Emily

---------------------------------
 Student Names ~ Ascending Order
---------------------------------
        Davies, Emily
        Evans, Olivia
        Jones, Rhys
        Jones, Trevor
        Li, Na
        Lloyd, Arthur
        Saleem, Mohammad
        Smith, John
        Song, Mona
        Zhang, Xiu Ying

---------------------------------
Student Names ~ Descending Order
---------------------------------
        Zhang, Xiu Ying
        Song, Mona
        Smith, John
        Saleem, Mohammad
        Lloyd, Arthur
        Li, Na
        Jones, Trevor
        Jones, Rhys
        Evans, Olivia
        Davies, Emily

*/