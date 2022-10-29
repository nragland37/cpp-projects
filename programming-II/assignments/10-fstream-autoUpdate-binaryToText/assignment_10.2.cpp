#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//****************************************************************************************************

const int NAME_SIZE = 20; 
struct Translation {
    string american;
    string english;
};
struct Date {
    int month;
    int day;
    int year;
};
struct Person {
    char name[NAME_SIZE];
    double score;
    Date testTaken;
};

Translation* readTranslation(const string& fileName, int& num);
void testersUpdates(const Translation translate[], int numT, const string& fileName);
void takeTest(const Translation translate[], int numT, Person& p);
void displayTesters(const string& fileName);
void displayTranslateAnswers(const Translation translate[], int numT);

//****************************************************************************************************

int main() {
    int numT = 0;
    string fileName;
    char studyEntry;
    Translation* translate = nullptr;

    cout << fixed << setprecision(1);

    translate = readTranslation("Translation.txt", numT);
    displayTesters("Testers.dat");
    cout << "\n---------------------------------------------------" << endl;
    cout << "\tAmerican to English Translation Test" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "   Three people from this list will be randomly" << endl;
    cout << "            selected to take the test." << endl;
    cout << "\nWould you like to study before the test? (Y/N)" << endl;  // prompts user to study before test
    cin >> studyEntry;
    if (studyEntry == 'y' || studyEntry == 'Y') {
        displayTranslateAnswers(translate, numT);
        cout << "\nPress enter to continue..." << endl;
        cin.ignore();
        cin.get();
        cout << "Good Luck!" << endl;
    } else {
        cout << "\nGood Luck!" << endl;
    }
    testersUpdates(translate, numT, "Testers.dat");
    cout << "===================================================" << endl;
    cout << "\t\tUpdated Information" << endl;
    cout << "===================================================";
    displayTesters("Testers.dat");

    delete[] translate;
    translate = nullptr;

    return 0;
}

//****************************************************************************************************

Translation* readTranslation(const string& fileName, int& num) {
    Translation* t = nullptr;
    ifstream f(fileName);
    if (f.is_open()) {
        f >> num;
        f.ignore();
        t = new Translation[num];
        for (int i = 0; i < num; ++i) {
            getline(f, t[i].american, ',');
            getline(f, t[i].english);
        }
        f.close();
    } else {
        cout << "FILE DOES NOT EXIST" << endl;
    }
    return t;
}

//****************************************************************************************************

void testersUpdates(const Translation translate[], int numT, const string& fileName) {
    const int numTests = 3;  // # of random tests ~ same people can be tested more than once
    int randomPerson = 0,
        numP,
        month,
        day,
        year;
    Person people;
    short seed;
    seed = time(0);
    srand(seed);

    cout << "\n---------------------------------" << endl;
    cout << "        Enter Today's Date" << endl;
    cout << "---------------------------------" << endl;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter year: ";
    cin >> year;
    cout << "\n\n---------------------------------" << endl;
    cout << "            Questions" << endl;
    cout << "---------------------------------" << endl;
    cout << "    Ten American words will be" << endl;
    cout << " randomly selected from the list." << endl;
    cout << "  Enter the English translation." << endl;

    fstream f(fileName, ios::in | ios::out | ios::binary);
    f.read(reinterpret_cast<char*>(&numP), sizeof(int));
    for (int i = 0; i < numTests; ++i) {
        randomPerson = (rand() % numP) + 1;  // (numP: 10) range: (0 - 9) + 1 (adds to range)  // range: 1 - 10
        f.seekg((sizeof(int) + (randomPerson - 1) * sizeof(Person)), ios::beg);
        f.read(reinterpret_cast<char*>(&people), sizeof(Person));
        people.testTaken.month = month;
        people.testTaken.day = day;
        people.testTaken.year = year;
        cout << "\n=================================" << endl;
        cout << setfill(' ') << setw(3) << left << "#"
             << setw(20) << left << "NAME"
             << "TEST TAKEN" << endl;
        cout << "---------------------------------" << endl;
        cout << setw(3) << left << randomPerson
             << setw(20) << left << people.name
             << people.testTaken.month << "/"
             << people.testTaken.day << "/"
             << people.testTaken.year << endl;
        takeTest(translate, numT, people);
        f.seekp((sizeof(int) + (randomPerson - 1) * sizeof(Person)), ios::beg);
        f.write(reinterpret_cast<char*>(&people), sizeof(Person));
    }
    f.close();
}

