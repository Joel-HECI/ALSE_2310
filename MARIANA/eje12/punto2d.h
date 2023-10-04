#include <iostream>
#include <math.h>
using namespace std;

class Punto{
  double cx,cy;

public:
  Punto();
  //Punto( Punto &a );
  Punto(double x, double y );
  double   getX();
  bool     setX( double x );
  double   getY();
  bool     setY( double y );
  double   distancia( const Punto &b );
  double   angulo();
  double   magnitud();
  Punto operator+(Punto &a);
  Punto operator-(Punto &a);
  friend   ostream& operator<< (ostream& out, Punto &a);
};

