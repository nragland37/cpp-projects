//*****************************************************************************************************
//      Morra Game Simulation
//
//      This program is a simple game of Morra (a game played with fingers) between two players and
//      the results of each game are written to a file.
//
//*****************************************************************************************************

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

//*****************************************************************************************************

int main() {
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

    short seed;
    seed = time(0);
    srand(seed);

    playerOneFingers = rand() % (MAX_FINGERS - MIN_FINGERS) + MIN_FINGERS;
    playerOneGuess = rand() % (MAX_GUESS - MIN_GUESS) + MIN_GUESS;
    playerTwoFingers = rand() % (MAX_FINGERS - MIN_FINGERS) + MIN_FINGERS;
    playerTwoGuess = rand() % (MAX_GUESS - MIN_GUESS) + MIN_GUESS;

    out << "Fingers\tTotal" << endl;

    out << playerOneFingers << "\t\t" << playerOneGuess << endl;

    out << playerTwoFingers << "\t\t" << playerTwoGuess << endl;

    sum = playerOneFingers + playerTwoFingers;
    out << "\nCorrect total is " << sum << endl;

    if (sum == playerOneGuess && sum == playerTwoGuess)
        out << "TIE" << endl;
    else if (sum == playerOneGuess)
        out << "PLAYER 1 WINS" << endl;
    else if (sum == playerTwoGuess)
        out << "PLAYER 2 WINS" << endl;
    else
        out << "NO ONE WINS" << endl;

    return 0;
}

//*****************************************************************************************************
/*

Fingers	Total
4		5
3		9

Correct total is 7
NO ONE WINS

*****************************************************************************************************

Fingers	Total
1		2
1		6

Correct total is 2
PLAYER 1 WINS

*****************************************************************************************************

Fingers	Total
2		1
4		6

Correct total is 6
PLAYER 2 WINS

*/