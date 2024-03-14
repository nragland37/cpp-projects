//*****************************************************************************************************
//      American to English Translation Test with Binary File Updates
//
//      The program reads translation information from a text file, reads the tester information 
//      from the binary file created in the previous program, and updates the binary file with the
//      new test information.
//
//      Other files required:
//        1.  Testers.txt - number of testers and the tester information
//        2.  Translation.txt - number of translations and the translation information
//
//*****************************************************************************************************

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

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

Translation *readTranslation(const string &fileName, int &num);
void testersUpdates(const Translation translate[], int numT, const string &fileName);
void takeTest(const Translation translate[], int numT, Person &p);
void displayTesters(const string &fileName);
void displayTranslateAnswers(const Translation translate[], int numT);

//*****************************************************************************************************

int main() {
    int numT = 0;
    string fileName;
    char studyEntry;
    Translation *translate = nullptr;

    cout << fixed << setprecision(1);

    translate = readTranslation("Translation.txt", numT);
    displayTesters("Testers.dat");

    cout << "\n---------------------------------------------------\n"
         << "\tAmerican to English Translation Test\n"
         << "---------------------------------------------------\n"
         << "   Three people from this list will be randomly\n"
         << "            selected to take the test \n\n"
         << "Would you like to study before the test? (Y/N)" << endl;
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

    cout << "===================================================\n"
         << "\t\tUpdated Information\n"
         << "===================================================";

    displayTesters("Testers.dat");

    delete[] translate;
    translate = nullptr;

    return 0;
}

//*****************************************************************************************************

Translation *readTranslation(const string &fileName, int &num) {
    Translation *t = nullptr;
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
        cerr << "Error: Unable to open file\n";
    }

    return t;
}

//*****************************************************************************************************

void testersUpdates(const Translation translate[], int numT, const string &fileName) {
    const int NUM_TESTS = 3;
    int randomPerson = 0,
        numP,
        month,
        day,
        year;
    Person people;
    short seed;

    seed = time(0);
    srand(seed);

    cout << "\n---------------------------------\n"
         << "      Enter Today's Date\n"
         << "---------------------------------" << endl;

    cout << "Enter month: ";
    cin >> month;

    cout << "Enter day: ";
    cin >> day;

    cout << "Enter year: ";
    cin >> year;

    cout << "\n\n---------------------------------\n"
         << "            Questions\n"
         << "---------------------------------\n"
         << "    Ten American words will be\n"
         << " randomly selected from the list.\n"
         << "  Enter the English translation." << endl;

    fstream f(fileName, ios::in | ios::out | ios::binary);     // opens file for reading and writing in binary mode
    f.read(reinterpret_cast<char *>(&numP), sizeof(int));      // reads number of people from file

    for (int i = 0; i < NUM_TESTS; ++i) {
        randomPerson = (rand() % numP) + 1;

        f.seekg((sizeof(int) + (randomPerson - 1) * sizeof(Person)), ios::beg);     // seekg(): get pointer (reads)
        f.read(reinterpret_cast<char *>(&people), sizeof(Person));                  // reads person from file
        people.testTaken.month = month;
        people.testTaken.day = day;
        people.testTaken.year = year;

        cout << "\n=================================\n"
             << setfill(' ') << setw(3) << left << "#" << setw(20) << "NAME"
             << "TEST TAKEN\n"
             << "---------------------------------\n"
             << setw(3) << randomPerson
             << setw(20) << people.name
             << people.testTaken.month << "/"
             << people.testTaken.day << "/"
             << people.testTaken.year << endl;

        takeTest(translate, numT, people);

        f.seekp((sizeof(int) + (randomPerson - 1) * sizeof(Person)), ios::beg);     // seekp(): put pointer (writes)
        f.write(reinterpret_cast<char *>(&people), sizeof(Person));                 // writes person to file
    }
    f.close();
}

//*****************************************************************************************************
/*

randomPerson range: (0 - 9) ~

    fstream f(fileName, ios::in | ios::out | ios::binary);
    f.read(reinterpret_cast<char*>(&numP), sizeof(int));
    
    for (int i = 0; i < NUM_TESTS; ++i) {
        randomPerson = rand() % numP;                                                        <<<<<<<<<<

        f.seekg((sizeof(int) + (randomPerson) * sizeof(Person)), ios::beg);                  <<<<<<<<<<
        f.read(reinterpret_cast<char*>(&people), sizeof(Person));

        people.testTaken.month = month;
        people.testTaken.day = day;
        people.testTaken.year = year;

        cout << "\n=================================\n"
             << setfill(' ') << setw(3) << left << "#" << setw(20) << "NAME" << "TEST TAKEN\n"
             << "---------------------------------\n"
             << setw(3) << randomPerson + 1
             << setw(20) << people.name
             << people.testTaken.month << "/"
             << people.testTaken.day << "/"
             << people.testTaken.year << endl;

        takeTest(translate, numT, people);

        f.seekp((sizeof(int) + (randomPerson) * sizeof(Person)), ios::beg);                  <<<<<<<<<<
        f.write(reinterpret_cast<char*>(&people), sizeof(Person));
    }

*****************************************************************************************************

seekp begins at current location ~

        for (int i = 0; i < NUM_TESTS; ++i) {
        randomPerson = (rand() % numP) + 1;

        f.seekg((sizeof(int) + (randomPerson - 1) * sizeof(Person)), ios::beg);
        f.read(reinterpret_cast<char*>(&people), sizeof(Person));

        people.testTaken.month = month;
        people.testTaken.day = day;
        people.testTaken.year = year;

        cout << "\n=================================\n"
             << setfill(' ') << setw(3) << left << "#" << setw(20) << "NAME" << "TEST TAKEN\n"
             << "---------------------------------\n"
             << setw(3) << randomPerson
             << setw(20) << people.name
             << people.testTaken.month << "/"
             << people.testTaken.day << "/"
             << people.testTaken.year << endl;

        takeTest(translate, numT, people);

        f.seekp(((-1) * sizeof(Person)), ios::cur);                                          <<<<<<<<<<
        f.write(reinterpret_cast<char*>(&people), sizeof(Person));
    }

*/

