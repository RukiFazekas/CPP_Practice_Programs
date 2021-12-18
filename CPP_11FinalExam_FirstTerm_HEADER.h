#include <string>

using namespace std;
//----------------------------------------------------------------//
//	Constants													  //
//----------------------------------------------------------------//

const int MAX_SPELL = 20;

//----------------------------------------------------------------//
//	Function prototypes 										  //
//----------------------------------------------------------------//

void loadSpellData(string spellName[], int spellDuration[], int spellLevel[], int& spellCount);
void displaySpellData(const string spellName[], const int spellDuration[], const int spellLevel[], int spellCount);
void addNewSpellData(string spellName[], int spellDuration[], int spellLevel[], int& spellCount);
void displayLongestSpell(const string spellName[], const int spellDuration[], const int spellLevel[], int spellCount);
int longestSpellDuration(const int spellDuration[], int spellCount);
void saveSpellData(const string spellName[], const int spellDuration[], const int spellLevel[], int spellCount);

void ProfessorsMessage();
char GetMenuSelection(void);

