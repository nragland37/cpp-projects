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
int main()
{
	float finalGbuPercent,
		finalAssignPercent,
		finalTermProjectJournalPercent,
		finalQuizPercent,
		finalTermProjectPercent,
		finalExamPercent,
		finalExtraPercent,
		PercentOutOf100,
		sum;

	const int GBU_PERCENT = 15,
		ASSIGN_PERCENT = 20,
		TPJ_PERCENT = 10,
		QUIZ_PERCENT = 15,
		TERM_PRO_PERCENT = 20,
		EXAM_PERCENT = 20,
		EXTRA_PERCENT = 5;

	cout << "Grade Calculator - Web Programming 'Final Grade'\n" << endl;


	cout << "The  weight  of  each  deliverable on their final grade. (shown below)\n\n"
		<< "\t" << "Good, Bad, & The Ugly: " << GBU_PERCENT << "%\n"
		<< "\t" << "Assignments: " << ASSIGN_PERCENT << "%\n"
		<< "\t" << "Term Project Journal: " << TPJ_PERCENT << "%\n"
		<< "\t" << "Quizzes: " << QUIZ_PERCENT << "%\n"
		<< "\t" << "Term Project: " << TERM_PRO_PERCENT << "%\n"
		<< "\t" << "Exam: " << EXAM_PERCENT << "%\n"
		<< "\t" << "Extra Credit: " << EXTRA_PERCENT << "%\n" << endl;

	cout << "What is the graded percentage (out of 100%) for Good, Bad, & The Ugly? ";
	cin >> PercentOutOf100;

	finalGbuPercent = PercentOutOf100 * 0.15;

	cout << "What is the graded percentage (out of 100%) for Assignments? ";
	cin >> PercentOutOf100;

	finalAssignPercent = PercentOutOf100 * 0.20;

	cout << "What is the graded percentage (out of 100%) for Term Project Journal? ";
	cin >> PercentOutOf100;

	finalTermProjectJournalPercent = PercentOutOf100 * 0.10;

	cout << "What is the graded percentage (out of 100%) for Quizzes? ";
	cin >> PercentOutOf100;

	finalQuizPercent = PercentOutOf100 * 0.15;

	cout << "What is the graded percentage (out of 100%) for Term Project? ";
	cin >> PercentOutOf100;

	finalTermProjectPercent = PercentOutOf100 * 0.20;

	cout << "What is the graded percentage (out of 100%) for Exams? ";
	cin >> PercentOutOf100;

	finalExamPercent = PercentOutOf100 * 0.20;

	cout << "What is the graded percentage (out of 100%) for Extra Credit? ";
	cin >> PercentOutOf100;

	finalExtraPercent = PercentOutOf100 * .05;

	sum = (finalGbuPercent + finalAssignPercent + finalTermProjectJournalPercent + finalQuizPercent + finalTermProjectPercent + finalExamPercent + finalExtraPercent);

	cout << "\n\n";

	cout << "\t" << finalGbuPercent << "% in Good, Bad, & The Ugly\n"
		<< "\t" << finalAssignPercent << "% in Assignments\n"
		<< "\t" << finalTermProjectJournalPercent << "% in Term Project Journal\n"
		<< "\t" << finalQuizPercent << "% in Quizzes\n"
		<< "\t" << finalTermProjectPercent << "% in Term Project\n"
		<< "\t" << finalExamPercent << "% in Exams\n"
		<< "\t" << finalExtraPercent << "% in Extra Credit\n" << endl;

	cout << "\n";

	cout << "Final Grade: " << sum << "%" << endl;

	cout << "\n";

	if (sum >= 100) {
		cout << "Perfect Score!!! ";
	}
	if (sum >= 97) {
		cout << "Congratulations!!! Final Grade is A+";
	}
	else if (sum >= 94) {
		cout << "Amazing Job!!! Final Grade is A";
	}
	else if (sum >= 90) {
		cout << "Wow, Great Job! Final Grade is A-";
	}
	else if (sum >= 87) {
		cout << "Great Job! Final Grade is B+";
	}
	else if (sum >= 84) {
		cout << "Great! Final Grade is B";
	}
	else if (sum >= 80) {
		cout << "Good! Final Grade is B-";
	}
	else if (sum >= 77) {
		cout << "Pretty Good. Final Grade is C+";
	}
	else if (sum >= 74) {
		cout << "Not Bad. Final Grade is C";
	}
	else if (sum >= 70) {
		cout << "Just Barely... Final Grade is C-";
	}
	else if (sum >= 60) {
		cout << "So Close... Final Grade is D";
	}
	else if (sum >= 50) {
		cout << "Failure...Final Grade Grade is F";
	}
	else if (sum <= 50) {
		cout << "Failure... Final Grade Grade is F";
	}

	cout << "\n";

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

Perfect Score!!! Congratulations!!! Final Grade is A+

*/