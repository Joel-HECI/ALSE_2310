#include <iostream>
#include <cmath>
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

string quitar_espacios(string &str)
{

  str.erase(remove(str.begin(), str.end(), ' '), str.end());

  return str;
}

double promedio(vector<point> &vec, bool x = true)
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

  size_t pos = 0;
  string a, b;
  double x, y;
  bool again;
  point aux;

  ifstream input("../datos.txt");
  if (input.good())
    cout << "Leyendo datos del archivo" << endl;

  string numero;

  vector<point> vec;

  int i = 0;

  while (getline(input, numero))
  {
    point p;

    // quitar espacios en blanco para evitar errores en la lectura de los números complejos
    // quitar_espacios(numero);

    // asignar los valores de los Re al vector de números complejos usando procesamiento de strings
    p.setX(atof(numero.substr(0, numero.find_last_of(" ")).c_str()));

    // asignar los valores de los Im al vector de números complejos usando procesamiento de strings
    p.setY(atof(numero.substr(numero.find_last_of(" "), numero.find_last_not_of("-.1234567890 ")).c_str()));

    vec.push_back(p);
    i++;
  }

  input.close();

  point mid(promedio(vec, true), promedio(vec, false));
  cout << "El punto medio es: " << mid << endl;

  point maxp;
  double maxlength;

  for (size_t i = 0; i < vec.size(); i++)
  {
    double dist = mid.distancia(vec[i]);

    if (dist > maxlength)
    {
      maxp = vec[i];
      maxlength = dist;
    }
    if (argv[1])
      cout << vec[i] << dist << endl;
    // cout << vec[i] << dist << endl;
  }
  cout << "El circulo que envuelve a todos los puntos tiene centro en " << mid << " y radio " << maxlength << endl;

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

  for (size_t i = 1; i < vec.size() - 1; i++)
  {
    int angl = angulo3puntos(vec[i - 1], vec[i], vec[i + 1]);

    point aux;

    if (angl > 0)
    {
      continue;
    }
    else
    {
      vec.erase(vec.begin() + i);
      i++;
    }
  }
  cout << "Puntos de Envolvente Convexa:" << endl;
  for (point i : vec)
  {
    cout << i << endl;
  }

  ofstream output("../output.txt"); // Se crea el objeto para abrir el archivo de escritura

  output << "\n - * - " << endl;
  for (size_t i = 0; i < vec.size(); i++)
  {
    if (maxp == vec[i])
      output << setfill(' ') << left << setw(1) << "*";
    else
    {
      output << setfill(' ') << left << setw(1) << "•";
    };

    output << vec[i];
    output << setfill(' ') << left << setw(1) << " | ";
    output << setfill(' ') << left << setw(6) << vec[i].angulo() << endl;
    //    cout << vec[i] << " < " <<  vec[i] ) << endl;
  }

  output.close(); // Se cierra el archivo de escritura.
  // system("cat ../output.txt");

  return 0;
}
