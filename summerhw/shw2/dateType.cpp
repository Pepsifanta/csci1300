#include <iostream>

#include "dateType.h"

using namespace std;

void dateType::setDate(int month, int day, int year)

{

// Checking month is valid

if (month<1 || month>12)

{

cout << "Entered month "<<month<< " is wrong"<<endl;

cout << "Enter correct month"<<endl;

return;

}

dMonth = month;

// Checking date is valid

if (day<1 || day>31)

{

cout << "Entered date "<<day<<" is wrong"<<endl;

cout<<"Enter correct date"<<endl;

return;

}

dDay = day;

int count_digits = 0;

int flag=0;

int year1;

// Counting number of digits in year

while(flag==0)

{

year1=year;

count_digits=0;

while (year) {

year /= 10;

count_digits++;

}

if(count_digits != 4)

{

cout << "Entered year "<<year1<<" is wrong"<<endl;

cout<<"Enter correct year"<<endl;

return;

flag=0;

}

else

flag=1;

}

dYear = year1;

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

if ( dYear%400 == 0)

cout<<endl<<dYear<< " is leap year.\n";

else if ( dYear%100 == 0)

cout<<endl<<dYear<< " is leap year.\n";

else if ( dYear%4 == 0 )

cout<<endl<<dYear<< " is leap year.\n";

else

cout<<endl<<dYear<< " is not leap year.\n";

}

//Constructor with parameters

dateType::dateType(int month, int day, int year)

{

// Checking month is valid

  setDate( month, day, year);


}
