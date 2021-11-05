/*********************************************************************************************************
Author:      Lucas Fazecas
Title:       Assignment 5 Part 2
Purpose:     Improve concentration game using conditionals and loops
Date:  October 18th, 2021
*********************************************************************************************************/

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// declare and initialize variables
	// variables to display... when user selects a position, assign actual card value
	char displayCard1 = '*', displayCard2 = '*', displayCard3 = '*', displayCard4 = '*', displayCard5 = '*', displayCard6 = '*';

	// variables to store the actual card values at each position
	char actualCard1 = 'A', actualCard2 = 'A', actualCard3 = 'B', actualCard4 = 'B', actualCard5 = 'C', actualCard6 = 'C';

	// variables for user's guesses
	short userGuess;
	char userGuessActual1 = ' ', userGuessActual2 = ' ';

	// variables to store match and turn count
	short matchCount = 0, turnCount = 0;

	// variables for flag and to not unflip cards that are already matched
	bool gameOver = false, matchA = false, matchB = false, matchC = false;


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

	system("pause");
	system("cls");

	while (!gameOver)
	{
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

		system("cls");

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

		system("cls");

		// display updated board after 2nd guess
		cout << "Concentration Board" << endl;
		cout << displayCard1 << " " << displayCard2 << " " << displayCard3 << endl;
		cout << displayCard4 << " " << displayCard5 << " " << displayCard6 << endl << endl;

		// check if user made a match or not and display message and count score accordingly
		if (userGuessActual1 == userGuessActual2)
		{
			SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN));
			cout << "Congrats, you got a match!" << endl << endl;
			SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN));
			matchCount++; // matchCount = matchCount + 1

			// check if game has ended
			if (matchCount == 3)
			{
				gameOver = true;
			}

			// check which pairs were already matched
			if (userGuessActual1 == 'A' && userGuessActual2 == 'A')
			{
				matchA = true;
			}
			else if (userGuessActual1 == 'B' && userGuessActual2 == 'B')
			{
				matchB = true;
			}			
			else if (userGuessActual1 == 'C' && userGuessActual2 == 'C')
			{
				matchC = true;
			}
		}
		else
		{
			SetConsoleTextAttribute(hConsole, (FOREGROUND_RED));
			cout << "Too bad! No match :(" << endl << endl;
			SetConsoleTextAttribute(hConsole, (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN));

			// flip cards that were not matched yet
			if (userGuessActual1 == 'A')
			{
				// check if pairs were not matched yet to prevent unflipping matched pairs
				if (matchA == false)
				{
					displayCard1 = '*', displayCard2 = '*';
				}
			}
			else if (userGuessActual1 == 'B')
			{
				if (matchB == false)
				{
					displayCard3 = '*', displayCard4 = '*';
				}
			}
			else if (userGuessActual1 == 'C')
			{
				if (matchC == false)
				{
					displayCard5 = '*', displayCard6 = '*';
				}
			}
			if (userGuessActual2 == 'A')
			{
				if (matchA == false)
				{
					displayCard1 = '*', displayCard2 = '*';
				}
			}
			else if (userGuessActual2 == 'B')
			{
				if (matchB == false)
				{
					displayCard3 = '*', displayCard4 = '*';
				}
			}
			else if (userGuessActual2 == 'C')
			{
				if (matchC == false)
				{
					displayCard5 = '*', displayCard6 = '*';
				}
			}
			
		}

		system("pause");
		system("cls");

		turnCount++;

		// end of while loop
	} 

	// start of conclusion screen
	cout << "Congrats, You made it!" << endl << endl;

	system("pause");
	cout << endl;

	cout << "It took you " << turnCount << " attempts to finish this game." << endl << endl;

	system("pause");

	// Output credits
	cout << endl << endl;
	cout << "*************************************************" << endl;
	cout << "*                                                *" << endl;
	cout << "*                That's All Folks!               *" << endl;
	cout << "*                                                *" << endl;
	cout << "**************************************************" << endl;
	cout << endl << endl;

	system("pause");
	return 0;
}