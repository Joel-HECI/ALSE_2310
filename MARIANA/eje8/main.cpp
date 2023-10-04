#include <iostream>
#include <math.h>
#include <cstring>
#include "complejo.h"

using namespace std;
// Utilizando los parámetros del main admita 4 valores el primero dos caracteres
// y luego cuatro valores reales que correspondan a dos números complejos
// ejemplo:  $> ./ej8 -a 3.14 4.68 8.55 6.68
//  los caracteres podrán ser -a -r -i -c para adición, resta, inverso y
//  conjugado. Dependiendo de estos dos caracteres, se debe ejecutar la 
//  operación correspondiente en el main y mostrar su resultado en pantalla 
//  hacendo uso de la estructura switch. Para convertir de cadena de texto a 
//  número real se puede utilizar la función atof.
//
//  Deberán implementar correctamente en el archivo complejo.cpp todos 
//  los métodos definidos en el archivo complejo.h

int main(int argc, char** argv){
  Complejo a, b, tercero, resta, conj1, conj2, inv1, inv2;
  double ang1, mag1;
  char ind[2];
  strcpy (ind, argv[1]);
  int (op);
  a.setRe ( atof(argv[2]) );
  a.setIm ( atof(argv[3]) );
  b.setRe ( atof(argv[4]) );
  b.setIm ( atof(argv[5]) );
  
  if (ind[1] == 'a')
  {
     op = 1;
  }
  else if (ind[1] == 'r')
  {
     op = 2;
  }
  else if (ind[1] == 'i')
  {
     op = 3;
  }
  else if (ind[1] == 'c')
  {
     op = 4;
  }
  else 
  {
  cout <<"Caracter Incorrecto."<<endl;
  }

  tercero = a + b;
  resta = a - b;
  conj1 = a.conjugado();
  conj2 = b.conjugado();
  inv1 = a.inverso();
  inv2 = b.inverso();
  ang1 = a.angulo();
  mag1 = a.magnitud();

  switch(op)
  {
  	case  1: cout << "La suma de (" << a << ") + (" << b << ") es igual a " << tercero << endl; 
  	break;
  	case  2: cout << "La resta de (" << a << ") - (" << b << ") es igual a " << resta << endl;
  	break;
  	case  3: cout << "El inverso de (" << a << ") es " << inv1 << " y el de (" << b << ") es " << inv2 << endl;
  	break;
  	case  4: cout << "El conjugado de (" << a << ") es " << conj1 << " y el de (" << b << ") es " << conj2 << endl;
  	break;

  	default: cout <<"Ingrese un caracter valido." <<endl;
  }

  cout <<"Angulo"<< ang1 <<endl;
  cout <<"Magnitud"<< mag1 <<endl;

  return 0;
}
