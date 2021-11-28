//----------------------------------------------------------------------
// Purpose: The purpose of this code is to modify
//          the existing code from Concentratio Game Level 2 into a more maintainable
//          and readable program by implementing various functions.
// Author:	Lucas Fazecas
// Date: November 26, 2021
//----------------------------------------------------------------------

#include <iostream>
#include <Windows.h>
#include "main.h"

using namespace std;

const int TOTAL_MATCHES = 3;

int main()
{
	char menuChoice;         // to get user input
	bool noExit = true;      // bool to exit game

	displayIntro();
	while (noExit)
	{

		menuChoice = gameMenu();

		switch (menuChoice)
		{
		case '1':
			playGame();
			break;
		case '9':
			noExit = false;
			break;
		}
	}
	displayCredits();
}

void displayIntro()
{
	cout << "**************************************************" << endl;   // Output program title screen
	cout << "                   Welcome to                    *" << endl;
	cout << "               Awesome Concentration             *" << endl;
	cout << "**************************************************" << endl;
	cout << endl << endl;
	system("pause");
	system("cls");
}

int gameMenu()
{
	char userSelection = 'a';
	bool exit = false;

	while (!exit)
	{
		system("cls");

		cout << "------------------------------------------------------------" << endl;
		cout << "-                      - GAME MENU -                       -" << endl;
		cout << "------------------------------------------------------------" << endl;
		cout << "- Enter 1 to Play the game                                 -" << endl;
		cout << "- Enter 9 to Quit                                          -" << endl;
		cout << "------------------------------------------------------------" << endl << endl;

		cout << "Selection: ";
		cin >> userSelection;

		switch (userSelection)
		{
		case '1':
		case '9':
			exit = true;
			break;
		default:
			cout << "Invalid Input. Please, check menu options again." << endl << endl;
			system("pause");
		}
	}
	return userSelection;
}

void playGame()
{
	int cardPosition, matchCount = 0, attempts = 0;			// variables for the card position user input, number of matches and attemptsd
	char firstGuess = '0', secondGuess = '1';				// holds the card value of the players first guess and second guess

	/************************************************************************************************/
	// INITIALIZE GAME DATA
	char card1 = 'A', card2 = 'A', card3 = 'B', card4 = 'B', card5 = 'C', card6 = 'C';		// the game cards
	/************************************************************************************************/

	/************************************************************************************************/
	// INITIALIZE GAME DISPLAY
	char display1 = '*', display2 = '*', display3 = '*', display4 = '*', display5 = '*', display6 = '*';	// the display variables
	char masterDisplay1 = '*', masterDisplay2 = '*', masterDisplay3 = '*', masterDisplay4 = '*', masterDisplay5 = '*', masterDisplay6 = '*';	// the master display variables
	/************************************************************************************************/

	bool gameOver = false;   // bool to end game

	system("cls");

	displayInstruction();

	initializeGameData(card1, card2, card3, card4, card5, card6);

	while (!gameOver)
	{
		// DISPLAY BOARD FUNCTION HERE ***********************************
		displayBoard(display1, display2, display3, display4, display5, display6);
		// *****************************************************************

		/****************************************************************/
		// GET VALID BOARD POSITION HERE
		cardPosition = getValidBoardPosition(display1, display2, display3, display4, display5, display6);
		/****************************************************************/

		// First attempt
		if (cardPosition == 1)		// Check position of guess, change the display card and store the actual game card in first guess
		{
			display1 = card1;
			firstGuess = card1;
		}
		else if (cardPosition == 2)
		{
			display2 = card2;
			firstGuess = card2;
		}
		else if (cardPosition == 3)
		{
			display3 = card3;
			firstGuess = card3;
		}
		else if (cardPosition == 4)
		{
			display4 = card4;
			firstGuess = card4;
		}
		else if (cardPosition == 5)
		{
			display5 = card5;
			firstGuess = card5;
		}
		else if (cardPosition == 6)
		{
			display6 = card6;
			firstGuess = card6;
		}

		// DISPLAY BOARD FUNCTION HERE ***********************************
		displayBoard(display1, display2, display3, display4, display5, display6);
		// ***************************************************************

		/****************************************************************/
		// GET VALID BOARD POSITION HERE
		cardPosition = getValidBoardPosition(display1, display2, display3, display4, display5, display6);
		/****************************************************************/

		// Second attempt
		if (cardPosition == 1)		// Check position of guess
		{
			display1 = card1;
			secondGuess = card1;
		}
		else if (cardPosition == 2)
		{
			display2 = card2;
			secondGuess = card2;
		}
		else if (cardPosition == 3)
		{
			display3 = card3;
			secondGuess = card3;
		}
		else if (cardPosition == 4)
		{
			display4 = card4;
			secondGuess = card4;
		}
		else if (cardPosition == 5)
		{
			display5 = card5;
			secondGuess = card5;
		}
		else if (cardPosition == 6)
		{
			display6 = card6;
			secondGuess = card6;
		}

		// DISPLAY BOARD FUNCTION HERE ***********************************
		displayBoard(display1, display2, display3, display4, display5, display6);
		// ****************************************************************

		if (firstGuess == secondGuess)					// Check first and second guess to see if they're equal, if so congratulate and increment matchCount
		{
			/************************************************************************************************/
			// MATCH MESSAGE FUNCTION HERE
			matchMessage();
			/************************************************************************************************/

			matchCount++;

			if (matchCount == TOTAL_MATCHES)			// game over as all matches have been made
			{
				gameOver = true;
			}
			else
			{
				masterDisplay1 = display1;				// update the master display variables based on a successful match
				masterDisplay2 = display2;
				masterDisplay3 = display3;
				masterDisplay4 = display4;
				masterDisplay5 = display5;
				masterDisplay6 = display6;
			}
		}
		else
		{
			/************************************************************************************************/
			// NO MATCH MESSAGE FUNCTION HERE
			noMatchMessage();
			/************************************************************************************************/

			/************************************************************************************************/
			// INITIALIZE GAME DISPLAY FUNCTION HERE
			initializeGameDisplay(display1, display2, display3, display4, display5, display6, masterDisplay1, masterDisplay2, masterDisplay3, masterDisplay4, masterDisplay5, masterDisplay6);
			/************************************************************************************************/
		}
		attempts++;
		system("pause");
	}

	system("cls");
	cout << "Congratulations you've just beaten this Awesome Concentration game!!" << endl;
	cout << "It took you " << attempts << " attempts!!" << endl << endl;
	system("pause");
}

