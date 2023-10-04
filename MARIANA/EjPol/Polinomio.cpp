#include <iostream>
#include "Polinomio.h"

using namespace std;

Nodo::Nodo()
{
    Coef = Exp = 0.;
}

Nodo::Nodo(int c, int e)
{
  Coef = c;
  Exp = e;
}


bool Nodo::setC( int c ){
    Coef = c;
    return true;
  }

bool Nodo::setE( int e ){
    Exp = e;
    return true;
  }

int Nodo::getC(){
    return Coef;
}

int Nodo::getE(){
    return Exp;
}

Polinomio::Polinomio()
{
  Termino = new Nodo();
}

Polinomio::~Polinomio()
{
  Nodo *p = Termino;
  while(p != NULL)
  {
    Nodo *aux = p;
    p = p -> siguiente;
    delete aux;
  }
}





