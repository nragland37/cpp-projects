//****************************************************************************************************
// 			File:                 gradeCalc.cpp
//
//			Student:              Nicholas Ragland
//
//			Assignment:           Program #4
//
//          Course Name:          Programming 1
//
//          Course Number:        COSC 1550 - 03
//
//          Due:                  September 16, 2021
//
//          This program calculates the final grade, based on the grade of each deliverable
//			(programming assignments, chapter tests, final exam, and class participation) given
//			by  the  user.
//
//****************************************************************************************************

#include <iomanip>
#include <iostream>
using namespace std;

//****************************************************************************************************
int main() {
    float assignWeight,
        testWeight,
        examWeight,
        particWeight,
        PercentOutOf100,
        sum_of_all_weights,
        avg;

    const int ASSIGN_PERCENT = 15,
              TEST_PERCENT = 50,
              EXAM_PERCENT = 30,
              PARTIC_PERCENT = 5;

    cout << "Grade Calculator - Computer Programming I 'Final Grade'\n"
         << endl;

    cout << "The  weight  of  each  deliverable on their final grade. (shown below)\n\n"
         << "\t"
         << "Programmig Assignments: " << ASSIGN_PERCENT << "%\n"
         << "\t"
         << "Chapter Tests: " << TEST_PERCENT << "%\n"
         << "\t"
         << "Final Exam: " << EXAM_PERCENT << "%\n"
         << "\t"
         << "Class Participation: " << PARTIC_PERCENT << "%\n"
         << endl;

    cout << "What is the graded percentage (out of 100%) for Programming Assignments? ";
    cin >> PercentOutOf100;

    assignWeight = PercentOutOf100 * ASSIGN_PERCENT;

    cout << "What is the graded percentage (out of 100%) for Chapter Tests? ";
    cin >> PercentOutOf100;

    testWeight = PercentOutOf100 * TEST_PERCENT;

    cout << "What is the graded percentage (out of 100%) for Final Exam? ";
    cin >> PercentOutOf100;

    examWeight = PercentOutOf100 * EXAM_PERCENT;

    cout << "What is the graded percentage (out of 100%) for Class Participation? ";
    cin >> PercentOutOf100;

    particWeight = PercentOutOf100 * PARTIC_PERCENT;

    sum_of_all_weights = (ASSIGN_PERCENT + TEST_PERCENT + EXAM_PERCENT + PARTIC_PERCENT);
    avg = (assignWeight + testWeight + examWeight + particWeight) / sum_of_all_weights;

    cout << fixed << setprecision(2);

    cout << "\n\n\t" << assignWeight / sum_of_all_weights << "% in Programming Assignments\n"
         << "\t" << testWeight / sum_of_all_weights << "% in Chapter Tests\n"
         << "\t" << examWeight / sum_of_all_weights << "% in Final Exam\n"
         << "\t" << particWeight / sum_of_all_weights << "% in Class Participation\n"
         << endl;

    cout << "\nFinal Grade: " << avg << "%" << endl
         << endl;

    if (avg >= 97 || avg == 100) {
        cout << "Your Grade is A+";
    } else if (avg >= 94 && avg <= 96) {
        cout << "Your Grade is A";
    } else if (avg >= 90 && avg <= 93) {
        cout << "Your Grade is A-";
    } else if (avg >= 87 && avg <= 89) {
        cout << "Your Grade is B+";
    } else if (avg >= 84 && avg <= 86) {
        cout << "Your Grade is B";
    } else if (avg >= 80 && avg <= 83) {
        cout << "Your Grade is B-";
    } else if (avg >= 77 && avg <= 79) {
        cout << "Your Grade is C+";
    } else if (avg >= 74 && avg <= 76) {
        cout << "Your Grade is C";
    } else if (avg >= 70 && avg <= 73) {
        cout << "Your Grade is C-";
    } else if (avg >= 60 && avg <= 69) {
        cout << "Your Grade is D";
    } else {
        cout << "Your Grade is F";
    }

    cout << endl
         << endl;

    return 0;
}

//****************************************************************************************************
/*

Grade Calculator - Computer Programming I 'Final Grade'

The  weight  of  each  deliverable on their final grade. (shown below)

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

*/