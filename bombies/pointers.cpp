#include <iostream>

using namespace std;

int main()
{
    
    int num;
    int i = 8;

    num = ++i + 10;

    cout << i << endl;
    cout << num << endl;

    num = i++ + 10;

    cout << i << endl;
    cout << num;

    return 0;
}