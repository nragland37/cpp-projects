//*****************************************************************************************************
//      Morra Series Game Simulation
//
//      This program is a series of 10 games of Morra (a game played with fingers) between two players
//      and the results of each game are written to a file.
//
//*****************************************************************************************************
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

//*****************************************************************************************************

int main() {
    // Constants defining the range of fingers and guesses
    const int MAXIMUM_FINGERS = 5,
              MINIMUM_FINGERS = 1,
              MAXIMUM_GUESS = 10,
              MINIMUM_GUESS = 0;

    // Variables to store player information, guesses, total fingers, and wins
    int playerOneFingerCount,
         playerTwoFingerCount,
         playerOneGuess,
         playerTwoGuess,
         totalFingers,
         playerOneWins = 0,
         playerTwoWins = 0;

    // File stream to write game results on .txt file...
    ofstream resultsFile("morraSeriesResults.txt");

    // Seed for random number generation
    srand(time(NULL));

    // Game loop (10 games)
    for (int gameNumber = 1; gameNumber <= 10; gameNumber++) {
        // Generate random finger counts and guesses for both players
        playerOneFingerCount = rand() % (MAXIMUM_FINGERS - MINIMUM_FINGERS) + MINIMUM_FINGERS;
        playerOneGuess = rand() % (MAXIMUM_GUESS - MINIMUM_GUESS) + MINIMUM_GUESS;
        playerTwoFingerCount = rand() % (MAXIMUM_FINGERS - MINIMUM_FINGERS) + MINIMUM_FINGERS;
        playerTwoGuess = rand() % (MAXIMUM_GUESS - MINIMUM_GUESS) + MINIMUM_GUESS;

        // Display game information and player choices
        cout << left << "Game " << gameNumber << ":" << setw(12) << endl;
        cout << "Player" << setw(12) << "|Fingers" << setw(12) << "|Total" << endl;
        cout << "============|===========|============" << endl;
        cout << setw(12) << "1"
             << "|" << setw(11) << playerOneFingerCount << "|" << playerOneGuess << endl;
        cout << setw(12) << "2"
             << "|" << setw(11) << playerTwoFingerCount << "|" << playerTwoGuess << endl;

        // Calculate the total number of fingers
        totalFingers = playerOneFingerCount + playerTwoFingerCount;
        cout << "\nCorrect total is " << totalFingers << endl;

        // Determine the winner based on guesses and total fingers
        if (totalFingers == playerOneGuess && totalFingers == playerTwoGuess) {
            cout << "TIE" << endl;
        } else if (totalFingers == playerOneGuess) {
            cout << "Player 1 Wins" << endl;
            playerOneWins++;
        } else if (totalFingers == playerTwoGuess) {
            cout << "Player 2 Wins" << endl;
            playerTwoWins++;
        } else {
            cout << "NO ONE WINS" << endl;
        }

        cout << "\n-------------------------------------" << endl;
    }

    // Display game summary and determine the winner of the series
    cout << "=====================================" << endl;
    resultsFile << "=====================================" << endl;
    cout << "Summary of the series" << endl;
    resultsFile << "Summary of the series" << endl;
    cout << "=====================================" << endl;
    resultsFile << "=====================================" << endl;
    cout << "Player 1 won " << playerOneWins << " games" << endl;
    resultsFile << "Player 1 won " << playerOneWins << " games" << endl;
    cout << "Player 2 won " << playerTwoWins << " games" << endl;
    resultsFile << "Player 2 won " << playerTwoWins << " games" << endl;

    cout << "\nWinner of the series: ";
    resultsFile << "\nWinner of the series: ";

    if ( playerOneWins > playerTwoWins ) {
        cout << "Player 1" << endl;
        resultsFile << "Player 1" << endl;

    } else if ( playerOneWins < playerTwoWins ) {
        cout << "Player 2" << endl;
        resultsFile << "Player 2" << endl;

    } else if ( playerOneWins == playerTwoWins ) {
        cout << "It is a TIE" << endl;
        resultsFile << "It is a TIE" << endl;

    } else {
        cout << "NO ONE WINS" << endl;
        resultsFile << "NO ONE WINS" << endl;

    }

    return 0;
}

//*****************************************************************************************************
/*

Game 1:
Player      |Fingers    |Total
============|===========|============
1           |2          |8
2           |3          |9

Correct total is 5
NO ONE WINS

-------------------------------------
Game 2:
Player      |Fingers    |Total
============|===========|============
1           |2          |8
2           |3          |5

Correct total is 5
Player 2 Wins

-------------------------------------
Game 3:
Player      |Fingers    |Total
============|===========|============
1           |1          |6
2           |4          |7

Correct total is 5
NO ONE WINS

-------------------------------------
Game 4:
Player      |Fingers    |Total
============|===========|============
1           |3          |6
2           |1          |4

Correct total is 4
Player 2 Wins

-------------------------------------
Game 5:
Player      |Fingers    |Total
============|===========|============
1           |3          |1
2           |4          |5

Correct total is 7
NO ONE WINS

-------------------------------------
Game 6:
Player      |Fingers    |Total
============|===========|============
1           |4          |2
2           |1          |3

Correct total is 5
NO ONE WINS

-------------------------------------
Game 7:
Player      |Fingers    |Total
============|===========|============
1           |2          |9
2           |3          |8

Correct total is 5
NO ONE WINS

-------------------------------------
Game 8:
Player      |Fingers    |Total
============|===========|============
1           |2          |1
2           |2          |5

Correct total is 4
NO ONE WINS

-------------------------------------
Game 9:
Player      |Fingers    |Total
============|===========|============
1           |3          |4
2           |2          |7

Correct total is 5
NO ONE WINS

-------------------------------------
Game 10:
Player      |Fingers    |Total
============|===========|============
1           |2          |6
2           |3          |4

Correct total is 5
NO ONE WINS

-------------------------------------
=====================================
Summary of the series
=====================================
Player 1 won 0 games
Player 2 won 2 games

Winner of the series: Player 2

*/