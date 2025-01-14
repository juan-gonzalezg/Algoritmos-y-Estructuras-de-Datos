//3) Dadas dos colas, elabora un procedimiento o función que permita fusionar dichas colas a partir 
//de un elemento inicial y otro elemento final de la primera cola (validar que existan) desde la mitad 
//de la segunda cola. Ejemplo: 
//Cola1 = {1,2,3,4,5,6,7,8,9,10} Elemento inicial = 5, Elemento final=9 
//Cola2 = {11,22,33,44,55,66}  
//Cola fusionada= {11,22,33,5,6,7,8,9,44,55,66}

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

int longitud(Cola *c){
   int contadaor=0;
   while(!ColaVacia(c)){
      contadaor++;
      Desencolar(&c);
   }
   return contadaor/2;
}

void fusionarColar(Cola *c, Cola **c2, int inicio, int final){
   Cola *aux=NULL;
   int mitad=longitud(*c2);
   while(!ColaVacia(*c2)){
      Encolar(&aux,PrimeroCola(*c2)->dato);
      Desencolar(c2);
   }
   while(!ColaVacia(aux) && mitad>0){
      Encolar(c2,PrimeroCola(aux)->dato);
      Desencolar(&aux);
      mitad--;
   }
   while(!ColaVacia(c) && PrimeroCola(c)->dato==inicio){
      Desencolar(&c);
   }
   while(!ColaVacia(c) && PrimeroCola(c)->dato==final){
      Encolar(c2,PrimeroCola(c)->dato);
      Desencolar(&c);
   }
   while(!ColaVacia(aux)){
      Encolar(c2,PrimeroCola(aux)->dato);
      Desencolar(&aux);
   }
}