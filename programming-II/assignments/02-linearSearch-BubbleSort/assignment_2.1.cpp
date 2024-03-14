//*****************************************************************************************************
//      Test Score Analysis
//
//      This program reads in test scores from a file, performs various calculations on the data, and
//      allows the user to search for students using a linear search algorithm.
//
//      Other files required:
//        1.  Assignment1Data.txt - test scores for 10 students
//
//*****************************************************************************************************

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

//*****************************************************************************************************

const int NUM_TESTS = 8;

void readTestScores(ifstream &f, int scores[][NUM_TESTS], int numStds);
void displayTestScores(const int scores[][NUM_TESTS], int numStds);
int totalOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber);
int totalOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber);
double averageOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber);
double averageOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber);
int highestOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber);
int topStudent(const int scores[][NUM_TESTS], int numStds);
bool searchStudents(const int scores[][NUM_TESTS], int numStds, double average);
bool searchTests(const int scores[][NUM_TESTS], int numStds, double average);

//*****************************************************************************************************

int main() {
    const int NUM_STDS = 10;
    int scores[NUM_STDS][NUM_TESTS];
    double average;
    ifstream f("Assignment1Data.txt");

    readTestScores(f, scores, NUM_STDS);
    f.close();
    displayTestScores(scores, NUM_STDS);

    cout << setprecision(2) << fixed;

    cout << "\nTotal for Test #1 is: " << totalOneTest(scores, NUM_STDS, 0)
         << "\n\nTotal for Test #5 is: " << totalOneTest(scores, NUM_STDS, 4)
         << "\n\nTotal for Student #3 is: " << totalOneStudent(scores, NUM_STDS, 2)
         << "\n\nTotal for Student #8 is: " << totalOneStudent(scores, NUM_STDS, 7)
         << "\n\nAverage for Test #5: " << averageOneTest(scores, NUM_STDS, 4)
         << "\n\nAverage for Test #8: " << averageOneTest(scores, NUM_STDS, 7)
         << "\n\nAverage for Student #5: " << averageOneStudent(scores, NUM_STDS, 4)
         << "\n\nAverage for Student #9: " << averageOneStudent(scores, NUM_STDS, 8)
         << "\n\nHighest test score for Student #2: " << highestOneStudent(scores, NUM_STDS, 1)
         << "\n\nThe top Student: " << topStudent(scores, NUM_STDS) << endl;

    cout << "\nFind if at least one student has an average score greater\n"
         << "Enter average score of student: ";
    cin >> average;

    if (searchStudents(scores, NUM_STDS, average))
        cout << "\nA student DOES have an average score greater than: " << average;
    else
        cout << "\nA student DOES NOT have an average score greater than: " << average;

    cout << "\n\nFind if at least one test has an average score greater\n"
         << "Enter average score of test: ";
    cin >> average;

    if (searchTests(scores, NUM_STDS, average))
        cout << "\nA test DOES have an average score greater than: " << average << endl;
    else
        cout << "\nA test DOES NOT have an average score greater than: " << average << endl;

    return 0;
}

//*****************************************************************************************************

void readTestScores(ifstream &f, int scores[][NUM_TESTS], int numStds) {
    if (f.is_open()) {
        for (int studentNumber = 0; studentNumber < numStds; ++studentNumber)
            for (int testNumber = 0; testNumber < NUM_TESTS; ++testNumber)
                f >> scores[studentNumber][testNumber];
    } else {
        cerr << "Error: Unable to open file\n";
    }
}

//*****************************************************************************************************

void displayTestScores(const int scores[][NUM_TESTS], int numStds) {
    cout << "    All Test scores" << endl;

    for (int studentNumber = 0; studentNumber < numStds; ++studentNumber) {
        for (int testNumber = 0; testNumber < NUM_TESTS; ++testNumber)
            cout << scores[studentNumber][testNumber] << " ";

        cout << endl;
    }
}

//*****************************************************************************************************

int totalOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber) {
    int sum = 0;

    for (int studentNumber = 0; studentNumber < numStds; ++studentNumber)
        sum += scores[studentNumber][testNumber];

    return sum;
}

//*****************************************************************************************************

int totalOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber) {
    int sum = 0;

    for (int testNumber = 0; testNumber < NUM_TESTS; ++testNumber)
        sum += scores[studentNumber][testNumber];

    return sum;
}

//*****************************************************************************************************

double averageOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber) {
    int total = 0;
    double average;

    for (int studentNumber = 0; studentNumber < numStds; ++studentNumber)
        total += scores[studentNumber][testNumber];

    average = static_cast<double>(total) / numStds;

    return average;
}

//*****************************************************************************************************

double averageOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber) {
    int total = 0;
    double average;

    for (int testNumber = 0; testNumber < NUM_TESTS; ++testNumber)
        total += scores[studentNumber][testNumber];

    average = static_cast<double>(total) / NUM_TESTS;

    return average;
}

//*****************************************************************************************************

int highestOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber) {
    int highest = scores[studentNumber][0];

    for (int testNumber = 1; testNumber < NUM_TESTS; ++testNumber)
        if (scores[studentNumber][testNumber] > highest)
            highest = scores[studentNumber][testNumber];

    return highest;
}

//*****************************************************************************************************

int topStudent(const int scores[][NUM_TESTS], int numStds) {
    int topPercent = 0,
        topStudent = 0,
        current;

    for (int studentNumber = 0; studentNumber < numStds; ++studentNumber) {
        current = averageOneStudent(scores, numStds, studentNumber);

        if (current > topPercent) {
            topPercent = current;
            topStudent = studentNumber;
        }
    }

    return (topStudent + 1);
}

//*****************************************************************************************************
// linear search algorithm (time complexity: O(n))

bool searchStudents(const int scores[][NUM_TESTS], int numStds, double average) {
    int studentNumber = 0;
    bool found = false;

    while ((studentNumber < numStds) && !found) {
        if (averageOneStudent(scores, numStds, studentNumber) > average)
            found = true;

        studentNumber++;
    }

    return found;
}

//*****************************************************************************************************

bool searchTests(const int scores[][NUM_TESTS], int numStds, double average) {
    int testNumber = 0;
    bool found = false;

    while ((testNumber < NUM_TESTS) && !found) {
        if (averageOneTest(scores, numStds, testNumber) > average)
            found = true;

        testNumber++;
    }

    return found;
}

//*****************************************************************************************************
/*

    All Test scores
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

Total for Test #1 is: 745

Total for Test #5 is: 968

Total for Student #3 is: 667

Total for Student #8 is: 757

Average for Test #5: 96.80

Average for Test #8: 85.90

Average for Student #5: 77.88

Average for Student #9: 85.38

Highest test score for Student #2: 99

The top Student: 8

Find if at least one student has an average score greater
Enter average score of student: 95

A student DOES NOT have an average score greater than: 95.00

Find if at least one test has an average score greater
Enter average score of test: 95

A test DOES have an average score greater than: 95.00

*****************************************************************************************************

    All Test scores
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

Total for Test #1 is: 745

Total for Test #5 is: 968

Total for Student #3 is: 667

Total for Student #8 is: 757

Average for Test #5: 96.80

Average for Test #8: 85.90

Average for Student #5: 77.88

Average for Student #9: 85.38

Highest test score for Student #2: 99

The top Student: 8

Find if at least one student has an average score greater
Enter average score of student: 60

A student DOES have an average score greater than: 60.00

Find if at least one test has an average score greater
Enter average score of test: 99

A test DOES NOT have an average score greater than: 99.00

*/