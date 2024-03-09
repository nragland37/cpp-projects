//*****************************************************************************************************
//      Speaker Management System
//
//      This program is a speaker bureau system that allows users to dynamically allocate memory for a
//      specified number of speakers, up to a limit of 5000, and allows users to input, update, and
//      display information on speakers, as well as search for speakers by topic.
//
//*****************************************************************************************************

#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

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
    int size;
    int numSpeakers = 0;
    string speakerName,
        topic;
    bool nameTest,
        topicTest;
    char topicEntry;

    cout << "\n---------------------------------------------------------------\n"
         << "     Enter the number of speakers at the Speakers' Bureau\n"
         << "---------------------------------------------------------------" << endl;

    do {
        cout << "Number: ";
        cin >> size;

        cin.ignore();

        if (size <= 0 || size >= 5000)
            cerr << "\nNumber must be greater than 0 and smaller than 5000\n";

    } while (size <= 0 || size >= 5000);

    Speaker *members = new Speaker[size];
    inputSpeakers(members, size, numSpeakers);

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

            cin.ignore();
        }
    } while (topicTest == false);

    displayTopicSpeakers(members, numSpeakers, topic);

    cout << "\n\n-------------------------------------------------------------\n"
         << "\t\tSpeakers' Bureau Information\n"
         << "-------------------------------------------------------------" << endl;

    displayAllSpeakerInfo(members, numSpeakers);

    delete[] members;
    members = nullptr;

    return 0;
}

//*****************************************************************************************************

