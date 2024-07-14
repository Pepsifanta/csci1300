#include <iostream>
#include "Point2D.h"

using namespace std;

int main()
{
    Point2D p;
    p.print();

    Point2D q(3, 4, "Q");
    q.print();

    Point2D r(-10, 4);
    r.print();
    r.setLabel("R");
    r.print();

    Point2D s;
    s.setX(2.5);
    s.setY(5.8);
    cout<< "x:"<<s.getx()<<",y:"<<s.gety()<<endl;

    cout<< "q.distance() :"<< q.distance()<<endl;
    cout<<"r.distance(q) :"<<r.distance(q)<<endl;

    cout<<"x : "<<s.getx()<<",y:"<<s.gety()<<endl;

    r.modify(s);
    cout<<"x :"<<s.getx()<<", y:"<< s.gety()<<endl;

    return 0;


}