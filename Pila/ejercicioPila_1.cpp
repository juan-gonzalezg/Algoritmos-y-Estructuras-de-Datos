//1) Cuenta el número de elementos pares de pila (sin perder la pila original)

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

void elementosPares(Pila *pila){
   Pila *aux=NULL;
   int i=0;
   while(!PilaVacia(pila)){
      if(Tope(pila)->dato%2==0)
         i++;
      Apilar(&aux,Tope(pila)->dato%2==0);
      Desapilar(&pila);
   }
   while(!PilaVacia(aux)){
      Apilar(&pila,Tope(aux)->dato);
      Desapilar(&aux);
   }
   cout<<"Cantidad de elementos pares de la pila es: "<<i;
}