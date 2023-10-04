#include <iostream>
#include <cmath>
#include <complex>
#include <fstream>
#include <string>
#include <cstddef>

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

  int      lineas = 0;
  string   texto;
  ifstream input( argv[1] );
  while( getline( input, texto) ){
    lineas++;
  }
  
  input.close();

  cout << "Leídas " << lineas << " líneas." << endl;
  complex <double> *vec = new complex <double> [lineas];

  input.open( argv[1] );  // Se abre nuevamente el archivo para leer los datos.

  size_t pos, pos2;
  string real, ima;
  char signo = '+', neg = '-', j = 'j';
  for(int  i = 0; i < lineas; i++ ){
    getline( input, texto);  // Aquí se leyó la línea y ahora falta procesarla para extraer la
                             // parte real y a parte imaginaria  ej: -3.14 + 2.67j
    pos = texto.find_first_of(signo);
    if (pos == std::string::npos){
        pos = texto.find_last_of(neg);
    }
    pos2 = texto.find_first_of(j);
    real = texto.substr(0,pos);
    ima = texto.substr(pos+1,(pos2-1)-(pos+1));
    vec[i].real( stof( real) );
    vec[i].imag( stof( ima ) );
  }

  input.close();  // Se cierra el archivo


  bool again;
  complex<double> aux;

  do{
    again = false;
      
    for( int i = 0; i < 4; i++){


      if ( arg( vec[i] ) > arg( vec[i+1] ) ){
        aux = vec[i];
        vec[i] = vec[i+1];
        vec[i+1] = aux;
        again = true;
      }else{
        if( arg( vec[i] ) == arg( vec[i+1] ) ){
          if( norm( vec[i] ) > norm( vec[i+1] ) ){
            aux =  vec[i];
            vec[i] = vec[i+1];
            vec[i+1] = aux;
            again = true;
          }
        }
      }
    }
  }while( again == true ); 

  ofstream output("output.txt");  // Se crea el objeto para abrir el archivo de escritura

  for(int  i = 0; i < lineas; i++ ){
    output<< vec[i].real() << ( vec[i].imag() < 0? " - ": " + " ) << vec[i].imag() << "j" << endl;
    cout << vec[i] << "<" << arg( vec[i] ) << endl;
  }
  
  output.close();  // Se cierra el archivo de escritura.
  delete [] vec;
  return 0;
}
