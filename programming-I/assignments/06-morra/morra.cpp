//*****************************************************************************************************
//
//		This program simulates a two-player game of guessing the sum of fingers. Both players randomly
//      display a number of fingers between 1 and 5 and guess the total number of fingers displayed.
//      The program then calculates the actual sum of the fingers and determines the winner of the
//      game. The results of the game, including the number of fingers displayed by each player and
//      the winner, are stored in a text file named "result.txt". If both players correctly guess the
//      sum of fingers, the game is declared a tie. If neither player correctly guesses the sum, then
//      no one wins. The output is written to the "result.txt" file, which is created if it does not
//      already exist.
//
//*****************************************************************************************************

#include <cstdlib>     // for rand() and srand()
#include <ctime>       // for time()
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
    ofstream out("result.txt");     // output file stream (write to file)

    short seed;         // seed for random number generator
    seed = time(0);     // get system time (0 = current time)
    srand(seed);        // seed random number generator

    playerOneFingers = rand() % (MAX_FINGERS - MIN_FINGERS) + MIN_FINGERS;     // random number between 1 and 5 (player 1)
    playerOneGuess = rand() % (MAX_GUESS - MIN_GUESS) + MIN_GUESS;             // random number between 0 and 10 (player 1)
    playerTwoFingers = rand() % (MAX_FINGERS - MIN_FINGERS) + MIN_FINGERS;     // random number between 1 and 5 (player 2)
    playerTwoGuess = rand() % (MAX_GUESS - MIN_GUESS) + MIN_GUESS;             // random number between 0 and 10  (player 2)

    out << "Fingers\tTotal" << endl;     // out is the output for the file "result.txt" (similar to cout but for files)

    out << playerOneFingers << "\t\t" << playerOneGuess << endl;

    out << playerTwoFingers << "\t\t" << playerTwoGuess << endl;

    sum = playerOneFingers + playerTwoFingers;
    out << "Correct total is " << sum << "\n"
        << endl;

    if (sum == playerOneGuess && sum == playerTwoGuess)     // if both players guess the correct sum (tie)
        out << "TIE" << endl;
    else if (sum == playerOneGuess)     // if player 1 guesses the correct sum (player 1 wins)
        out << "PLAYER 1 WINS" << endl;
    else if (sum == playerTwoGuess)     // if player 2 guesses the correct sum (player 2 wins)
        out << "PLAYER 2 WINS" << endl;
    else
        out << "NO ONE WINS" << endl;     // if neither player guesses the correct sum (no one wins)

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