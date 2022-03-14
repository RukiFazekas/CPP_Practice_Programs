// --------------------------------------------------------------- //
// Date Class Implementation File  						           //
// --------------------------------------------------------------- //

#include <iostream>
#include <string>
#include "dateType.h"

using namespace std;

//-------------------------------------------------------------------
void dateType::setDate(string month, int day, int year)
{
    dMonth = month;
    dDay = day;
    dYear = year;
}

//-------------------------------------------------------------------
int dateType::getDay() const
{
    return dDay;
}

//-------------------------------------------------------------------
string dateType::getMonth() const
{
    return dMonth;
}

//-------------------------------------------------------------------
int dateType::getYear() const
{
    return dYear;
}

//-------------------------------------------------------------------
void dateType::printDate() const
{
    cout << dMonth << "-" << dDay << "-" << dYear;
}

//-------------------------------------------------------------------
dateType::dateType(string month, int day, int year)
{
    dMonth = month;
    dDay = day;
    dYear = year;
}