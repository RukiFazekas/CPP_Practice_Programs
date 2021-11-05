/*********************************************************************************************************
Author:      Lucas Fazecas
Title:       Assignment 3
Purpose:     1. To breakdown a written problem into logical parts (prompts, input, calculations, output) in order to devise a solution.
             2. To utilize the iomanip (chapter 3) library to aid in formatting program output.
             3. To create a C++ program utilizing simple data types, operators, type casting and user prompts, variables and constants.
Date:  September 29th, 2021
*********************************************************************************************************/

#include <iostream>
#include <iomanip> // include librarie so it is possible to format output

using namespace std;

int main()
{
	float origPrice = 0.0f;
	float markedUpPercentage = 0.0f;
	float sellPrice = 0.0f;
	float salesTaxAmount = 0.0f; 
	float finalPrice = 0.0f;
	const float TAX_RATE = 12.0f;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "|        Welcome to Gecko's NFT Marketplace!       |" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "                        ___           .--.          " << endl;
	cout << "                       (   )          |  |          " << endl;
	cout << "    .--.   .--.   .--.  | |   ___  .--'..'  .--.    " << endl;
	cout << "   /    \\ /    \\ /    \\ | |  (   )/    \\  /  _  \\    " << endl;
	cout << "  ;  ,-. |  .-. |  .-. ;| |  ' / |  .-. ;. .' `. ;  " << endl;
	cout << "  | |  | |  | | |  |(___| |,' /  | |  | || '   | |  " << endl;
	cout << "  | |  | |  |/  |  |    | .  '.  | |  | |_\\_`.(___) " << endl;
	cout << "  | |  | |  ' _.|  | ___| | `. \\ | |  | (   ). '.   " << endl;
	cout << "  | '  | |  .'.-|  '(   | |   \\ \\| '  | || |  `\\ |  " << endl;
	cout << "  '  `-' '  `-' '  `-' || |    \\ '  `-' /; '._,' '  " << endl;
	cout << "   `.__. |`.__.' `.__,'(___) (___`.__.'  '.___.'   " << endl;
	cout << "   ( `-' ;                                          " << endl;
	cout << "    `.__.                                           " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	
	// prompt user to enter original price
	cout << "Enter the original price of the item: ";
	cin >> origPrice;
	
	// prompt user to enter marked up percentage
	cout << "Enter the marked up percentage: ";
	cin >> markedUpPercentage;

	// output of numeric values formatted to 2 decimal places
	cout << fixed << setprecision(2);

	// display the inputs entered by user to the screen
	cout << endl << "The original price = $" << origPrice << endl;
	cout << "The price is marked up by " << markedUpPercentage << "%" << endl << endl;

	// calculate selling price and display it
	sellPrice = origPrice * (1 + (markedUpPercentage / 100));
	cout << "The selling price      = $" << sellPrice << endl;

	// display sales tax rate
	cout << "The sales tax rate     = " << TAX_RATE << "%" << endl;

	// calculate sales tax amount nad dispaly it
	salesTaxAmount = sellPrice * (TAX_RATE / 100);
	cout << "The sales tax $ amount = $" << salesTaxAmount << endl;

	// calculate final price and display it
	finalPrice = sellPrice + salesTaxAmount;
	cout << "The final price        = $" << finalPrice << endl << endl << endl;


	system("pause");
	return 0;
}