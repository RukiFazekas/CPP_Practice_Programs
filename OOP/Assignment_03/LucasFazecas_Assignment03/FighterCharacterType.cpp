#include <iostream>
#include <iomanip>
#include <string>
#include "FighterCharacterType.h"

using namespace std;

// implementation methods for the Fighter class go here

string FighterCharacterType::weaponNames[5] = { "Not Specificied", "Dual Swords", "Katar", "Hammer", "Knuckles" };

void FighterCharacterType::Display() const
{
	string month;
	int day, year;

	createdDate.GetDate(month, day, year);

	cout << "Character Name:  " << name << endl;
	cout << "Character Level: " << level << endl;
	cout << "Character Health: " << health << endl;
	cout << "Character Experience: " << experience << endl;
	cout << "Melee Character Weapon: " << weaponNames[weapon] << endl;
	cout << "Melee Character Combo Level: " << comboLevel << endl;
	cout << "Melee Character Number of Kills: " << killScore << endl;
	cout << "Melee Character Created On: " << month << " " << setw(2) << setfill('0') << day << ", " << year << endl << endl;
}

// Parameterized constructor
FighterCharacterType::FighterCharacterType(string inName, int inLevel, int inCombo, WeaponType inWeapon, string inMonth,
	int inDay, int inYear) : CharacterType(inName, inLevel, inMonth, inDay, inYear)
{
	weapon = inWeapon;
	comboLevel = inCombo;
	killScore = 0;
}

// Default constructor
FighterCharacterType::FighterCharacterType() : CharacterType()
{
	weapon = NOT_SPECIFIED;
	comboLevel = 0;
	killScore = 0;
}