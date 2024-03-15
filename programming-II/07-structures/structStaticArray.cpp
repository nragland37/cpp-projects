//*****************************************************************************************************
//      Speaker Management System
//
//      This program is a speaker bureau system with a limit of 10 speakers that allows users to input,
//      update, and display information on speakers, as well as search for speakers by topic.
//
//*****************************************************************************************************

#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************
// struct: user-defined data type

struct Speaker {     
    string name;
    string phoneNum;
    string topic;
    double fee;
};

void inputSpeakers(Speaker members[], int size, int &numSpeakers);
void updateSpeaker(Speaker members[], int numSpeakers, const string &speakerName);
void displayOneSpeakerInfo(Speaker members[], int numSpeakers, const string &speakerName);
void displayTopicSpeakers(Speaker members[], int numSpeakers, const string &topic);
void displayAllSpeakerInfo(Speaker members[], int numSpeakers);
bool isEmpty(const string &str);
bool testName(Speaker members[], int numSpeakers, const string &speakerName);
bool testTopic(Speaker members[], int numSpeakers, const string &topic);

//*****************************************************************************************************

int main() {
    const int SIZE = 10;
    Speaker members[SIZE];
    int numSpeakers = 0;
    string speakerName,
        topic;
    bool nameTest,
        topicTest;
    char topicEntry;

    inputSpeakers(members, SIZE, numSpeakers);

    do {
        cout << "\n---------------------------------------------------------------\n"
             << "    Enter the name of the speaker you would like to update\n"
             << "---------------------------------------------------------------\n"
             << "Name: ";
        getline(cin, speakerName);

        nameTest = testName(members, numSpeakers, speakerName);

        if (nameTest == false)
            cerr << "\nSorry but the name does not exist\n";

    } while (nameTest == false);

    updateSpeaker(members, numSpeakers, speakerName);

    do {
        cout << "\n---------------------------------------------------------------\n"
             << "   Enter the name of the speaker you would like to display\n"
             << "---------------------------------------------------------------\n"
             << "Name: ";
        getline(cin, speakerName);

        nameTest = testName(members, numSpeakers, speakerName);

        if (nameTest == false)
            cerr << "\nSorry but the name does not exist\n";

    } while (nameTest == false);

    displayOneSpeakerInfo(members, numSpeakers, speakerName);

    do {
        cout << "\n---------------------------------------------------------------\n"
             << "     Enter the topic you would like to display names for\n"
             << "---------------------------------------------------------------\n"
             << "Topic: ";
        getline(cin, topic);

        topicTest = testTopic(members, numSpeakers, topic);

        if (topicTest == false) {
            cerr << "\nSorry but nobody is speaking about this topic\n\n";
            cout << "Do you have another topic? (Y/N)" << endl;
            cin >> topicEntry;
            topicEntry = toupper(topicEntry);

            if (topicEntry == 'N')
                break;

            cin.ignore();     // ignore the '\n' character
        }
    } while (topicTest == false);

    displayTopicSpeakers(members, numSpeakers, topic);

    cout << "\n\n-------------------------------------------------------------\n"
         << "\t\tSpeakers' Bureau Information\n"
         << "-------------------------------------------------------------" << endl;

    displayAllSpeakerInfo(members, numSpeakers);

    return 0;
}

//****************************************************************************************************

void inputSpeakers(Speaker members[], int size, int &numSpeakers) {
    char entry;

    for (int i = 0; i < size; ++i) {
        numSpeakers++;

        cout << "\n---------------------------------------------------------------\n"
             << "\tEnter the following information of speaker " << i + 1 << ".\n"
             << "---------------------------------------------------------------\n"
             << "Name: ";
        getline(cin, members[i].name);

        while (isEmpty(members[i].name)) {
            cerr << "\nSorry but the name could not be empty\n\n";
            cout << "Name: ";
            getline(cin, members[i].name);
        }

        cout << "Telephone Number: ";
        getline(cin, members[i].phoneNum);

        while (isEmpty(members[i].phoneNum)) {
            cerr << "\nSorry but the telephone number could not be empty\n\n";
            cout << "Telephone Number: ";
            getline(cin, members[i].phoneNum);
        }

        cout << "Topic: ";
        getline(cin, members[i].topic);

        while (isEmpty(members[i].topic)) {
            cerr << "\nSorry but the topic could not be empty\n\n";
            cout << "Topic: ";
            getline(cin, members[i].topic);
        }

        cout << "Fee: ";
        cin >> members[i].fee;

        while (members[i].fee < 0) {
            cerr << "\nSorry but the fees could not be negative\n\n";
            cout << "Fee: ";
            cin >> members[i].fee;
        }

        cout << "Do you have another entry? (Y/N): " << endl;
        cin >> entry;

        entry = toupper(entry);

        if (entry == 'N') {
            cin.ignore();
            break;
        }

        cin.ignore();
    }
}

