//*****************************************************************************************************
//
//      This program reads in a file of student data and instantiates a doubly linked list to store 
//      the student objects. It then displays a menu of options to perform its methods.
//
//      Other files required:
//        1.	 DLList.h - header file for the DLList class
//        2.	 student.h - header file for the Student struct
//        3.	 studentFile.txt - file containing student data of 61 students
//
//*****************************************************************************************************

#include "DLList.h"
#include "student.h"

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

//*****************************************************************************************************

char getChoice();
void process(DLList<Student> &studentList);
void buildList(DLList<Student> &studentList);
void displayStudent(DLList<Student> &studentList);
void displayStudentRev(DLList<Student> &studentList);
void countStudents(DLList<Student> &studentList);
void addNewStudent(DLList<Student> &studentList);
void removeStudent(DLList<Student> &studentList);
void findStudent(DLList<Student> &studentList);

//*****************************************************************************************************

int main() {
    DLList<Student> studentList;

    buildList(studentList);
    process(studentList);

    return 0;
}

//*****************************************************************************************************

char getChoice() {
    char choice;
    bool valid;

    cout << "============= MENU =============\n"
         << "A: Add a new student\n"
         << "F: Find a student\n"
         << "R: Remove a student\n"
         << "C: Count the students\n"
         << "V: Reverse display the students\n"
         << "D: Display the students\n"
         << "Q: Quit\n"
         << "================================\n"
         << "Enter your choice: ";

    do {
        cin >> choice;
        choice = toupper(choice);

        switch (choice) {
            case 'A':
            case 'F':
            case 'R':
            case 'C':
            case 'V':
            case 'D':
            case 'Q':
                valid = true;
                break;
            default:
                valid = false;
                cerr << "\n\aInvalid choice\n"
                     << "Please try again: ";
                break;
        }
    } while (!valid);

    return choice;
}

//*****************************************************************************************************

void process(DLList<Student> &studentList) {
    char choice;

    do {
        choice = getChoice();

        switch (choice) {
            case 'A':
                addNewStudent(studentList);
                break;
            case 'F':
                findStudent(studentList);
                break;
            case 'R':
                removeStudent(studentList);
                break;
            case 'C':
                countStudents(studentList);
                break;
            case 'V':
                displayStudentRev(studentList);
                break;
            case 'D':
                displayStudent(studentList);
                break;
            case 'Q':
                break;
        }
    } while (choice != 'Q');
}

//*****************************************************************************************************

void buildList(DLList<Student> &studentList) {
    Student student;
    ifstream studentData;

    studentData.open("studentFile.txt");

    while (studentData >> student.id) {
        studentData.ignore();
        studentData.getline(student.name, 50);
        studentData.getline(student.cityState, 50);
        studentData >> student.phone >> student.gender >> 
        student.year >> student.credits >> student.gpa >> student.major;

        studentList.insert(student);
    }

    studentData.close();
}

//*****************************************************************************************************

void displayStudent(DLList<Student> &studentList) {
    cout << "\n\n"
         << setw(32) << right << "STUDENT LIST\n"
         << "==================================================\n"
         << setw(11) << left << "ID" << setw(25) << "NAME" << setw(10) << "MAJOR" << "GPA\n"
         << "==================================================" << endl;

    studentList.display();
}

//*****************************************************************************************************

void displayStudentRev(DLList<Student> &studentList) {
    cout << "\n\n"
         << setw(36) << right << "REVERSE STUDENT LIST\n"
         << "==================================================\n"
         << setw(11) << left << "ID" << setw(25) << "NAME" << setw(10) << "MAJOR" << "GPA\n"
         << "==================================================" << endl;

    studentList.displayReverse();
}

//*****************************************************************************************************

void countStudents(DLList<Student> &studentList) {
    cout << "\n\nNumber of students: " << studentList.getNumValues() << "\n"
         << endl;
}

//*****************************************************************************************************

void addNewStudent(DLList<Student> &studentList) {
    Student student;

    cout << "\n\nID: ";
    cin >> student.id;

    cout << "Name (e.g. Smith, John A): ";
    cin.ignore();
    cin.getline(student.name, 50);

    cout << "City, State (e.g. San Diego, California): ";
    cin.ignore();
    cin.getline(student.cityState, 50);

    cout << "Phone Number (e.g. 3145551212): ";
    cin >> student.phone;

    cout << "Gender (M/F): ";
    cin >> student.gender;

    cout << "Year (1-5): ";
    cin >> student.year;

    cout << "Credits (0-200): ";
    cin >> student.credits;

    cout << "Gpa (0.00-4.00): ";
    cin >> student.gpa;

    cout << "Major (e.g. MATH): ";
    cin >> student.major;

    studentList.insert(student);

    cout << "\n\n"
         << setw(31) << right << "STUDENT ADDED\n"
         << "==================================================\n"
         << setw(11) << left << "ID" << setw(25) << "NAME" << setw(10) << "MAJOR" << "GPA\n"
         << "==================================================\n"
         << student << endl;
}

