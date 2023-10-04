#include <iostream>
#include <math.h>
#include "punto2d.h"

using namespace std;

bool Punto::setX( double x ){
  cx = x;
  return true;
}

bool Punto::setY( double y ){
  cy = y;
  return true;
}

double Punto::distancia( const Punto &b ){
    double m = b.cx - cx;
    double n = b.cy - cy;
    return sqrt( m * m  + n * n );
}

double Punto::angulo(){
  return atan2(cy, cx);
}

double Punto::magnitud(){
  return sqrt(cx*cx + cy*cy);
}

Punto Punto::operator+(Punto &a){
    Punto c;
    c.cx = cx + a.cx;
    c.cy = cy + a.cy;
    return c;
  }

ostream& operator<< (ostream& out, Punto &a){
  out  << "(" << a.cx << "," << a.cy << ")" << endl;
  return out;
}
  

Punto::Punto()
{
    cx = cy = 0.;
}

/*Punto::Punto(Punto &a)
{
  cx = a.cx;
  cy = a.cy;
}
*/

Punto::Punto(double x, double y)
{
  cx = x;
  cy = y;
}

double   Punto::getX(){
  return cx;
}

double    Punto::getY(){
  return cy;
}

Punto  Punto::operator-(Punto &a){
  Punto c;
  c.cx = cx - a.cx;
  c.cy = cy - a.cy;
  return c;
}







