//8) Dada una lista enlazada y un valor X, particiona la lista en dos sublistas. La primera sublista 
//contendrá  todos  los  nodos  con  valores  menores  o  iguales  a  X,  y  la  segunda  sublista 
//contendrá los nodos con valores mayores a X.

#include <iostream>
using namespace std;

struct Nodo{
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

void mostrarLista(Nodo *inicio){
   Nodo *mover;

   if (!listaVacia(inicio)){
       mover = inicio;
      while (mover != NULL)
        {
           cout << mover->dato <<"->";
           mover = mover->prox;
         }
         cout<<"NULL"<<endl;
   }  
  else
     cout<<"Lista esta vacia"<<endl;
}

void insertarUltimo(Nodo **inicio, int valor){
    Nodo *nuevo = crearNodo(valor);
 
   if (listaVacia(*inicio)) {
       *inicio = nuevo;
    } 
    else {
       Nodo *auxiliar = *inicio;
       while (auxiliar->prox != NULL) {
           auxiliar = auxiliar->prox;
       }
        auxiliar->prox = nuevo;
  }
   
} 

int pedir_valor(){
   int valor;
   cout<<"Indica valor: ";
   cin>>valor;
   return valor;
}

void sublistasMenoresMayores(Nodo *inicio, int x){
   Nodo *actual=inicio;
   Nodo *sublista1=NULL, *sublista2=NULL;
   while(actual!=NULL){
      if(actual->dato<=x)
         insertarUltimo(&sublista1,actual->dato);
      else
         insertarUltimo(&sublista2,actual->dato);
      actual=actual->prox;
   }
   cout<<"Sublista con los valores menores a "<<x<<": ";
   mostrarLista(sublista1);
   cout<<"Sublista con los valores mayores a "<<x<<": ";
   mostrarLista(sublista2);
}