//*****************************************************************************************************
//      Text File to Binary Conversion
//
//      This program reads tester information from a text file and writes the information to a binary 
//      file.
//
//      Other files required:
//        1.  Testers.txt - number of testers and the tester information
//
//*****************************************************************************************************

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

const int NAME_SIZE = 20;

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

Person *readTesters(const string &fileName, int &num);
void writeTesters(const string &fileName, Person people[], int numP);

//*****************************************************************************************************

int main() {
    int numP = 0;
    string fileName;
    Person *people = nullptr;

    people = readTesters("Testers.txt", numP);     // read data from text file
    writeTesters("Testers.dat", people, numP);     // write data to binary file

    delete[] people;
    people = nullptr;

    return 0;
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

void writeTesters(const string &fileName, Person people[], int numP) {
    ofstream f(fileName, ios::binary);     // open file for writing in binary mode
    f.write(reinterpret_cast<char *>(&numP), sizeof(int));
    f.write(reinterpret_cast<char *>(people), sizeof(Person) * numP);
    f.close();
}

//*****************************************************************************************************
/*

reinterpret_cast<new_type>(expression)

C++ type cast operator used to cast an expression to a different type, regardless of the relationship
between the original type and the new type.

*****************************************************************************************************

f.write(reinterpret_cast<char*>(&numP), sizeof(int));

(&numP) - casts it to a char* pointer, allowing it to be written to the binary file
sizeof(int) - specifies the size of the data being written is an int type

*****************************************************************************************************

f.write(reinterpret_cast<char*>(people), sizeof(Person) * numP);

(people) - casts it to a char* pointer, allowing it to be written to the binary file.
sizeof(Person) * numP - specifies the size of the data being written is an array of Person structs with
                       numP number of elements.

*/