#pragma once

#include <string>
#include "CharacterType.h"

using namespace std;

// class definition for the Fighter character
class FighterCharacterType : public CharacterType
{
public:
	static enum WeaponType { NOT_SPECIFIED, DUAL_SWORDS, KATAR, HAMMER, KNUCKLES };
	static string weaponNames[5];

private:
	WeaponType weapon;
	int comboLevel;
	int killScore;

public:
	void SetWeapon(WeaponType inWeapon) { weapon = inWeapon; }
	WeaponType GetWeapon() const { return weapon; }
	void SetComboLevel(int inComboLevel) { comboLevel = inComboLevel; }
	int GetComboLevel() const { return comboLevel; }
	void SetKillScore(int inKillScore) { killScore = inKillScore; }
	int GetKillScore() const { return killScore; }
	void Display() const;

	FighterCharacterType(string inName, int inLevel, int inCombo, WeaponType inWeapon, string inMonth, int inDay, int inYear);

	FighterCharacterType();

};
