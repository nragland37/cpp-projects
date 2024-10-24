//*****************************************************************************************************
//      Computer Programming I Grade Calculator
//
//      This program is a simple grade calculator based on your performance during the computer programming course.
//
//*****************************************************************************************************

#include <iomanip>
#include <iostream>
using namespace std;

//*****************************************************************************************************
int main() {
    // Constants for component weights
    const int programming_assignment_weight = 15;
    const int chapter_test_weight = 50;
    const int final_exam_weight = 30;
    const int class_participation_weight = 5;

    // Variables to store graded percentages and weighted scores
    float programming_assignment_percentage;
    float chapter_test_percentage;
    float final_exam_percentage;
    float class_participation_percentage;

    float programming_assignment_score;
    float chapter_test_score;
    float final_exam_score;
    float class_participation_score;

    // Variable to store the final grade
    float final_grade;

    // Display introductory message
    cout << "Grade Calculator - Computer Programming I" << endl;

    cout << "\nThe weight of each deliverable on their final grade\n"
         << "\tProgrammig Assignments: " << programming_assignment_weight << "%\n"
         << "\tChapter Tests: " << chapter_test_weight << "%\n"
         << "\tFinal Exam: " << final_exam_weight << "%\n"
         << "\tClass Participation: " << class_participation_weight << "%" << endl;

    // Get user input for graded percentages
    cout << "\nWhat is the graded percentage (out of 100%) for Programming Assignments? ";
    cin >> programming_assignment_percentage;

    cout << "What is the graded percentage (out of 100%) for Chapter Tests? ";
    cin >> chapter_test_percentage;

    cout << "What is the graded percentage (out of 100%) for Final Exam? ";
    cin >> final_exam_percentage;

    cout << "What is the graded percentage (out of 100%) for Class Participation? ";
    cin >> class_participation_percentage;

    // Calculate weighted scores
    programming_assignment_score = programming_assignment_percentage * programming_assignment_weight;
    chapter_test_score = chapter_test_percentage * chapter_test_weight;
    final_exam_score = final_exam_percentage * final_exam_weight;
    class_participation_score = class_participation_percentage * class_participation_weight;

    // Calculate final grade
    final_grade = (programming_assignment_score + chapter_test_score + final_exam_score + class_participation_score) /
                   (programming_assignment_weight + chapter_test_weight + final_exam_weight + class_participation_weight);

    // Display results of final grades { programming assinments, Chapter Tests, Final Exams, Class Participation }
    cout << fixed << setprecision(2);

    cout << "\n\n\t" << programming_assignment_score << " points in Programming Assignments\n"
         << "\t" << chapter_test_score << " points in Chapter Tests\n"
         << "\t" << final_exam_score << " points in Final Exam\n"
         << "\t" << class_participation_score << " points in Class Participation" << endl;

    cout << "\n\nFinal Grade: " << final_grade << "%" << endl;

    // Determine grade of student based on their marks.
    if (final_grade >= 97 || final_grade == 100) {
        cout << "\nYour Grade is A+";
    } else if (final_grade >= 94 && final_grade <= 96) {
        cout << "\nYour Grade is A";
    } else if (final_grade >= 90 && final_grade <= 93) {
        cout << "\nYour Grade is A-";
    } else if (final_grade >= 87 && final_grade <= 89) {
        cout << "\nYour Grade is B+";
    } else if (final_grade >= 84 && final_grade <= 86) {
        cout << "\nYour Grade is B";
    } else if (final_grade >= 80 && final_grade <= 83) {
        cout << "\nYour Grade is B-";
    } else if (final_grade >= 77 && final_grade <= 79) {
        cout << "\nYour Grade is C+";
    } else if (final_grade >= 74 && final_grade <= 76) {
        cout << "\nYour Grade is C";
    } else if (final_grade >= 70 && final_grade <= 73) {
        cout << "\nYour Grade is C-";
    } else if (final_grade >= 60 && final_grade <= 69) {
        cout << "\nYour Grade is D";
    } else {
        cout << "\nYour Grade is F";
    }

    return 0;
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


        15.00% in Programming Assignments
        50.00% in Chapter Tests
        30.00% in Final Exam
        5.00% in Class Participation


Final Grade: 100.00%

Your Grade is A+

*****************************************************************************************************

Grade Calculator - Computer Programming I

The weight of each deliverable on their final grade
        Programmig Assignments: 15%
        Chapter Tests: 50%
        Final Exam: 30%
        Class Participation: 5%

What is the graded percentage (out of 100%) for Programming Assignments? 75
What is the graded percentage (out of 100%) for Chapter Tests? 95
What is the graded percentage (out of 100%) for Final Exam? 80
What is the graded percentage (out of 100%) for Class Participation? 98


        11.25% in Programming Assignments
        47.50% in Chapter Tests
        24.00% in Final Exam
        4.90% in Class Participation


Final Grade: 87.65%

Your Grade is B+

*/