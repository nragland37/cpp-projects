#include <iostream>
#include <string>

using namespace std;

int main() {
    char letters[] = {‘A’, ‘B’, ‘C’, ‘\0’};  // null character at the end
    char letters[] = “ABC”;                  // automatically inserts null character at the end
                                             // so the same initialization
    int numbers[] = {1, 2, 3};
    cout << numbers;  // Displays the address of the first element
    cout << letters;  // Displays “ABC”, up to the null character

    char letters[] = “ABC”;
    cout << sizeof(letters);  // 4, since \0 is at the end

    char sentence[] = “This is a test in coding”;
    char* ptr = nullptr;

    ptr = strstr(sentence, “test”);  // sets ‘ptr’ to point to the element of the array
                                     // at which “test” starts
    cout << ptr;                     // Displays “test in coding”

    char name1[10];
    char name2[10];
    if (strcmp(name1, name2) == 0)  // Checks if they are the same

        if (strcmp(name1, name2) < 0)      // Checks if name1 is alphabetically less than name2
            if (strcmp(name1, name2) > 0)  // Checks if name1 is alphabetically greater than name2

                int num = atoi(“12345”);  // Assigns 12345 to ‘num’
    int num = atoi(“12ABC”);              // Assigns 12 to ‘num’
    double d = atof(“3.14159”);           // Assigns 3.14159 to ‘d’

    string name;
    getline(cin, name);  // Any length name will be stored
    cin >> name;         // Any length name will be stored, up to a space

    if (name1 == name2) {  // Can check if strings are equal using standard syntax

    }
    if (name1 < name2)  // Check if name1 is alphabetically less than name2

        string name2;
    name2 = name1;  // Can assign strings

    return 0;
}