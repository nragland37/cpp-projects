#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

//****************************************************************************************************

int main() {
    short seed;

    const int MAX_FINGERS = 5.,
              MIN_FINGERS = 1,
              MAX_GUESS = 10,
              MIN_GUESS = 0;

    int playerOneFingers,
        playerOneGuess,
        playerTwoFingers,
        playerTwoGuess,
        sum;

    ofstream out("result.txt");

    seed = time(0);
    srand(seed);

    playerOneFingers = rand() % (MAX_FINGERS - MIN_FINGERS) + MIN_FINGERS;
    playerOneGuess = rand() % (MAX_GUESS - MIN_GUESS) + MIN_GUESS;
    playerTwoFingers = rand() % (MAX_FINGERS - MIN_FINGERS) + MIN_FINGERS;
    playerTwoGuess = rand() % (MAX_GUESS - MIN_GUESS) + MIN_GUESS;

    out << "Fingers"
        << "\t"
        << "Total" << endl;

    out << playerOneFingers << "\t" << playerOneGuess << endl;

    out << playerTwoFingers << "\t" << playerTwoGuess << endl;

    sum = playerOneFingers + playerTwoFingers;
    out << "Correct total is " << sum << endl
        << endl;

    if (sum == playerOneGuess && sum == playerTwoGuess) {
        out << "TIE" << endl;
    } else if (sum == playerOneGuess) {
        out << "PLAYER 1 WINS" << endl;
    } else if (sum == playerTwoGuess) {
        out << "PLAYER 2 WINS" << endl;
    } else {
        out << "NO ONE WINS" << endl;
    }

    return 0;
}

//****************************************************************************************************
/*

Fingers	Total
2		6
1		9
Correct total is 3

NO ONE WINS

*/