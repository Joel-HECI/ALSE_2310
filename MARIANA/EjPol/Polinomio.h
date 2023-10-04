#include <iostream>
using namespace std;

class Nodo{
public:
  int Coef;
  int Exp;
  Nodo *siguiente;
  Nodo();
  Nodo (int c, int e);

  int getC();
  bool  setC( int c );
  int   getE();
  bool  setE( int e );
 };

class Polinomio{
    Nodo* Termino;
public:
    Polinomio();
    ~Polinomio();
    void insertarlista(int c, int e);
    void mostrarlista(int c, int e);
};



