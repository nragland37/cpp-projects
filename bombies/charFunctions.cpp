#include <iostream>

using namespace std;

bool testID(const char custNum[], int size);
bool testID2(const char custNum[], int size);
int main() {
    const int SIZE = 6;
    char custNum[SIZE] = "Test";
    bool test1,
        test2;

    test1 = testID(custNum, SIZE);
    cout << test1 << endl;
    cout << sizeof(custNum);

    return 0;
}

bool testID(const char custNum[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        if (!isalpha(custNum[i])) {
            return false;
        }
    }
    return true;
}

bool testID2(const char custNum[], int size) {
    bool correctFormat = true;
    int i = 0;
    while ((correctFormat) && (i < size / 2)) {
        if (!isalpha(custNum[i])) {
            correctFormat = false;
        }
        ++i;
    }
    while ((correctFormat) && (i < size)) {
        if (!isdigit(custNum[i])) {
            correctFormat = false;
        }
        ++i;
    }
    return correctFormat;
}