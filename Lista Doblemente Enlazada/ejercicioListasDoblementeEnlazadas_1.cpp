//1)Dadas dos listas determinar lo siguiente: 
//a. Si las listas son iguales en tamaño y contenido. 
//b. Si las listas son iguales en tamaño, pero no en contenido. 
//c. Si las listas no tienen el mismo tamaño ni contenido.

#include <iostream>
using namespace std;

struct Nodo{
   int dato;
   Nodo *previo;
   Nodo *prox;
};

int longitudLista(Nodo *inicio){
   int contador=0;
   while(inicio!=NULL){
      inicio=inicio->prox;
      contador++;
   }
}

void comparacionListas(Nodo *inicio1,Nodo *inicio2){
   int longitud1=longitudLista(inicio1);
   int longitud2=longitudLista(inicio2);
   bool contenido=false;
   while(inicio1!=NULL){
      if(inicio1->dato!=inicio2->dato)
         contenido=false;
      else
         contenido==true;
      inicio1=inicio1->prox;
      inicio2=inicio2->prox;
   }
   if(longitud1==longitud2){
      if(contenido)
         cout<<"Las listas son iguales en tamanio y contenido";
      else if(!contenido)
         cout<<"Las listas son iguales en tamanio, pero no en contenido";
   }else{
      if(!contenido)
         cout<<"Las listas no tienen el mismo tamanio ni contenido";
      else
         cout<<"Las listas no tienen el mismo tamanio, pero son iguales en contenido";
   }
}

