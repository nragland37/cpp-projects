#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    int age;
    string department;
};

struct Company {
    string name;
    int year;
    Employee* emps = nullptr;
    int numEmps;
};

void populate(Employee& e);
void display(const Employee& e);
void populateComp(Company& c);
void displayComp(const Company& c);

int main() {
    Employee e;
    Company c;
    populate(e);
    display(e);
    populateComp(c);
    displayComp(c);

    delete[] c.emps;
    return 0;
}

void populate(Employee& e) {
    cout << "name: ";
    getline(cin, e.name);
    cout << "age: ";
    cin >> e.age;
    cin.ignore();
    cout << "department: ";
    getline(cin, e.department);
}

void display(const Employee& e) {
    cout << "\nname: " << e.name;
    cout << "\nage: " << e.age;
    cout << "\ndepartment: " << e.department;
}

void populateComp(Company& c) {
    cout << "\ncompany name: ";
    getline(cin, c.name);
    cout << "company year: ";
    cin >> c.year;
    cout << "# of employees: ";
    cin >> c.numEmps;
    c.emps = new Employee[c.numEmps];
    cin.ignore();
    for (int i = 0; i < c.numEmps; ++i) {
        populate(c.emps[i]);
    }
}

void displayComp(const Company& c) {
    cout << "\nCompany name: " << c.name;
    cout << "\nCompany year: " << c.year;
    cout << "\n# of employees: " << c.numEmps;
    for (int i = 0; i < c.numEmps; ++i) {
        display(c.emps[i]);
    }
}