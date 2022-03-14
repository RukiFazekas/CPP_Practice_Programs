#pragma once

#include <string>
#include "CharacterType.h"

using namespace std;

// Class definition for the Mage Character

class MageCharacterType : public CharacterType
{
public:
	static enum WeaponType { NOT_SPECIFIED, WAND, STAFF, GRIMOIRE, TIME_ORB };
	static string weaponNames[5];

private:
	WeaponType weapon;
	int magicHealth;
	int totalMagicDmg;

public:
	void SetWeapon(WeaponType inWeapon) { weapon = inWeapon; }
	WeaponType GetWeapon() const { return weapon; }
	void SetMagicHealth(int inMagicHealth) { magicHealth = inMagicHealth; }
	int GetMagicHealth() const { return magicHealth; }
	void SetMagicDmg(int inMagicDmg) { totalMagicDmg = inMagicDmg; }
	int GetMagicDmg() const { return totalMagicDmg; }
	void Display() const;

	MageCharacterType(string inName, int inLevel, int inMagicHealth, WeaponType inWeapoN,
		string inMonth, int inDay, int inYear);

	MageCharacterType();
};