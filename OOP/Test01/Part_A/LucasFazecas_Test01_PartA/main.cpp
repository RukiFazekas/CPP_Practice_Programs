// --------------------------------------------------------------- //
// Author:	Lucas Fazecas    
// Purpose:	Test 01 - Part A
// Date: Feb 16, 2022
// --------------------------------------------------------------- //

#include<iostream>
#include <string>
#include <iomanip>
#include "gameObjectType.h"

using namespace std;

int main()
{
	float x, y;		// variables to get object's position

	cout << "Time to think 'object'ively....!!\n\n";

	// Instantiate objects as required

	gameObjectType bowser;
		
	gameObjectType mario("Mario", 1, 10, 20);

	gameObjectType mushroom("Mushroom", 2, 10, 20);

	// Using setter/mutator functions to set the values of the first object

	bowser.setName("Bowser");
	bowser.setWorld(3);
	bowser.setPosition(5, 160);

	// Display data from all 3 objects

	cout << "Displaying object information:" << endl;
	bowser.display();
	mario.display();
	mushroom.display();

	// Display the number of active objects

	cout << "Active objects: " << gameObjectType::getObjectCount() << endl << endl;

	// Check if objects 2 and 3 are equal

	cout << "Are Objects 2 and 3 equal? ";
	if (mario.equal(mushroom))
	{
		cout << mario.getName() << " is equal to " << mushroom.getName() << endl << endl;
	}
	else
	{
		cout << mario.getName() << " is NOT equal to " << mushroom.getName() << endl << endl;
	}

	// Display the name and position of object 3

	mushroom.getPosition(x, y);
	cout << "Object 3 Name and Position: " << mushroom.getName() << " is at position (" << x << ", " << y << ")" << endl << endl;

	system("pause");
	return 0;
}