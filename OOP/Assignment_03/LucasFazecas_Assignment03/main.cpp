//------------------------------------------------------------------------------
// Author: Lucas Fazecas
// Purpose: Practice knowledge acquired of inheritance and aggregation by building
//			a combat system between characters
// Date: Feb 20, 2022
//------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include "main.h"
#include "DateType.h"
#include "CharacterType.h"
#include "FighterCharacterType.h"

using namespace std;

//------------------------------------------------------------------------------
void main()
{
	/*//CharacterType thor("Thor", 100);		// Remove this character once you have devloped the derived classes
	//thor.Display();

	cout << "\n\nStart by:\n1. Writing your date class\n2. Integrating it into the Character class\n3. Write the derived classes\n4. Uncomment the appropriate code as you move along to bring the battle to life!" << endl << endl;
	system("pause");*/

	MageCharacterType mageChar("Merlin", 1, 30, MageCharacterType::STAFF, "March", 3, 2021);		// Use parameterized constructors to initialize objects
	FighterCharacterType fighterChar("Brutus", 1, 3, FighterCharacterType::HAMMER, "January", 14, 2022);

	//// Display Initialized Character Data
	DisplayCharacterInformation(mageChar, fighterChar, "Intial Character Data: ");    

	//// Testing derived class
	TestMageClass(mageChar);  
	TestFighterClass(fighterChar);
	
	//// Display Final Character Data
	DisplayCharacterInformation(mageChar, fighterChar, "Final Character Data: ");     
}

//------------------------------------------------------------------------------
// Test Fighter Class
//------------------------------------------------------------------------------
void TestFighterClass(FighterCharacterType& fighter)
{
  cout << " *** Testing Fighter Class ***" << endl << endl;
  fighter.Display();
  system("pause");
  system("cls");

  // Update fighter Levels Based on Experience ( assume fighterChar is in battle )
  for (int i = 0; i < FIGHTER_SUCCESSFUL_COMBOS; i++)
  {
	  // Assume fighter character performs successful combos
	  cout << fighter.GetName() <<" succesfully completed combo!!!" << endl;
	  fighter.UpdateExperience(FIGHTER_EXP_COMBO_GAIN);
	  fighter.UpdateLevel();
  }

  // Display Fighter Character Data
  cout << endl;
  fighter.Display();
  system("pause");
  system("cls");

  // Assume fighterChar has killed 3 enemies
  cout << endl << endl << fighter.GetName() <<" has killed three enemies!" << endl;
  fighter.SetKillScore(3);

  // Assume fighter character takes a lot of damage and loses alot of health
  fighter.UpdateHealth(FIGHTER_HEALTH_LOSS);
  cout << fighter.GetName() << " is losing battle. Health is " <<  fighter.GetHealth() << " !!!" << endl;

  // Display fighter Character Data
  fighter.Display();
  system("pause");
  system("cls");
}

//------------------------------------------------------------------------------
// Test Mage Class
//------------------------------------------------------------------------------
void TestMageClass(MageCharacterType& mage)
{
  int mageLevelBefore =  mage.GetLevel(), totalMagicalDamageDealt = 0;

  cout << " *** Testing Mage Class ***" << endl << endl;
  mage.Display();
  system("pause");
  system("cls");

  // Update Mage Levels Based on Experience
  for (int i = 0; i < MAGE_SUCCESSFUL_CASTS; i++)
  {
	  // Assume Mage casts spell and does Magical Damage
	  cout << mage.GetName() <<" casts spell and does Magical Damage..." <<endl;
  
	  totalMagicalDamageDealt = mage.GetMagicDmg();
	  totalMagicalDamageDealt += MAGE_MAG_DAMAGE_DEALT;
	  mage.SetMagicDmg(totalMagicalDamageDealt);
	  mage.UpdateExperience(MAGE_EXP_GAIN);
	  mage.UpdateLevel();
  }
  
  // If Mage leveled up then get new weapon... 
  if (mageLevelBefore < mage.GetLevel())
  {
   // Use any weapon here you want
	  cout << endl << mage.GetName() <<" leveled up and gains GRIMOIRE weapon!!!" << endl << endl;
	  mage.SetWeapon(MageCharacterType::GRIMOIRE);
  }
  
  // Display Data
  cout << endl;
  mage.Display();
  system("pause");
  system("cls");
}

//------------------------------------------------------------------------------
// Display Character Data
//------------------------------------------------------------------------------
void DisplayCharacterInformation(MageCharacterType mageChar, FighterCharacterType fighterChar, string title)
{
  cout << title << endl;

  cout << endl;
  mageChar.Display();
  cout << endl;

  fighterChar.Display();
  system("pause");
  system("cls");
}