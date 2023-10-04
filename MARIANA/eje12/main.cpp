#include <iostream>
#include <cmath>
#include <complex>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "punto2d.h"

using namespace std;

/*  La forma de llamar al programa será:
    eje10 ../datos.txt
*/

int main(int argc, char** argv){
//  cout << argc << endl;
  if( argc != 2 ){
    cout << "Debe pasar la url del archivo que contiene los números complejos.";
    return 1;
  }
  
  int i=0;
  size_t pos=0;
  string a, b;
  double x, y;
  bool again;
  Punto aux;

  string   texto;
  vector< Punto > vec;
  vector< Punto > dis;
  vector< double > ang;
  vector< Punto > env;


  ifstream input( argv[1] );

  while( getline( input, texto) ){
    // Aquí se leyó la línea y ahora falta procesarla para extraer la
    // parte real y a parte imaginaria  ej: -3.14 + 2.67j

//    cout << texto << endl;
    pos = texto.find_first_not_of(".,0123456789", 1 );
    a = (texto.substr( 0, pos));
    a.erase( remove( a.begin(), a.end(), ' '), a.end() );
    b =  texto.substr( pos, texto.length() - pos - 1);
    b.erase( remove( b.begin(), b.end(), ' ' ), b.end() );
    x = stod( a.c_str());
    y = stod( b.c_str() );
    aux.setX(x);
    aux.setY(y);
//    cout << aux << endl;
    vec.push_back(aux);
//    cout << i++ << endl;
  }


  input.close();
  
bool mayor;
  do {
      mayor = false;
      for (int i = 0; i < 4; i++){
          if(vec[i].angulo() > vec[i+1].angulo()){
              aux = vec[i];
              vec[i] = vec[i+1];
              vec[i+1] = aux;
              mayor = true;
          }if (vec[i].angulo() == vec[i+1].angulo()){
              if(vec[i].magnitud() > vec[i+1].magnitud()){
                  aux = vec[i];
                  vec[i] = vec[i+1];
                  vec[i+1] = aux;
                  mayor = true;
              }
          }
          }
  } while (mayor == true);

  // Promedio
    Punto suma, prom;
      for(size_t  i = 0; i < vec.size(); i++ ){
          suma = suma + vec[i];
      }

      cout << suma << endl;
      prom.setX(suma.getX()/vec.size());
      prom.setY(suma.getY()/vec.size());

  //Radio Mayor
    Punto rmayor;
    for(size_t i = 0; i < vec.size(); i++ ){
        if (vec[i].distancia(prom) > mayor){
            rmayor = vec[i];
        }
    }


  ofstream output("output.txt");  // Se crea el objeto para abrir el archivo de escritura


  for(size_t  i = 0; i < vec.size(); i++ ){
    output << vec[i] << endl;
  }
  cout << prom << endl;
  cout << rmayor << endl;

  output.close();  // Se cierra el archivo de escritura.

  return 0;

}

