#include <iostream>

using namespace std;

class line
{
    point a, b;

public:
    line();
    line(point a, point b);
    line(const line &a);

    point getA();
    point getB();
    double getYIntercept();
    void setA(point a);
    void setB(point b);

    void escalado(double a);
    double longitud();
    double pendiente();

    friend ostream &operator<<(ostream &out, line &a);
};