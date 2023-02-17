//*****************************************************************************************************
//
//      This is a grade calculator program that calculates the final grade for a student in a Computer
//      Programming I course. It takes the percentage for each deliverable (Programming Assignments,
//      Chapter Tests, Final Exam, and Class Participation) and multiplies it by its weight to obtain
//      the final percentage. The final grades for each deliverable are summed up to produce the final
//      grade for the course.
//
//*****************************************************************************************************

#include <iomanip>
#include <iostream>
using namespace std;

//*****************************************************************************************************

int main() {
    const int ASSIGN_PERCENT = 15,
              TEST_PERCENT = 50,
              EXAM_PERCENT = 30,
              PARTIC_PERCENT = 5;
    float assignWeight,
        testWeight,
        examWeight,
        particWeight,
        PercentOutOf100,
        sum_of_all_weights,
        avg;

    cout << "Grade Calculator - Computer Programming I \n" << endl;

    cout << "The weight of each deliverable on their final grade \n"
         << "\t" << "Programmig Assignments: " << ASSIGN_PERCENT << "% \n"
         << "\t" << "Chapter Tests: " << TEST_PERCENT << "% \n"
         << "\t" << "Final Exam: " << EXAM_PERCENT << "% \n"
         << "\t" << "Class Participation: " << PARTIC_PERCENT << "% \n" << endl;

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

    cout << "\n\n\t" << assignWeight / sum_of_all_weights << "% in Programming Assignments \n"
         << "\t" << testWeight / sum_of_all_weights << "% in Chapter Tests \n"
         << "\t" << examWeight / sum_of_all_weights << "% in Final Exam \n"
         << "\t" << particWeight / sum_of_all_weights << "% in Class Participation \n" << endl;

    cout << "\nFinal Grade: " << avg << "% \n" << endl;

    if (avg >= 97 || avg == 100)         // 97% is the lowest A+ 
        cout << "Your Grade is A+";
    else if (avg >= 94 && avg <= 96)     // 94% is the lowest A 
        cout << "Your Grade is A";
    else if (avg >= 90 && avg <= 93)     // 90% is the lowest A- 
        cout << "Your Grade is A-";
    else if (avg >= 87 && avg <= 89)     // 87% is the lowest B+ 
        cout << "Your Grade is B+";
    else if (avg >= 84 && avg <= 86)     // 84% is the lowest B 
        cout << "Your Grade is B";
    else if (avg >= 80 && avg <= 83)     // 80% is the lowest B- 
        cout << "Your Grade is B-";
    else if (avg >= 77 && avg <= 79)     // 77% is the lowest C+ 
        cout << "Your Grade is C+";
    else if (avg >= 74 && avg <= 76)     // 74% is the lowest C 
        cout << "Your Grade is C";
    else if (avg >= 70 && avg <= 73)     // 70% is the lowest C- 
        cout << "Your Grade is C-";
    else if (avg >= 60 && avg <= 69)     // 60% is the lowest D 
        cout << "Your Grade is D";
    else
        cout << "Your Grade is F";       // 59% is the lowest F 

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

//*****************************************************************************************************

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