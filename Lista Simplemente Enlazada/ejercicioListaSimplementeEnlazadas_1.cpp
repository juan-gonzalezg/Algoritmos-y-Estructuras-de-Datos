//1) Agregar un elemento a una lista en forma ordenada (observación: no se trata de desarrollar 
//un algoritmo de ordenamiento, sino de modificar la primitiva Insertar para que al crear la 
//lista se haga de forma ordenada).

#include <iostream>
using namespace std;

struct Nodo {
  int dato;
  Nodo *prox;
};

Nodo* crearNodo(int valor) {
  Nodo *nuevo = new Nodo;
  nuevo->dato = valor;
  nuevo->prox = NULL;
  return nuevo;
}

bool listaVacia(Nodo *inicio){
    return inicio==NULL;
}

void insertarOrdenado(Nodo **inicio, int valor){
   Nodo *nuevo = crearNodo(valor);
 
   if (listaVacia(*inicio) || (*inicio)->dato > nuevo->dato) {
      nuevo->prox = *inicio;
      *inicio = nuevo;
   } else {
      Nodo *auxiliar = *inicio;
      while (auxiliar->prox != NULL && auxiliar->prox->dato < nuevo->dato) {
         auxiliar = auxiliar->prox;
      }
      nuevo->prox = auxiliar->prox;
      auxiliar->prox = nuevo;
   }
}