void inputSpeakers(Speaker members[], int size, int &numSpeakers) {
    char entry;

    for (int i = 0; i < size; ++i) {
        numSpeakers++;

        cout << "\n---------------------------------------------------------------\n"
             << "\tEnter the following information of speaker " << i + 1 << ".\n"
             << "---------------------------------------------------------------" << endl;

        cout << "Name: ";
        getline(cin, members[i].name);

        while (isEmpty(members[i].name)) {
            cerr << "\nSorry but the name could not be empty\n";
            cout << "\nName: ";
            getline(cin, members[i].name);
        }

        cout << "Telephone Number: ";
        getline(cin, members[i].phoneNum);

        while (isEmpty(members[i].phoneNum)) {
            cerr << "\nSorry but the telephone number could not be empty\n";
            cout << "\nTelephone Number: ";
            getline(cin, members[i].phoneNum);
        }

        cout << "Topic: ";
        getline(cin, members[i].topic);

        while (isEmpty(members[i].topic)) {
            cerr << "\nSorry but the topic could not be empty\n";
            cout << "\nTopic: ";
            getline(cin, members[i].topic);
        }

        cout << "Fee: ";
        cin >> members[i].fee;

        while (members[i].fee < 0) {
            cerr << "\nSorry but the fees could not be negative\n";
            cout << "\nFee: ";
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

//*****************************************************************************************************

void updateSpeaker(Speaker members[], int numSpeakers, const string &speakerName) {
    cout << "\n---------------------------------------------------------------\n"
         << "\tPlease enter the speaker's updated information\n"
         << "---------------------------------------------------------------" << endl;

    for (int i = 0; i < numSpeakers; ++i) {
        if (speakerName == members[i].name) {
            cout << "Name: ";
            getline(cin, members[i].name);

            while (isEmpty(members[i].name)) {
                cerr << "\nSorry but the name could not be empty\n";
                cout << "\nName: ";
                getline(cin, members[i].name);
            }

            cout << "Telephone Number: ";
            getline(cin, members[i].phoneNum);

            while (isEmpty(members[i].phoneNum)) {
                cerr << "\nSorry but the telephone number could not be empty\n";
                cout << "\nTelephone Number: ";
                getline(cin, members[i].phoneNum);
            }

            cout << "Topic: ";
            getline(cin, members[i].topic);

            while (isEmpty(members[i].topic)) {
                cerr << "\nSorry but the topic could not be empty\n";
                cout << "\nTopic: ";
                getline(cin, members[i].topic);
            }

            cout << "Fee: ";
            cin >> members[i].fee;

            while (members[i].fee < 0) {
                cerr << "\nSorry but the fees could not be negative\n";
                cout << "\nFee: ";
                cin >> members[i].fee;
            }

            cin.ignore();
        }
    }
}

//*****************************************************************************************************

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

//*****************************************************************************************************

void displayTopicSpeakers(Speaker members[], int numSpeakers, const string &topic) {
    for (int i = 0; i < numSpeakers; ++i)
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

//*****************************************************************************************************

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

//*****************************************************************************************************

bool isEmpty(const string &str) {
    bool success = false;

    if (str.empty())
        success = true;

    return success;
}

//*****************************************************************************************************

bool testName(Speaker members[], int numSpeakers, const string &speakerName) {
    bool nameFound = false;

    for (int i = 0; i < numSpeakers; ++i) {
        if (speakerName == members[i].name) {
            nameFound = true;
            break;
        }
    }

    return nameFound;
}

//*****************************************************************************************************

bool testTopic(Speaker members[], int numSpeakers, const string &topic) {
    bool topicFound = false;

    for (int i = 0; i < numSpeakers; ++i) {
        if (topic == members[i].topic) {
            topicFound = true;
            break;
        }
    }

    return topicFound;
}

//*****************************************************************************************************
/*

---------------------------------------------------------------
     Enter the number of speakers at the Speakers' Bureau
---------------------------------------------------------------
Number: -10

Number must be greater than 0 and smaller than 5000
Number: 0

Number must be greater than 0 and smaller than 5000
Number: 5000

Number must be greater than 0 and smaller than 5000
Number: 4

---------------------------------------------------------------
        Enter the following information of speaker 1.
---------------------------------------------------------------
Name: Nicholas Ragland
Telephone Number: 314-219-9992
Topic: Art
Fee: 30.45
Do you have another entry? (Y/N):
Y

---------------------------------------------------------------
        Enter the following information of speaker 2.
---------------------------------------------------------------
Name: Olivia Davisson
Telephone Number: 314-299-9999
Topic: Computer Science
Fee: 25.50
Do you have another entry? (Y/N):
Y

---------------------------------------------------------------
        Enter the following information of speaker 3.
---------------------------------------------------------------
Name: John Smith
Telephone Number: 314-238-8455
Topic: History
Fee: 32
Do you have another entry? (Y/N):
Y

---------------------------------------------------------------
        Enter the following information of speaker 4.
---------------------------------------------------------------
Name: Sam Smith
Telephone Number: 314-883-5462
Topic: Poetry
Fee: 10
Do you have another entry? (Y/N):
N

---------------------------------------------------------------
    Enter the name of the speaker you would like to update
---------------------------------------------------------------
Name: Nicholas Ragland

---------------------------------------------------------------
        Please enter the speaker's updated information
---------------------------------------------------------------
Name: Nicholas Smith
Telephone Number: 314-219-9993
Topic: Computer Science
Fee: 12.75

---------------------------------------------------------------
   Enter the name of the speaker you would like to display
---------------------------------------------------------------
Name: Nicholas Smith

Speaker 1
        Name ......................... Nicholas Smith
        Telephone Number ............. 314-219-9993
        Topic ........................ Computer Science
        Fee .......................... 12.75

---------------------------------------------------------------
     Enter the topic you would like to display names for
---------------------------------------------------------------
Topic: Computer Science

Speaker 1
        Name ......................... Nicholas Smith
        Telephone Number ............. 314-219-9993
        Topic ........................ Computer Science
        Fee .......................... 12.75

Speaker 2
        Name ......................... Olivia Davisson
        Telephone Number ............. 314-299-9999
        Topic ........................ Computer Science
        Fee .......................... 25.5



-------------------------------------------------------------
                Speakers' Bureau Information
-------------------------------------------------------------

Speaker 1
        Name ......................... Nicholas Smith
        Telephone Number ............. 314-219-9993
        Topic ........................ Computer Science
        Fee .......................... 12.75

Speaker 2
        Name ......................... Olivia Davisson
        Telephone Number ............. 314-299-9999
        Topic ........................ Computer Science
        Fee .......................... 25.5

Speaker 3
        Name ......................... John Smith
        Telephone Number ............. 314-238-8455
        Topic ........................ History
        Fee .......................... 32

Speaker 4
        Name ......................... Sam Smith
        Telephone Number ............. 314-883-5462
        Topic ........................ Poetry
        Fee .......................... 10

*/