//6) Desarrolla una función que verifique si dos colas son iguales (contienen los mismos elementos en 
//el mismo orden). 

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

void colasSonIguales(Cola *c1, Cola *c2){
   bool iguales=true;
   while(!ColaVacia(c1) && !ColaVacia(c2) && iguales){
      if(PrimeroCola(c1)->dato!=PrimeroCola(c2)->dato)
         iguales=false;
      Desencolar(&c1);
      Desencolar(&c2);
   }
   if(iguales==true && (ColaVacia(c1) || ColaVacia(c2)))
      cout<<"FALSO";
   else if(iguales==false && ColaVacia(c1) && ColaVacia(c2))
      cout<<"FALSO";
   else
      cout<<"VERDADERO";
}