#include<iostream>

#include "dateType.h"

using namespace std;

int main()

{

dateType *dt1=new dateType();

cout<<"Date is "<<endl;

dt1->printDate();

cout<<endl;

dt1->isLeapYear();

cout<<endl;

dateType *dt2=new dateType(11,14,2019);

cout<<"Date is "<<endl;

dt2->printDate();

cout<<endl;

dt2->isLeapYear();

cout<<endl;

dt2->setDate(13,32,2016);

cout<<"Date is "<<endl;

dt2->printDate();

cout<<endl;

dt2->isLeapYear();

cout<<endl;

dt1->setDate(10,10,198);

cout<<"Date is "<<endl;

dt1->printDate();

cout<<endl;

dt1->isLeapYear();

cout<<endl;

system("pause");

return 0;

}
