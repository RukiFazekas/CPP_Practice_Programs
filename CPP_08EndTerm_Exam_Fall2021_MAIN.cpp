//----------------------------------------------------------------//
//	Author: Lucas Fazecas                						  //
//  Purpose: Test 02                                              //
//  Date: November 18, 2021                                       //
//----------------------------------------------------------------//

#include <iostream>
#include <string>
#include "main.h"

using namespace std;

//----------------------------------------------------------------//
// Main function...
void main()
{
	// variables declaration
	int userChoice = -1, num1 = 0, num2 = 0, width = 0, height = 0, perimeter = 0, area = 0;
	float centimeter = 0.00f, foot = 0.00f, inch = 0.00f;

	cout << "Let's get functioning ...  woot . Woot . WOot . WOOt . WOOT . WOOT! . WOOT!!" << endl << endl;

	// flag while
	while (userChoice != 99) // checks user's choice, display function or exit accordingly
	{
		userChoice = MainMenu();

		switch(userChoice)
		{
		case 1: // calls Ascending Order funcion and output results
			cout << "Ascending Order" << endl;
			num1 = getUserInput();
			num2 = getUserInput();
			if (AscendingNumber(num1, num2))
			{
				cout << num1 << " and " << num2 << " are in ascending order" << endl << endl;
			}
			else
			{
				cout << num1 << " and " << num2 << " are NOT in ascending order" << endl << endl;
			}
			system("pause");
			break;
		case 2: // calls centimeters to feet and inches conversion function and output results
			cout << "Centimeters to feet and inches" << endl;
			centimeter = getUserInput();
			lengthConversion(centimeter, foot, inch);
			cout << centimeter << " centimeters converts to " << foot << " foot and " << inch << " inches." << endl << endl;
			system("pause");
			break;
		case 3: // calls calculation of area and perimeter of a rectangle function and output results
			cout << "Area and perimeter of a rectangle" << endl;
			width = getUserInput();
			height = getUserInput();
			rectangleDimension(width, height, perimeter, area);
			cout << "The perimeter of the rectangle is: " << perimeter << endl;
			cout << "The area of the rectangle is: " << area << endl << endl;
			system("pause");
			break;
		}
	}
	cout << "Exiting" << endl << endl;
	system("pause");
}

int MainMenu() // display options to user and validate their entry
{
	bool validInput = false;
	int userEntry = -1;

	//flag while
	while (!validInput) // checks user input until it is valid
	{
		system("cls");

		cout << "------------------------System Menu---------------------------" << endl;
		cout << "Enter 1  Ascending Order" << endl;
		cout << "Enter 2  Centimeters to feet and inches" << endl;
		cout << "Enter 3  Calculate the area and perimeter of a rectangle" << endl;
		cout << "Enter 99 to quit" << endl;
		cout << "--------------------------------------------------------------" << endl << endl;

		cout << "Selection: ";
		cin >> userEntry;
		cout << endl;

		// get proper input from user according to their choice
		switch(userEntry)
		{
		case 1:
		case 2:
		case 3:
		case 99:
			cout << "Valid Input. Continue." << endl << endl;
			validInput = true;
			break;
		default:
			cout << "Invalid Input. Check menu options again" << endl << endl;
			system("pause");
		}
	}
	return userEntry;
}

int getUserInput()
{
	int userInput = 0;

	// gets user input
	cout << "Please, enter a integer number: ";
	cin >> userInput;

	return userInput;
}

bool AscendingNumber(int value1, int value2)
{
	bool ascendingOrder = false;

	// check if values are in ascending order
	if (value1 < value2)
	{
		ascendingOrder = true;
	}

	return ascendingOrder;
}

void lengthConversion(float centimeterInput, float& footOutput, float& inchOutput)
{
	// converts centimeter to foot and turn it into int type
	footOutput = static_cast<int>((centimeterInput * CENT_TO_INCH) / (FOOT_TO_INCH));
	// converts the remaining centimeters that were cut out after int conversion of footOutput into inch
	inchOutput = (centimeterInput * CENT_TO_INCH) - (footOutput * FOOT_TO_INCH);
}

void rectangleDimension(int widthInput, int heightInput, int& perimeterOutput, int& areaOutput)
{
	//calculates perimeter
	perimeterOutput = (2 * widthInput) + (2 * heightInput);
	//calculates area 
	areaOutput = widthInput * heightInput;
}
