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

#include <iostream>
using namespace std;

//****************************************************************************************************
int main() {
    float finalAssignPercent,
        finalTestPercent,
        finalExamPercent,
        finalParticPercent,
        PercentOutOf100,
        sum;

    const int ASSIGN_PERCENT = 15,
              TEST_PERCENT = 50,
              EXAM_PERCENT = 30,
              PARTIC_PERCENT = 5;

    cout << "Grade Calculator - Computer Programming I 'Final Grade'" << endl
         << endl;

    cout << "The  weight  of  each  deliverable on their final grade. (shown below)" << endl
         << endl
         << "\t"
         << "Programmig Assignments: " << ASSIGN_PERCENT << "%" << endl
         << "\t"
         << "Chapter Tests: " << TEST_PERCENT << "%" << endl
         << "\t"
         << "Final Exam: " << EXAM_PERCENT << "%" << endl
         << "\t"
         << "Class Participation: " << PARTIC_PERCENT << "%" << endl
         << endl;

    cout << "What is the graded percentage (out of 100%) for Programming Assignments? ";
    cin >> PercentOutOf100;

    finalAssignPercent = PercentOutOf100 * 0.15;

    cout << "What is the graded percentage (out of 100%) for Chapter Tests? ";
    cin >> PercentOutOf100;

    finalTestPercent = PercentOutOf100 * 0.50;

    cout << "What is the graded percentage (out of 100%) for Final Exam? ";
    cin >> PercentOutOf100;

    finalExamPercent = PercentOutOf100 * 0.30;

    cout << "What is the graded percentage (out of 100%) for Class Participation? ";
    cin >> PercentOutOf100;

    finalParticPercent = PercentOutOf100 * .05;

    sum = (finalAssignPercent + finalTestPercent + finalExamPercent + finalParticPercent);

    cout << endl
         << endl
         << endl;

    cout << "\t" << finalAssignPercent << "% in Programming Assignments" << endl
         << "\t" << finalTestPercent << "% in Chapter Tests" << endl
         << "\t" << finalExamPercent << "% in Final Exam" << endl
         << "\t" << finalParticPercent << "% in Class Participation" << endl
         << endl
         << endl;

    cout << "Final Grade: " << sum << "%" << endl;

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