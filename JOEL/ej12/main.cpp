#include <iostream>
#include "punto2d.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

/*  La forma de llamar al programa será:
    eje10 ../datos.txt
*/

double promedio(const vector<point> &vec, bool x = true)
{
  double sum = 0;

  if (x)
  {

    for (size_t i = 0; i < vec.size(); i++)
    {
      sum += vec[i].getX();
    }

    return sum / vec.size();
  }

  else
  {
    for (size_t i = 0; i < vec.size(); i++)
    {
      sum += vec[i].getY();
    }
    return sum / vec.size();
  }
}

int main(int argc, char **argv)
{
  //  cout << argc << endl;
  /* if( argc != 2 ){
    cout << "Debe pasar la url del archivo que contiene los números complejos.";
    return 1;
  } */

  bool again;
  point aux;

  ifstream input(argv[1]);

  string numero;

  vector<point> vec;

  int i = 0;

  while (getline(input, numero))
  {
    point p;

    // asignar los valores de los Re al vector de números complejos usando procesamiento de strings
    p.setX(atof(numero.substr(0, numero.find_last_of(" ")).c_str()));

    // asignar los valores de los Im al vector de números complejos usando procesamiento de strings
    p.setY(atof(numero.substr(numero.find_last_of(" "), numero.find_last_not_of("-.1234567890 ")).c_str()));

    vec.push_back(p);
    i++;
  }

  input.close();

  // Encontrar el punto medio de todos los puntos

  point mid(promedio(vec, true), promedio(vec, false));

  point maxp;
  double radius;

  // Encontrar el punto más alejado del punto medio

  for (size_t i = 0; i < vec.size(); i++)
  {
    double dist = mid.distancia(vec[i]);

    if (dist > radius)
    {
      maxp = vec[i];
      radius = dist;
    }
  }

  // Organizar puntos según su angulo respecto al origen
  do
  {
    again = false;

    for (size_t i = 0; i < vec.size() - 1; i++)
    {
      if (vec[i].angulo() > vec[i + 1].angulo())
      {
        aux = vec[i];
        vec[i] = vec[i + 1];
        vec[i + 1] = aux;
        again = true;
      }
      else
      {
        if (vec[i].angulo() == vec[i + 1].angulo())
        {
          if (vec[i].magnitud() > vec[i + 1].magnitud())
          {
            aux = vec[i];
            vec[i] = vec[i + 1];
            vec[i + 1] = aux;
            again = true;
          }
        }
      }
    }
  } while (again == true);

  // Algoritmo de Graham, se itera entre tripletas de puntos para descartar los
  // que genere un angulo a favor de las manecillas del reloj, depurando el vector
  vector<point> envolvente = vec;
  for (size_t i = 1; i < envolvente.size() - 1; i++)
  {
    int angl = angulo3puntos(envolvente[i - 1], envolvente[i], envolvente[i + 1]);

    point aux;

    if (angl > 0)
    {
      continue;
    }
    else
    {

      envolvente.erase(envolvente.begin() + i);
      i++;
    }
  }

  // Escritura a archivo de salida

  ofstream output("../output.txt"); // Se crea el objeto para abrir el archivo de escritura
  // Enunciar el circulo con centro med y radio maxlength
  output << "Ejercicio 12 " << endl;
  output << " - * - " << endl;
  output << "Puntos leidos del archivo: " << endl;
  for (size_t i = 0; i < vec.size(); i++)
  {
    output << setfill(' ') << left << setw(1) << "•";
    output << vec[i] << endl;
  }
  output << " - * - " << endl;
  output << "El punto medio de los datos es: " << mid << endl;
  output << " - * - " << endl;
  output << "El circulo que envuelve a todos los puntos tiene centro en " << mid << " y radio " << radius << endl;
  output << " - * - " << endl;
  output << "Puntos pertenecientes a la envolvente:" << endl;
  for (size_t i = 0; i < envolvente.size(); i++)
  {

    // El punto mas alejado del centro se marca con un asterisco
    if (maxp == envolvente[i])
      output << setfill(' ') << left << setw(1) << "*";
    else
    {
      output << setfill(' ') << left << setw(1) << "•";
    };

    output << envolvente[i] << endl;
  }

  output.close(); // Se cierra el archivo de escritura.
  system("cat ../output.txt");

  return 0;
}