void initializeGameData(char& c1, char& c2, char& c3, char& c4, char& c5, char& c6)
{
	int gameBoardLayout = 1;

	gameBoardLayout = (rand() % 3) + 1; // gives a random number between 1 and 3 included

	if (gameBoardLayout == 1)
	{
		c1 = 'T';
		c2 = 'O';
		c3 = 'O';
		c4 = 'Y';
		c5 = 'T';
		c6 = 'Y';
	}
	else if (gameBoardLayout == 2)
	{
		c1 = 'A';
		c2 = 'F';
		c3 = 'D';
		c4 = 'D';
		c5 = 'F';
		c6 = 'A';
	}
	else if (gameBoardLayout == 3)
	{
		c1 = 'X';
		c2 = 'H';
		c3 = 'R';
		c4 = 'H';
		c5 = 'X';
		c6 = 'R';
	}
}

void initializeGameDisplay(char& disp1, char& disp2, char& disp3, char& disp4, char& disp5, char& disp6, char masterDisp1, char masterDisp2, char masterDisp3, char masterDisp4, char masterDisp5, char masterDisp6)
{
disp1 = masterDisp1;					// reset the display variables due to an incorrect match
disp2 = masterDisp2;
disp3 = masterDisp3;
disp4 = masterDisp4;
disp5 = masterDisp5;
disp6 = masterDisp6;
}

void displayInstruction()
{
	cout << "-------------------------------------------------------------------" << endl;   // Instructions
	cout << "Instructions: Enter a 1, 2, 3, 4, 5 or 6 to choose a card location " << endl;
	cout << "1 2 3" << endl;
	cout << "4 5 6" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << endl;
	system("pause");
	system("cls");
}

void displayBoard(char disp1, char disp2, char disp3, char disp4, char disp5, char disp6)
{
	system("cls");

	cout << "Concentration Board" << endl;				// Display board
	cout << disp1 << "  " << disp2 << "  " << disp3 << endl;
	cout << disp4 << "  " << disp5 << "  " << disp6 << endl;
}

int getValidBoardPosition(char currentDisp1, char currentDisp2, char currentDisp3, char currentDisp4, char currentDisp5, char currentDisp6)
{
	int boardPosition = -1;
	bool validPosition = false;

	while (!validPosition)
	{
		cout << "select a card position: ";
		cin >> boardPosition;
		cout << endl << endl;

		switch (boardPosition)
		{
		case 1:
			if (currentDisp1 == '*')
			{
				validPosition = true;
			}
			else
			{
				cout << "You've already chosen that card. Please, choose another one." << endl;
			}
			break;
		case 2:
			if (currentDisp2 == '*')
			{
				validPosition = true;
			}
			else
			{
				cout << "You've already chosen that card. Please, choose another one." << endl;
			}
			break;
		case 3:
			if (currentDisp3 == '*')
			{
				validPosition = true;
			}
			else
			{
				cout << "You've already chosen that card. Please, choose another one." << endl;
			}
			break;
		case 4:
			if (currentDisp4 == '*')
			{
				validPosition = true;
			}
			else
			{
				cout << "You've already chosen that card. Please, choose another one." << endl;
			}
			break;
		case 5:
			if (currentDisp5 == '*')
			{
				validPosition = true;
			}
			else
			{
				cout << "You've already chosen that card. Please, choose another one." << endl;
			}
			break;
		case 6:
			if (currentDisp6 == '*')
			{
				validPosition = true;
			}
			else
			{
				cout << "You've already chosen that card. Please, choose another one." << endl;
			}
			break;
		default:
			cout << "Invalid entry for board position. Please, try again." << endl;
		}
	}
	return boardPosition;
}

void matchMessage()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "Congrats, you've made a match!!" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void noMatchMessage()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << "So sorry, no match for you.  :(" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void displayCredits()
{
	system("cls");

	cout << "**************************************************" << endl;   // Output credits.
	cout << "*              Credits:                          *" << endl;
	cout << "*              Hope you enjoyed :D               *" << endl;
	cout << "*                                                *" << endl;
	cout << "*              By: Ruki                          *" << endl;
	cout << "**************************************************" << endl;
	cout << endl << endl;

	system("pause");
}