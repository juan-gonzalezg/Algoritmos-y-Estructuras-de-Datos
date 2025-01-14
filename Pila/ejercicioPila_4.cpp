//4)  Invertir el orden de los elementos de una pila. 

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

void invertirPila(Pila **pila){
   Pila *aux=NULL;
   while(!PilaVacia(*pila)){
      Apilar(&aux,Tope(*pila)->dato);
      Desapilar(pila);
   }
   mostrarPila(aux);
}