//*****************************************************************************************************

void takeTest(const Translation translate[], int numT, Person &p) {
    const int NUM_QUESTIONS = 10;
    int randomQuestion = 0;
    double correct = 0,
           avg = 0;
    string answer,
        guess;
    short seed;

    seed = time(0);
    srand(seed);

    cout << "\n---------------------------------" << endl;
    cout << setfill(' ')
         << setw(3) << left << "#" << setw(18) << "American"
         << "English\n"
         << "---------------------------------" << endl;

    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        randomQuestion = rand() % numT;     // (numT: 20) range: 0 - 19
        cout << setfill(' ') << setw(3) << left << randomQuestion + 1
             << setfill('.') << setw(18) << translate[randomQuestion].american;
        cin >> guess;

        answer = translate[randomQuestion].english;

        if (guess == answer) {
            cout << "\n\t    Correct!" << endl;
            correct++;
        } else {
            cout << "\n\t   Incorrect! \n\n"
                 << "Answer: " << translate[randomQuestion].english << endl;
        }

        cout << endl;
    }

    avg = (static_cast<double>(correct) / NUM_QUESTIONS) * 100;
    p.score = avg;
}

//*****************************************************************************************************

void displayTesters(const string &fileName) {
    int numP = 0;
    Person people;

    fstream f(fileName, ios::in | ios::binary);     // open file for reading in binary mode

    if (f.is_open()) {
        f.read(reinterpret_cast<char *>(&numP), sizeof(numP));

        cout << "\n---------------------------------------------------" << endl;
        cout << setfill(' ')
             << setw(3) << left << "#" << setw(20) << "NAME" << setw(15) << "SCORE %"
             << "TEST TAKEN\n"
             << "---------------------------------------------------" << endl;

        for (int i = 0; i < numP; ++i) {
            f.read(reinterpret_cast<char *>(&people), sizeof(Person));
            cout << setw(3) << left << i + 1
                 << setw(20) << people.name
                 << setw(15) << people.score
                 << people.testTaken.month << "/"
                 << people.testTaken.day << "/"
                 << people.testTaken.year << endl;
        }

        f.close();
    } else {
        cerr << "Error: Unable to open file\n";
    }
}

//*****************************************************************************************************

void displayTranslateAnswers(const Translation translate[], int numT) {
    cout << "\n---------------------------------\n"
         << setw(3) << left << "#" << setw(18) << "American"
         << "English\n"
         << "---------------------------------" << endl;

    for (int i = 0; i < numT; ++i)
        cout << setfill(' ') << setw(3) << left << i + 1
             << setfill('.') << setw(18) << translate[i].american
             << translate[i].english << endl;
}

//*****************************************************************************************************

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
N

Good Luck!

*****************************************************************************************************

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
            selected to take the test

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
    Ten American words will be
 randomly selected from the list.
  Enter the English translation.

=================================
#  NAME                TEST TAKEN
---------------------------------
10 Mark James          4/22/2022

---------------------------------
#  American          English
---------------------------------
13 last name.........surname

            Correct!

1  chips.............crisps

            Correct!

8  soccer............football

            Correct!

4  cookie............biscuit

            Correct!

1  chips.............crisps

            Correct!

9  movie.............film

            Correct!

13 last name.........surname

            Correct!

4  cookie............biscuit

            Correct!

12 hood..............bonnet

            Correct!

10 sweater...........jumper

            Correct!


=================================
#  NAME                TEST TAKEN
---------------------------------
3  Li Ying             4/22/2022

---------------------------------
#  American          English
---------------------------------
4  cookie............biscuit

            Correct!

7  gas...............gasoline

           Incorrect!

Answer: petrol

2  french fries......chips

            Correct!

5  apartment.........flat

            Correct!

9  movie.............film

            Correct!

9  movie.............film

            Correct!

12 hood..............hoodie

           Incorrect!

Answer: bonnet

20 mailbox...........email

           Incorrect!

Answer: postbox

6  elevator..........lift

            Correct!

5  apartment.........flat

            Correct!


=================================
#  NAME                TEST TAKEN
---------------------------------
9  Helen Hu            4/22/2022

---------------------------------
#  American          English
---------------------------------
3  sidewalk..........walk

           Incorrect!

Answer: pavement

5  apartment.........flat

            Correct!

12 hood..............bonnet

            Correct!

8  soccer............football

            Correct!

15 cart..............trolley

            Correct!

3  sidewalk..........walkside

           Incorrect!

Answer: pavement

17 vacation..........holiday

            Correct!

20 mailbox...........postbox

            Correct!

19 pants.............trouser

           Incorrect!

Answer: trousers

2  french fries......crisps

           Incorrect!

Answer: chips

===================================================            updated binary file
                Updated Information                            
===================================================
---------------------------------------------------
#  NAME                SCORE %        TEST TAKEN
---------------------------------------------------
1  Steve Smith         56.6           11/11/2019
2  Sue Jones           10.0           11/11/2011
3  Li Ying             70.0           4/22/2022
4  Kun Joom            20.0           11/11/2021
5  Joe Bush            10.0           11/11/2021
6  Kim Long            0.0            11/11/2011
7  Fred Ring           33.3           5/5/2019
8  Frank Pearse        20.0           11/11/2011
9  Helen Hu            60.0           4/22/2022
10 Mark James          100.0          4/22/2022

*/