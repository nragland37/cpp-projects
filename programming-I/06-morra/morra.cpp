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

// Constants
const int MAX_FINGERS = 5; // Maximum number of fingers a player can show
const int MIN_FINGERS = 1; // Minimum number of fingers a player can show
const int MAX_GUESS = 10; // Maximum guess a player can make
const int MIN_GUESS = 0; // Minimum guess a player can make

int main() {

    // Variables
    int playerOneFingerCount; // Number of fingers shown by player one
    int playerOneGuess; // Guess made by player one
    int playerTwoFingerCount; // Number of fingers shown by player two
    int playerTwoGuess; // Guess made by player two
    int totalFingers; // Total number of fingers shown by both players

    ofstream outputFile("result.txt"); // Stores the results in "result.txt" file...

    srand(time(NULL)) ;

    // Generate random numbers for each player
    playerOneFingerCount = rand() % (MAX_FINGERS - MIN_FINGERS) + MIN_FINGERS;
    playerOneGuess = rand() % (MAX_GUESS - MIN_GUESS) + MIN_GUESS;
    playerTwoFingerCount = rand() % (MAX_FINGERS - MIN_FINGERS) + MIN_FINGERS;
    playerTwoGuess = rand() % (MAX_GUESS - MIN_GUESS) + MIN_GUESS;

    // Write the results to the file
    outputFile << "Fingers\tTotal" << endl;
    outputFile << playerOneFingerCount << "\t\t" << playerOneGuess << endl;
    outputFile << playerTwoFingerCount << "\t\t" << playerTwoGuess << endl;

    // Calculate the total number of fingers
    totalFingers = playerOneFingerCount + playerTwoFingerCount;

    // Write the correct total to the file
    outputFile << "\nCorrect total is " << totalFingers << endl;

    // Determine the winner
    if ( totalFingers == playerOneGuess && totalFingers == playerTwoGuess ) {
        outputFile << "TIE" << endl;

    } else if ( totalFingers == playerOneGuess ) {
        outputFile << "PLAYER 1 WINS" << endl;

    } else if ( totalFingers == playerTwoGuess ) {
        outputFile << "PLAYER 2 WINS" << endl;

    } else {
        outputFile << "NO ONE WINS" << endl;
        
    }

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