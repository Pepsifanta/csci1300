#include <iostream>

#include "dateType.h"

using namespace std;

 
void dateType::setDate(int month, int day, int year)
{
    // Checking month is valid
    if (month < 1 || month > 12)
    {
        month = 1; // Set default month value
    }

    // Checking year is valid
    if (year < 1900)
    {
        year = 1900; // Set default year value
    }

    // Checking the validity of the day
    bool isLeap = isLeapYear();
    int maxDay;

    switch (month)
    {
    case 2: // February
        maxDay = isLeap ? 29 : 28;
        break;
    case 4: // April
    case 6: // June
    case 9: // September
    case 11: // November
        maxDay = 30;
        break;
    default:
        maxDay = 31;
        break;
    }

    if (day < 1 || day > maxDay)
    {
        day = 1; // Set default day value
    }

    dMonth = month;
    dDay = day;
    dYear = year;
}



int dateType::getDay() const
{
    return dDay;
}

int dateType::getMonth() const
{
    return dMonth;
}

int dateType::getYear() const
{
    return dYear;
}

void dateType::printDate() const
{
    cout << dMonth << "-" << dDay << "-" << dYear;
}

bool dateType::isLeapYear() const
{
    if (dYear % 400 == 0)
        return true;
    else if (dYear % 100 == 0)
        return false;
    else if (dYear % 4 == 0)
        return true;
    return false;
}

dateType::dateType(int month, int day, int year)
{
    setDate(month, day, year);
}
