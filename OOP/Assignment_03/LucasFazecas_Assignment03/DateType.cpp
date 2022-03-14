// date class implementation

#include <iostream>
#include <iomanip>
#include <string>
#include "DateType.h"

void DateType::displayDate() const
{
	cout << month << ", " << setw(2) << setfill('0') << day << ", " << year;
}

DateType::DateType(string inMonth , int inDay, int inYear)
{
	month = inMonth;
	day = inDay;
	year = inYear;
}