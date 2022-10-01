//****************************************************************************************************
//
//			Nicholas Ragland
//			Nested Loops
//
//****************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

int readInput();
int findSquare(int);
void displaySquare(int, int);

//****************************************************************************************************

int main() {
    int exp,
        square;

    exp = readInput();
    square = findSquare(exp);
    displaySquare(exp, square);

    return 0;
}

int readInput() {
    int exponent;

    cout << "Enter the base you want to find the square of ";
    cin >> exponent;

    return exponent;
}

int findSquare(int exp) {
    int square;
    square = exp * exp;

    return square;
}

void displaySquare(int exp, int square) {
    cout << "The square of " << exp << " is " << square << "." << endl;
}

//****************************************************************************************************
/*
//****************************************************************************************************
int main()

    int exp,
        square;

    exp = readInput();
    square = findSquare(exp);
    displaySquare(exp, square);

    return 0;
}

int readInput()
{
    int exponent;

    cout << "Enter the base you want to find the square of ";
    cin >> exponent;

    return exponent;
}

int findSquare(int exp)
{
    int square;
    square = exp * exp;

    return square;
}

void displaySquare(int exp, int square)
{
    cout << "The square of " << exp << " is " << square << endl;
}

//****************************************************************************************************
//****************************************************************************************************
int main()

    for (int j = 5; j >= 1; j--)
    {
        for (int i = 1; i <= j; i++)
        {
            cout << " ";
        }

        for (int i = 1; i <= 6-j; i++)
        {
            cout << "#";
        }
        cout << endl;
    }

//****************************************************************************************************
        for (int i = 10; i <= 13; i++)
    {
        for (int j = 50; j <= 55; j++)
        {
            cout << "(" << i << ":" << j << ")";
        }

        cout << endl;
    }
//****************************************************************************************************
//****************************************************************************************************
int main()

    {
    int inputNum;

    cout << "Enter a number: ";
    cin >> inputNum;

    cout << endl;

    if (testEven(inputNum))
        cout << "Your number is even";
    else
        cout << "Your number is odd";

    for (inputNum= inputNum; inputNum == inputNum; inputNum++)
        cout << "Get Fucked" << endl;

    cout << endl;

    return 0;
}

bool testEven(int num)
{
    bool even;

    if (num % 2 == 0)
        even = true;
    else
        even = false;
    return even;
}

//****************************************************************************************************
//****************************************************************************************************

string getName();
void greet(string);

//****************************************************************************************************
int main()

{

    greet(getName());

    return 0;
}

string getName()
{
    string nameInput;

    cout << "what is your name?";
    cin >> nameInput;

    return nameInput;
}

void greet(string name)
{
    cout << "Hello " << name << endl;
}

//****************************************************************************************************
//****************************************************************************************************

int main()
{
    int nicksTime = 0, // minutes //
        jpsPatience;

    const int FAMILY_PATIENCE = 5;

    do
    {

        cout << "Family waiting.." << endl;

        nicksTime++;

        cout << "What is Jp's Patience (in minutes): ";
        cin >> jpsPatience;

        if (jpsPatience == nicksTime || jpsPatience == 0)
        {
            cout << "Jp screams, 'Lets go slick!'" << endl;
            break;
        }
    } while (nicksTime < FAMILY_PATIENCE);
    {

        cout << "Nick gets up to join Family" << endl;

    }


        return 0;

    //****************************************************************************************************
    //****************************************************************************************************

int main()
{
    int nicksTime = 0, // minutes //
        jpsPatience;

    const int FAMILY_PATIENCE = 5;

    do
    {

        cout << "Family waiting.." << endl;

        nicksTime++;

        cout << "What is Jp's Patience (in minutes): ";
        cin >> jpsPatience;

        if (jpsPatience == nicksTime || jpsPatience == 0)
        {
            cout << "Jp screams, 'Lets go slick!'" << endl;
            break;
        }
    } while (nicksTime < FAMILY_PATIENCE);
    {

        cout << "Nick gets up to join Family" << endl;

    }


        return 0;
*/