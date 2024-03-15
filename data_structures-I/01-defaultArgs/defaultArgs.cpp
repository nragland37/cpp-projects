//*****************************************************************************************************
//
//      This program demonstrates the use of default arguments in a function.
//
//*****************************************************************************************************

#include <iostream>
using namespace std;

//*****************************************************************************************************

void displayMsg(const char msg[] = "Decide. Commit. Succeed.", char symbol = ' ', int num = 10);

//*****************************************************************************************************

int main() {
    displayMsg("I will decide.", '*', 15);
    displayMsg("I will commit.", '+');
    displayMsg("I will succeed.");
    displayMsg();

    return 0;
}

//*****************************************************************************************************

void displayMsg(const char msg[], char symbol, int num) {
    for (int i = 0; i < num; ++i)
        cout << symbol;

    cout << msg;

    for (int i = 0; i < num; ++i)
        cout << symbol;

    cout << endl;
}

//*****************************************************************************************************
/*

***************I will decide.***************
++++++++++I will commit.++++++++++
          I will succeed.
          Decide. Commit. Succeed.

*/
