/*********************************************************************************************************
Author:      Lucas Fazecas
Title:       Assignment 2
Purpose:     1. To create a C++ program utilizing simple data types, operators, type casting and user prompts.
Date:  September 23, 2021
*********************************************************************************************************/

#include <iostream>

using namespace std;

int main()
{
	double decNum1, decNum2, decNum3, decNum4, decNum5, decNum6, productDecNum;
	int num1, num2, num3, num4, num5, num6, productNum;

	// prompt user to input 6 decimal numbers
	cout << "Enter 6 decimal numbers:" << endl;
	cin >> decNum1 >> decNum2 >> decNum3 >> decNum4 >> decNum5>> decNum6;
	
	// output to the screen all the entered inputs
	cout << endl << "The decimal numbers you entered are:" << endl;
	cout << decNum1 << " " << decNum2 << " " << decNum3 << " " << decNum4 << " " << decNum5 << " " << decNum6 << endl << endl;

	// convert all inputs entered by user to the nearest integer numbers
	num1 = static_cast<int>(decNum1 + 0.5f);
	num2 = static_cast<int>(decNum2 + 0.5f);
	num3 = static_cast<int>(decNum3 + 0.5f);
	num4 = static_cast<int>(decNum4 + 0.5f);
	num5 = static_cast<int>(decNum5 + 0.5f);
	num6 = static_cast<int>(decNum6 + 0.5f);

	// output to the screen the nearest integer numbers based on user input
	cout << "The nearest integer conversion numbers are:" << endl;
	cout << num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5 << " " << num6 << endl << endl;

	// calculate the product of all decimal numbers input by user and output it to the screen
	productDecNum = decNum1 * decNum2 * decNum3 * decNum4 * decNum5 * decNum6;
	cout << "Product of double values: " << productDecNum << endl;

	// calculate the product of all the nearest integer numbers input by user and output it to the screen
	productNum = num1 * num2 * num3 * num4 * num5 * num6;
	cout << "Product of int values : " << productNum << endl << endl;
 

	system("pause");

	return 0;	
}