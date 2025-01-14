//4) A partir de dos listas L1 y L2 eliminar  de la lista L1 los elementos que  son comunes con la 
//lista L2. Ejemplo: 
//L1 = {2,3,4,45,33,22,313,55} y L2={2,3,44,33,33,4,5,6,8,31} => L1={45,22,313,55}

#include <iostream>
using namespace std;

struct Nodo{
   int dato;
   Nodo *prox;
};

Nodo* crearNodo(int valor) {
  Nodo *nuevo = new Nodo;
  nuevo->dato = valor;
  nuevo->prox = NULL;
  return nuevo;
}

bool listaVacia(Nodo *inicio){
    return inicio==NULL;
}

void mostrarLista(Nodo *inicio){
   Nodo *mover;

   if (!listaVacia(inicio)){
       mover = inicio;
      while (mover != NULL)
        {
           cout << mover->dato <<"->";
           mover = mover->prox;
         }
         cout<<"NULL"<<endl;
   }  
  else
     cout<<"Lista esta vacia"<<endl;
}

void insertarUltimo(Nodo **inicio, int valor){
    Nodo *nuevo = crearNodo(valor);
 
   if (listaVacia(*inicio)) {
       *inicio = nuevo;
    } 
    else {
       Nodo *auxiliar = *inicio;
       while (auxiliar->prox != NULL) {
           auxiliar = auxiliar->prox;
       }
        auxiliar->prox = nuevo;
  }
   
} 

int pedir_valor(){
   int valor;
   cout<<"Indica valor: ";
   cin>>valor;
   return valor;
}

void eliminar(Nodo **inicio, int valor){
   Nodo *mover,*anterior = NULL;

   if (listaVacia(*inicio))
      cout<<"Lista esta vacia"<<endl;
   else {
      mover = *inicio;
      while (mover != NULL && mover->dato != valor){
         anterior = mover;
         mover = mover->prox;
      }
      if (mover == NULL)
         cout<<"El elemento no existe en la lista "<<endl;
      else{
         if (mover == *inicio)
            *inicio=(*inicio)->prox;
         else
            anterior->prox = mover->prox;
         delete mover;
      }
   }
}

void eleminarComunes(Nodo **inicio, Nodo **inicio2){
   Nodo *lista1 = *inicio;
   Nodo *lista2 = *inicio2;
   bool salir;
   if(listaVacia(lista2))
      mostrarLista(lista1);
   else if (listaVacia(lista1))
      cout<<"La lista L1 se encuentra vacia"<<endl;
   else{
      while (lista1 != NULL) {
         salir= false;
         lista2=*inicio2;
         while(lista2 != NULL && salir==false){
            if (lista1->dato == lista2->dato)
               salir=true;
            lista2=lista2->prox;
         }
         if(salir==true){
            eliminar(inicio,(*inicio)->dato);
         }
         lista1=lista1->prox;
      }
   }
}
