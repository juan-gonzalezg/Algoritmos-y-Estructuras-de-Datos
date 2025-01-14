//9) Rotar los elementos de una lista k posiciones hacia la izquierda.

#include <iostream>
using namespace std;

struct Nodo{
   int dato;
   Nodo *prox;
};

int longitudLista(Nodo *inicio){
   int longitud=0;
   while(inicio!=NULL){
      longitud++;
   }
   return longitud;
}

void rotarIzquierda(Nodo **inicio,int k, int elemento){
   Nodo *actual=*inicio, *anterior=*inicio;
   int longitud=longitudLista(*inicio);
   int posicion=1;
   if(k<longitud){
      while(actual->prox!=NULL){
         
      }
   }
}