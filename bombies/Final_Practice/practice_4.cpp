#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "ABC101";

    cout << str.at(2) << endl;
    cout << str.size() << endl;
    cout << str.back() << endl;
    str.append("ABC");
    cout << str << endl;
    str.clear();
    cout << "test: " << str << endl;

    return 0;
}