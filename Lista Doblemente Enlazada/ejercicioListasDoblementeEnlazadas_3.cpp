//3) Implementa  un  procedimiento  que  rote  una  lista  doblemente  enlazada  por  "K" 
//posiciones a la derecha (en clase de teoría de desarrollará rotar a la izquierda).

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

void rotarDER(Nodo **inicio, int k){ //usando las primitivas en vez de punteros, para rotar k nodos a la izquierda
   int contador=1;
   Nodo *anterior=NULL;
   if(listaVacia(*inicio))
      cout<<"La lista esta vacia no se puede rotar"<<endl;
   else{
      Nodo *actual=*inicio;
      while(actual!=NULL && contador<=k){
         insertarUltimo(inicio,actual->dato);
         anterior=actual->prox;
         anterior->previo=NULL;
         delete actual;
         actual=anterior;
         contador++;
      }
   }
}