#include "CharacterType.h"
#include "FighterCharacterType.h"
#include "MageCharacterType.h"

// Uncomment prototypes below as you develop the derived classes
//--------------------------------------------------------
void DisplayCharacterInformation(MageCharacterType mageChar, FighterCharacterType fighterChar, string title);
void TestMageClass(MageCharacterType& mage);
void TestFighterClass(FighterCharacterType& fighter);

//Mage TEST CONSTANTS
const int MAGE_SUCCESSFUL_CASTS = 5;
const int MAGE_EXP_GAIN = 10;
const int MAGE_MAG_DAMAGE_DEALT = 10;

//Fighter TEST CONSTANTS
const int FIGHTER_SUCCESSFUL_COMBOS = 4;
const int FIGHTER_EXP_COMBO_GAIN = 20;
const int FIGHTER_HEALTH_LOSS = -65;
