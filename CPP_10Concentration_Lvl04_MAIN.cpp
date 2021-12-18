//---------------------------------------------------------------------------------
// Author:  Lucas Fázecas
// Purpose: Function based Concentration game improved with arrays and file stream
// Date: Dec 14, 2021
//---------------------------------------------------------------------------------
#include <iostream>
#include <Windows.h>
#include <fstream>      // header for manipulating files
#include <iomanip>
#include "main.h"

using namespace std;

//---------------------------------------------------------------------------------
// main line
int main()
{
	mainMenu menuChoice = DEFAULT;
	bool noExit = true;
	int scores[MAX_SCORES];				// array to hold the scores that is read in
	string playerList[MAX_SCORES];      // array to hold player's name
	int recordCount = 0;				// variable to track the number of records that were read in
	string playerName;
	int attempts = 0;

	loadScoreData(playerList, scores, recordCount);

	displayIntro();
	while (noExit)
	{
		menuChoice = gameMenu();

		switch (menuChoice)
		{
		case INSTRUCTIONS:
			displayInstructions();
			break;
		case PLAY:
			cout << "Please enter your name: ";
			cin >> playerName;
			playGame(playerName, attempts);
			updateScore(playerName, attempts, playerList, scores, recordCount);
			playerName = " ";
			attempts = 0;
			break;
		case DISPLAY:
			outputScores(playerList, scores, recordCount);
			break;
		case SAVE:
			saveDataToFile(playerList, scores, recordCount);
			break;
		case EXIT:
			noExit = false;
			break;
		}
	}
	displayCredits();
}

//---------------------------------------------------------------------------------
// display the game menu and validates the users choice
mainMenu gameMenu()
{
	int selection = -1;
	bool noExit = true;

	system("cls");
	while (noExit)
	{
		system("cls");
		cout << "-------------------------------------------------------------" << endl;
		cout << "-                       GAME MENU                           -" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << "- 1 - View Instructions                                     -" << endl;
		cout << "- 2 - Play Game                                             -" << endl;
		cout << "- 3 - Display Scores                                        -" << endl;
		cout << "- 4 - Save Scores                                           -" << endl;
		cout << "- 9 - Exit                                                  -" << endl;
		cout << "-------------------------------------------------------------" << endl;
		cout << endl << "Selection: ";
		cin >> selection;

		switch (selection)
		{
		case INSTRUCTIONS:
		case PLAY:
		case DISPLAY:
		case SAVE:
		case EXIT:
			noExit = false;
			break;
		default:
			cout << "Invalid entry. Please, check menu options again." << endl << endl;
			system("pause");
		}
	}
	return static_cast<mainMenu>(selection);
}

//---------------------------------------------------------------------------------
// Plays 1 game of concentration
void playGame(string& playerName, int& attempts)
{
	char cards[10];
	char displayCards[10];
	char masterDisplay[10];
	int cardPosition, matches = 0;
	char guess = -1, firstGuess, secondGuess;
	bool gameOver = false;

	system("cls");

	initializeGameData(cards);

	initializeDisplayData(displayCards, masterDisplay);

	while (!gameOver)
	{
		for (int i = 0; i < 2; i++)
		{
			displayBoard(displayCards);
			cardPosition = getValidBoardPosition(displayCards, playerName);

			if (cardPosition == 1)
			{
				displayCards[0] = cards[0];
				guess = cards[0];
			}
			else if (cardPosition == 2)
			{
				displayCards[1] = cards[1];
				guess = cards[1];
			}
			else if (cardPosition == 3)
			{
				displayCards[2] = cards[2];
				guess = cards[2];
			}
			else if (cardPosition == 4)
			{
				displayCards[3] = cards[3];
				guess = cards[3];
			}
			else if (cardPosition == 5)
			{
				displayCards[4] = cards[4];
				guess = cards[4];
			}
			else if (cardPosition == 6)
			{
				displayCards[5] = cards[5];
				guess = cards[5];
			}
			if (cardPosition == 7)
			{
				displayCards[6] = cards[6];
				guess = cards[6];
			}
			else if (cardPosition == 8)
			{
				displayCards[7] = cards[7];
				guess = cards[7];
			}
			else if (cardPosition == 9)
			{
				displayCards[8] = cards[8];
				guess = cards[8];
			}
			else if (cardPosition == 10)
			{
				displayCards[9] = cards[9];
				guess = cards[9];
			}
			else if (cardPosition == 99)
			{
				cheatMode(cards);
				displayBoard(displayCards);
				cardPosition = getValidBoardPosition(displayCards, playerName);

				if (cardPosition == 1)
				{
					displayCards[0] = cards[0];
					guess = cards[0];
				}
				else if (cardPosition == 2)
				{
					displayCards[1] = cards[1];
					guess = cards[1];
				}
				else if (cardPosition == 3)
				{
					displayCards[2] = cards[2];
					guess = cards[2];
				}
				else if (cardPosition == 4)
				{
					displayCards[3] = cards[3];
					guess = cards[3];
				}
				else if (cardPosition == 5)
				{
					displayCards[4] = cards[4];
					guess = cards[4];
				}
				else if (cardPosition == 6)
				{
					displayCards[5] = cards[5];
					guess = cards[5];
				}
				if (cardPosition == 7)
				{
					displayCards[6] = cards[6];
					guess = cards[6];
				}
				else if (cardPosition == 8)
				{
					displayCards[7] = cards[7];
					guess = cards[7];
				}
				else if (cardPosition == 9)
				{
					displayCards[8] = cards[8];
					guess = cards[8];
				}
				else if (cardPosition == 10)
				{
					displayCards[9] = cards[9];
					guess = cards[9];
				}
			}

			if (i == 0)
				firstGuess = guess;
			else
				secondGuess = guess;
		}
		displayBoard(displayCards);

		if (firstGuess == secondGuess)
		{
			matches++;
			matchMessage();
			if (matches == TOTAL_MATCHES)
			{
				gameOver = true;
			}
			else
			{
				for (int i = 0; i < 10; i++)
				{
					masterDisplay[i] = displayCards[i];
				}
			}
		}
		else
		{
			noMatchMessage();
			for (int i = 0; i < 10; i++)
			{
				displayCards[i] = masterDisplay[i];
			}
		}
		attempts++;
	}
	system("cls");
	cout << "Congratulations you've just beaten this Almost Awesome Concentration game!!" << endl;
	cout << "It took you " << attempts << " attempts!!" << endl << endl;
	system("pause");
}

