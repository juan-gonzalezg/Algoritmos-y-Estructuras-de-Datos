//2) Diseña un procedimiento que divida una lista doblemente enlazada en dos listas: 
//una que contenga los nodos en posiciones pares y otra con los nodos en posiciones 
//impares (basado en el índice de los nodos, no en los valores).

#include <iostream>
using namespace std;

struct Nodo{
   int dato;
   Nodo *previo;
   Nodo *prox;
};

#include <iostream>
using namespace std;

//Elaborado por Lia Mendoza

// Definicion de la estructura de un nodo de lista doblemente enlazada
struct Nodo {
  int dato;
  Nodo *previo;
  Nodo *prox;
};

// Funcion para crear un nuevo nodo de lista doblemente enlazada
Nodo* crearNodo(int dato) {
  Nodo *nuevo = new Nodo;
  nuevo->dato = dato;
  nuevo->previo = NULL;
  nuevo->prox = NULL;
  return nuevo;
}

// Funcion para comprobar si una lista doblemente enlazada esta vacia
bool listaVacia(Nodo *inicio) {
  return inicio == NULL;
}

void insertarUltimo(Nodo **inicio, int valor) 
{
 
   Nodo *nuevo = crearNodo(valor);
 
  // Si la lista esta vacia
    if (listaVacia(*inicio))
       *inicio = nuevo;
    else 
     {

       // Recorremos la lista hasta el ultimo nodo
       Nodo *actual = *inicio;
       while (actual->prox != NULL) {
            actual = actual->prox;
        }

      // Insertamos el nuevo nodo al final de la lista
        actual->prox = nuevo;
        actual->prox->previo = actual;
     }
}

void dividirLista(Nodo **inicio, Nodo **pares, Nodo ** impares){
   Nodo *actual=*inicio;
   while(actual!=NULL){
      if(actual->dato%2==0)
         insertarUltimo(pares,actual->dato);
      else
         insertarUltimo(impares,actual->dato);
      actual=actual->prox;
   }
}