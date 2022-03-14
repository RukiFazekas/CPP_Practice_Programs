#pragma once

#include <string>
#include "DateType.h"

using namespace std;

class CharacterType
{
public:
    //CONSTANTS
    static const int MAX_EXPERIENCE = 1000;  // max experience value
    static const int MAX_HEALTH = 100;   // max health value
    static const int EXP_LEVEL_THRESHOLD = 20;    // experience level threshold value ( every 20 experience points increments level )
    static const int MAX_CHAR_LEVELS = MAX_EXPERIENCE / EXP_LEVEL_THRESHOLD; // max character level

protected:
    string	name;
    int		level;
    int		experience;
    int		health;

    DateType createdDate;

public:

    // Accessor Functions
    void SetHealth(int inValue) { health = inValue; }
    int GetHealth() const { return health; }

    void SetExperience(int inValue) { experience = inValue; }
    int GetExperienceh() const { return experience; }

    void SetName(string inValue) { name = inValue; }
    string GetName() const { return name; }

    void SetLevel(int inLevel) { level = inLevel; }
    int GetLevel() const { return level; }

    // General Class Functions

    void UpdateLevel();

    void LevelIncrease() { level++; }
    void LevelDecrease();

    void UpdateHealth(int inHealthInc);
    void UpdateExperience(int inExpInc);

    void Display();

    // Constructors
    CharacterType();
    CharacterType(string inName, int inLevel, string inMonth, int inDay, int inYear);

    // Destructor
    ~CharacterType();

};
