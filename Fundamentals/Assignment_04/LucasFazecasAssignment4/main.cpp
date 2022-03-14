/*********************************************************************************************************
Author:      Lucas Fazecas
Title:       Assignment 4
Purpose:     Develop a rough Concentration game
Date:  October 12th, 2021
*********************************************************************************************************/

#include <iostream>

using namespace std;

int main()
{
	// declare and initialize variables
	// variables to display... when user selects a position, assign actual card value
	char displayCard1 = '*';
	char displayCard2 = '*';
	char displayCard3 = '*';
	char displayCard4 = '*';
	char displayCard5 = '*';
	char displayCard6 = '*';

	// variables to store the actual card values at each position
	char actualCard1 = 'B';
	char actualCard2 = 'A';
	char actualCard3 = 'C';
	char actualCard4 = 'C';
	char actualCard5 = 'B';
	char actualCard6 = 'A';

	// variables for user's guesses
	short userGuess;
	char userGuessActual1 = ' ';
	char userGuessActual2 = ' ';

	//variable to store user's score
	short userScore = 0;
	

	// display intro screen
	cout << "**************************************************" << endl;
	cout << "*                  Welcome to                    *" << endl;
	cout << "*              Awesome Concentration             *" << endl;
	cout << "**************************************************" << endl << endl;

	system("pause");
	system("cls");

	// display instructions
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Instructions: Enter 1, 2, 3, 4, 5 or 6 to choose a card location" << endl;
	cout << "1 2 3" << endl;
	cout << "4 5 6" << endl;
	cout << "-------------------------------------------------------------------" << endl << endl;

	// ************ START OF TURN #1  - user guesses twice for each turn ************

	// display board with all cards faced down
	cout << "Concentration Board" << endl;
	cout << displayCard1 << " " << displayCard2 << " " << displayCard3 << endl;
	cout << displayCard4 << " " << displayCard5 << " " << displayCard6 << endl << endl;

	// 1ST GUESS
	// prompt user to enter card position
	cout << "select a card position: ";
	cin >> userGuess;
	cout << endl;

	// check position entered by user, unhide the card and store the 1st guess
	if (userGuess == 1)
	{
		// user selected position 1
		displayCard1 = actualCard1;
		userGuessActual1 = actualCard1;
	}
	else if (userGuess == 2)
	{
		// user selected position 2
		displayCard2 = actualCard2;
		userGuessActual1 = actualCard2;
	}
	else if (userGuess == 3)
	{
		// user selected position 3
		displayCard3 = actualCard3;
		userGuessActual1 = actualCard3;
	}
	else if (userGuess == 4)
	{
		// user selected position 4
		displayCard4 = actualCard4;
		userGuessActual1 = actualCard4;
	}
	else if (userGuess == 5)
	{
		// user selected position 5
		displayCard5 = actualCard5;
		userGuessActual1 = actualCard5;
	}
	else if (userGuess == 6)
	{
		// user selected position 6
		displayCard6 = actualCard6;
		userGuessActual1 = actualCard6;
	}
	else
	{
		cout << "I've told ya to choose an integer number between 1 and 6... exiting since you've disappointed me :(" << endl;
		system("pause");
		return 0;
	}

	// display updated board after 1st guess
	cout << "Concentration Board" << endl;
	cout << displayCard1 << " " << displayCard2 << " " << displayCard3 << endl;
	cout << displayCard4 << " " << displayCard5 << " " << displayCard6 << endl << endl;

	// 2ND GUESS
	// prompt user to enter card position
	cout << "select a card position: ";
	cin >> userGuess;
	cout << endl;

	// check position entered by user, unhide the card and store the 2nd guess
	if (userGuess == 1)
	{
		// user selected position 1
		displayCard1 = actualCard1;
		userGuessActual2 = actualCard1;
	}
	else if (userGuess == 2)
	{
		// user selected position 2
		displayCard2 = actualCard2;
		userGuessActual2 = actualCard2;
	}
	else if (userGuess == 3)
	{
		// user selected position 3
		displayCard3 = actualCard3;
		userGuessActual2 = actualCard3;
	}
	else if (userGuess == 4)
	{
		// user selected position 4
		displayCard4 = actualCard4;
		userGuessActual2 = actualCard4;
	}
	else if (userGuess == 5)
	{
		// user selected position 5
		displayCard5 = actualCard5;
		userGuessActual2 = actualCard5;
	}
	else if (userGuess == 6)
	{
		// user selected position 6
		displayCard6 = actualCard6;
		userGuessActual2 = actualCard6;
	}
	else
	{
		cout << "I've told ya to choose an integer number between 1 and 6... exiting since you've disappointed me :(" << endl;
		system("pause");
		return 0;
	}

	// display updated board after 2nd guess
	cout << "Concentration Board" << endl;
	cout << displayCard1 << " " << displayCard2 << " " << displayCard3 << endl;
	cout << displayCard4 << " " << displayCard5 << " " << displayCard6 << endl << endl;

	// check if user made a match or not and display message and count score accordingly
	if (userGuessActual1 == userGuessActual2)
	{
		cout << "Congrats, you got a match!" << endl << endl;
		userScore++; // userScore = userScore + 1
	}
	else
	{
		cout << "Too bad! No match :(" << endl << endl;
	}

	// ************ END OF TURN #1 ************

	// ************ START OF TURN #2 ************

	// 1ST GUESS
	// prompt user to enter card position
	cout << "select a card position: ";
	cin >> userGuess;
	cout << endl;

	// check position entered by user, unhide the card and store the 1st guess
	if (userGuess == 1)
	{
		// user selected position 1
		displayCard1 = actualCard1;
		userGuessActual1 = actualCard1;
	}
	else if (userGuess == 2)
	{
		// user selected position 2
		displayCard2 = actualCard2;
		userGuessActual1 = actualCard2;
	}
	else if (userGuess == 3)
	{
		// user selected position 3
		displayCard3 = actualCard3;
		userGuessActual1 = actualCard3;
	}
	else if (userGuess == 4)
	{
		// user selected position 4
		displayCard4 = actualCard4;
		userGuessActual1 = actualCard4;
	}
	else if (userGuess == 5)
	{
		// user selected position 5
		displayCard5 = actualCard5;
		userGuessActual1 = actualCard5;
	}
	else if (userGuess == 6)
	{
		// user selected position 6
		displayCard6 = actualCard6;
		userGuessActual1 = actualCard6;
	}
	else
	{
		cout << "I've told ya to choose an integer number between 1 and 6... exiting since you've disappointed me :(" << endl;
		system("pause");
		return 0;
	}

	// display updated board after 1st guess
	cout << "Concentration Board" << endl;
	cout << displayCard1 << " " << displayCard2 << " " << displayCard3 << endl;
	cout << displayCard4 << " " << displayCard5 << " " << displayCard6 << endl << endl;

	// 2ND GUESS
	// prompt user to enter card position
	cout << "select a card position: ";
	cin >> userGuess;
	cout << endl;

	// check position entered by user, unhide the card and store the 2nd guess
	if (userGuess == 1)
	{
		// user selected position 1
		displayCard1 = actualCard1;
		userGuessActual2 = actualCard1;
	}
	else if (userGuess == 2)
	{
		// user selected position 2
		displayCard2 = actualCard2;
		userGuessActual2 = actualCard2;
	}
	else if (userGuess == 3)
	{
		// user selected position 3
		displayCard3 = actualCard3;
		userGuessActual2 = actualCard3;
	}
	else if (userGuess == 4)
	{
		// user selected position 4
		displayCard4 = actualCard4;
		userGuessActual2 = actualCard4;
	}
	else if (userGuess == 5)
	{
		// user selected position 5
		displayCard5 = actualCard5;
		userGuessActual2 = actualCard5;
	}
	else if (userGuess == 6)
	{
		// user selected position 6
		displayCard6 = actualCard6;
		userGuessActual2 = actualCard6;
	}
	else
	{
		cout << "I've told ya to choose an integer number between 1 and 6... exiting since you've disappointed me :(" << endl;
		system("pause");
		return 0;
	}

	// display updated board after 2nd guess
	cout << "Concentration Board" << endl;
	cout << displayCard1 << " " << displayCard2 << " " << displayCard3 << endl;
	cout << displayCard4 << " " << displayCard5 << " " << displayCard6 << endl << endl;

	// check if user made a match or not and display message and count score accordingly
	if (userGuessActual1 == userGuessActual2)
	{
		cout << "Congrats, you got a match!" << endl << endl;
		userScore++;
	}
	else
	{
		cout << "Too bad! No match :(" << endl << endl;
	}

	// ************ END OF TURN #2 ************

	// ************ START OF TURN #3 ************

	// 1ST GUESS
	// prompt user to enter card position
	cout << "select a card position: ";
	cin >> userGuess;
	cout << endl;

	// check position entered by user, unhide the card and store the 1st guess
	if (userGuess == 1)
	{
		// user selected position 1
		displayCard1 = actualCard1;
		userGuessActual1 = actualCard1;
	}
	else if (userGuess == 2)
	{
		// user selected position 2
		displayCard2 = actualCard2;
		userGuessActual1 = actualCard2;
	}
	else if (userGuess == 3)
	{
		// user selected position 3
		displayCard3 = actualCard3;
		userGuessActual1 = actualCard3;
	}
	else if (userGuess == 4)
	{
		// user selected position 4
		displayCard4 = actualCard4;
		userGuessActual1 = actualCard4;
	}
	else if (userGuess == 5)
	{
		// user selected position 5
		displayCard5 = actualCard5;
		userGuessActual1 = actualCard5;
	}
	else if (userGuess == 6)
	{
		// user selected position 6
		displayCard6 = actualCard6;
		userGuessActual1 = actualCard6;
	}
	else
	{
		cout << "I've told ya to choose an integer number between 1 and 6... exiting since you've disappointed me :(" << endl;
		system("pause");
		return 0;
	}

	// display updated board after 1st guess
	cout << "Concentration Board" << endl;
	cout << displayCard1 << " " << displayCard2 << " " << displayCard3 << endl;
	cout << displayCard4 << " " << displayCard5 << " " << displayCard6 << endl << endl;

	// 2ND GUESS
	// prompt user to enter card positioN
	cout << "select a card position: ";
	cin >> userGuess;
	cout << endl;

	// check position entered by user, unhide the card and store the 2nd guess
	if (userGuess == 1)
	{
		// user selected position 1
		displayCard1 = actualCard1;
		userGuessActual2 = actualCard1;
	}
	else if (userGuess == 2)
	{
		// user selected position 2
		displayCard2 = actualCard2;
		userGuessActual2 = actualCard2;
	}
	else if (userGuess == 3)
	{
		// user selected position 3
		displayCard3 = actualCard3;
		userGuessActual2 = actualCard3;
	}
	else if (userGuess == 4)
	{
		// user selected position 4
		displayCard4 = actualCard4;
		userGuessActual2 = actualCard4;
	}
	else if (userGuess == 5)
	{
		// user selected position 5
		displayCard5 = actualCard5;
		userGuessActual2 = actualCard5;
	}
	else if (userGuess == 6)
	{
		// user selected position 6
		displayCard6 = actualCard6;
		userGuessActual2 = actualCard6;
	}
	else
	{
		cout << "I've told ya to choose an integer number between 1 and 6... exiting since you've disappointed me :(" << endl;
		system("pause");
		return 0;
	}

	// display updated board after 2nd guess
	cout << "Concentration Board" << endl;
	cout << displayCard1 << " " << displayCard2 << " " << displayCard3 << endl;
	cout << displayCard4 << " " << displayCard5 << " " << displayCard6 << endl << endl;

	// check if user made a match or not and display message and count score accordingly
	if (userGuessActual1 == userGuessActual2)
	{
		cout << "Congrats, you got a match!" << endl << endl;
		userScore++;
	}
	else
	{
		cout << "Too bad! No match :(" << endl << endl;
	}
	// ************ END OF TURN #3 ************

	system("pause");
	system("cls");

	// start of display score
	cout << "Let's check how bad you've done..." << endl << endl;
	system("pause");
	cout << endl;

	// check score and display message accordingly
	if (userScore == 1)
	{
		cout << "You matched " << userScore << " pair" << endl;
		cout << "Well... you tried but... TRY HARDER!" << endl << endl;
	}
	else if (userScore == 2)
	{
		cout << "You matched " << userScore << " pairs" << endl;
		cout << "You did kinda good... but not enough..." << endl << endl;
	}
	else if (userScore == 3)
	{
		cout << "You matched " << userScore << " pairs" << endl;
		cout << "Geez! You're INSANE!!!" << endl << endl;
	}
	else
	{
		cout << "NOT EVEN ONE MATCH???" << endl;
		cout << "You're a shame for humankind!!" << endl << endl;
	}

	system("pause");
	return 0;
}