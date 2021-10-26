#include <iostream>
#include "hypocycloid.h"
#include "dialog.h"



template<typename T>
T input() {
    using namespace std;
    T x;
    if (cin.eof())
        return x;

    while (true) {
        cin >> x;
        if (cin.good())
            return x;
        if (cin.eof())
            return x;
        if (cin.bad())
            throw runtime_error("I have error while you input information");

        cout << "ERROR" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int choice()
{
    using namespace std;
    int a = 0;
    cout << "Please input your choice:"<<endl;
    cout << "1.Return coordiantes of point..."<<endl;
    cout << "2.Return radiuses of circles..."<<endl;
    cout << "3.Return the radius of curvature from the angle of rotation of the beam..."<<endl;
    cout << "4.Return a type of cypocycloid"<<endl;
    cout << "5.Return the sectorial area of the hypocycloid..."<<endl;
    cout << "6.Exit"<<endl;
    cin >> a;

    while (a < 1 || a > 6) {
        cout << "Please input 1-6!!!"<<endl;
        cin >> a;
    };
    return a;
}

double R(){
    double R;
    using namespace std;
    cout << "Please input a radius of big circle --->"<<endl;

    cout << " > ";
    R = input<double>();

    return R;
}
double r(){
    double r;
    using namespace std;
    cout << "Please input a radius of little circle --->"<<endl;

    cout << " > ";
    r = input<double>();

    return r;
}
double dist(){
    double d;
    using namespace std;
    cout << "Please input a distance from little circle to hypocycloid"<<endl;

    cout << " > ";
    d = input<double>();

    return d;
}
double x(){
    double x;
    using namespace std;
    cout << "Please input coordinate X --->"<<endl;
    cout << " > ";
    x = input<double>();
    return x;
}
double y(){
    double y;
    using namespace std;
    cout << "Please input coordinate Y --->"<<endl;
    cout << " > ";
    y = input<double>();
    return y;
}
double ungl(){
    double fi;
    using namespace std;
    cout << "Please input an ungle --->"<<endl;

    cout << " > ";
    fi = input<double>();

    return fi;
}

namespace hypocyc{
    hypocycloid::hypocycloid()
    {
        p  = Point{0,0};
        r = 0;
        R = 0;
        dist = 0;
    }

    hypocycloid::hypocycloid(Point start_p, double RAD, double rad,  double dl)
    {
        p = start_p;
        if (rad < 0 || RAD < 0  || dl < 0)
            throw std::runtime_error("invalid radius");
        r = rad;
        R = RAD;
        dist = dl ;
    }
    hypocycloid& hypocycloid::set_r(double r0)
    {
        if (r0 < 0)
            throw std::runtime_error("invalid radius");
        r = r0;
        return *this;
    }
    hypocycloid& hypocycloid::set_R(double R0)
    {
        if (R0 < 0)
            throw std::runtime_error("invalid radius");
        R = R0;
        return *this;
    }
    hypocycloid& hypocycloid::set_dist(double d0)
    {
        if (d0 < 0)
            throw std::runtime_error("invalid radius");
        dist = d0;
        return *this;
    }
    Point hypocycloid::coordinates(double fi) const {
        double k = (R/r);
        double x,y;
        x = p.x + r * (k-1) * (cos(fi) + (cos(k-1) * fi) / (k-1));
        y = p.y + r * (k-1) * (sin(fi) + (sin(k-1) * fi) / (k-1));
        return Point(x,y);

    }
    double hypocycloid::radius_of_curvature(double fi) const {
        double k = (R/r);
        double  Rk;

        Rk = (4*R*(k-1))/(k*k*(k-2)) * sin(fi/2);
        return Rk;
    }

    int hypocycloid::type() const {
        if( dist == r){
            return 1;
        }

        else if(dist < r){
            return 2;
        }

        else {
            return 3;
        }

    }
    double hypocycloid::sec_square(double fi) const {
        double S;
        S = std::abs(((R+r)*(R+2*r)/2) * (fi - r/R * sin(R/r * fi)));
        return S;
    }
}