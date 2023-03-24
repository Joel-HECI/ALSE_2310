#include <iostream>
#include "punto2d.h"
#include "pointList.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, char **argv)
{
  //  cout << argc << endl;
  /* if( argc != 2 ){
    cout << "Debe pasar la url del archivo que contiene los números complejos.";
    return 1;
  } */

  ifstream input("../datos.txt");
  string numero;

  pointList vec;

  while (getline(input, numero))
  {
    point p;

    // asignar los valores de los Re al vector de números complejos usando procesamiento de strings
    p.setX(atof(numero.substr(0, numero.find_last_of(" ")).c_str()));

    // asignar los valores de los Im al vector de números complejos usando procesamiento de strings
    p.setY(atof(numero.substr(numero.find_last_of(" "), numero.find_last_not_of("-.1234567890 ")).c_str()));

    vec.addPoint(p);
  }

  input.close();

  // Encontrar el punto medio de todos los puntos
  point mid = vec.centroide();

  // Encontrar el punto más alejado del punto medio
  point maxp = vec.maxEfrompoint(mid);
  double radius = mid.distancia(maxp);

  // Organizar puntos según su angulo respecto al origen
  vec.bubbleOrdering();

  // Algoritmo de Graham, se itera entre tripletas de puntos para descartar los
  // que genere un angulo a favor de las manecillas del reloj, depurando el vector
  pointList envolvente = vec;
  envolvente.grahamHull();

  // Escritura a archivo de salida
  // Se crea el objeto para abrir el archivo de escritura
  ofstream output("../output.txt");

  // Enunciar el circulo con centro med y radio maxlength
  output << "Ejercicio 12 " << endl;

  output << " - * - " << endl;
  output << "Puntos leidos del archivo: " << endl;
  output << vec << endl;

  output << " - * - " << endl;
  output << "El punto medio de los datos es: " << mid << endl;

  output << " - * - " << endl;
  output << "El circulo que envuelve a todos los puntos tiene centro en " << mid << " y radio " << radius << endl;
  output << " - * - " << endl;

  output << "Puntos pertenecientes a la envolvente:" << endl;
  output << envolvente << endl;

  // Se cierra el archivo de escritura.
  output.close();
  system("cat ../output.txt");

  return 0;
}
