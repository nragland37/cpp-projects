//*****************************************************************************************************
//      American to English Translation Test
//
//      The program reads the translation and tester information from text files and randomly selects 
//      three people from the list to take the test. The results are recorded along with the date
//      taken for each person, and is automatically written back to the text file.
//
//      Other files required:
//        1.  Testers.txt - number of testers and the tester information
//        2.  Translation.txt - number of translations and the translation information
//
//*****************************************************************************************************

#include <cctype>
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
    Date testTaken;     // nested structure
};

Translation *readTranslation(const string &fileName, int &num);
Person *readTesters(const string &fileName, int &num);
void testingOptions(const Translation translate[], int numT, Person people[], int numP);
void takeTest(const Translation translate[], int numT, Person &p);
void displayTesters(const Person people[], int numP);
void writeTesters(const string &fileName, const Person people[], int numP);
void displayTranslateAnswers(const Translation translate[], int numT);

//*****************************************************************************************************

int main() {
    int numT = 0,
        numP = 0;
    string fileName;
    char studyEntry;
    Translation *translate = nullptr;
    Person *people = nullptr;

    cout << fixed << setprecision(1);

    translate = readTranslation("Translation.txt", numT);
    people = readTesters("Testers.txt", numP);

    displayTesters(people, numP);

    cout << "\n---------------------------------------------------\n"
         << "\tAmerican to English Translation Test\n"
         << "---------------------------------------------------\n"
         << "   Three people from this list will be randomly\n"
         << "            selected to take the test \n\n"
         << "Would you like to study before the test? (Y/N)" << endl;    
    cin >> studyEntry;
    studyEntry = toupper(studyEntry);

    if (studyEntry == 'Y') {
        displayTranslateAnswers(translate, numT);
        cout << "\nPress enter to continue..." << endl;
        cin.ignore();     
        cin.get();        
        cout << "Good Luck!" << endl;
    } else {
        cout << "\nGood Luck!" << endl;
    }

    testingOptions(translate, numT, people, numP);

    cout << "===================================================\n"
         << "\t\tUpdated Information\n"
         << "===================================================";

    displayTesters(people, numP);
    writeTesters("Testers.txt", people, numP);

    delete[] translate;
    translate = nullptr;
    delete[] people;
    people = nullptr;

    return 0;
}

//*****************************************************************************************************

