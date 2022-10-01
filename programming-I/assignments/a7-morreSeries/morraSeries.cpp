//****************************************************************************************************
// 			File:                 morraSeries.cpp
//
//			Student:              Nicholas Ragland
//
//			Assignment:           Program #7
//
//          Course Name:          Programming 1
//
//          Course Number:        COSC 1550 - 03
//
//          Due:                  October 14, 2021
//
//          This program implements a series of Morra games between two players. There will
//			be 10 rounds for this series. The person who wins the most of the games will win the
//			series. If both win an equal number of games, it outputs that it is a tie.
//
//****************************************************************************************************

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

//****************************************************************************************************

int main() {
    short seed;

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
             << "|" << setw(11) << playerTwoFingers << "|" << playerTwoGuess << endl
             << endl;

        sum = playerOneFingers + playerTwoFingers;
        cout << "Correct total is " << sum << endl;

        if (sum == playerOneGuess && sum == playerTwoGuess) {
            cout << "TIE" << endl
                 << endl;
        } else if (sum == playerOneGuess) {
            cout << "Player 1 Wins" << endl
                 << endl;
            playerOneWins++;
        } else if (sum == playerTwoGuess) {
            cout << "Player 2 Wins" << endl
                 << endl;
            playerTwoWins++;
        } else {
            cout << "NO ONE WINS" << endl
                 << endl;
        }

        cout << "-----------------------------------------------------" << endl;
    }

    cout << "=====================================================" << endl;
    cout << "Summary of the series" << endl;
    cout << "=====================================================" << endl;
    cout << "Player 1 won " << playerOneWins << " games" << endl;
    cout << "Player 2 won " << playerTwoWins << " games" << endl
         << endl;

    cout << "Winner of the series: ";

    if (playerOneWins == playerTwoWins) {
        cout << "It is a TIE" << endl;
    } else if (playerOneWins > playerTwoWins) {
        cout << "Player 1" << endl;
    } else if (playerTwoWins > playerOneWins) {
        cout << "Player 2" << endl;
    } else {
        cout << "NO ONE WINS" << endl;
    }

    return 0;
}

//****************************************************************************************************
/*

Game 1:
Player      |Fingers    |Total
============|===========|============
1           |1          |5
2           |3          |6

Correct total is 4
NO ONE WINS

-----------------------------------------------------
Game 2:
Player      |Fingers    |Total
============|===========|============
1           |1          |4
2           |4          |0

Correct total is 5
NO ONE WINS

-----------------------------------------------------
Game 3:
Player      |Fingers    |Total
============|===========|============
1           |1          |6
2           |3          |9

Correct total is 4
NO ONE WINS

-----------------------------------------------------
Game 4:
Player      |Fingers    |Total
============|===========|============
1           |2          |7
2           |1          |7

Correct total is 3
NO ONE WINS

-----------------------------------------------------
Game 5:
Player      |Fingers    |Total
============|===========|============
1           |4          |8
2           |4          |9

Correct total is 8
Player 1 Wins

-----------------------------------------------------
Game 6:
Player      |Fingers    |Total
============|===========|============
1           |4          |7
2           |4          |4

Correct total is 8
NO ONE WINS

-----------------------------------------------------
Game 7:
Player      |Fingers    |Total
============|===========|============
1           |3          |2
2           |1          |0

Correct total is 4
NO ONE WINS

-----------------------------------------------------
Game 8:
Player      |Fingers    |Total
============|===========|============
1           |3          |2
2           |3          |5

Correct total is 6
NO ONE WINS

-----------------------------------------------------
Game 9:
Player      |Fingers    |Total
============|===========|============
1           |2          |2
2           |1          |4

Correct total is 3
NO ONE WINS

-----------------------------------------------------
Game 10:
Player      |Fingers    |Total
============|===========|============
1           |1          |0
2           |2          |7

Correct total is 3
NO ONE WINS

-----------------------------------------------------
=====================================================
Summary of the series
=====================================================
Player 1 won 1 games
Player 2 won 0 games

Winner of the series: Player 1

*/