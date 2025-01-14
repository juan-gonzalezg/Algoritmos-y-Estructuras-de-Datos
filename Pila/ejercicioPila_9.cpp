//9)  Intercambiar el contenido de dos pilas

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

void intercambiarContenidoPilas(Pila **pila1, Pila **pila2){
   Pila *aux=NULL;
   while(!PilaVacia(*pila1)){
      Apilar(&aux,Tope(*pila1)->dato);
      Desapilar(pila1);
   }
   while(!PilaVacia(*pila2)){
      Apilar(pila1,Tope(*pila2)->dato);
      Desapilar(pila2);
   }
   while(!PilaVacia(aux)){
      Apilar(pila2,Tope(aux)->dato);
      Desapilar(&aux);
   }
}