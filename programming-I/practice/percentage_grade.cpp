//****************************************************************************************************

#include <iostream>
using namespace std;

//****************************************************************************************************
int main() {
    int marks;

    cout << "Enter the percentage of your final grade: ";
    cin >> marks;

    cout << "\n\n";

    if (marks >= 100) {
        cout << " Your Grade is A+";
    }
    if (marks >= 96) {
        cout << " Your Grade is A+";
    } else if (marks >= 95) {
        cout << " Your Grade is A";
    } else if (marks >= 90) {
        cout << " Your Grade is A-";
    } else if (marks >= 86) {
        cout << " Your Grade is B+";
    } else if (marks >= 85) {
        cout << " Your Grade is B";
    } else if (marks >= 80) {
        cout << " Your Grade is B-";
    } else if (marks >= 76) {
        cout << " Your Grade is C+";
    } else if (marks >= 75) {
        cout << " Your Grade is C";
    } else if (marks >= 70) {
        cout << " Your Grade is C-";
    } else if (marks >= 60) {
        cout << " Your Grade is D";
    } else if (marks >= 50) {
        cout << " Your Grade is F";
    } else if (marks <= 50) {
        cout << " Your Grade is F";
    } else {
        cout << "Enter Valid Marks";
    }

    cout << "\n\n";
    cout << "\n\n";

    return 0;
}

//****************************************************************************************************