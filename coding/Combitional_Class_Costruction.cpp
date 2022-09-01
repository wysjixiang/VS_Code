#include <iostream>
#include <math.h>

class point
{

private:
    double x,y;

public:

    point(double i, double j) { x=i;y=j;};
    point(point &p)
    {
        std::cout<< "point function restruct!\n" << std::endl;
        x = p.x;
        y = p.y;

    }

    double getpoint_x()
    {

        return x;
    }

    double getpoint_y()
    {

        return y;
    }

};



class distance
{

private: 

    point a,b;
    double dist;


public:
    distance(point i,point j);

    double getdist();

};

distance::distance(point i,point j): a(i),b(j)
{
    std::cout<< "dist function init..."<<std::endl;
    double x = abs( a.getpoint_x()  -b.getpoint_x() );
    double y = abs( a.getpoint_y()  -b.getpoint_y() );
    dist = sqrt(x*x + y*y  );
}

double distance::getdist()
{
    return dist;

}



int main()
{

    point p1(0.2,3),p2(4.1,-1.2);

    distance d(p1,p2);

    std::cout<< d.getdist() << std::endl;


    system("pause");
    return 0;
}