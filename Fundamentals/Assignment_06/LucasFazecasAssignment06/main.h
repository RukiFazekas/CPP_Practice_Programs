#pragma once

void displayIntroScreen();
int mainMenu();
void sellGame(int& soldSingleA, int& soldDoubleA, int& soldTripleA, float& totalMoney, float& runningSale);
int gameMenu(float currentSale);
void earnedMoney(float totalMoney);
void totalGameSold(int allGameSold);
void gameCount(int soldSingleA, int soldDoubleA, int soldTripleA);
void salesInfo(float totalMoney, int allGameSold, int soldSingleA, int soldDoubleA, int soldTripleA);