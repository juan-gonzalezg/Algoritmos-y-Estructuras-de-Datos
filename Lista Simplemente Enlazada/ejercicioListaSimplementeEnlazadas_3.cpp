//3) Elimine un valor dado en una lista la última de las veces que aparece en la lista. Ejemplo: 
//L1 ={3,44,55,3,4,5,6,3,8} =>  L1= {3,44,55,3,4,5,6,8}
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

void eliminarUltimoRepetido(Nodo **inicio, int valor){
   Nodo *mover,*anterior, *repetido = NULL; 
   
   if (listaVacia(*inicio))
      cout<<"Lista esta vacia"<<endl;
   else {   
      mover = *inicio;
      while (mover != NULL){
         if(mover->prox != NULL && mover->prox->dato == valor){
            anterior = mover;
            repetido = mover->prox;
         }
         mover = mover->prox;
      }
      if (repetido == NULL)
         cout<<"El elemento no existe en la lista "<<endl;
      else{ 
         if (repetido == *inicio)
            *inicio=(*inicio)->prox;
         else
            anterior->prox = repetido->prox;
         delete repetido;  
      }      
   }
}