//*****************************************************************************************************
//      Computer Programming I Grade Calculator
//
//	This program is a grade calculator for a Computer Programming I class that uses functions.
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

//*****************************************************************************************************

void readGrades(float &, float &, float &, float &);
void calcWeights(float &, float &, float &, float &, float, float, float, float);
float calcFind(float, float, float, float);
void displayResults(float);

//*****************************************************************************************************

int main() {
    const int ASSIGN_PERCENT = 15,
              TEST_PERCENT = 50,
              EXAM_PERCENT = 30,
              PARTIC_PERCENT = 5;
    float assign,
        test,
        exam,
        partic,
        finalGrade;

    cout << "Grade Calculator - Computer Programming I" << endl;

    cout << "\nThe weight of each deliverable on their final grade\n\n"
         << "\tProgrammig Assignments: " << ASSIGN_PERCENT << "%\n"
         << "\tChapter Tests: " << TEST_PERCENT << "%\n"
         << "\tFinal Exam: " << EXAM_PERCENT << "%\n"
         << "\tClass Participation: " << PARTIC_PERCENT << "%" << endl;

    readGrades(assign, test, exam, partic);
    calcWeights(assign, test, exam, partic, ASSIGN_PERCENT, TEST_PERCENT, EXAM_PERCENT, PARTIC_PERCENT);

    finalGrade = calcFind(assign, test, exam, partic);

    cout << "\n\t" << assign << "% in Programming Assignments"
         << "\n\t" << test << "% in Chapter Tests"
         << "\n\t" << exam << "% in Final Exam"
         << "\n\t" << partic << "% in Class Participation" << endl;

    displayResults(finalGrade);

    return 0;
}

//*****************************************************************************************************

void readGrades(float &assign, float &test, float &exam, float &partic) {
    cout << "\nWhat is the graded percentage (out of 100%) for Programming Assignments? ";
    cin >> assign;

    cout << "What is the graded percentage (out of 100%) for Chapter Tests? ";
    cin >> test;

    cout << "What is the graded percentage (out of 100%) for Final Exam? ";
    cin >> exam;

    cout << "What is the graded percentage (out of 100%) for Class Participation? ";
    cin >> partic;
}

//*****************************************************************************************************

void calcWeights(float &assign, float &test, float &exam, float &partic,
                 float ASSIGN_PERCENT, float TEST_PERCENT, float EXAM_PERCENT, float PARTIC_PERCENT) {
    assign = (assign * ASSIGN_PERCENT) / 100;
    test = (test * TEST_PERCENT) / 100;
    exam = (exam * EXAM_PERCENT) / 100;
    partic = (partic * PARTIC_PERCENT) / 100;
}

//*****************************************************************************************************

float calcFind(float assign, float test, float exam, float partic) {
    return (assign + test + exam + partic);
}

//*****************************************************************************************************

void displayResults(float finalGrade) {
    cout << "\nFinal Grade: " << finalGrade << "%" << endl;
}

//*****************************************************************************************************
/*

Grade Calculator - Computer Programming I

The weight of each deliverable on their final grade

        Programmig Assignments: 15%
        Chapter Tests: 50%
        Final Exam: 30%
        Class Participation: 5%

What is the graded percentage (out of 100%) for Programming Assignments? 100
What is the graded percentage (out of 100%) for Chapter Tests? 100
What is the graded percentage (out of 100%) for Final Exam? 100
What is the graded percentage (out of 100%) for Class Participation? 100

        15% in Programming Assignments
        50% in Chapter Tests
        30% in Final Exam
        5% in Class Participation

Final Grade: 100%

//*****************************************************************************************************

Grade Calculator - Computer Programming I

The weight of each deliverable on their final grade

        Programmig Assignments: 15%
        Chapter Tests: 50%
        Final Exam: 30%
        Class Participation: 5%

What is the graded percentage (out of 100%) for Programming Assignments? 85
What is the graded percentage (out of 100%) for Chapter Tests? 90
What is the graded percentage (out of 100%) for Final Exam? 95
What is the graded percentage (out of 100%) for Class Participation? 100

        12.75% in Programming Assignments
        45% in Chapter Tests
        28.5% in Final Exam
        5% in Class Participation

Final Grade: 91.25%

//*****************************************************************************************************

Grade Calculator - Computer Programming I

The weight of each deliverable on their final grade

        Programmig Assignments: 15%
        Chapter Tests: 50%
        Final Exam: 30%
        Class Participation: 5%

What is the graded percentage (out of 100%) for Programming Assignments? 75
What is the graded percentage (out of 100%) for Chapter Tests? 85
What is the graded percentage (out of 100%) for Final Exam? 95
What is the graded percentage (out of 100%) for Class Participation? 90

        11.25% in Programming Assignments
        42.5% in Chapter Tests
        28.5% in Final Exam
        4.5% in Class Participation

Final Grade: 86.75%

*/