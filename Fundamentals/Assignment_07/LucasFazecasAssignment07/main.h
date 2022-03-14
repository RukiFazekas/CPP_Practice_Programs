#pragma once

void displayIntro();
int gameMenu();
void playGame();
void initializeGameData(char& c1, char& c2, char& c3, char& c4, char& c5, char& c6);
void initializeGameDisplay(char& disp1, char& disp2, char& disp3, char& disp4, char& disp5, char& disp6, char masterDisp1, char masterDisp2, char masterDisp3, char masterDisp4, char masterDisp5, char masterDisp6);
void displayInstruction();
void displayBoard(char disp1, char disp2, char disp3, char disp4, char disp5, char disp6);
int getValidBoardPosition(char currentDisp1, char currentDisp2, char currentDisp3, char currentDisp4, char currentDisp5, char currentDisp6);
void matchMessage();
void noMatchMessage();
void displayCredits();