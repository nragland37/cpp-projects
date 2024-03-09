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
    const int MAX_FINGERS = 5,
              MIN_FINGERS = 1,
              MAX_GUESS = 10,
              MIN_GUESS = 0;
    int playerOneFingers,
        playerTwoFingers,
        playerOneGuess,
        playerTwoGuess,
        sum,
        playerOneWins = 0,
        playerTwoWins = 0;
    ofstream out("morraSeriesResults.txt");

    short seed;
    seed = time(0);
    srand(seed);

    for (int game = 1; game <= 10; game++) {
        playerOneFingers = rand() % (MAX_FINGERS - MIN_FINGERS) + MIN_FINGERS;
        playerOneGuess = rand() % (MAX_GUESS - MIN_GUESS) + MIN_GUESS;
        playerTwoFingers = rand() % (MAX_FINGERS - MIN_FINGERS) + MIN_FINGERS;
        playerTwoGuess = rand() % (MAX_GUESS - MIN_GUESS) + MIN_GUESS;

        cout << left << "Game " << game << ":" << setw(12) << endl;
        cout << "Player" << setw(12) << "|Fingers" << setw(12) << "|Total" << endl;
        cout << "============|===========|============" << endl;
        cout << setw(12) << "1"
             << "|" << setw(11) << playerOneFingers << "|" << playerOneGuess << endl;
        cout << setw(12) << "2"
             << "|" << setw(11) << playerTwoFingers << "|" << playerTwoGuess << endl;

        sum = playerOneFingers + playerTwoFingers;
        cout << "\nCorrect total is " << sum << endl;

        if (sum == playerOneGuess && sum == playerTwoGuess) {
            cout << "TIE" << endl;
        } else if (sum == playerOneGuess) {
            cout << "Player 1 Wins" << endl;
            playerOneWins++;
        } else if (sum == playerTwoGuess) {
            cout << "Player 2 Wins" << endl;
            playerTwoWins++;
        } else {
            cout << "NO ONE WINS" << endl;
        }

        cout << "\n-------------------------------------" << endl;
    }

    cout << "=====================================" << endl;
    out << "=====================================" << endl;
    cout << "Summary of the series" << endl;
    out << "Summary of the series" << endl;
    cout << "=====================================" << endl;
    out << "=====================================" << endl;
    cout << "Player 1 won " << playerOneWins << " games" << endl;
    out << "Player 1 won " << playerOneWins << " games" << endl;
    cout << "Player 2 won " << playerTwoWins << " games" << endl;
    out << "Player 2 won " << playerTwoWins << " games" << endl;

    cout << "\nWinner of the series: ";
    out << "\nWinner of the series: ";

    if (playerOneWins > playerTwoWins) {
        cout << "Player 1" << endl;
        out << "Player 1" << endl;
    } else if (playerOneWins < playerTwoWins) {
        cout << "Player 2" << endl;
        out << "Player 2" << endl;
    } else if (playerOneWins == playerTwoWins) {
        cout << "It is a TIE" << endl;
        out << "It is a TIE" << endl;
    } else {
        cout << "NO ONE WINS" << endl;
        out << "NO ONE WINS" << endl;
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