#include <iostream>
#include <iomanip>
#include <string>
#include "MageCharacterType.h"
#include "CharacterType.h"

using namespace std;

string MageCharacterType::weaponNames[5] = { "Not Specificied", "Wand", "Staff", "Grimoire", "Time Orb" };

void MageCharacterType::Display() const
{
	std::string month;
	int day, year;

	createdDate.GetDate(month, day, year);

	cout << "Character Name:  " << name << endl;
	cout << "Character Level: " << level << endl;
	cout << "Character Health: " << health << endl;
	cout << "Character Experience: " << experience << endl;
	cout << "Wizard Character Weapon: " << weaponNames[weapon] << endl;
	cout << "Wizard Character Magic Health: " << magicHealth << endl;
	cout << "Wizard Character Total Magic Damage: " << totalMagicDmg << endl;
	cout << "Wizard Character Created On: " << month << " " << setw(2) << setfill('0') << day << ", " << year << endl << endl;
}

// Parameterized constructor
MageCharacterType::MageCharacterType(string inName, int inLevel, int inMagicHealth, WeaponType inWeapon,
	string inMonth, int inDay, int inYear)
	: CharacterType(inName, inLevel, inMonth, inDay, inYear)
{
	weapon = inWeapon;
	magicHealth = inMagicHealth;
	totalMagicDmg = 0;
}

// Default constructor
MageCharacterType::MageCharacterType() : CharacterType()
{
	weapon = NOT_SPECIFIED;
	magicHealth = 0;
	totalMagicDmg = 0;
}