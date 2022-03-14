#include <iostream>
#include <string>
#include "CharacterType.h"
#include "DateType.h"

using namespace std;

//------------------------------------------------------------------------------------
CharacterType::CharacterType() : createdDate()
{
	name = "";
	level = 0;
	health = MAX_HEALTH;
	experience = 0;
}

//------------------------------------------------------------------------------------
CharacterType::CharacterType(string inName, int inLevel, string inMonth, int inDay, int inYear ) : createdDate(inMonth, inDay, inYear)
{
	name = inName;
	level = inLevel;
	health = MAX_HEALTH;
	experience = 0;
	createdDate.SetDate(inMonth, inDay, inYear);
}

//------------------------------------------------------------------------------------
CharacterType::~CharacterType()
{
}

//------------------------------------------------------------------------------------
void CharacterType::LevelDecrease()
{
	if (level > 1)
		level--;
}

//------------------------------------------------------------------------------------
void CharacterType::Display()
{
	cout << "Character Name:  " << name << endl;
	cout << "Character Level: " << level << endl;
	cout << "Character Health: " << health << endl;
	cout << "Character Experience: " << experience << endl;
}

//------------------------------------------------------------------------------------
void CharacterType::UpdateHealth(int inHealthInc)
{
	health += inHealthInc;
	if (health < 0)
	{
		health = 0;
	}
	else if (health > MAX_HEALTH)
	{
		health = MAX_HEALTH;
	}
}

//------------------------------------------------------------------------------------
//
// UpdateExperience( int inExpInc  )
//
// UpdateExperience increases the experience variable of the character and will 
// level up the character as experience reaches certain levels.
//
void CharacterType::UpdateExperience(int inExpInc)
{
	//Only update experience if we are gaining experience
	if (inExpInc > 0)
	{
		experience += inExpInc;
		if (experience < 0)
		{
			experience = 0;
		}
		else if (experience >= MAX_EXPERIENCE)
		{
			experience = MAX_EXPERIENCE;
		}
		/*else if (experience < MAX_EXPERIENCE && experience > 0)
		{
			experience += inExpInc;
		}*/
	}
}

//------------------------------------------------------------------------------------
//
// UpdateLevel( )
//
// UpdateLevel sets the level variable to match the character's experience value
//
void CharacterType::UpdateLevel()
{
	int level = (experience / EXP_LEVEL_THRESHOLD) + 1;

	if (level > MAX_CHAR_LEVELS)
		SetLevel(MAX_CHAR_LEVELS);
	else
		SetLevel(level);
}