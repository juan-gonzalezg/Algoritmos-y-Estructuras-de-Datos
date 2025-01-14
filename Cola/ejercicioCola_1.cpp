//Desarrolla una función que divida una cola en dos colas, una con la primera mitad de los elementos 
//y otra con la segunda mitad.

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

void Desencolar(Cola **col){
     if (!ColaVacia(*col))
        *col=(*col)->prox;
     else
       cout<<"Cola vacia imposible desencolar "<<endl;
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

Cola*  PrimeroCola(Cola *col){
   if (!ColaVacia(col))
      return col; 
   else   
      return nullptr;    
}

int longitud(Cola *c){
   int contador=0;
   while(!ColaVacia(c)){
      contador++;
      Desencolar(&c);
   }
   return contador;
}

void dividirCola(Cola **c){
   Cola *cPrimera=NULL;
   Cola *cSegunda=NULL;
   int longi=longitud(*c);
   int contador=0;
   int mitad=longi/2;
   while(!ColaVacia(*c)){
      if(mitad>0){
         Encolar(&cPrimera,PrimeroCola(*c)->dato);
         mitad--;
      }else
         Encolar(&cSegunda,PrimeroCola(*c)->dato);
      Desencolar(c);
   }
}