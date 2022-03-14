// --------------------------------------------------------------- //
// gameObjectType.cpp -- implementation file					   //
// --------------------------------------------------------------- //

#include <iostream>
#include <iomanip>
#include "gameObjectType.h"

int gameObjectType::objectCount = 0;

void gameObjectType::display() const
{
	cout << "-------------------------------------------------------------" << endl;
	cout << setw(18) << left << "Object Name: " << setw(10) << left << name << endl;
	cout << setw(18) << left << "Object World: " << setw(10) << left << world << endl;
	cout << setw(18) << left << "Object Position: " << "(" << xPosition << ", " << yPosition << ")" << endl;
	cout << "-------------------------------------------------------------" << endl << endl;
}

bool gameObjectType::equal(gameObjectType& compareTarget) const
{
	if (xPosition == compareTarget.xPosition && yPosition == compareTarget.yPosition)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Parameterized constructor
gameObjectType::gameObjectType(string inName, int inWorld, float inXPos, float inYPos)
{
	name = inName;
	world = inWorld;
	xPosition = inXPos;
	yPosition = inYPos;
	objectCount++;
}

// Default constructor
gameObjectType::gameObjectType()
{
	name = "Unknown";
	world = -1;
	xPosition = 0.0f;
	yPosition = 0.0f;
	objectCount++;
}

// Destructor
gameObjectType::~gameObjectType()
{
	cout << "Object no longer exists..." << endl << endl;
	objectCount--;
}