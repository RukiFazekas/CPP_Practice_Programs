#pragma once
#include <string>

using namespace std;

//-----------------------------------------------
// Program Constants 

const int TOTAL_MATCHES = 5;
const int MAX_SCORES = 20;
const int NOT_FOUND_INDEX = -1;

//-----------------------------------------------
// Enumerated Type

enum mainMenu {DEFAULT = -1, INSTRUCTIONS = 1, PLAY, DISPLAY, SAVE, EXIT = 9};

//-----------------------------------------------
// Function Prototypes
void initializeGameData(char card[]);
void initializeDisplayData(char disp[], char masterDisp[]);
void displayInstructions();
void displayIntro();
void displayCredits();
void displayBoard(char disp[]);
int getValidBoardPosition(char disp[], string playerName);
void matchMessage();
void noMatchMessage();
mainMenu gameMenu();
void playGame(string& playerName, int& attempts);
void cheatMode(char cards[]);
void loadScoreData(string playerList[], int scores[], int& recordCount);
void outputScores(string const playerList[], int const scores[], int recordCount);
void saveDataToFile(string const playerList[], int const scores[], int recordCount);
void updateScore(string playerName, int attempts, string playerList[], int scores[], int& recordCount);
bool searchPlayerName(string playerName, int attempts, const string playerList[], const int scores[], int recordCount, int& foundIndex);
