#include <iostream>
#include <vector>
#include "Polinomio.h"

void insertarLista(Nodo *&, int, int);
void mostrarLista(Nodo *);


vector <Polinomio> Polinomios;

int main(){
    Nodo *lista = NULL;
    int Coef, Exp;
    int cant;

    cout <<"Ingresar los terminos de dos polinomios que desee operar"<< endl;

    cout << "Cuantos terminos desea ingresar del polinomio 1: ";
    cin >> cant;

    for (int i = 0; i < cant; i++) {
        cout << "Termino " << i+1 << ":\n";
        cout << "Ingrese el coeficiente: ";
        cin >> Coef;
        cout << "Ingrese el exponente: ";
        cin >> Exp;
        insertarLista(lista, Coef, Exp);
    }
    mostrarLista(lista);

    cout << "Cuantos terminos desea ingresar del polinomio 2: ";
    cin >> cant;

    for (int i = 0; i < cant; i++) {
        cout << "Termino " << i+1 << ":\n";
        cout << "Ingrese el coeficiente: ";
        cin >> Coef;
        cout << "Ingrese el exponente: ";
        cin >> Exp;
        insertarLista(lista, Coef, Exp);
    }
    mostrarLista(lista);
}

void insertarLista (Nodo *&lista, int c, int e) {
    Nodo *nuevo_nodo = new Nodo(c, e);
    nuevo_nodo -> Coef = c;
    nuevo_nodo -> Exp = e;
    Nodo *aux1 = lista;
    Nodo *aux2;

while ((aux1 != NULL)&&(aux1-> Exp < e)){
        aux2 = aux1;
        aux1 = aux1 -> siguiente;
        }
if (lista == aux1){
    lista = nuevo_nodo;
}
else {
    aux2 -> siguiente = nuevo_nodo;
}
    nuevo_nodo -> siguiente = aux1;
}

void mostrarLista(Nodo *lista){
    Nodo *actual = lista;

    while (actual != NULL){
        cout << actual->Coef << "x^" << actual->Exp << endl;
        actual = actual -> siguiente;
    }
}
