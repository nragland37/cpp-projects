//*****************************************************************************************************
//
//      This program reverses a string using recursion.
//
//*****************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

void reverseString(string &s, int start = 0);

//*****************************************************************************************************

int main() {
    string s = "ABC";

    reverseString(s);
    cout << "Reversed string: " << s << endl;

    cout << "Enter string to reverse: ";
    getline(cin, s);

    reverseString(s);
    cout << "Reversed string: " << s << endl;
}

//*****************************************************************************************************

void reverseString(string &s, int start) {
    size_t end = (s.size() - 1) - start;
    char temp;

    if (start < end) {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        reverseString(s, start + 1);
    }
}

//*****************************************************************************************************
/*

Reversed string: CBA
Enter string to reverse: helloworld
Reversed string: dlrowolleh

*******************************************************************************************************

Reversed string: CBA
Enter string to reverse: hello. world. +=
Reversed string: =+ .dlrow .olleh

*/