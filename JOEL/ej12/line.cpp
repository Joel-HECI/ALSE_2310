#include <iostream>
#include <cmath>
#include "punto2d.h"
#include "line.h"

using namespace std;

line::line()
{
    a = b = point(0., 0.);
}
line::line(point A, point B)
{
    a = A;
    b = B;
}
line::line(const line &A)
{
    a = A.a;
    b = A.b;
}

point line::getA()
{
    return a;
}
point line::getB()
{
    return b;
}

double line::getYIntercept()
{
    return a.getY() - pendiente() * a.getX();
}

void line::setA(point A)
{
    a = A;
}
void line::setB(point B)
{
    b = B;
}

void line::escalado(double factor)
{
    double m = pendiente();
    double b_Y = getYIntercept();
    double x;
    double p = a.getX();
    double q = a.getY();

    double new_length = longitud() * factor;

    if (b.getX() < 0)
    {
        x = (((-b_Y * m) + p + (m * q) - sqrt(-(b_Y * b_Y) + (1 + m * m) * (new_length * new_length) - pow(((-m * p) + q), 2) + b_Y * ((-2 * m * p) + (2 * q)))) / (m * m + 1));
    }
    else
    {
        x = (((-b_Y * m) + p + (m * q) + sqrt(-(b_Y * b_Y) + (1 + m * m) * (new_length * new_length) - pow(((-m * p) + q), 2) + b_Y * ((-2 * m * p) + (2 * q)))) / (m * m + 1));
    }

    double y = x * m + b_Y;

    setB(point(x, y));
}
double line::pendiente()
{
    return (b.getY() - a.getY()) / (b.getX() - a.getX());
}
double line::longitud()
{
    return a.distancia(b);
}
ostream &operator<<(ostream &out, line &A)
{
    out << A.a << A.b;
    return out;
}