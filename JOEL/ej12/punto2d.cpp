#include <iostream>
#include <cmath>
#include "punto2d.h"
#include <iomanip>

using namespace std;

bool point::setX(double X)
{
  x = X;
  return true;
}

bool point::setY(double Y)
{
  y = Y;
  return true;
}

double point::distancia(const point &b)
{
  double x = b.x - x;
  double y = b.y - y;
  return sqrt(x * x + y * y);
}

double point::angulo()
{
  return atan2(y, x);
}

double point::magnitud()
{
  return sqrt(x * x + y * y);
}

ostream &operator<<(ostream &out, point &a)
{
  out << setfill(' ') << left << setw(1) << "(";

  out << setfill(' ') << right << setw(5) << a.getX();

  out << setfill(' ') << left << setw(2) << ",";

  out << setfill(' ') << right << setw(5) << a.getY();

  out << setfill(' ') << left << setw(1) << ")";

  return out;
}

point::point(const point &a)
{
  x = a.x;
  y = a.y;
}

point::point()
{
  x = y = 0.;
}
point::point(double X, double Y)
{
  x = X;
  y = Y;
}

double point::getX()
{
  return x;
}

double point::getY()
{
  return y;
}

point &point::operator=(const point &p)
{
  x = p.x;
  y = p.y;

  return *this;
}

bool point::operator==(const point &a)
{
  if (x == a.x && y == a.y)
    return true;
  return false;
}

int angulo3puntos(point &a, point &b, point &c)
{

  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}