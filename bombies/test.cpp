#include <iostream>
#include <string>
using namespace std;

void input(string names[], int matches[], int size);
void display(const string names[], const int matches[], int size);
void displayMostMatches(const string names[], const int matches[], int size);
double mean(const int matches[], int num);
void swapValues(int& a, int& b);
void sortStudents(string names[], int matches[], int size);

int main() {
    int size;
    string* ptr1 = nullptr;
    int* ptr2 = nullptr;
    double meanMatches;

    cout << "How many students were surveyed?" << endl;
    cin >> size;
    cin.ignore();

    ptr1 = new string[size];
    ptr2 = new int[size];

    cout << endl
         << "Enter the name of each student and number of cricket matches played by that student."
         << endl;
    input(ptr1, ptr2, size);

    cout << endl
         << "Your completed survey: " << endl;
    display(ptr1, ptr2, size);

    cout << endl
         << "The student with the most matches is: " << endl;
    displayMostMatches(ptr1, ptr2, size);

    meanMatches = mean(ptr2, size);
    cout << endl
         << "The average number of matches played: " << meanMatches << endl;

    sortStudents(ptr1, ptr2, size);
    cout << endl
         << "Your survey in alphabetical order: " << endl;
    display(ptr1, ptr2, size);

    delete[] ptr1;
    delete[] ptr2;

    return 0;
}

//****************************************************************************************************

void input(string names[], int matches[], int size) {
    bool valid = true;

    for (int i = 0; i < size; i++) {
        getline(cin, names[i]);
        cin >> matches[i];
        cin.ignore();
        if (matches[i] < 0) {
            valid = false;
            cout << "Invalid number. Re-enter number of matches." << endl;
            cin >> matches[i];
            cin.ignore();
        }
    }
}

//****************************************************************************************************

void display(const string names[], const int matches[], int size) {
    for (int i = 0; i < size; i++) {
        cout << names[i] << " " << matches[i] << endl;
    }
}

//****************************************************************************************************

void displayMostMatches(const string names[], const int matches[], int size) {
    int most = 0;
    string mostStudent;

    for (int i = 0; i < size; i++) {
        if (matches[i] > most) {
            most = matches[i];
            mostStudent = names[i];
        }
    }
    cout << mostStudent << " " << most << endl;
}

//****************************************************************************************************

double mean(const int matches[], int num) {
    int sum = 0;
    double mean;

    for (int i = 0; i < num; i++) {
        sum += matches[i];
    }
    mean = static_cast<double>(sum) / num;

    return mean;
}

//****************************************************************************************************

void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//****************************************************************************************************

void sortStudents(string names[], int matches[], int size) {
    bool swap;
    string temp;

    do {
        swap = false;
        for (int i = 0; i < (size - 1); i++) {
            if (names[i] > names[i + 1]) {
                temp = names[i];
                names[i] = names[i + 1];
                names[i + 1] = temp;
                swapValues(matches[i], matches[i + 1]);
                swap = true;
            }
        }
    } while (swap);
}