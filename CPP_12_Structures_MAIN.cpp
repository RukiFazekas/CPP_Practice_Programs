//---------------------------------------------------------------------------
// Title:   Assignment 01
// Purpose: Read/Write from a file using structs with a simple menu system
// Author:  Lucas Fazecas
// Date:	Jan 23, 2022
//----------------------------------------------------------------------------
#include <iostream>
#include <iomanip> 
#include <fstream>
#include "main.h"

using namespace std;

int main()
{
	characterCollectionType characterCollection;	// this includes an array of characterType

	menuType choice = DEFAULT;

	if (loadCharacterInformation(characterCollection))
	{
		while (choice != EXIT)
		{
			choice = menu();		// Call the functin "menu" in order to get the user input

			switch (choice)			// check the user's choice and then call the appropriate function
			{
			case DISPLAY_CHAR_INFO:
				displayCharacterInformation(characterCollection);
				break;
			case ADD_NEW_CHAR:
				addNewCharacter(characterCollection);
				break;
			case DISPLAY_HEALTH:
				displayHighLow(characterCollection);
				break;
			case DISPLAY_CHAR_TYPE:
				displayCharacterByType(characterCollection);
				break;
			case SAVE_CHAR:
				saveCharacterInformation(characterCollection);
				break;
			case EXIT:
				cout << "Exiting from program...\n\n";
				break;
			}
			system("pause");
			system("cls");
		}
	}
	return 0;
}

//----------------------------------------------------------------------
// Menu function: Outputs the menu items, grabs the user input 
// and checks for a valid menu selection
//----------------------------------------------------------------------
menuType menu()
{
	bool exit = false;		// flag for the while loop
	int selection = -1;		// user selection

	while (!exit)
	{
		cout << "1: Display Character Information" << endl;			// show the menu items
		cout << "2: Add New Character" << endl;
		cout << "3: Display Highest and Lowest by Health" << endl;
		cout << "4: Display Character by Type" << endl;
		cout << "5: Save Character Data to Disk" << endl;
		cout << "9: Exit the program" << endl << endl;
		cout << "Enter your choice: ";
		cin >> selection;

		switch (selection)			// check the selection to make sure it's valid
		{
		case DISPLAY_CHAR_INFO:
		case ADD_NEW_CHAR:
		case DISPLAY_HEALTH:
		case DISPLAY_CHAR_TYPE:
		case SAVE_CHAR:
		case EXIT:
			exit = true;
			break;
		default:
			cout << "You've entered an invalid selection, please enter a 1 - 5 or 9" << endl;
			system("pause");
			break;
		}
		cout << endl;
	}
	return static_cast<menuType>(selection);  // return the selection value 
}

//---------------------------------------------------------------------------------------
// Display Character Infomation function: Outputs all the info (name, type and health)
// for each character cointaned in the characters array
//---------------------------------------------------------------------------------------

void displayCharacterInformation(characterCollectionType collection)
{
	system("cls");

	cout << setw(10) << left << "Character" << setw(5) << left << "Type" << setw(6) << "Health\n";
	cout << "---------------------\n";

	for (int i = 0; i < collection.characterCount; i++)		// loops through the entire array to display all characters info
	{
		cout << setw(10) << left << collection.characters[i].name;
		cout << setw(5) << left << collection.characters[i].type;
		cout << setw(6) << left << collection.characters[i].health << endl;
	}
	cout << endl << endl;
}

//---------------------------------------------------------------------------------------
// Add New Character function: asks for user input to add a new character information
// and stores it in characters array
//---------------------------------------------------------------------------------------
void addNewCharacter(characterCollectionType& collection)
{
	system("cls");
	bool properInput = false;		// flag for while loop
	char userTypeInput = ' ';		// variable to hold user input on character type and compare if it is valid

	if (collection.characterCount < MAX_CHARACTERS)
	{
		cout << "Please, add the new character information.\n";
		cout << "Name: ";
		cin >> collection.characters[collection.characterCount].name;

		while (!properInput)
		{
			cout << "Type is (R)anged or (M)elee: ";
			cin >> userTypeInput;
			
			if (islower(userTypeInput))		// converts user input to upper case if it is lower case
			{
				userTypeInput = toupper(userTypeInput);
			}

			if (userTypeInput == 'R' || userTypeInput == 'M') // checks if user has entered a valid character type
			{
				collection.characters[collection.characterCount].type = userTypeInput;
				properInput = true;
				break;
			}
			else
			{
				cout << "Please, enter a valid Type (R or M)\n";
			}
		}

		cout << "Health: ";
		cin >> collection.characters[collection.characterCount].health;

		collection.characterCount++;

		cout << endl << endl << "Character added succesfully." << endl << endl;
	}
	else
	{
		cout << "Cannot add more characters. Maximum capacity reached";
	}
}

