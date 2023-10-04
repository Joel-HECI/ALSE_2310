#include <iostream>

using namespace std;

float mediana(int Vec[]){
  float med;
  
  med = (Vec[4]+Vec[5])/2.;
  
  return med;
}

int main(){
  int arreglo[10];
  float med=0.;

//Creación Puntero
  float *dirmed;
  dirmed = &med;
  cout << "Dirección de med: " << dirmed << " almacenado en: " << &dirmed << endl;

  cout << "Ingresar diez números enteros para obtener su mediana: \n ";
 
  for( int i = 0; i < 10; i++){
    cout << "Ingrese el numero " << i+1 << ":";
    cin >> arreglo[i];
  }

  med = mediana(arreglo);

  cout << "La mediana de los datos ingresados es: " << *dirmed << "\n";
  return 0;
}
