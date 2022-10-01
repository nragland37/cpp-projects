#include <cstring>
#include <iostream>

using namespace std;

int main() {
    char str[15] = "ABC101";

    if (islower(str[2])) {
        cout << "LOWERCASE" << endl;
    } else {
        cout << "UPPERCASE" << endl;
    }
    for (int i = 0; i < 15; ++i) {
        cout << str[i];
    }
    cout << endl;

    strcat(str, "XYZ");

    for (int i = 0; i < 15; ++i) {
        cout << str[i];
    }

    return 0;
}