//6)  Ordenar una pila de manera ascendente.

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

int minimoElemento(Pila *pila){
   int minimo=999;
   while(!PilaVacia(pila)){
      if(Tope(pila)->dato<minimo)
         minimo=Tope(pila)->dato;
      Desapilar(&pila);
   }
   return minimo;
}

void ordenarAscendente(Pila **pila){
   Pila *aux=NULL;
   Pila *aux2=NULL;
   int minimo=minimoElemento(*pila);
   while(!PilaVacia(*pila)){
      Apilar(&aux,Tope(*pila)->dato);
      Desapilar(pila);
   }
   while(!PilaVacia(aux)){
      if(Tope(aux)->dato==minimo){
         Apilar(pila,Tope(aux)->dato);
         Desapilar(&aux);
         while(!PilaVacia(aux2)){
            Apilar(&aux,Tope(aux2)->dato);
            Desapilar(&aux2);
         }
         if(!PilaVacia(aux))
            minimo=minimoElemento(aux);
      }else{
         Apilar(&aux2,Tope(aux)->dato);
         Desapilar(&aux);
      }
   }
}