//*****************************************************************************************************

void removeStudent(DLList<Student> &studentList) {
    Student student;

    cout << "\n\nEnter the student's ID to remove: ";
    cin >> student.id;

    if (studentList.remove(student))
        cout << "\n\n"
             << setw(32) << right << "STUDENT REMOVED\n"
             << "==================================================\n"
             << setw(11) << left << "ID" << setw(25) << "NAME" << setw(10) << "MAJOR" << "GPA\n"
             << "==================================================\n"
             << student << endl;
    else
        cerr << "\n\nStudent not found\n\n";
}

//*****************************************************************************************************

void findStudent(DLList<Student> &studentList) {
    Student student;

    cout << "\n\nEnter the student's ID to find: ";
    cin >> student.id;

    if (studentList.retrieve(student))
        cout << "\n\n"
             << setw(33) << right << "STUDENT FOUND\n"
             << "==================================================\n"
             << setw(11) << left << "ID" << setw(25) << "NAME" << setw(10) << "MAJOR" << "GPA\n"
             << "==================================================\n"
             << student << endl;
    else
        cerr << "\n\nStudent not found\n\n";
}

//*****************************************************************************************************
/*

============= MENU =============
A: Add a new student
F: Find a student
R: Remove a student
C: Count the students
V: Reverse display the students
D: Display the students
Q: Quit
================================
Enter your choice: v


               REVERSE STUDENT LIST
==================================================
ID         NAME                     MAJOR     GPA
==================================================
32631      Freud, JR, Fred E        PSYC      1.85
32598      Xerxes, Art I            GREE      3.25
31631      Aristotle, Alice A       PHIL      3.1
30878      Lewis, Clark N           GEOG      3.37
30749      Mendelssohn, Mozart W    MUSC      2.87
30655      Angelo, Mike L           ART       3.74
30381      Elba, Able M             SPEE      3.4
30280      Dewey, Johanna A         EDUC      3.83
30268      Newmann, Alfred E        EDUC      0.99
29583      Yewliss, Cal C           MATH      2.99
28658      Cicero, Marsha           LATI      2.87
27503      Fahrenheit, Felicia O    CHEM      3.85
26316      Custer, General G        HIST      1.95
25831      Santamaria, Nina P       HIST      1.77
25377      Porgy, Bess N            MUSI      2.78
24237      Euler, Lennie L          MATH      3.83
23750      Vespucci, Vera D         GEOG      2.29
23544      Gestalt, Gloria G        PSYC      2.48
23497      Fault, Paige D           CPSC      2.95
23314      Macdonald, Ronald B      CPSC      2.99
22447      Zylstra, Zelda A         ENGL      1.95
22277      Principal, Pamela P      EDUC      1.75
21144      Pasteur, Louise A        BIOL      3.1
20991      Augusta, Ada B           CPSC      3.83
20454      Chicita, Juanita A       BIOL      2.66
19918      Virus, Vera W            CPSC      3.25
19077      Medes, Archie L          ENGR      3.1
18264      Lucky, Lucy L            HIST      2.29
18213      Marx, Karl Z             ECON      2.75
17424      Nakamura, Toky O         SOCI      1.95
17376      Scrooge, Ebenezer T      SOCI      3.25
16622      Issacson, Esau B         RELI      2.98
16540      Weerd, Dewey L           PHIL      2.99
16183      Kuts, Cole               FOOD      3.98
15889      Gazelle, Gwendolyn D     PE        2.78
15802      Pascal, Blaze R          CPSC      1.98
15755      VandenVander, Vanessa V  HIST      3.74
15671      Rembrandt, Roberta E     ART       2.2
15052      Einstein, Alfred M       ENGR      2.78
14815      Tchaikovsky, Wolfgang A  MUSC      2.75
14674      Rockne, Newton K         PE        1.98
13511      Pitt, Stew               GNED      0.21
11951      Mouse, Michael E         EDUC      1.99
11749      Issacson, Jacob A        RELI      2.99
11688      Kronecker, Leo P         MATH      2.75
10304      Deutsch, Sprechen Z      GERM      3.05
10236      Andrews, Peter J         CPSC      2.78
9743       Johnson, James L         ENGR      3.15
9463       Hochschule, Hortense C   EDUC      2.7
7885       Fibonacci, Leonard O     MATH      3.25
7844       Aardvark, Anthony A      ENGR      2.79
7448       Roosevelt, Rose Y        POLS      2.95
7107       Shoemaker, Imelda M      POLS      3.15
5873       Psycho, II,  Prunella E  PSYC      2.99
5710       Busch, Arch E            ENGR      2.75
5430       Nightingale, Florence K  NURS      3.15
5316       GotoDijkstra, Edgar G    CPSC      4
4777       Gauss, Carl F            MATH      4
4559       Shyster, Samuel D        SOCI      1.95
4454       Atanasoff, Eniac C       CPSC      1.88
3930       Leibniz, Gottfried W     MATH      1.95

*/