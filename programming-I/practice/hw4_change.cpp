#include <iostream>
using namespace std;

//****************************************************************************************************
int main() {
    int balance,
        quarters,
        dimes,
        nickels,
        pennies;

    const int Q = 25,
              D = 10,
              N = 5;

    cout << "Enter the balance in cents: ";
    cin >> balance;

    quarters = balance / Q;
    balance = balance % Q;

    dimes = balance / D;
    balance = balance % D;

    nickels = balance / N;
    balance = balance % N;

    pennies = balance;

    cout << endl;

    cout << "Quarters: " << quarters << endl
         << endl
         << "Dimes: " << dimes << endl
         << endl
         << "Nickels: " << nickels << endl
         << endl
         << "Pennies: " << pennies << endl;

    return 0;
}

//****************************************************************************************************