//2) Escribir un procedimiento que reemplace todos los elementos de un valor dado en una cola con 
//otro valor especificado, ambos valores proporcionados por el usuario.

#include <iostream>
using namespace std;

struct Cola{
   int   dato;
   Cola *prox;
};

Cola* crearCola(int valor){
    Cola *nuevo = new Cola;
    nuevo->dato = valor;
    nuevo->prox = NULL;
    return nuevo;
}

bool ColaVacia(Cola *col){
    return col==NULL;
}

Cola*  PrimeroCola(Cola *col){
   if (!ColaVacia(col))
      return col; 
   else   
      return nullptr;    
}

void Encolar(Cola **col, int valor){
   Cola *nuevo = crearCola(valor);
 
   if (ColaVacia(*col)) {
       *col = nuevo;
    } 
    else {
       Cola *auxiliar = *col;
       while (auxiliar->prox != NULL) {
           auxiliar = auxiliar->prox;
       }
       auxiliar->prox = nuevo;
  }
   
}

void Desencolar(Cola **col){
     if (!ColaVacia(*col))
        *col=(*col)->prox;
     else
       cout<<"Cola vacia imposible desencolar "<<endl;
}

void reemplazarElementos(Cola **c, int elemento, int reemplazo){
   Cola *aux=NULL;
   while(!ColaVacia(*c)){
      Encolar(&aux,PrimeroCola(*c)->dato);
      Desencolar(c);
   }
   while(!ColaVacia(aux)){
      if(PrimeroCola(aux)->dato==elemento)
         Encolar(c,reemplazo);
      else
         Encolar(c,PrimeroCola(aux)->dato);
      Desencolar(&aux);
   }
}