//****************************************************************************************************
/* randomPerson range: (0 - 9) ~

    fstream f(fileName, ios::in | ios::out | ios::binary);
    f.read(reinterpret_cast<char*>(&numP), sizeof(int));
    for (int i = 0; i < numTests; ++i) {
        randomPerson = rand() % numP;                                        <<<<<<<<<<
        f.seekg((sizeof(int) + (randomPerson) * sizeof(Person)), ios::beg);  <<<<<<<<<<
        f.read(reinterpret_cast<char*>(&people), sizeof(Person));
        people.testTaken.month = month;
        people.testTaken.day = day;
        people.testTaken.year = year;
        cout << "\n=================================" << endl;
        cout << setfill(' ') << setw(3) << left << "#"
             << setw(20) << left << "NAME"
             << "TEST TAKEN" << endl;
        cout << "---------------------------------" << endl;
        cout << setw(3) << left << randomPerson + 1
             << setw(20) << left << people.name
             << people.testTaken.month << "/"
             << people.testTaken.day << "/"
             << people.testTaken.year << endl;
        takeTest(translate, numT, people);
        f.seekp((sizeof(int) + (randomPerson) * sizeof(Person)), ios::beg); <<<<<<<<<<
        f.write(reinterpret_cast<char*>(&people), sizeof(Person));
    }

//****************************************************************************************************
// seekp begins at current location ~

        for (int i = 0; i < numTests; ++i) {
        randomPerson = (rand() % numP) + 1;
        f.seekg((sizeof(int) + (randomPerson - 1) * sizeof(Person)), ios::beg);
        f.read(reinterpret_cast<char*>(&people), sizeof(Person));
        people.testTaken.month = month;
        people.testTaken.day = day;
        people.testTaken.year = year;
        cout << "\n=================================" << endl;
        cout << setfill(' ') << setw(3) << left << "#"
             << setw(20) << left << "NAME"
             << "TEST TAKEN" << endl;
        cout << "---------------------------------" << endl;
        cout << setw(3) << left << randomPerson
             << setw(20) << left << people.name
             << people.testTaken.month << "/"
             << people.testTaken.day << "/"
             << people.testTaken.year << endl;
        takeTest(translate, numT, people);
        f.seekp(((-1) * sizeof(Person)), ios::cur);                    <<<<<<<<<<
        f.write(reinterpret_cast<char*>(&people), sizeof(Person));
    }

*/
//****************************************************************************************************

void takeTest(const Translation translate[], int numT, Person& p) {
    const int numQuestions = 10;  // # of questions ~ changing number of questions may result in 'double' avg
    int randomQuestion = 0;
    double correct = 0,
           avg = 0;
    string answer,
        guess;
    short seed;
    seed = time(0);
    srand(seed);

    cout << "\n---------------------------------" << endl;
    cout << setfill(' ') << setw(3) << left << "#"
         << setw(18) << left << "American"
         << "English" << endl;
    cout << "---------------------------------" << endl;
    for (int i = 0; i < numQuestions; ++i) {
        randomQuestion = rand() % numT;  // (numT: 20) range: 0 - 19
        cout << setfill(' ') << setw(3) << left << randomQuestion + 1
             << setfill('.') << setw(18) << left << translate[randomQuestion].american;
        cin >> guess;
        answer = translate[randomQuestion].english;
        if (guess == answer) {
            cout << "\n\t    Correct!" << endl
                 << endl;
            correct++;
        } else {
            cout << "\n\t   Incorrect!" << endl;
            cout << "\nAnswer: " << translate[randomQuestion].english << endl
                 << endl;
        }
    }
    avg = (static_cast<double>(correct) / numQuestions) * 100;
    p.score = avg;
}

//****************************************************************************************************

void displayTesters(const string& fileName) {
    int numP = 0;
    Person people;

    fstream f(fileName, ios::in | ios::binary);

    if (f.is_open()) {
        f.read(reinterpret_cast<char*>(&numP), sizeof(numP));
        cout << "\n---------------------------------------------------" << endl;
        cout << setfill(' ') << setw(3) << left << "#"
             << setw(20) << left << "NAME"
             << setw(15) << left << "SCORE %"
             << "TEST TAKEN" << endl;
        cout << "---------------------------------------------------" << endl;
        for (int i = 0; i < numP; ++i) {
            f.read(reinterpret_cast<char*>(&people), sizeof(Person));
            cout << setw(3) << left << i + 1
                 << setw(20) << left << people.name
                 << setw(15) << left << people.score
                 << people.testTaken.month << "/"
                 << people.testTaken.day << "/"
                 << people.testTaken.year << endl;
        }
        f.close();
    } else {
        cout << "FILE DOES NOT EXIST" << endl;
    }
}

//****************************************************************************************************

