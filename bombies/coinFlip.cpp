#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

string coinToss();
int main() {
    srand(time(NULL));
    int numOfToss,
        playerOneWins = 0,
        playerTwoWins = 0;
    string playerOneGuess,
        playerTwoGuess;

    cout << '\t' << "Coin Toss!" << endl;
    cout << "How many tosses should I make? ";
    cin >> numOfToss;

    for (int i = 1; i <= numOfToss; ++i) {
        cin.get();
        string result = coinToss();
        cout << "Player 1 Guess(heads or tails): ";
        cin >> playerOneGuess;
        if (playerOneGuess == "heads") {
            playerTwoGuess = "tails";
        } else {
            playerTwoGuess = "heads";
        }
        cout << "-----------------------------------------------------" << endl;
        cout << left << "Game " << i << ":" << setw(12) << endl;
        cout << "Player" << setw(12) << "|Guess" << setw(12) << "|Toss" << endl;
        cout << "============|===========|============" << endl;

        cout << setw(12) << "1"
             << "|" << setw(11) << playerOneGuess << "|" << result << endl;

        cout << setw(12) << "2"
             << "|" << setw(11) << playerTwoGuess << "|" << result << endl
             << endl;
        cout << "-----------------------------------------------------" << endl;

        if (result == playerOneGuess) {
            cout << "Player 1 Wins" << endl
                 << endl;
            playerOneWins++;
        } else if (result == playerTwoGuess) {
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
    if (playerOneWins > playerTwoWins) {
        cout << "Player 1" << endl;
    } else if (playerTwoWins > playerOneWins) {
        cout << "Player 2" << endl;
    } else {
        cout << "NO ONE WINS" << endl;
    }
    return 0;
}

string coinToss() {
    int headOrTails = rand() % 2 + 1;
    if (headOrTails == 1) {
        return "heads";
    } else {
        return "tails";
    }
}