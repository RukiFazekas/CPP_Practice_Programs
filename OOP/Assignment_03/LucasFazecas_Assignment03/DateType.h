#pragma once

#include <string>

using namespace std;

// date class definition

class DateType
{
public:
	void SetDate(string inMonth, int inDay, int inYear) { month = inMonth, day = inDay, year = inYear; }
	void GetDate(string& outMonth, int& outDay, int& outYear) const { outMonth = month, outDay = day, outYear = year; }
	void displayDate() const;

	DateType(string inMonth = "Unknown", int inDay = 99, int inYear = 9999);

private:
	string month;
	int day;
	int year;
};