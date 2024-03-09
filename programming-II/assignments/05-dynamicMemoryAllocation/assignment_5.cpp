//*****************************************************************************************************
//      Cricket Matches Survey Analysis
//
//      This program prompts the user to input data on cricket matches played by college students,
//      dynamically allocates memory for the data, and performs various operations such as displaying
//      the data, finding the student who played the most matches, calculating the mean number of
//      matches played, and sorting the data in ascending order by student names.
//
//*****************************************************************************************************

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

void input(string names[], int matches[], int size);
void display(const string names[], const int matches[], int size);
void displayMostMatches(const string names[], const int matches[], int size);
double mean(const int matches[], int num);
void sortStudents(string names[], int matches[], int size);

//*****************************************************************************************************

int main() {
    int size;     // size of the array to be dynamically allocated
    int *matches = nullptr;
    double average;
    string *names = nullptr;     // pointer to dynamically allocated array and set to nullptr

    cout << "-------------------------------------------------\n"
         << " Cricket Matches College Students Play in a Year\n"
         << "-------------------------------------------------" << endl;

    do {
        cout << "How many students were surveyed? (1-5000): ";
        cin >> size;

        if (size <= 0 || size > 5000)
            cerr << "\nError: Invalid Entry\n";

        cin.ignore();
    } while (size <= 0 || size > 5000);

    names = new string[size];     // dynamically allocate memory
    matches = new int[size];

    input(names, matches, size);

    cout << "\n-------------------------------------------------\n"
         << "\tStudent Names & Matches Played\n"
         << "-------------------------------------------------" << endl;

    display(names, matches, size);

    cout << "\n-------------------------------------------------\n"
         << "\tStudent Who Played Most Matches\n"
         << "-------------------------------------------------" << endl;

    displayMostMatches(names, matches, size);

    cout << "\n-------------------------------------------------\n"
         << "\tAverage Matches Played for Students\n"
         << "-------------------------------------------------" << endl;

    average = mean(matches, size);
    cout << "Average: " << average << endl;

    cout << "\n-------------------------------------------------\n"
         << "Student Names & Matches Played ~ Ascending Order\n"
         << "-------------------------------------------------" << endl;

    sortStudents(names, matches, size);
    display(names, matches, size);

    delete[] names;      // deallocate memory
    names = nullptr;     // set pointer to nullptr to prevent dangling pointers
    delete[] matches;
    matches = nullptr;

    return 0;
}

//*****************************************************************************************************

void input(string names[], int matches[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "\nEnter name of student " << i + 1 << ": ";
        getline(cin, names[i]);

        while (true) {
            cout << "Enter number of matches for " << names[i] << ": ";
            cin >> matches[i];

            cin.ignore();

            if (matches[i] >= 0)
                break;
            else
                cerr << "\nError: Invalid Entry\n";
        }
    }
}

//*****************************************************************************************************

void display(const string names[], const int matches[], int size) {
    for (int i = 0; i < size; ++i)
        cout << i + 1 << "  " << setfill('.') << setw(30) << left << names[i]
             << " Matches: " << matches[i] << endl;
}

//*****************************************************************************************************

void displayMostMatches(const string names[], const int matches[], int size) {
    int max = matches[0];
    int temp = 0;

    for (int i = 0; i < size; ++i) {
        if (matches[i] > max) {
            max = matches[i];
            temp = i;
        }
    }

    cout << temp + 1 << "  " << setfill('.') << setw(30) << left << names[temp]
         << " Matches: " << matches[temp] << endl;
}

//*****************************************************************************************************

double mean(const int matches[], int size) {
    double sum = 0;

    for (int i = 0; i < size; ++i)
        sum += matches[i];

    return (sum / size);
}

//*****************************************************************************************************
// selection sort algorithm (time complexity: O(n^2)

void sortStudents(string names[], int matches[], int size) {     
    int minIndex,
        minValueMatches;
    string minValueNames;

    for (int startScan = 0; startScan < (size - 1); ++startScan) {
        minIndex = startScan;
        minValueNames = names[minIndex];
        minValueMatches = matches[minIndex];

        for (int index = startScan + 1; index < size; ++index) {
            if (names[index] < minValueNames) {
                minValueNames = names[index];
                minValueMatches = matches[index];
                minIndex = index;
            }
        }

        names[minIndex] = names[startScan];
        names[startScan] = minValueNames;
        matches[minIndex] = matches[startScan];
        matches[startScan] = minValueMatches;
    }
}

//*****************************************************************************************************
/*

-------------------------------------------------
 Cricket Matches College Students Play in a Year
-------------------------------------------------
How many students were surveyed? (1-5000): 0

Error: Invalid Entry
How many students were surveyed? (1-5000): -1

Error: Invalid Entry
How many students were surveyed? (1-5000): 10000

Error: Invalid Entry
How many students were surveyed? (1-5000): 5

Enter name of student 1: Ragland, Nicholas
Enter number of matches for Ragland, Nicholas: -1

Error: Invalid Entry
Enter number of matches for Ragland, Nicholas: 23

Enter name of student 2: Smith, John
Enter number of matches for Smith, John: 28

Enter name of student 3: Zhang, Xiu Ying
Enter number of matches for Zhang, Xiu Ying: 21

Enter name of student 4: Evans, Olivia
Enter number of matches for Evans, Olivia: 30

Enter name of student 5: Song, Mona
Enter number of matches for Song, Mona: 26

-------------------------------------------------
        Student Names & Matches Played
-------------------------------------------------
1  Ragland, Nicholas............. Matches: 23
2  Smith, John................... Matches: 28
3  Zhang, Xiu Ying............... Matches: 21
4  Evans, Olivia................. Matches: 30
5  Song, Mona.................... Matches: 26

-------------------------------------------------
        Student Who Played Most Matches
-------------------------------------------------
4  Evans, Olivia................. Matches: 30

-------------------------------------------------
        Average Matches Played for Students
-------------------------------------------------
Average: 25.6

-------------------------------------------------
Student Names & Matches Played ~ Ascending Order
-------------------------------------------------
1  Evans, Olivia................. Matches: 30
2  Ragland, Nicholas............. Matches: 23
3  Smith, John................... Matches: 28
4  Song, Mona.................... Matches: 26
5  Zhang, Xiu Ying............... Matches: 21

*/