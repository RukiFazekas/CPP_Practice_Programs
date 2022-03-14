/*************************************************************/
// Author: Lucas Fazecas
// Purpose: create a battle race game using classes
// Date: Feb 6, 2022
/*************************************************************/

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <ctime>
#include "CarType.h"
#include "main.h"

using namespace std;

//---------------------------------------------------------------------------
int main()
{
	carType car1("Lightning McQueen", 10, 100);  // use parameterized constructor to initialize first car 
	carType car2;

	car2.setName("Chick Hicks");				// use set functions to set information on second car
	car2.setRamStrength(15);
	car2.setBodyDamage(75);
	car2.setHitPoints(80);

	raceCars(car1, car2);						// runs the simulated race

	system("pause");
	return 0;
}

//---------------------------------------------------------------------------
// Displays the race intro, runs the simulated race and displays the race 
// results.
void raceCars(carType& car1, carType& car2)
{
	raceIntro(car1, car2);		// Introduces the race
	race(car1, car2);			// Simulates the race between the 2 cars
	raceReport(car1, car2);		// Produces a Race Report declaring the winner
}

//-------------------------------------------------------------------------
// Simulates the race between 2 cars.  The simulation runs until one or 
// both cars are destroyed.
void race(carType& car1, carType& car2)
{
	int roundCount = 0;

	srand(time(NULL));
	while (car1.isAlive() && car2.isAlive())			// Continue simulation as long as both cars are alive
	{
		cout << "Lap " << roundCount + 1 << "...... \n\n";
		car1.attackCar(car2);							// cars attack each other
		car2.attackCar(car1);

		car1.display();									// display current car values
		car2.display();

		cout << endl << endl;
		//sleep(1000);									// use in place of system("pause") for auto play
		system("pause");
		system("cls");
		roundCount++;
	}
	
}

/***************************************************************************/
// function used to display the intro screen
void raceIntro(const carType& outCar1, const carType& outCar2)
{
	cout << "-------------------------------- Racing Cars --------------------------------" << endl << endl;

	outCar1.display();
	outCar2.display();

	cout << "Let's do this......" << endl << endl;
	
	system("pause");
	system("cls");
}

/***************************************************************************/
// function used to display the report screen after game is ended
void raceReport(const carType& outCar1, const carType& outCar2)
{
	cout << "Race Report ......." << endl << endl;
	Beep(523, 500);								// annoy beep if you're so inclined

	// checks which car is alive or if both are destroyed
	if (outCar1.isAlive() && !outCar2.isAlive())
	{
		cout << outCar1.getName() << " defeats " << outCar2.getName() << endl << endl;
	}
	else if(!outCar1.isAlive() && outCar2.isAlive())
	{
	cout << outCar2.getName() << " defeats " << outCar1.getName() << endl << endl;
	}
	else if(!outCar1.isAlive() && !outCar2.isAlive())
	{
	cout << "********** WASTED! **********" << endl << endl;
	}

	cout << "Woot Woot !! ...........GAME OVER!!" << endl << endl;
}