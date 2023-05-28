//*****************************************************************************************************
//
//      This program reads in a file of RPN expressions and evaluates them using a stack.
//
//      Other files required:
//        1.	 stack.h - header file for the Stack class
//        2.	 expressions.txt - file containing RPN expressions
//
//*****************************************************************************************************

#include <cctype> 
#include <cstdlib>  
#include <fstream>
#include <iostream>
using namespace std;
#include "stack.h"

//*****************************************************************************************************

void outputToken(char token[], ofstream &resultsFile);
void processNumber(char token[], Stack<int> &rpnStack, ofstream &resultsFile);
bool processOperator(char token[], Stack<int> &rpnStack, ofstream &resultsFile);
void displayResult(Stack<int> &rpnStack, ofstream &resultsFile, bool &isValid);
void resetFlagStack(Stack<int> &rpnStack, bool &isValid);

//*****************************************************************************************************

int main() {
    Stack<int> rpnStack;
    bool isValid = true;
    char token[5];

    ifstream in("expressions.txt");
    ofstream out("results.txt");

    while (in >> token) {
        outputToken(token, out);

        if (token[0] == ';') {
            displayResult(rpnStack, out, isValid);
            resetFlagStack(rpnStack, isValid);
        } else if ((isValid) && (isdigit(token[0]))) {
            processNumber(token, rpnStack, out);
        } else if ((isValid) && (ispunct(token[0]))) {
            isValid = processOperator(token, rpnStack, out);
        }
    }

    in.close();
    out.close();

    return 0;
}

//*****************************************************************************************************

void outputToken(char token[], ofstream &resultsFile) {
    resultsFile << endl << "(Token: " << token << ")\t\t";

    if (token[0] != ';')
        cout << token << " ";
}

//*****************************************************************************************************

void processNumber(char token[], Stack<int> &rpnStack, ofstream &resultsFile) {
    int num;

    num = atoi(token);

    rpnStack.push(num);
    resultsFile << "Push " << num;
}

//*****************************************************************************************************

bool processOperator(char token[], Stack<int> &rpnStack, ofstream &resultsFile) {
    bool success = false;
    int op1,
        op2,
        result;

    if ((rpnStack.pop(op2)) && (rpnStack.pop(op1))) {
        resultsFile << "Pop  " << op2 << "\tPop  " << op1;

        switch (token[0]) {
            case '*':
                result = op1 * op2;
                break;
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            case '%':
                result = op1 % op2;
                break;
        }

        rpnStack.push(result);
        resultsFile << "\tPush " << result;

        success = true;
    }

    return success;
}

//*****************************************************************************************************

void displayResult(Stack<int> &rpnStack, ofstream &resultsFile, bool &isValid) {
    int result;

    if (isValid) {
        if (rpnStack.getNumValues() == 1) {
            rpnStack.pop(result);
            resultsFile << "Pop  " << result << "\n\t\tValid:  result = " << result << "\n" << endl;
            cout << "= " << result << endl;
        } else if (rpnStack.getNumValues() > 1) {
            resultsFile << "\n\t\tInvalid RPN expression - too many operands\n" << endl;
            cerr << "\t\tinvalid\n";

            isValid = false;
        }
    } else {
        resultsFile << "\n\t\tInvalid RPN expression - not enough operands\n" << endl;
        cerr << "\t\tinvalid\n";
    }
}

//*****************************************************************************************************

void resetFlagStack(Stack<int> &rpnStack, bool &isValid) {
    int popVal;

    while (rpnStack.pop(popVal));

    isValid = true;
}

//*****************************************************************************************************

/*

2 4 * 5 + = 13
13 5 % 5 + = 8
15 1 + 2 / 1 - = 7
15 + 1 + 2 / 1 -                invalid
3 4 + 15 10 - * = 35
3 4 + 6 15 10 - *               invalid
2 13 + 14 6 - - 5 * 4 + = 39
35 6 4 2 2 / + * - = 5
3 4 + 1 2 - * 4 2 / 3 - + = -8
3 14 1 2 4 2 3 + % * + - + = 8

*/