Translation *readTranslation(const string &fileName, int &num) {
    Translation *t = nullptr;
    ifstream f(fileName);

    if (f.is_open()) {        // check if file is open before reading
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

Person *readTesters(const string &fileName, int &num) {
    Person *p = nullptr;
    ifstream f(fileName);

    if (f.is_open()) {
        f >> num;
        f.ignore();     

        p = new Person[num];

        for (int i = 0; i < num; ++i) {
            f.getline(p[i].name, NAME_SIZE);
            f >> p[i].score;
            f.ignore();    
            f >> p[i].testTaken.month;
            f.ignore();     
            f >> p[i].testTaken.day;
            f.ignore();     
            f >> p[i].testTaken.year;
            f.ignore();    
        }

        f.close();
    } else {
        cerr << "Error: Unable to open file\n";
    }

    return p;
}

//*****************************************************************************************************

void testingOptions(const Translation translate[], int numT, Person people[], int numP) {
    const int NUM_TESTS = 3;     
    int randomPerson = 0,
        month,
        day,
        year;
    short seed;

    seed = time(0);
    srand(seed);

    cout << "\n---------------------------------\n"
         << "        Enter Today's Date\n"
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
         << "   Five American words will be\n"
         << " randomly selected from the list\n"
         << "  Enter the English translation." << endl;

    for (int i = 0; i < NUM_TESTS; ++i) {
        randomPerson = rand() % numP;     

        people[randomPerson].testTaken.month = month;     
        people[randomPerson].testTaken.day = day;         
        people[randomPerson].testTaken.year = year;       

        cout << "\n=================================" << endl;
        cout << setfill(' ')
             << setw(3) << left << "#" << setw(20) << "NAME" << "TEST TAKEN\n"
             << "---------------------------------" << endl;

        cout << setw(3) << randomPerson + 1
             << setw(20) << people[randomPerson].name     
             << people[randomPerson].testTaken.month << "/"       
             << people[randomPerson].testTaken.day << "/"
             << people[randomPerson].testTaken.year << endl;

        takeTest(translate, numT, people[randomPerson]);     
    }
}

//*****************************************************************************************************

void takeTest(const Translation translate[], int numT, Person &p) {
    const int NUM_QUESTIONS = 5;     
    int randomQuestion = 0,
        correct = 0;
    double avg = 0;
    string answer,
        guess;
    short seed;

    seed = time(0);
    srand(seed);

    cout << "\n---------------------------------" << endl;
    cout << setfill(' ') 
         << setw(3) << left << "#" << setw(18) << "American" << "English\n"
         << "---------------------------------" << endl;

    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        randomQuestion = rand() % numT;     
        cout << setfill(' ') << setw(3)  << randomQuestion + 1
             << setfill('.') << setw(18) << translate[randomQuestion].american;
        cin >> guess;

        answer = translate[randomQuestion].english;

        if (guess == answer) {
            cout << "\n\t    Correct!" << endl;
            correct++;
        } else {
            cout << "\n\t   Incorrect!\n\n"
                 << "Answer: " << translate[randomQuestion].english << endl;
        }

        cout << endl;
    }

    avg = (static_cast<double>(correct) / NUM_QUESTIONS) * 100;     
    p.score = avg;
}

//*****************************************************************************************************

void displayTesters(const Person people[], int numP) {
    cout << "\n---------------------------------------------------" << endl;
    cout << setfill(' ') 
         << setw(3) << left << "#" << setw(20) << "NAME" << setw(15) << "SCORE %" << "TEST TAKEN\n"
         << "---------------------------------------------------" << endl;

    for (int i = 0; i < numP; ++i)     
        cout << setw(3) << i + 1
             << setw(20) << people[i].name
             << setw(15) << people[i].score
             << people[i].testTaken.month << "/"
             << people[i].testTaken.day << "/"
             << people[i].testTaken.year << endl;
}

//*****************************************************************************************************

void writeTesters(const string &fileName, const Person people[], int numP) {
    ofstream f(fileName);

    f << numP << endl;     

    for (int i = 0; i < numP; ++i)     
        f << people[i].name << "\n"
          << people[i].score << ","
          << people[i].testTaken.month
          << "/" << people[i].testTaken.day
          << "/" << people[i].testTaken.year << endl;

    f.close();     
}

//*****************************************************************************************************

void displayTranslateAnswers(const Translation translate[], int numT) {
    cout << "\n---------------------------------\n" 
         << setw(3) << left << "#" << setw(18) << "American" << "English\n"
         << "---------------------------------" << endl;

    for (int i = 0; i < numT; ++i)     
        cout << setfill(' ') << setw(3) << i + 1
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
Enter day: 14
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
4  Kun Joom            4/14/2022

---------------------------------
#  American          English
---------------------------------
15 cart..............trolley                    numbers added to easily locate answers from the list

            Correct!

5  apartment.........flat

            Correct!

4  cookie............biscuit

            Correct!

17 vacation..........holiday

            Correct!

16 candy.............sweet

            Correct!


=================================
#  NAME                TEST TAKEN
---------------------------------
5  Joe Bush            4/14/2022

---------------------------------
#  American          English
---------------------------------
6  elevator..........lift

            Correct!

17 vacation..........holiday

            Correct!

5  apartment.........complex

           Incorrect!

Answer: flat                                 incorrect answers are displayed with the correct answer

16 candy.............yumyum

           Incorrect!

Answer: sweet

8  soccer............football

            Correct!


=================================
#  NAME                TEST TAKEN
---------------------------------
9  Helen Hu            4/14/2022

---------------------------------
#  American          English
---------------------------------
20 mailbox...........postbox

            Correct!

3  sidewalk..........pavement

            Correct!

19 pants.............trousers

            Correct!

20 mailbox...........postbox

            Correct!

16 candy.............sweeties

           Incorrect!

Answer: sweet

===================================================
                Updated Information
===================================================
---------------------------------------------------
#  NAME                SCORE %        TEST TAKEN
---------------------------------------------------
1  Steve Smith         56.6           11/11/2019
2  Sue Jones           10.0           11/11/2011
3  Li Ying             0.0            11/11/2011
4  Kun Joom            100.0          4/14/2022
5  Joe Bush            60.0           4/14/2022
6  Kim Long            0.0            11/11/2011
7  Fred Ring           33.3           5/5/2019
8  Frank Pearse        20.0           11/11/2011
9  Helen Hu            80.0           4/14/2022
10 Mark James          0.0            11/11/2021


*****************************************************************************************************

10                                                       updated file with new scores and test dates
Steve Smith
56.6,11/11/2019
Sue Jones
10,11/11/2011
Li Ying
0,11/11/2011
Kun Joom
100,4/14/2022
Joe Bush
60,4/14/2022
Kim Long
0,11/11/2011
Fred Ring
33.3,5/5/2019
Frank Pearse
20,11/11/2011
Helen Hu
80,4/14/2022
Mark James
0,11/11/2021

*/