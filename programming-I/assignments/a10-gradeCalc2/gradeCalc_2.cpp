//****************************************************************************************************
// 			File:                 gradeCalc_2.cpp
//
//			Student:              Nicholas Ragland 
//
//			Assignment:           Program #9
//			
//          Course Name:          Programming 1
//
//          Course Number:        COSC 1550 - 03
//          
//          Due:                  November 18, 2021
//
//          This program uses functions to calculate the final grade, based on the grade of each 
//			deliverable (programming assignments, chapter tests, final exam, and class participation) 
//			given by  the  user. 
//
//****************************************************************************************************

#include <iostream>
using namespace std;

void readGrades(float &, float &, float &, float &);
void calcWeights(float &, float &, float &, float &, float, float, float, float);
float calcFind(float, float, float, float);
void displayResults(float);

//****************************************************************************************************

int main()
{
	float finalAssignPercent,
		  finalTestPercent,
		  finalExamPercent,
		  finalParticPercent,
		  finalGrade;

	const int ASSIGN_PERCENT = 15,
			  TEST_PERCENT = 50,
		      EXAM_PERCENT = 30,
			  PARTIC_PERCENT = 5;

	cout << "Grade Calculator - Computer Programming I 'Final Grade'" << endl << endl;

	cout << "The  weight  of  each  deliverable on their final grade. (shown below)" << endl << endl
		 << "\t" << "Programmig Assignments: " << ASSIGN_PERCENT << "%" << endl
		 << "\t" << "Chapter Tests: " << TEST_PERCENT << "%" << endl
		 << "\t" << "Final Exam: " << EXAM_PERCENT << "%" << endl
		 << "\t" << "Class Participation: " << PARTIC_PERCENT << "%" << endl << endl;

	readGrades(finalAssignPercent, finalTestPercent, finalExamPercent, finalParticPercent);
	calcWeights(finalAssignPercent, finalTestPercent, finalExamPercent, finalParticPercent,
			    ASSIGN_PERCENT, TEST_PERCENT, EXAM_PERCENT, PARTIC_PERCENT);
	finalGrade = calcFind(finalAssignPercent, finalTestPercent, finalExamPercent, finalParticPercent);

	cout << endl << endl;

	cout << "\t" << finalAssignPercent << "% in Programming Assignments" << endl
		 << "\t" << finalTestPercent << "% in Chapter Tests" << endl
		 << "\t" << finalExamPercent << "% in Final Exam" << endl
		 << "\t" << finalParticPercent << "% in Class Participation" << endl << endl << endl;

	displayResults(finalGrade);

	cout << endl;

	return 0;
}

//****************************************************************************************************

void readGrades(float& assignInput, float& testInput, float& examInput, float& particInput)
{
	cout << "What is the graded percentage (out of 100%) for Programming Assignments? ";
	cin >> assignInput;

	cout << "What is the graded percentage (out of 100%) for Chapter Tests? ";
	cin >> testInput;

	cout << "What is the graded percentage (out of 100%) for Final Exam? ";
	cin >> examInput;

	cout << "What is the graded percentage (out of 100%) for Class Participation? ";
	cin >> particInput;
}

//****************************************************************************************************

void calcWeights(float& assign, float& test, float& exam, float& partic, 
				 float assignPercent, float testPercent, float examPercent, float particPercent)
{
	assign  = assign * assignPercent/100;

	test = test * testPercent/100;

	exam = exam * examPercent/100;

	partic = partic * particPercent/100;
}

//****************************************************************************************************

float calcFind(float finalAssign, float finalTest, float finalExam, float finalPartic)
{
	return finalAssign + finalTest + finalExam + finalPartic;
}

//****************************************************************************************************

void displayResults(float finalGrade)
{
	cout << "Final Grade: " << finalGrade << "%" << endl;
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