//---------------------------------------------------------------------------------
// displays the game instructions
void displayBoard(char disp[])
{ 

	cout << "Concentration Board" << endl;
	cout << "-------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4)
		{
			cout << disp[i] << endl;
		}
		else
		{
			cout << disp[i] << " ";
		}
	}
	cout << endl;
}

//---------------------------------------------------------------------------------
// validates the users board position and returns the position to PlayGame
int getValidBoardPosition(char disp[], string playerName)
{
	int cardPosition;
	bool invalidInput = true;

	while (invalidInput)
	{
		cout << endl;
		cout << playerName << ", please select a card position between 1 and 10: ";
		cin >> cardPosition;
		cout << endl;

		if (cardPosition >= 1 && cardPosition <= 10 || cardPosition == 99)
		{
			if ((cardPosition == 1 && disp[0] == '*') || (cardPosition == 2 && disp[1] == '*') ||
				(cardPosition == 3 && disp[2] == '*') || (cardPosition == 4 && disp[3] == '*') ||
				(cardPosition == 5 && disp[4] == '*') || (cardPosition == 6 && disp[5] == '*') ||
				(cardPosition == 7 && disp[6] == '*') || (cardPosition == 8 && disp[7] == '*') || 
				(cardPosition == 9 && disp[8] == '*') || (cardPosition == 10 && disp[9] == '*') ||
				 cardPosition == 99)
				invalidInput = false;
			else
				cout << "Position " << cardPosition << " has all ready been used." << endl << endl;
		}
		else
		{
			cout << "Invalid board choice. Please, make sure you choose between 1 and 10" << endl << endl;
		}
	}
	cout << endl << endl;

	return cardPosition;
}

//---------------------------------------------------------------------------------
// displays the game instructions
void displayInstructions()
{
	system("cls");
	cout << "-----------------------------------------------------------------------" << endl;   // Instructions
	cout << "Instructions: Enter a number between 1 and 10 to choose a card location " << endl;
	cout << "1 2 3 4 5" << endl;
	cout << "6 7 8 9 10" << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	cout << endl;
	system("pause");
}

//---------------------------------------------------------------------------------
// Initializes game cards
void initializeGameData(char cards[])
{
	char baseCard[13] = { '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A' };
	int randomIndex;
	char selectedCard;
	int placeCard = 0;
	int boardPosition;
	int placed;

	// clear the board
	for (int i = 0; i < 10; i++)
	{
		cards[i] = '-';
	}

	while (placeCard < 10)
	{
		randomIndex = rand() % 13; // random number between 0 and 13. srand could be other good option
		selectedCard = baseCard[randomIndex];
		placed = 2;  // place matching pairs

		while (placed > 0)
		{
			boardPosition = rand() % 13;
			if (cards[boardPosition] == '-') // checks if a card has already been placed in the current position
			{
				cards[boardPosition] = selectedCard;
				placed--;
				placeCard++;
			}
		}
	}
}

