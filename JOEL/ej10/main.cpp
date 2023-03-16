#include <iostream>
#include <cmath>
#include <complex>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

/*
 Direccion del archivo de in/out en parametros de main [√]
 Buscar archivo en directorio default []
 Comprobar si archivo(s) existe(n) [√]
 Si no, crearlo (salida) [√]
 Abrir archivo de salida [√]
  */

using namespace std;

// Función para contar el número de líneas (Números) dentro del archivo de lectura
// recibe como parámetro el url del archivo

int num_lineas(const string path2file)
{
  int lineas = 0;
  string texto;
  ifstream input(path2file);

  while (getline(input, texto))
  {
    lineas++;
  }
  input.close();
  return lineas;
}

// Función para eliminar los espacios en blanco de un string que representa un número complejo
// modifica la string ya que es pasada por referencia

string quitar_espacios(string &str)
{

  str.erase(remove(str.begin(), str.end(), ' '), str.end());

  return str;
}

// Función para crear un separador de caracteres (Formato de salida)
string separator(int length, char symbol, ostream &out)
{
  string sep;

  for (int i = 0; i < length; i++)
  {
    sep.push_back(symbol);
  }

  return sep;
}

int main(int argc, char **argv)
{

  // La forma de llamar el programa será ./ej10 ../datos.txt ../output.txt (opcional)

  string outfile_name;

  if (argc == 2 or argc == 3)
  {
    fstream read_file(argv[1]);
    fstream out_file(argv[2]);

    // comprobar si el archivo de lectura existe
    if (!read_file.good())
    {
      cout << "El archivo de lectura no existe." << endl;
      return 1;
    }

    // comprobar si se pasó el archivo de salida o si existe, si no, preguntar si se desea crearlo
    if (!out_file.good() || argc == 2)
    {
      cout << "El archivo de salida no existe, desea crearlo? [y/n]: ";
      if (cin.get() == 'y')
      {
        cout << "Introduzca el nombre del archivo: ";
        cin >> outfile_name;
      }
      else
      {
        cout << "No se creará el archivo." << endl;
        return 0;
      }
    }
  }
  else
  {
    cout << "Debe pasar el archivo por leer." << endl;
    return 1;
  }

  // crear un vector de números complejos con el tamaño del número de líneas del archivo de lectura

  complex<double> *vec = new complex<double>[num_lineas(argv[1])];

  // ciclo while para leer los componentes de números complejos del archivo de lectura, linea por linea

  ifstream input(argv[1]);
  string numero;

  int i = 0;

  while (getline(input, numero))
  {
    // quitar espacios en blanco para evitar errores en la lectura de los números complejos
    quitar_espacios(numero);

    // asignar los valores de los Re al vector de números complejos usando procesamiento de strings
    vec[i].real(atof(numero.substr(0, (numero.find("+") == numero.npos ? numero.find_last_of("-") : numero.find("+"))).c_str()));

    // asignar los valores de los Im al vector de números complejos usando procesamiento de strings
    vec[i].imag(atof(numero.substr((numero.find("+") == numero.npos ? numero.find_last_of("-") : numero.find("+")), numero.find_last_not_of("j")).c_str()));

    i++;
  }

  input.close();

  // Algoritmo de ordenamiento burbuja para ordenar los números complejos por su anglulo de fase o magni

  bool again;

  do
  {
    again = false;
    complex<double> tmp;

    for (int i = 0; i < 4; i++)
    {

      if (arg(vec[i]) > arg(vec[i + 1]))
      {
        tmp = vec[i];
        vec[i] = vec[i + 1];
        vec[i + 1] = tmp;
        again = true;
      }
      else
      {
        if (arg(vec[i]) == arg(vec[i + 1]))
        {
          if (norm(vec[i]) > norm(vec[i + 1]))
          {
            tmp = vec[i];
            vec[i] = vec[i + 1];
            vec[i + 1] = tmp;
            again = true;
          }
        }
      }
    }

  } while (again);

  cout << "Organización completada!" << endl;

  // Escribir en archivo de salida

  ofstream outf((argc == 3 ? argv[2] : "../" + outfile_name + ".txt"));

  // Encabezado del archivo
  string file_header = "Números Complejos en " + (string)argv[1] + " ordenados.";
  outf << file_header << endl;
  outf << separator(file_header.length(), '-', outf) << endl;
  // Usando la libreria iomanip escribir los numeros complejos como una tabla.
  outf << setfill(' ') << left << setw(20) << "Número        |   Ángulo" << endl;

  for (int i = 0; i < 5; i++)
  {
    outf << setfill(' ') << left << setw(1) << (vec[i].real() < 0 ? "- " : "  ");
    outf << setfill(' ') << right << setw(4) << abs(vec[i].real());
    outf << setfill(' ') << left << setw(1) << (vec[i].imag() < 0 ? " - " : " + ");
    outf << setfill(' ') << right << setw(4) << abs(vec[i].imag());
    outf << setfill(' ') << left << setw(3) << " :" << (arg(vec[i]) < 0 ? "- " : "  ") << round(abs(arg(vec[i])) * 10000) / 10000 << "°" << endl;
  }

  outf.close();

  // Abrir nano para visualizar documento de salida

  system(("nano -v " + (argc == 3 ? argv[2] : "../" + outfile_name + ".txt")).c_str());

  return 0;
}