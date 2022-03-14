// --------------------------------------------------------------- //
// Person Class Definition File								       //
// --------------------------------------------------------------- //

#pragma once

#include <string>
#include "dateType.h"

using namespace std;

class personType
{
public:
	void setName(string inName) { name = inName; }
	string getName() const { return name; }
	void setBirthDate(string inMonth, int inDay, int inYear);
	void getBirthDate(string& outMonth, int& outDay, int& outYear) const;
	void display() const;

	personType();
	personType(string inName, string inMonth, int inDay, int inYear);

private:
	string name;
	dateType birthDate;
};