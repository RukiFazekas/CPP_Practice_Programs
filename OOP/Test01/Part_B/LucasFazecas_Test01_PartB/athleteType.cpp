// --------------------------------------------------------------- //
// Athlete Class Implementation File  						       //
// --------------------------------------------------------------- //

#include <iostream>
#include <iomanip>
#include <string>
#include "athleteType.h"

using namespace std;

// array to hold enumerated sportType parameters as strings
string athleteType::sportNames[5] = { "No Sport Assigned", "Hockey", "Baseball", "Golf", "Cricket" };

// function to display all info related to an athlete
void athleteType::display() const
{
	string month;
	int day, year;

	getBirthDate(month, day, year);

	cout << setw(17) << left << "Person Name:" << getName() << endl;
	cout << setw(17) << left << "Person DOB:" << month << "-" << day << "-" << year << endl;
	cout << setw(17) << left << "Athlete Sport:" << sportNames[sport] << endl;
	cout << setw(17) << left << "Athlete Is Pro:" << isProfessional << endl;
	cout << setw(17) << left << "Athlete Team:" << teamName << endl << endl;
}

// default constructor
athleteType::athleteType() 
{
	sport = UNASSIGNED;
	isProfessional = "No";
	teamName = "No Team Assigned";
}

// parameterized constructor
athleteType::athleteType(string inName, string inMonth, int inDay, int inYear, sportType inSport, string inIsPro, string inTeamName)
	: personType(inName, inMonth, inDay, inYear)
{
	sport = inSport;
	isProfessional = inIsPro;
	teamName = inTeamName;
}