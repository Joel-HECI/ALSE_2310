#include <iostream>
#include <math.h>

using namespace std;

struct Punto{
  double x,y;
};

double distancia( Punto a, Punto b){
  return sqrt(pow((b.y - a.y),2) + pow((b.x - a.x),2));
}

double  angulo (double dist, double distCA){
  return acos(distCA/dist);
}

int main(int argc, char** argv){
  Punto a, b;
  double dist;
  a.x = 3.;
  a.y = 4.;
  b.x = 8.;
  b.y = 6.;

  Punto x0,xf;
  double distCA;
  x0.x = a.x;
  x0.y = 0.;
  xf.x = b.x;
  xf.y = 0.;

  double ang;

  dist = distancia(a,b);
  distCA = distancia(x0 ,xf);
  ang = (angulo(dist,distCA))*180/(3.14159265358979323846);

  cout << "El angulo comprendido entre la linea formada por los puntos a (" << a.x <<"," << a.y << ") y b (" << b.x << "," << b.y << ") con la horizontal es:" << ang << endl;

 return 0;
}
