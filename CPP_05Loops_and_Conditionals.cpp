/*********************************************************************************************************
Author:      Lucas Fazecas
Title:       Assignment 5 Part 1
Purpose:     To solve mathematical problems using loops and conditionals
Date:  October 18th, 2021
*********************************************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

void main()
{
	/////// Part a ////////
	int firstNum = 0, secondNum = 0, count = 0, product = 1, average = 0, sum = 0, divisor = 0;
	bool properInput = false;

	while (!properInput) // flag while loop
	{
		cout << "Enter two numbers, the first number must be less than the second number." << endl;
		cout << "Enter numbers: " << endl;
		cin >> firstNum >> secondNum;

		if (firstNum < secondNum)
		{
			cout << endl << "Number entries are valid...proceed with calculations." << endl << endl;
			properInput = true;
		}
		else
		{
			cout << endl << "Number entries are not valid... Please, carefully read the instructions." << endl << endl;
		}
	}

	/////// Part b ////////
	cout << "Part B.Even integers between " << firstNum << " and " << secondNum << " are:" << endl;

	count = firstNum; // count starts equal to firstNum so it is included

	while (count <= secondNum) // make less than or equal to secondNum to include it
	{
		if (count % 2 == 0)
		{
			cout << count << endl;
		}
		count++;
	}

	/////// Part c ////////
	count = firstNum + 1; // add one to exclude firstNum

	while (count < secondNum) // make less than secondNum to exclude it
	{
		product *= count; // same as product = product * count
		count++;
	}

	cout << endl;
	cout << "Part C.The product of all integers between " << firstNum << " and " << secondNum << " is: " << product << endl << endl;

	/////// Part d ////////
	count = firstNum;

	do
	{
		sum += count; // same as sum = sum + count
		divisor++;
		count++;
	} while (count <= secondNum);

	average = sum / divisor;

	cout << "Part D. The average of the integers between and including " << firstNum << " and " << secondNum << " = " << average << endl << endl;

	/////// Part e ////////
	cout << "PART E. The numbers and their squares between 1 and 20:" << endl;

	for (int i = 1; i <= 20; i++)
	{
		cout << "The square of " << i << " is: " << i * i << endl;
	}


	cout << endl << endl;
	system("pause");
}