//-------------------------------------------------------------------------------------------
// Display High Low function: display characters with the highest and lowest health values
//-------------------------------------------------------------------------------------------
void displayHighLow(characterCollectionType collection)
{
	system("cls");

	int highestHealthValue = highestHealth(collection);
	int lowestHealthValue = lowestHealth(collection);

	cout << "Highest Health Characters\n";
	cout << "-------------------------\n";
	for (int i = 0; i < collection.characterCount; i++)
	{
		if (collection.characters[i].health == highestHealthValue)
		{
			cout << setw(10) << left << collection.characters[i].name;
			cout << setw(5) << left << collection.characters[i].type;
			cout << setw(6) << left << collection.characters[i].health << endl;
		}
	}
	cout << endl << endl;

	cout << "Lowest Health Characters\n";
	cout << "-------------------------\n";
	for (int i = 0; i < collection.characterCount; i++)
	{
		if (collection.characters[i].health == lowestHealthValue)
		{
			cout << setw(10) << left << collection.characters[i].name;
			cout << setw(5) << left << collection.characters[i].type;
			cout << setw(6) << left << collection.characters[i].health << endl;
		}
	}
	cout << endl << endl;
}

//--------------------------------------------------------------------------------------------------------------
// Highest Health function: determines the highest health value in all character records and returns its value
//--------------------------------------------------------------------------------------------------------------
int highestHealth(characterCollectionType collection)
{
	int highest = collection.characters[0].health;		// sets the first character in the array as the highest health

	for (int i = 0; i < collection.characterCount; i++)		// scans the array for the highest health value
	{
		if (collection.characters[i].health > highest) 
		{
			highest = collection.characters[i].health;
		}
	}

	return highest;
}

//--------------------------------------------------------------------------------------------------------------
// Lowest Health function: determines the lowest health value in all character records and returns its value
//--------------------------------------------------------------------------------------------------------------
int lowestHealth(characterCollectionType collection)
{
	int lowest = collection.characters[0].health;		// sets the first character in the array as the lowest health

	for (int i = 0; i < collection.characterCount; i++)		// scans the array for the highest health value
	{
		if (collection.characters[i].health < lowest)
		{
			lowest = collection.characters[i].health;
		}
	}

	return lowest;
}

//-------------------------------------------------------------------------------------------
// Display Character By Type function: gets user input to display desired character type
//-------------------------------------------------------------------------------------------
void displayCharacterByType(characterCollectionType collection)
{
	system("cls");

	char userInput = ' ';

	cout << "Please, enter the character type you would like to have displayed (R or M): ";
	cin >> userInput;
	cout << endl << endl;

	if (islower(userInput))		// converts user input to upper case if it is lower case
	{
		userInput = toupper(userInput);
	}

	if (userInput == 'R')		// checks user choice and outputs accordingly
	{
		cout << "Results for R Character Type\n";
		cout << "-----------------------------\n";
		for (int i = 0; i < collection.characterCount; i++)
		{
			if (collection.characters[i].type == 'R')
			{
				cout << setw(10) << left << collection.characters[i].name;
				cout << setw(5) << left << collection.characters[i].type;
				cout << setw(6) << left << collection.characters[i].health << endl;
			}
		}
	}
	else if (userInput == 'M')
	{
		cout << "Results for M Character Type\n";
		cout << "-----------------------------\n";
		for (int i = 0; i < collection.characterCount; i++)
		{
			if (collection.characters[i].type == 'M')
			{
				cout << setw(10) << left << collection.characters[i].name;
				cout << setw(5) << left << collection.characters[i].type;
				cout << setw(6) << left << collection.characters[i].health << endl;
			}
		}
	}
	cout << endl << endl;
}

//---------------------------------------------------------------------------------------------
// Load Character Information function: reads data from a file on the disk into the structure
//---------------------------------------------------------------------------------------------
bool loadCharacterInformation(characterCollectionType& collection)
{
	ifstream inFile;
	int recordCount = 0;		// variable to keep track of number of records loaded into the structure

	inFile.open(FILE_NAME);		// opens file
	if (inFile.is_open())				// check if file is open
	{
		while (!inFile.eof() && recordCount < MAX_CHARACTERS)	// loads data until it's not in the end of file and maximum number of records haven't been reached
		{
			inFile >> collection.characters[recordCount].name >> collection.characters[recordCount].type >> collection.characters[recordCount].health;
			recordCount++;
		}
		collection.characterCount = recordCount;
		inFile.close();			// closes file
		return true;
	}
	else	// error message if task above fails
	{
		cout << "Error when loading data. exiting from program...\n\n";
		system("pause");
		return false;		
	}
}

//-------------------------------------------------------------------------------------------------------
// Save Character Information function: writes current characters info from the structure into the disk 
//-------------------------------------------------------------------------------------------------------
void saveCharacterInformation(characterCollectionType collection)
{
	ofstream outFile;

	outFile.open(FILE_NAME);
	if (outFile.is_open())
	{
		for (int i = 0; i < collection.characterCount; i++)
		{
			outFile << collection.characters[i].name << " " << collection.characters[i].type << " " << collection.characters[i].health;
			if (i + 1 != collection.characterCount)		// checks if it isnt the last character record then adds new line entry
			{
				outFile << endl;
			}
		}
		cout << "Data saved succesfully!\n\n";
	}
	else
	{
		cout << "Error saving data...\n\n";
	}
}