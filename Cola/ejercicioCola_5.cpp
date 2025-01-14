//5)  Implementar  una  función  o  procedimiento  que  combine  dos  colas  ordenadas  en  una  sola  cola 
//ordenada  (no   hay    que    aplicar    ningún  algoritmo  de  ordenamiento,  sólo  a  través del recorrido).   
//Ejemplo: sean C1= {1,2,3,4,4,7} y C2={1,2,5,6,8,8,9} el resultado es:  
//C3= {1,2,3,4,5,6,7,8,9}

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

bool existeElemento(Cola *c, int valor){
   bool encontrado=false;
   if(ColaVacia(c))
      return encontrado;
   else{
      while(!ColaVacia(c) && encontrado==false){
         if(PrimeroCola(c)->dato==valor)
            encontrado=true;
         Desencolar(&c);
      }
   }
}

void combinarColas(Cola *aux, Cola **c){
   while(!ColaVacia(aux)){
      if(!existeElemento(*c,PrimeroCola(aux)->dato))
         Encolar(c,PrimeroCola(aux)->dato);
      Desencolar(&aux);
   }
}

void unirColas(Cola *c1, Cola *c2, Cola **c3){
   Cola *aux=NULL;
   while(!ColaVacia(c1) && !ColaVacia(c2)){
      if(PrimeroCola(c1)<PrimeroCola(c2)){
         Encolar(&aux,PrimeroCola(c1)->dato);
         Desencolar(&c1);
      }else if(PrimeroCola(c2)<PrimeroCola(c1)){
         Encolar(&aux,PrimeroCola(c2)->dato);
         Desencolar(&c2);
      }else{
         Encolar(&aux,PrimeroCola(c1)->dato);
         Desencolar(&c1);
         Desencolar(&c2);
      }
   }
   if(ColaVacia(c1) && ColaVacia(c2)){
      combinarColas(aux,c3);
   }else if(ColaVacia(c1)){
      while(!ColaVacia(c2)){
         Encolar(&aux,PrimeroCola(c2)->dato);
         Desencolar(&c2);
      }
      combinarColas(aux,c3);
   }else{
      while(!ColaVacia(c1)){
         Encolar(&aux,PrimeroCola(c1)->dato);
         Desencolar(&c1);
      }
      combinarColas(aux,c3);
   }
}