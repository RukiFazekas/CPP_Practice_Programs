/*********************************************************************************************************
Author:      Lucas Fazecas
Title:       Assignment 6
Purpose:     To develop a program that will track sales information using User Defined Functions
Date:  November 13th, 2021
*********************************************************************************************************/

#include <iostream>
#include <iomanip>
#include "main.h" // header file for User Define Function

using namespace std;

int main()
{
	int userChoice = -1, soldSingleA = 0, soldDoubleA = 0, soldTripleA = 0, allGameSold = 0;
	float totalMoney = 0.00f, runningSale = 0.00f;

	displayIntroScreen(); // function to display store's intro and logo

	while (userChoice != 9) // flag while to check user's choice
	{
		userChoice = mainMenu(); // function to display main menu options for user to choose

		if (userChoice != 9) // check user's choice to display option accordingly
		{
			switch (userChoice)
			{
			case 1:
				sellGame(soldSingleA, soldDoubleA, soldTripleA, totalMoney, runningSale); // functions for user to buy games
				break;
			case 2:
				earnedMoney(totalMoney); // function to check total money made
				break;
			case 3:
				totalGameSold(allGameSold); // function to check all games that were sold
				break;
			case 4:
				gameCount(soldSingleA, soldDoubleA, soldTripleA); // function to check all games that were sold according to type
				break;
			case 5:
				salesInfo(totalMoney, allGameSold, soldSingleA, soldDoubleA, soldTripleA); // function to display all sale information according to functions above from case 2 to 4
				break;
			}
		}
	}
	system("pause");
	return 0;
}

void displayIntroScreen()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "|         Welcome to Gecko's Gaming Store!         |" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                        ___           .--.          " << endl;
	cout << "                       (   )          |  |          " << endl;
	cout << "    .--.   .--.   .--.  | |   ___  .--'..'  .--.    " << endl;
	cout << "   /    \\ /    \\ /    \\ | |  (   )/    \\  /  _  \\    " << endl;
	cout << "  ;  ,-. |  .-. |  .-. ;| |  ' / |  .-. ;. .' `. ;  " << endl;
	cout << "  | |  | |  | | |  |(___| |,' /  | |  | || '   | |  " << endl;
	cout << "  | |  | |  |/  |  |    | .  '.  | |  | |_\\_`.(___) " << endl;
	cout << "  | |  | |  ' _.|  | ___| | `. \\ | |  | (   ). '.   " << endl;
	cout << "  | '  | |  .'.-|  '(   | |   \\ \\| '  | || |  `\\ |  " << endl;
	cout << "  '  `-' '  `-' '  `-' || |    \\ '  `-' /; '._,' '  " << endl;
	cout << "   `.__. |`.__.' `.__,'(___) (___`.__.'  '.___.'   " << endl;
	cout << "   ( `-' ;                                          " << endl;
	cout << "    `.__.                                           " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

	system("pause");
	system("cls");
}

int mainMenu()
{
	bool exit = false;
	int userEntry = -1;

	system("cls");

	while(!exit)
	{
		cout << "-------------------- - Main Menu-----------------------" << endl;
		cout << "1 : Enter 1 to sell a game." << endl;
		cout << "2 : Enter 2 to check the total money made up to this time." << endl;
		cout << "3 : Enter 3 to check the total amount of games sold up to this time." << endl;
		cout << "4 : Enter 4 to check the number of game types sold." << endl;
		cout << "5 : Enter 5 to check all sales information." << endl;
		cout << "9 : Enter 9 to exit the program." << endl << endl;

		cout << "Selection: ";
		cin >> userEntry;
		cout << endl;

		switch(userEntry)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 9:
			exit = true;
			break;
		default:
			cout << "Invalid input. Please, check the menu options again." << endl << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return userEntry;
}

void sellGame(int& soldSingleA, int& soldDoubleA, int& soldTripleA, float& totalMoney, float& runningSale)
{
	int userBuyChoice = -1;
	const float SINGLE_A = 10.99f, DOUBLE_A = 20.99f, TRIPLE_A = 40.99f; // game prices according to type

	system("cls");

	while (userBuyChoice != 9)
	{
		userBuyChoice = gameMenu(runningSale);
		int numSingleA, numDoubleA, numTripleA;

		if (userBuyChoice != 9)
		{
			switch (userBuyChoice)
			{
			case 1:
				cout << "Enter the number of Single A Games: ";
				cin >> numSingleA;
				soldSingleA += numSingleA;
				totalMoney += (numSingleA * SINGLE_A);
				runningSale += (numSingleA * SINGLE_A);
				break;
			case 2:
				cout << "Enter the number of Double A Games: ";
				cin >> numDoubleA;
				soldDoubleA += numDoubleA;
				totalMoney += (numDoubleA * DOUBLE_A);
				runningSale += (numDoubleA * DOUBLE_A);
				break;
			case 3:
				cout << "Enter the number of Double A Games: ";
				cin >> numTripleA;
				soldTripleA += numTripleA;
				totalMoney += (numTripleA * TRIPLE_A);
				runningSale += (numTripleA * TRIPLE_A);
				break;
			}
		}
	}
	if (userBuyChoice == 9)
	{
		if (runningSale != 0)
		{
			cout << fixed << setprecision(2);
			cout << "Please, pay $" << runningSale << endl << endl;
			runningSale = 0;

			system("pause");
			system("cls");
		}
	}
}

int gameMenu(float currentSale)
{
	bool exit = false;
	int userEntry = -1;

	system("cls");

	while (!exit)
	{
		cout << "--------------------- Game Menu -----------------------" << endl;
		cout << "1 : Enter 1 to buy a Single A game." << endl;
		cout << "2 : Enter 2 to buy a Double A game." << endl;
		cout << "3 : Enter 3 to buy a Triple A game." << endl;
		cout << "9 : Enter 9 to return to the main menu." << endl << endl;

		cout << fixed << setprecision(2);
		cout << "Current total: $" << currentSale << endl << endl;

		cout << "Selection: ";
		cin >> userEntry;
		cout << endl;

		switch (userEntry)
		{
		case 1:
		case 2:
		case 3:
		case 9:
			exit = true;
			break;
		default:
			cout << "Invalid input. Please, check the menu options again." << endl << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return userEntry;
}

void earnedMoney(float totalMoney)
{
	cout << fixed << setprecision(2);
	cout << "Total money made : $" << totalMoney << endl;
	
	system("pause");
}

void totalGameSold(int allGameSold)
{
	cout << "Total games sold : " << allGameSold << endl;

	system("pause");
}

void gameCount(int soldSingleA, int soldDoubleA, int soldTripleA)
{
	cout << "Single A sold : " << soldSingleA << endl;
	cout << "Double A sold : " << soldDoubleA << endl;
	cout << "Triple A sold : " << soldTripleA << endl;

	system("pause");
}

void salesInfo(float totalMoney, int allGameSold, int soldSingleA, int soldDoubleA, int soldTripleA)
{
	cout << fixed << setprecision(2);
	cout << "Total money made : $" << totalMoney << endl;
	cout << "Total games sold : " << allGameSold << endl;
	cout << "Single A sold : " << soldSingleA << endl;
	cout << "Double A sold : " << soldDoubleA << endl;
	cout << "Triple A sold : " << soldTripleA << endl;

	system("pause");
}