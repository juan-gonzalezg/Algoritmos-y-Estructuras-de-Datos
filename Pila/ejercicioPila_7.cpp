//7)  Comprobar si dos pilas son iguales

#include <iostream>
using namespace std;

struct Pila{
   int dato;
   Pila *prox;
};

Pila* crearPila(int valor){
    Pila *nuevo = new Pila;
    nuevo->dato = valor;
    nuevo->prox = NULL;
    return nuevo;
}

bool PilaVacia(Pila *pila){
    return pila==NULL;
}

Pila*  Tope(Pila *pila){
   if (!PilaVacia(pila))
      return pila; 
   else   
      return nullptr;    
}

void Apilar(Pila **pila, int valor){
   Pila *nuevo = crearPila(valor);
   nuevo->prox=*pila;
   *pila=nuevo;
}

void Desapilar(Pila **pila){
     if (!PilaVacia(*pila))
         *pila = (*pila)->prox; 
     else
       cout<<"Pila vacia imposible desapilar "<<endl;
}

void mostrarPila(Pila *pila){
  while (!PilaVacia(pila)) {
    cout <<Tope(pila)->dato<< "  ";
    Desapilar(&pila);
  }
}

void pilasIguales(Pila *pila1, Pila *pila2, int i, int j){
   Pila *aux1=NULL,*aux2=NULL;
   int cont=0;
   bool iguales=false;
   if(i==j){
      while(!PilaVacia(pila1)){
         Apilar(&aux1,Tope(pila1)->dato);
         Desapilar(&pila1);
      }
      while(!PilaVacia(pila2)){
         Apilar(&aux2,Tope(pila2)->dato);
         Desapilar(&pila2);
      }
      while(!PilaVacia(aux1)){
         if(Tope(aux1)->dato==Tope(aux2)->dato){
            iguales=true;
            cont++;
         }else
            iguales=false;
         Desapilar(&aux1);
         Desapilar(&aux2);
      }
      if(iguales && cont==i)
         cout<<"Los elementos son los mismos en ambas Pilas";
      else if(iguales && cont==0)
         cout<<"Los elementos de ambas Pilas no son los mismos";
      else if(iguales && cont<i)
         cout<<"No todos los elemntos de ambas Pilas son los mismos";
   }else if(i>j){
      cout<<"Las pilas no tienen la misma cantidad de elementos";
   }
}