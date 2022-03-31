//****************************************************************************************************
// 		    File:                 assignment_7.1.cpp
//
//		    Student:              Nicholas Ragland
//
//		    Assignment:           Program #7
//
//          Course Name:          Programming II
//
//          Course Number:        COSC-1560 - 02
//
//          Due:                  March 30, 2022
//
//****************************************************************************************************

#include <iostream>
#include <string>

using namespace std;

//****************************************************************************************************
const int SIZE = 10;

struct Speaker {
    string name;
    string phoneNum;
    string topic;
    double fee;
} members[SIZE];

void inputSpeakers(Speaker members[], int size, int& numSpeakers);
void updateSpeaker(Speaker members[], int numSpeakers, const string& speakerName);

//****************************************************************************************************

int main() {
    int numSpeakers = 0;
    string speakerName; 

    inputSpeakers(members, SIZE, numSpeakers);
    updateSpeaker(members, numSpeakers, speakerName);

    return 0;
}

//****************************************************************************************************

void inputSpeakers(Speaker members[], int size, int& numSpeakers) {
    char entry;
    for (int i = 0; i < size; ++i) {
        numSpeakers++;
        cout << "Please enter the following information of speaker " << i + 1 << ": " << endl;
        cout << "Speaker Name: ";
        cin.ignore();
        getline(cin, members[i].name);
        cout << "Speaker Telephone Number: ";
        cin.ignore();
        getline(cin, members[i].phoneNum);
        cout << "Speaker Topic: ";
        cin.ignore();
        getline(cin, members[i].topic);
        cout << "Fee Required: ";
        cin >> members[i].fee;
        while (members[i].fee < 0) {
            cout << "\nSorry but the fees could not be negative.\n"
                 << "\nFee Required: ";
            cin >> members[i].fee;
        }
        cout << "Do you have another entry? (Y/N): " << endl;
        cin >> entry;
        if (entry == 'n' || entry == 'N') {
            break;
        }
    }
}

//****************************************************************************************************

void updateSpeaker(Speaker members[], int numSpeakers, const string& speakerName) {

}

/*


*/