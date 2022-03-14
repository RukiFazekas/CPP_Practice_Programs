/************************************************/
// Car class implementation
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include "carType.h"

using namespace std;

const int carType::MAX_HP = 100;

/***************************************************/
// function used to display the car's info
void carType::display() const
{
	cout << setw(20) << left << "Car Name:" << setw(20) << left << getName() << endl;
	cout << setw(20) << left << "Ram Damage:" << setw(20) << left << getRamStrength() << endl;

	setTextColour(getBodyDamage());
	cout << setw(20) << left << "Body Damage:" << setw(20) << left << getBodyDamage() << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	setTextColour(getHitPoints());
	cout << setw(20) << left << "Hit Points:" << setw(20) << left << getHitPoints() << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

/***************************************************/
// function to change text display color
void carType::setTextColour(int inValue) const
{
	if (inValue > 65 && inValue <= MAX_HP) // if true, changes to green
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	}
	else if (inValue > 35 && inValue <= 65) // if true, changes to yellow
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_RED | FOREGROUND_GREEN));
	}
	else if (inValue <= 35) // fi true, changes to red
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	}
}

/***************************************************/
// function to check if the car is alive or not
bool carType::isAlive() const
{
	if (getHitPoints() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*********************************************************************/
// function used to apply damage to a car's body damage or hit points
void carType::takeDamage(const int& inRamStrength)
{
	int remainingValue = MAX_HP;		// holds remaining hp or body damage value to be checked in if statement
	srand(time(NULL));

	if (getBodyDamage() > 0)		// checks if car still has body damage to be deducted
	{
		remainingValue = getBodyDamage() - rand() % ((inRamStrength + 1) / 2);  // attack between 0 and half ram str

		if (remainingValue > 0)	// checks if car body damage is not below 0 after taking damage. if it does, sets body damage to 0
		{
			setBodyDamage(remainingValue);
		}
		else
		{
			setBodyDamage(0);
			setHitPoints(getHitPoints() + remainingValue); // deduct remaining attack points (represented as a negative number) from hp
		}
	}
	else if (getHitPoints() > 0)
	{
		remainingValue = getHitPoints() - rand() % ((inRamStrength + 1)); // attack between 0 and full ram str

		if (remainingValue > 0) // checks if car hp is not below 0 after taking damage. if it does, sets hp to 0
		{
			setHitPoints(remainingValue);
		}
		else
		{
			setHitPoints(0);
		}
	}
}

/************************************************************************************************/
// function used to apply damage to a target car's body damage or hit points if target is alive
void carType::attackCar(carType& target)
{
	if (target.isAlive())
	{
		target.takeDamage(getRamStrength());
	}
}

/*********************************************************************************************/
// Parameterized constructor to initialize a car's info that was instantiated with parameters
carType::carType(string inName, int inRamStr, int inHp)
{
	setName(inName);
	setRamStrength(inRamStr);
	setBodyDamage(100);
	if (inHp > MAX_HP)
	{
		setHitPoints(MAX_HP);
	}
	else
	{
		setHitPoints(inHp);
	}
}

/******************************************************************************************/
// Default constructor to initialize a car's info that was instantiated with no parameters
carType::carType()
{
	setName("Default");
	setRamStrength(1);
	setHitPoints(MAX_HP);
}

/*******************/
// Destructor
carType::~carType() {};