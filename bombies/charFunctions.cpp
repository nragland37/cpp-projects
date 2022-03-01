#include <iostream>

using namespace std;

bool testID(const char custNum[], int size);
bool testID(const char custNum[], int size);
int main() {
    const int SIZE = 10;
    char custNum[SIZE] = "Mine";

    return 0;
}

bool testID(const char custNum[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        if (!isalpha(custNum[i])) {
            return false;
        }
    }
    for (int i = size / 2; i < size; ++i) {
        if (!isdigit(custNum[i])) {
            return false;
        }
    }
    return true;
}

bool testID(const char custNum[], int size) {
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