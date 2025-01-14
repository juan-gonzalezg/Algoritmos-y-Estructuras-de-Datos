//4) Dadas  dos  listas  calcular  en  la  primera  lista  el  valor  mínimo  impar  y  luego 
//intercambiarlo con el valor máximo par de la segunda lista.

#include <iostream>
using namespace std;

struct Nodo {
  int dato;
  Nodo *previo;
  Nodo *prox;
};

int minimoValorImpar(Nodo *inicio){
   int minimo=9999;
   while(inicio!=NULL){
      if(inicio->dato%2!=0 && inicio->dato<minimo)
         minimo=inicio->dato;
      inicio=inicio->prox;
   }
   return minimo;
}

int maximoValorPar(Nodo *inicio){
   int maximo=0;
   while(inicio!=NULL){
      if(inicio->dato%2==0 && inicio->dato>maximo)
         maximo=inicio->dato;
      inicio=inicio->prox;
   }
   return maximo;
}

void intercambiarValores(Nodo **inicio1, Nodo **inicio2){
   int minimoImpar=minimoValorImpar(*inicio1);
   int maximoPar=maximoValorPar(*inicio2);
   while(inicio1!=nullptr){
      if((*inicio1)->dato==minimoImpar)
         (*inicio1)->dato=maximoPar;
      (*inicio1)=(*inicio1)->prox;
   }
   while(inicio2!=NULL){
      if((*inicio2)->dato==maximoPar)
         (*inicio2)->dato=minimoImpar;
      (*inicio2)=(*inicio2)->prox;
   }
}