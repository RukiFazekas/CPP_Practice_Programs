// --------------------------------------------------------------- //
// Person Class IMplementaion File								   //
// --------------------------------------------------------------- //

#include <iostream>
#include <iomanip>
#include <string>
#include "personType.h"

using namespace std;

// function to input birth date for a person
void personType::setBirthDate(string inMonth, int inDay, int inYear)
{
	birthDate.setDate(inMonth, inDay, inYear);
}

// function to retrieve info about a person's birth date
void personType::getBirthDate(string& outMonth, int& outDay, int& outYear) const
{
	outMonth = birthDate.getMonth();
	outDay = birthDate.getDay();
	outYear = birthDate.getYear();
}

// function to display all info related to a person
void personType::display() const
{
	cout << setw(17) << left << "Person Name:" << name << endl;
	cout << setw(17) << left << "Person DOB:" << birthDate.getMonth() << "-" << birthDate.getDay() << "-" << birthDate.getYear();
	cout << endl << endl;
}

// default constructor
personType::personType()
{
	name = "Unassigned";
	birthDate.setDate("January", 1, 1900);
}

// parameterized constructor
personType::personType(string inName, string inMonth, int inDay, int inYear)
{
	name = inName;
	birthDate.setDate(inMonth, inDay, inYear);
}