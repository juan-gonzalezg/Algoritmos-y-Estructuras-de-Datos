//11) Mezclar dos pilas de manera alternada en una nueva pila

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

void mezclarPilas(Pila *pila1, Pila *pila2){
   Pila *aux=nullptr;
   while(!PilaVacia(pila1) && !PilaVacia(pila2)){
      Apilar(&aux,Tope(pila1)->dato);
      Desapilar(&pila1);
      Apilar(&aux,Tope(pila2)->dato);
      Desapilar(&pila2);
   }
   if(!PilaVacia(pila1) && PilaVacia(pila2)){
      while(!PilaVacia(pila1)){
         Apilar(&aux,Tope(pila1)->dato);
         Desapilar(&pila1);
      }
   }else{
      Apilar(&aux,Tope(pila2)->dato);
      Desapilar(&pila2);
   }
}