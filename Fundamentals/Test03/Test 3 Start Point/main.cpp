//----------------------------------------------------------------//
//	Author: Lucas Fázecas           							  //
//  Purpose: Test 3                  							  //
//  Date: Dec 12, 2021              							  //
//----------------------------------------------------------------//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "main.h"

using namespace std;

//----------------------------------------------------------------//
// Main function...
int main()
{
	string spellName[MAX_SPELL];
	int spellDuration[MAX_SPELL];
	int spellLevel[MAX_SPELL];
	int spellCount = 0;
	char menuSelection;
	bool noExit = true;

	ProfessorsMessage();

	loadSpellData(spellName, spellDuration, spellLevel, spellCount);

	while (noExit)
	{
		menuSelection = GetMenuSelection();
		if (menuSelection == 'A')
		{
			displaySpellData(spellName, spellDuration, spellLevel, spellCount);
		}
		else if (menuSelection == 'B')
		{
			addNewSpellData(spellName, spellDuration, spellLevel, spellCount);
		}
		else if (menuSelection == 'C')
		{
			displayLongestSpell(spellName, spellDuration, spellLevel, spellCount);
		}
		else if (menuSelection == 'D')
		{
			saveSpellData(spellName, spellDuration, spellLevel, spellCount);
		}
		else if (menuSelection == 'X')
		{
			noExit = false;
			system("cls");
			cout << endl << "Happy Holidays!!" << endl << endl;
		}
		system("pause");
		system("cls");
	}
}

//------------------------------------------------------------------------
// Displays the menu and returns the validated user selection
char GetMenuSelection(void)
{
	bool exit = false;
	char entry;

	do
	{
		cout << "-------------------------------------------------------" << endl;
		cout << "														" << endl;
		cout << "  A. Display Spell Information							" << endl;
		cout << "  B. Add New Spell Information							" << endl;
		cout << "  C. Display Spell with Longest Duration				" << endl;
		cout << "  D. Save Spell Data to Disk                   " << endl;
		cout << "  X. Exit Program                                    " << endl;
		cout << "                                                     " << endl;
		cout << "-----------------------------------------------------" << endl << endl;

		cout << "Please enter a menu selection>> ";
		cin >> entry;
		entry = toupper(entry);

		if ((entry >= 'A' && entry <= 'D') || entry == 'X')
		{
			exit = true;
		}
		else
		{
			cout << endl << "Please enter a valid menu option (A-D or X) " << endl << endl;
			system("pause");
			system("cls");
		}
	} while (!exit);

	cout << endl;
	return entry;
}


//----------------------------------------------------------------------------------------------------------------
// Displays the Professors message
void ProfessorsMessage()
{
	string messagePart1 = "Woot Woot Woot Woot Woo";
	string messagePart2 = "t!!";

	cout << "Last class today... Woot Woot!" << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << messagePart1 + messagePart2  << endl;
		messagePart1 += "o";
	}

	cout << endl;
	system("pause");
	system("cls");
}

//--------------------------------------------------------------------
// Loads the spell data from the file into the arrays
void loadSpellData(string spellName[], int spellDuration[], int spellLevel[], int& spellCount)
{
	ifstream inFile;

	inFile.open("SpellDataInput.txt");
	if (inFile.is_open())
	{
		while (!inFile.eof() && spellCount < MAX_SPELL)
		{
			inFile >> spellName[spellCount] >> spellDuration[spellCount] >> spellLevel[spellCount];
			spellCount++;
		}
		inFile.close();
	}
	else
	{
		cout << "Error loading spell data input file" << endl;
	}
}

//-------------------------------------------------------------------
// Displays all spells
void displaySpellData(const string spellName[], const int spellDuration[], const int spellLevel[], int spellCount)
{
	system("cls");

	
	cout << "------------- Spell List ---------------" << endl;
	cout << left << setw(20) << "Spell" << right << setw(10) << "Duration" << right << setw(10) << "Level" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < spellCount; i++)
	{
		cout << left << setw(20) << spellName[i] << right<< setw(10) << spellDuration[i] << right << setw(10) << spellLevel[i] << endl;
	}
	cout << endl;
}

//-------------------------------------------------------------------
// Adds new spell data
void addNewSpellData(string spellName[], int spellDuration[], int spellLevel[], int& spellCount)
{
	system("cls");

	if (spellCount < MAX_SPELL)
	{
		cout << "Please, enter spell name: ";
		cin >> spellName[spellCount];
		cout << "Please enter spell duration:  ";
		cin >> spellDuration[spellCount];
		cout << "Please enter spell Level: ";
		cin >> spellLevel[spellCount];
		spellCount++;

		cout << endl << endl << "New spell data added." << endl << endl;
	}
	else
	{
		cout << "Maximum number of spells reached." << endl << endl;
	}
}

//-------------------------------------------------------------------
// Displays spell with longest duration
void displayLongestSpell(const string spellName[], const int spellDuration[], const int spellLevel[], int spellCount)
{
	int longestSpell = longestSpellDuration(spellDuration, spellCount);

	system("cls");

	cout << "------ Spell with Longest Duration ------" << endl;
	cout << left << setw(20) << "Spell" << right << setw(10) << "Duration" << right << setw(10) << "Level" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < spellCount; i++)
	{
		if (spellDuration[i] == longestSpell)
		{
			cout << left << setw(20) << spellName[i] << right << setw(10) << spellDuration[i] << right << setw(10) << spellLevel[i] << endl;
		}
	}
	cout << endl;
}

//---------------------------------------------------------------------------------
// Determines the longest spell duration in all the spell data and return the duration
int longestSpellDuration(const int spellDuration[], int spellCount)
{
	int longestDuration = spellDuration[0];

	for (int i = 1; i < spellCount; i++)
	{
		if (longestDuration < spellDuration[i])
			longestDuration = spellDuration[i];
	}

	return longestDuration;
}

//-------------------------------------------------------------------
// Saves the spell data
void saveSpellData(const string spellName[], const int spellDuration[], const int spellLevel[], int spellCount)
{
	system("cls");

	ofstream outFile;

	outFile.open("SpellDataOutput.txt");
	if (outFile.is_open())
	{
			outFile << "------------- Spell List ---------------" << endl;
			outFile << left << setw(20) << "Spell" << right << setw(10) << "Duration" << right << setw(10) << "Level" << endl;
			outFile << "----------------------------------------" << endl;

			for (int i = 0; i < spellCount; i++)
			{
				outFile << left << setw(20) << spellName[i] << right << setw(10) << spellDuration[i] << right << setw(10) << spellLevel[i] << endl;
			}
		cout << "Spell data saved succesfully" << endl << endl;
	}
	else
	{
		cout << "Error saving spell data" << endl;
	}
}