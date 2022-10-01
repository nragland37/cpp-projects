//****************************************************************************************************
// 			File:                 morra.cpp
//
//			Student:              Nicholas Ragland  
//
//			Assignment:           Program #6
//			
//          Course Name:          Programming 1
//
//          Course Number:        COSC 1550 - 03
//          
//          Due:                  October 7, 2021
//
//          This program implements one instant of a Morra game between two players.Each player 
//          simultaniuosly throws out a single hand with a 0 to five number of fingers and says a 
//			guessed sum of all fingers showed by both players.The player who could guess the total 
//			correct wins. If both players guessed it correctly, it is a tie.
//
//****************************************************************************************************  

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

//****************************************************************************************************
int main()
{

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

	out << "Fingers" << "\t" << "Total" << endl;

	out << playerOneFingers << "\t" << playerOneGuess << endl;

	out << playerTwoFingers << "\t" << playerTwoGuess << endl;

	sum = playerOneFingers + playerTwoFingers;
	out << "Correct total is " << sum << endl << endl;

	if (sum == playerOneGuess && sum == playerTwoGuess)
	{
		out << "TIE" << endl;
	}
	else if (sum == playerOneGuess) 
	{
		out << "PLAYER 1 WINS" << endl;
	}
	else if (sum == playerTwoGuess) 
	{
		out << "PLAYER 2 WINS" << endl;
	}
	else
	{
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