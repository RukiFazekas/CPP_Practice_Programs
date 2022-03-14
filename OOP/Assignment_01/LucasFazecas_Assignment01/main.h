#pragma once

using namespace std;

/*********************************************/
// Constant variables
/*********************************************/

const int MAX_CHARACTERS = 20;		// max number of character records
const string FILE_NAME = "CharacterInfo.txt";

/*********************************************/
// Structures
/*********************************************/

struct characterType
{
	string name;
	char type;		// character can be meele (M) or ranged (R)
	int health;
};

struct characterCollectionType
{
	characterType characters[MAX_CHARACTERS];
	int characterCount = 0;		// keeps track of current number of character records
};

/*********************************************/
// Enumerated Types
/*********************************************/

enum menuType { DEFAULT = -1, DISPLAY_CHAR_INFO = 1, ADD_NEW_CHAR, DISPLAY_HEALTH, DISPLAY_CHAR_TYPE, SAVE_CHAR, EXIT = 9 };


/*********************************************/
// Functions Prototypes
/*********************************************/

menuType menu();
void displayCharacterInformation(characterCollectionType collection);
void addNewCharacter(characterCollectionType& collection);
void displayHighLow(characterCollectionType collection);
int highestHealth(characterCollectionType collection);
int lowestHealth(characterCollectionType collection);
void displayCharacterByType(characterCollectionType collection);
bool loadCharacterInformation(characterCollectionType& collection);
void saveCharacterInformation(characterCollectionType collection);