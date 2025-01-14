//8)  Eliminar los elementos duplicados de una pila

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

void eliminarDuplicados(Pila **pila){
   Pila *aux=NULL, *auxcopia=NULL;
   int elemento=0;
   while(!PilaVacia(*pila)){
      Apilar(&aux,Tope(*pila)->dato);
      Desapilar(pila);
   }
   while(!PilaVacia(aux)){
      if(PilaVacia(*pila))
         Apilar(pila,Tope(aux)->dato);
      else{
         while(!PilaVacia(*pila)){
            Apilar(&auxcopia,Tope(*pila)->dato);
            Desapilar(pila);
         }
         elemento=Tope(aux)->dato;
         while(!PilaVacia(auxcopia)){
            if(elemento!=Tope(auxcopia)->dato)
               Apilar(pila,Tope(auxcopia)->dato);
            Desapilar(&auxcopia);
         }
      }
      Desapilar(&aux);
   }
}