/*********************************************************************************************************
Author:      Lucas Fazecas
Title:       Test 1
Purpose:     Evaluation of acquired knowledge
Date:  October 21th, 2021
*********************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Part A ///////////////////////////////////////////////////////////////////////
	cout << "Part A: ------------------------------------------" << endl << endl;

	// Code for Part A goes here
	
	// declare variables
	int firstNum = 0, secondNum = 0, product = 1;
	bool properInput = false;

	// request input of two int numbers until first input is less than the second input.
	while (!properInput)
	{
		cout << "Please enter two numbers in ascending order: ";
		cin >> firstNum >> secondNum;
		cout << endl;

		// check if first is less than the second
		if (firstNum < secondNum)
		{
			properInput = true;
		}
		else
		{
			//alert user if input is not valid
			cout << "The numbers you entered are not in ascending order." << endl << endl;
		}
	}

	//  print the product of all the numbers between firstNum and secondNum, including the two inputs by user
	for (int i = firstNum; i <= secondNum; i++)
	{
		product *= i;
	}

	cout << "The product of the numbers between (and including) " << firstNum << " and " << secondNum << " is: " << product;

	cout << endl << endl << endl;
	// Part B ///////////////////////////////////////////////////////////////////////
	cout << "Part B: ------------------------------------------" << endl << endl;

	// Code for Part B goes here

	//declare variables
	int userNum = 0, sumGreater10 = 0, sumLess10 = 0;

	// sentinel while
	while (userNum != 10)
	{
		// request input until user enters 10
		cout << "Please enter a number, enter 10 to quit: ";
		cin >> userNum;

		// calculate the sum of all numbers greater than 10
		if (userNum > 10)
		{
			sumGreater10 += userNum;
		}
		// calculate the sum of all numbers less than 10
		else if (userNum < 10)
		{
			sumLess10 += userNum;
		}
	}

	// print the sums
	cout << endl << endl;
	cout << "The sum of all the numbers greater than 10 is: " << sumGreater10 << endl;
	cout << "The sum of all the numbers less than 10 is: " << sumLess10;

	cout << endl << endl << endl;
	// Part C ///////////////////////////////////////////////////////////////////////
	cout << "Part C: ------------------------------------------" << endl << endl;

	// Code for Part C goes here

	// declare variables
	int userInput = 0, multiplication = 0;

	// request input of a number from 1 to 60
	cout << "Please enter an integer between 1 and 60: ";
	cin >> userInput;
	cout << endl;

	// calculate and display multiplication table from 0 to 23 for the entered number
	for (int i = 0; i <= 23; i++)
	{
		multiplication = i * userInput;
		cout << i << " * " << userInput << " = " << multiplication << endl;
	}

	cout << endl << endl;
	cout << "All Done... Woot Woot!!" << endl << endl;
	system("pause");
	return 0;
}