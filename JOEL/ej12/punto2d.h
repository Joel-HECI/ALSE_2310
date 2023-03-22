#include <iostream>

using namespace std;

class point
{
  double x, y;

public:
  point();
  point(double X, double Y);
  point(const point &a);
  point &operator=(const point &a);

  double getX();
  bool setX(double X);
  double getY();
  bool setY(double Y);
  double distancia(const point &b);
  double angulo();

  double magnitud();

  bool operator==(const point &a);
  friend ostream &operator<<(ostream &out, point &a);
  friend int angulo3puntos(point &q, point &p, point &r);
};