//---------------------------------------------------------------------------------
// Initializes game display varibles
void initializeDisplayData(char disp[], char masterDisp[])
{
	for (int i = 0; i < 10; i++)
	{
		disp[i] = '*';
		masterDisp[i] = '*';
	};
}

//---------------------------------------------------------------------------------
// display match message
void matchMessage()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	cout << "Congrats, you've made a match!!" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	system("pause");
	system("cls");
}

//---------------------------------------------------------------------------------
// display no match message
void noMatchMessage()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << "So sorry, no match for you.  :(" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	system("pause");
	system("cls");
}

//---------------------------------------------------------------------------------
// Outputs program title screen
void displayIntro()
{
	cout << "**************************************************" << endl;
	cout << "                   Welcome to                    *" << endl;
	cout << "               Awesome Concentration             *" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
	system("pause");
	system("cls");
}

//---------------------------------------------------------------------------------
// Outputs program credits
void displayCredits()
{
	system("cls");
	cout << "**************************************************" << endl;
	cout << "               Credits:                          *" << endl;
	cout << "               Hope you enjoyed :D               *" << endl;
	cout << "                                                 *" << endl;
	cout << "               By: Ruki                          *" << endl;
	cout << "**************************************************" << endl;
	cout << endl << endl;

	system("pause");
}

//---------------------------------------------------------------------------------
// Reveal all cards
void cheatMode(char cards[])
{
	cout << "CHEATER Board" << endl;
	cout << "-------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4)
		{
			cout << cards[i] << endl;
		}
		else
		{
			cout << cards[i] << " ";
		}
	}
	cout << endl << endl;
}

//---------------------------------------------------------------------------------
// Load saved scores data
void loadScoreData(string playerList[], int scores[], int& recordCount)
{
	ifstream inFile;

	inFile.open("scores.txt");
	if (inFile.is_open())
	{
		while (!inFile.eof() && recordCount < MAX_SCORES)
		{
			inFile >> playerList[recordCount] >> scores[recordCount];
			recordCount++;
		}
		inFile.close();
	}
	else
	{
		cout << "error loading file" << endl << endl;
		system("pause");
	}
}

//---------------------------------------------------------------------------------
// Output saved scores data
void outputScores(string const playerList[], int const scores[], int recordCount)
{
	system("cls");

	cout << left << setw(20) << "Player Name" << right << setw(10) << "Score" << endl;
	cout << "------------------------------" << endl;

		for (int i = 0; i < recordCount; i++)
	{
		cout << left << setw(20) << playerList[i] << right << setw(10) << scores[i] << endl;
	}
	cout << endl << endl;
	system("pause");
}

//---------------------------------------------------------------------------------
// Save scores a file
void saveDataToFile(string const playerList[], int const scores[], int recordCount)
{
	ofstream outFile;

	outFile.open("saved_scores.txt");
	if (outFile.is_open())
	{
		outFile << left << setw(20) << "Player Name" << right << setw(10) << "Score" << endl;
		outFile << "------------------------------" << endl;

		for (int i = 0; i < recordCount; i++)
		{
			outFile << left << setw(20) << playerList[i] << right << setw(10) << scores[i] << endl;
		}
		outFile.close();
	}
	else
	{
		cout << "error saving file" << endl << endl;
		system("pause");
	}

	cout << endl << endl;
	cout << "Data saved succesfully" << endl;
	cout << endl << endl;

	system("pause");
}

//----------------------------------------------------------------------------------
// Update data for players' names and scores. checks whether player exists, then add or modify existing data
void updateScore(string playerName, int attempts, string playerList[], int scores[], int& recordCount)
{
	int foundIndex = NOT_FOUND_INDEX;

	// search for player name. if player exists, update score.
	if (searchPlayerName(playerName, attempts, playerList, scores, recordCount, foundIndex))
	{
		scores[foundIndex] = attempts;
	}
	// if new player, add new entry
	else if (recordCount < MAX_SCORES)
	{
		playerList[recordCount] = playerName;
		scores[recordCount] = attempts;
		recordCount++;
	}
	// if max number of records reached, display warning.
	else
	{
		cout << "Maximum values reached, can not save more data.";
	}
}

//----------------------------------------------------------------------------------
// search for player name inside existing records. if does exist, return true. if doesn't, return false
bool searchPlayerName(string playerName, int attempts, const string playerList[], const int scores[], int recordCount, int& foundIndex)
{
	bool existingPlayer = false;

	for (int i = 0; i < recordCount; i++)
	{
		// search for player name. if does exist, store their index
		if (playerName == playerList[i])
		{
			foundIndex = i;
			existingPlayer = true;
			break;
		}
	}
	return existingPlayer;
}