//****************************************************************************************************

void updateSpeaker(Speaker members[], int numSpeakers, const string &speakerName) {
    cout << "\n---------------------------------------------------------------\n"
         << "\tPlease enter the speaker's updated information\n"
         << "---------------------------------------------------------------" << endl;

    for (int i = 0; i < numSpeakers; ++i) {
        if (speakerName == members[i].name) {
            cout << "Name: ";
            getline(cin, members[i].name);

            while (isEmpty(members[i].name)) {
                cerr << "\nSorry but the name could not be empty\n\n";
                cout << "Name: ";
                getline(cin, members[i].name);
            }

            cout << "Telephone Number: ";
            getline(cin, members[i].phoneNum);

            while (isEmpty(members[i].phoneNum)) {
                cerr << "\nSorry but the telephone number could not be empty\n\n";
                cout << "Telephone Number: ";
                getline(cin, members[i].phoneNum);
            }

            cout << "Topic: ";
            getline(cin, members[i].topic);

            while (isEmpty(members[i].topic)) {
                cerr << "\nSorry but the topic could not be empty\n\n";
                cout << "Topic: ";
                getline(cin, members[i].topic);
            }

            cout << "Fee: ";
            cin >> members[i].fee;

            while (members[i].fee < 0) {
                cerr << "\nSorry but the fees could not be negative\n\n";
                cout << "Fee: ";
                cin >> members[i].fee;
            }

            cin.ignore();
        }
    }
}

//****************************************************************************************************

void displayOneSpeakerInfo(Speaker members[], int numSpeakers, const string &speakerName) {
    for (int i = 0; i < numSpeakers; ++i)
        if (speakerName == members[i].name)
            cout << "\nSpeaker " << i + 1
                 << "\n\t" << setfill('.') << setw(30) << left << "Name "
                 << " " << members[i].name
                 << "\n\t" << setw(30) << "Telephone Number "
                 << " " << members[i].phoneNum
                 << "\n\t" << setw(30) << "Topic "
                 << " " << members[i].topic
                 << "\n\t" << setw(30) << "Fee "
                 << " " << members[i].fee << endl;
}

//****************************************************************************************************

void displayTopicSpeakers(Speaker members[], int numSpeakers, const string &topic) {
    for (int i = 0; i < numSpeakers; i++)
        if (topic == members[i].topic)
            cout << "\nSpeaker " << i + 1
                 << "\n\t" << setfill('.') << setw(30) << left << "Name "
                 << " " << members[i].name
                 << "\n\t" << setw(30) << "Telephone Number "
                 << " " << members[i].phoneNum
                 << "\n\t" << setw(30) << "Topic "
                 << " " << members[i].topic
                 << "\n\t" << setw(30) << "Fee "
                 << " " << members[i].fee << endl;
}

//****************************************************************************************************

void displayAllSpeakerInfo(Speaker members[], int numSpeakers) {
    for (int i = 0; i < numSpeakers; ++i)
        cout << "\nSpeaker " << i + 1
             << "\n\t" << setfill('.') << setw(30) << left << "Name "
             << " " << members[i].name
             << "\n\t" << setw(30) << "Telephone Number "
             << " " << members[i].phoneNum
             << "\n\t" << setw(30) << "Topic "
             << " " << members[i].topic
             << "\n\t" << setw(30) << "Fee "
             << " " << members[i].fee << endl;
}