void displayTranslateAnswers(const Translation translate[], int numT) {
    cout << "\n---------------------------------" << endl;
    cout << setw(3) << left << "#"
         << setw(18) << left << "American"
         << "English" << endl;
    cout << "---------------------------------" << endl;
    for (int i = 0; i < numT; ++i) {
        cout << setfill(' ') << setw(3) << left << i + 1
             << setfill('.') << setw(18) << left << translate[i].american
             << translate[i].english << endl;
    }
}

/*

---------------------------------------------------
#  NAME                SCORE %        TEST TAKEN
---------------------------------------------------
1  Steve Smith         56.6           11/11/2019
2  Sue Jones           10.0           11/11/2011
3  Li Ying             0.0            11/11/2011
4  Kun Joom            20.0           11/11/2021
5  Joe Bush            10.0           11/11/2021
6  Kim Long            0.0            11/11/2011
7  Fred Ring           33.3           5/5/2019
8  Frank Pearse        20.0           11/11/2011
9  Helen Hu            0.1            11/11/2011
10 Mark James          0.0            11/11/2021

---------------------------------------------------
        American to English Translation Test
---------------------------------------------------
   Three people from this list will be randomly
            selected to take the test.

Would you like to study before the test? (Y/N)
Y

---------------------------------
#  American          English
---------------------------------
1  chips.............crisps
2  french fries......chips
3  sidewalk..........pavement
4  cookie............biscuit
5  apartment.........flat
6  elevator..........lift
7  gas...............petrol
8  soccer............football
9  movie.............film
10 sweater...........jumper
11 trunk.............boot
12 hood..............bonnet
13 last name.........surname
14 restroom..........toilet
15 cart..............trolley
16 candy.............sweet
17 vacation..........holiday
18 subway............underground
19 pants.............trousers
20 mailbox...........postbox

Press enter to continue...

Good Luck!

---------------------------------
        Enter Today's Date
---------------------------------
Enter month: 4
Enter day: 22
Enter year: 2022


---------------------------------
            Questions
---------------------------------
   Five American words will be
 randomly selected from the list.
  Enter the English translation.

=================================
#  NAME                TEST TAKEN
---------------------------------
3  Li Ying             4/22/2022

---------------------------------
#  American          English
---------------------------------
12 hood..............bonnet

            Correct!

8  soccer............football

            Correct!

6  elevator..........lift

            Correct!

8  soccer............football

            Correct!

2  french fries......chips

            Correct!

4  cookie............biscuit

            Correct!

6  elevator..........lift

            Correct!

9  movie.............film

            Correct!

4  cookie............biscuit

            Correct!

2  french fries......chips

            Correct!


=================================
#  NAME                TEST TAKEN
---------------------------------
2  Sue Jones           4/22/2022

---------------------------------
#  American          English
---------------------------------
3  sidewalk..........pavement

            Correct!

12 hood..............bonnet

            Correct!

5  apartment.........flat

            Correct!

9  movie.............film

            Correct!

1  chips.............crisps

            Correct!

14 restroom..........bathroom

           Incorrect!

Answer: toilet

12 hood..............hoodie

           Incorrect!

Answer: bonnet

10 sweater...........jumper

            Correct!

8  soccer............football

            Correct!

4  cookie............biscuit

            Correct!


=================================
#  NAME                TEST TAKEN
---------------------------------
6  Kim Long            4/22/2022

---------------------------------
#  American          English
---------------------------------
12 hood..............bonnet

            Correct!

6  elevator..........lift

            Correct!

20 mailbox...........postbox

            Correct!

19 pants.............trousers

            Correct!

8  soccer............football

            Correct!

10 sweater...........jumper

            Correct!

11 trunk.............boot

            Correct!

8  soccer............football

            Correct!

1  chips.............fries

           Incorrect!

Answer: crisps

20 mailbox...........postbox

            Correct!
                                                             // checks updated binary file
===================================================          // read from 'Testers.dat' file after 'testersUpdates' function
                Updated Information
===================================================
---------------------------------------------------
#  NAME                SCORE %        TEST TAKEN
---------------------------------------------------
1  Steve Smith         56.6           11/11/2019
2  Sue Jones           80.0           4/22/2022
3  Li Ying             100.0          4/22/2022
4  Kun Joom            20.0           11/11/2021
5  Joe Bush            10.0           11/11/2021
6  Kim Long            90.0           4/22/2022
7  Fred Ring           33.3           5/5/2019
8  Frank Pearse        20.0           11/11/2011
9  Helen Hu            0.1            11/11/2011
10 Mark James          0.0            11/11/2021

*/