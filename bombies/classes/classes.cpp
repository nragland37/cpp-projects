#include <iostream>
#include <string>
using namespace std;

class Employee {
   private:  // data members of the class
    string name;
    int age;
    double gpa;

   public:                          // member functions
    string getName() const;         // access function
    void setName(const string& n);  // set function
    int getAge();
    void setAge(int a);
    double getGPA();
    void setGPA(double g);
    void display() const;
};

string Student::getName() {
    return name;
}
void Student::setAge(int a) {
    if (a < 0) {
        age = 0;
    } else {
        age = a;
    }
    age = a;
}

int main() {
    Student s1;           // object oriented
    s1.setName("Helen");  // public members
    s1.setAge(15);        // public members
    // s1.age = 20;  //wrong because the data types are private

    return 0;
}
