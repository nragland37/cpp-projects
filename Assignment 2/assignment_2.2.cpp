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
//          This program reads and displays eight test scores, as a percentage, for ten students
//          from a file. The functions calculate total points of one student for all tests,
//          total points for one test for all students, total average of all students for one test,
//          average of all tests for one student, highest test score for one student, and the student
//          with the highest average test score.
//
//****************************************************************************************************

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void readNames(ifstream &inputFile, string names[], int numNames);
// Read all names from the file. The names should be stored in the array as they are stored in the file.
void displayNames(const string names[], int numNames);
// Display the names.
int searchNames(const string names[], int numNames, const string &name);
/*Return the array index if the name, passed as the third argument, is found in the
array.  If the name is not found then return -1.  The user should be prompted for
the name before the function is called.
Use the ‘linear search’ algorithm to implement this function.*/
void bubbleSort(string names[], int numNames);
// Sort the names in ascending order using the bubble sort algorithm.
void bubbleSortDescending(string names[], int numNames);
// Sort the names in descending order using the bubble sort algorithm

//****************************************************************************************************

int main()
{
    ifstream inputFile("StudentNames.txt");

    const int NUM_NAMES = 21;

    string names [NUM_NAMES];

    readNames(inputFile, names, NUM_NAMES);
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
             inputFile >> names[nameNumber];
        }
    else
        cout << "ERROR: Could not open file" << endl;
}

//****************************************************************************************************

void displayNames(const string names[], int numNames)
{
    cout << "All Names:" << endl;
    for (int nameNumber = 0; nameNumber < numNames; ++nameNumber)
    {
        cout << names[nameNumber] << " " << endl;
    }
}

//****************************************************************************************************

int searchNames(const string names[], int numNames, const string &name)
{
    // linear search with string 
    return 0;
}

//****************************************************************************************************

void bubbleSort(string names[], int numNames)
{

}

//****************************************************************************************************

void bubbleSortDescending(string names[], int numNames)
{
    
}

/*

All names:
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


*/