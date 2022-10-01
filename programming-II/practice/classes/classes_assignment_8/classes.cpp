#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Employee {
    string name;
    int age;
    int month, day, year;

   public:
    Employee *readEmployees(const string &empFile, int &numEmps) {
        string filename = "Employees.txt";
        int t;
        ifstream f(filename);
        if (!f) {
            cout << "cannot open file" << endl;
        }
        f >> t;
        Employee *tmp = new Employee[t];
        if (tmp == nullptr) {
            cerr << "cannot allocate memory" << endl;
        }
        getline(f, filename);
        for (int i = 0; i < t; i++) {
            string data;

            getline(f, data);
            int found = data.find(',');
            tmp[i].name = data.substr(0, found);
            int found1 = data.find(',', found + 1);

            tmp[i].age = stoi(data.substr(found + 1, found1 - found - 1));
            found = data.find('/', found1);

            tmp[i].month = stoi(data.substr(found1 + 1, found - found1 - 1));
            found1 = data.find('/', found + 1);

            tmp[i].day = stoi(data.substr(found + 1, found1 - found - 1));

            tmp[i].year = stoi(data.substr(found1 + 1));
        }
        f.close();
        return tmp;
    }

    void displayEmployees(const Employee emps[], int numEmps) {
        cout << setw(15) << "NAME" << setw(10) << "AGE" << setw(15) << "DATE EMPLOYED" << endl;
        for (int i = 0; i < numEmps; i++)
            cout << setw(20) << emps[i].name << setw(5) << emps[i].age
                 << setw(5) << emps[i].month << "/" << setw(2) << emps[i].day
                 << "/" << setw(4) << emps[i].year << endl;
    }

    Employee *inputEmployees(Employee *emps, int &numEmps) {
        Employee *newemps = new Employee[numEmps + 1];
        for (int i = 0; i < numEmps; i++) {
            newemps[i].name = emps[i].name;
            newemps[i].age = emps[i].age;
            newemps[i].month = emps[i].month;
            newemps[i].day = emps[i].day;
            newemps[i].year = emps[i].year;
        }

        string name;
        int age, month, day, year;
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter year: ";
        cin >> year;
        newemps[numEmps].name = name;
        newemps[numEmps].age = age;
        newemps[numEmps].month = month;
        newemps[numEmps].day = day;
        newemps[numEmps].year = year;
        numEmps++;
        ofstream f("Employees.txt");
        f << numEmps << endl;
        for (int i = 0; i < numEmps; i++) {
            f << newemps[i].name << "," << newemps[i].age << ","
              << newemps[i].month << "/" << newemps[i].day << "/" << newemps[i].year << endl;
        }
        f.close();
        return newemps;
    }
};

int main() {
    string filename = "Employees.txt";
    int numemps;
    ifstream f(filename);
    f >> numemps;
    f.close();
    Employee emp;
    Employee *arr = emp.readEmployees("Employees.txt", numemps);
    emp.displayEmployees(arr, numemps);
    Employee *newarr = emp.inputEmployees(arr, numemps);
    emp.displayEmployees(newarr, numemps);
}