//****************************************************************************************************

bool isEmpty(const string &str) {
    bool success = false;

    if (str.empty())
        success = true;

    return success;
}

//****************************************************************************************************

bool testName(Speaker members[], int numSpeakers, const string &speakerName) {
    bool success = false;

    for (int i = 0; i < numSpeakers; ++i) {
        if (speakerName == members[i].name) {
            success = true;
            break;
        }
    }

    return success;
}

//****************************************************************************************************

bool testTopic(Speaker members[], int numSpeakers, const string &topic) {
    bool success = false;

    for (int i = 0; i < numSpeakers; ++i) {
        if (topic == members[i].topic) {
            success = true;
            break;
        }
    }

    return success;
}

//*****************************************************************************************************
/*

---------------------------------------------------------------
        Enter the following information of speaker 1.
---------------------------------------------------------------
Name: John Smith
Telephone Number: 314-111-1111
Topic: Art
Fee: 30
Do you have another entry? (Y/N):
Y

---------------------------------------------------------------
        Enter the following information of speaker 2.
---------------------------------------------------------------
Name: Olivia Potters
Telephone Number: 314-222-2222
Topic: Computer Science
Fee: 40
Do you have another entry? (Y/N):
Y

---------------------------------------------------------------
        Enter the following information of speaker 3.
---------------------------------------------------------------
Name: Sam Smith
Telephone Number:

Sorry but the telephone number could not be empty

Telephone Number: 314-219-3333
Topic:

Sorry but the topic could not be empty

Topic: History
Fee: -12

Sorry but the fees could not be negative

Fee: 23
Do you have another entry? (Y/N):
N

---------------------------------------------------------------
    Enter the name of the speaker you would like to update
---------------------------------------------------------------
Name: Julia

Sorry but the name does not exist

---------------------------------------------------------------
    Enter the name of the speaker you would like to update
---------------------------------------------------------------
Name: Nick Plant

Sorry but the name does not exist

---------------------------------------------------------------
    Enter the name of the speaker you would like to update
---------------------------------------------------------------
Name: Joe Slow

Sorry but the name does not exist

---------------------------------------------------------------
    Enter the name of the speaker you would like to update
---------------------------------------------------------------
Name: John Smith

---------------------------------------------------------------
        Please enter the speaker's updated information
---------------------------------------------------------------
Name: Nick Plant
Telephone Number: 314-219-9392
Topic: Computer Science
Fee: 55

---------------------------------------------------------------
   Enter the name of the speaker you would like to display
---------------------------------------------------------------
Name: James

Sorry but the name does not exist

---------------------------------------------------------------
   Enter the name of the speaker you would like to display
---------------------------------------------------------------
Name: Nick Plant

Speaker 1
        Name ......................... Nick Plant
        Telephone Number ............. 314-219-9392
        Topic ........................ Computer Science
        Fee .......................... 55

---------------------------------------------------------------
     Enter the topic you would like to display names for
---------------------------------------------------------------
Topic: Baseball

Sorry but nobody is speaking about this topic

Do you have another topic? (Y/N)
Y

---------------------------------------------------------------
     Enter the topic you would like to display names for
---------------------------------------------------------------
Topic: Computer Science

Speaker 1
        Name ......................... Nick Plant
        Telephone Number ............. 314-219-9392
        Topic ........................ Computer Science
        Fee .......................... 55

Speaker 2
        Name ......................... Olivia Potters
        Telephone Number ............. 314-222-2222
        Topic ........................ Computer Science
        Fee .......................... 40


-------------------------------------------------------------
                Speakers' Bureau Information
-------------------------------------------------------------

Speaker 1
        Name ......................... Nick Plant
        Telephone Number ............. 314-219-9392
        Topic ........................ Computer Science
        Fee .......................... 55

Speaker 2
        Name ......................... Olivia Potters
        Telephone Number ............. 314-222-2222
        Topic ........................ Computer Science
        Fee .......................... 40

Speaker 3
        Name ......................... Sam Smith
        Telephone Number ............. 314-219-3333
        Topic ........................ History
        Fee .......................... 23

*/