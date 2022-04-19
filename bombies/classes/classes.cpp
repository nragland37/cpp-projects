#include <iostream>
using namespace std;

class Employee {
   private:  // data members of the class
    string name;
    int age;
    double gpa;

   public:                          // member functions
    string getName();               // access function
    void setName(const string& n);  // set function
    int getAge();
    void setAge(int a);
    double getGPA();
    void setGPA(double g);
    void display();
};

int main() {
    return 0;
}