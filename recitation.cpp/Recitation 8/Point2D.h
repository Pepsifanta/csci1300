
#include <string>
using namespace std;
//****************** what is in the post.cpp
class Point2D
{

    public:

        Point2D();
        Point2D( double p, double q, string label = "");

        void print();
        double distance(Point2D q=Point2D(0,0));

        double getx() ;
        double gety() ;
        string getLabel();

        void setX(double p);
        void setY(double q);
        void setLabel(string s);
        void modify(Point2D point);

    private:
        double x;
        double y;
        string label;

};
