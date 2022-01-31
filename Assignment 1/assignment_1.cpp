//****************************************************************************************************
// 			File:                 assignment_1.cpp
//
//			Student:              Nicholas Ragland
//
//			Assignment:           Program #1
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  January 31, 2021
//
//          This program reads and displays eight test scores, as a percentage, for ten students 
//          from a file. The functions calculate total points of one student for all tests,
//          total points for one test for all students, total average of all students for one test, 
//          average of all tests for one student, highest test score for one student, and the student 
//          with the highest average test score.       
//
//****************************************************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int NUM_TESTS = 8;

void readTestScores(ifstream &f, int scores[][NUM_TESTS], int numStds);
void displayTestScores(const int scores[][NUM_TESTS], int numStds);
int totalOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber);
int totalOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber);
double averageOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber);
double averageOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber);
int highestOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber);
int topStudent(const int scores[][NUM_TESTS], int numStds);

//****************************************************************************************************

int main()
{
    ifstream f("Assignment1Data.txt");

    const int NUM_STDS = 10;

    int scores[NUM_STDS][NUM_TESTS];

    readTestScores(f, scores, NUM_STDS);
    displayTestScores(scores, NUM_STDS);

    cout << setprecision(2) << fixed;

    cin.get();
    cout << "\nTotal for Test #1 is: " << totalOneTest(scores, NUM_STDS, 0);
    cin.get();
    cout << "\n\nTotal for Test #5 is: " << totalOneTest(scores, NUM_STDS, 4);
    cin.get();
    cout << "\n\nTotal for Student #3 is: " << totalOneStudent(scores, NUM_STDS, 2);
    cin.get();
    cout << "\n\nTotal for Student #8 is: " << totalOneStudent(scores, NUM_STDS, 7);
    cin.get();
    cout << "\n\nAverage for Test #5: " << averageOneTest(scores, NUM_STDS, 4);
    cin.get();
    cout << "\n\nAverage for Test #8: " << averageOneTest(scores, NUM_STDS, 7);
    cin.get();
    cout << "\n\nAverage for Student #5: " << averageOneStudent(scores, NUM_STDS, 4);
    cin.get();
    cout << "\n\nAverage for Student #9: " << averageOneStudent(scores, NUM_STDS, 8);
    cin.get();
    cout << "\n\nHighest test score for Student #2: " << highestOneStudent(scores, NUM_STDS, 1);
    cin.get();
    cout <<"\n\nThe top Student: " << topStudent(scores, NUM_STDS);
    cin.get();

    f.close();
    
	return 0;
}

//****************************************************************************************************

void readTestScores(ifstream &f, int scores[][NUM_TESTS], int numStds)
{
    if (f.is_open())
        for (int studentNumber = 0; studentNumber < numStds; ++studentNumber) {
            for (int testNumber = 0; testNumber < NUM_TESTS; ++testNumber) {
                f >> scores[studentNumber][testNumber];
            }
        }
    else
    cout << "ERROR: Could not open file" << endl; 
}

//****************************************************************************************************

void displayTestScores(const int scores[][NUM_TESTS], int numStds)
{
    cout << "All Test scores:" << endl;
    
    for (int studentNumber = 0; studentNumber < numStds; ++studentNumber) {
         for (int testNumber = 0; testNumber < NUM_TESTS; ++testNumber) {
             cout << scores[studentNumber][testNumber] << " ";
        }
        cout << endl;
    }
}

//****************************************************************************************************

int totalOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber)
{
    int sum = 0;

    for (int studentNumber = 0; studentNumber < numStds; ++studentNumber) {
        sum += scores[studentNumber][testNumber];
    }

    return sum;
}

//****************************************************************************************************

int totalOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber)
{
    int sum = 0;

    for (int testNumber = 0; testNumber < NUM_TESTS; ++testNumber) {
        sum += scores[studentNumber][testNumber];
    }

    return sum;
}

//****************************************************************************************************

double averageOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber)
{   
    int total = 0;
    double average;

    for (int studentNumber = 0; studentNumber < numStds; ++studentNumber) {
        total += scores[studentNumber][testNumber];
    }
    average = static_cast<double>(total) / numStds;

    return average;
}

//****************************************************************************************************

double averageOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber)
{
    int total = 0;
    double average;

    for (int testNumber = 0; testNumber < NUM_TESTS; ++testNumber) {
        total += scores[studentNumber][testNumber];
    }
    average = static_cast<double>(total) / NUM_TESTS;

    return average;
}

//****************************************************************************************************

int highestOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber)
{
    int highest = scores[studentNumber][0];
    for (int testNumber = 1; testNumber < NUM_TESTS; ++testNumber) {
        if (scores[studentNumber][testNumber] > highest) {
            highest = scores[studentNumber][testNumber];
        }
    }
    return highest;
}

//****************************************************************************************************

int topStudent(const int scores[][NUM_TESTS], int numStds)            
{
    int topPercent = 0,
        topStudent,
        current;

    for (int studentNumber = 0; studentNumber < numStds; ++studentNumber) {
        current = averageOneStudent(scores, numStds, studentNumber);
        if (current >= topPercent) {
            topPercent = current;
            topStudent = studentNumber;
        }
    }

    return topStudent+1;
}

/*

All Test scores:
87 90 65 45 88 89 75 80
89 85 78 56 90 91 99 82
80 90 72 95 99 66 77 88
90 65 80 98 99 76 77 88
55 75 66 99 99 56 87 86
30 60 80 90 99 56 67 88
90 55 95 35 98 86 37 88
99 97 99 98 98 96 87 83
90 65 80 98 99 76 87 88
35 75 60 99 99 56 87 88

Press Enter to Continue 
 
Total for Test #1 is: 745
Press Enter to Continue 
 
Total for Test #5 is: 968
Press Enter to Continue 
 
Total for Student #3 is: 667 
Press Enter to Continue 
 
Total for Student #8 is: 757
Press Enter to Continue 
 
Average for Test #5: 96.80  
Press Enter to Continue 
 
Average for Test #8: 85.90 
Press Enter to Continue 
 
Average for Student #5: 77.88
Press Enter to Continue 
 
Average for Student #9: 85.38 
Press Enter to Continue 
 
Highest test score for Student #2: 99 
Press Enter to Continue 
 
The top Student: 8 
Press Enter to Continue

*/