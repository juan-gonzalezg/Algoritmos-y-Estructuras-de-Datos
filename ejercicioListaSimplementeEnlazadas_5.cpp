//5) A partir de dos listas simplemente enlazadas generar una tercera lista con la intersección 
//de ambas listas

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

void insertarUltimo(Nodo **inicio, int valor){
   Nodo *nuevo = crearNodo(valor);
   if (listaVacia(*inicio)) {
      *inicio = nuevo;
   } else {
   Nodo *auxiliar = *inicio;
   while (auxiliar->prox != NULL) {
      auxiliar = auxiliar->prox;
      }
      auxiliar->prox = nuevo;
   }
} 

bool buscarElemento(Nodo *inicio, int valor) {
   Nodo *aux = inicio; 
   bool encontrado = false;
   while (aux != NULL && encontrado == false) {
      if (aux->dato == valor)
         encontrado = true;
      else 
         aux = aux->prox;
   }
   if (encontrado == false)
      cout<<"Valor no encontrado en la lista "<<endl;
   return encontrado;
}

void llenarLista(Nodo **lista){ 
   int cantidad, i=1, valor;
   cout<<"Indica la cantidad de elementos a agregar: ";
   cin>>cantidad;
   while(i<=cantidad){ 
      cout<<"Indica numero: ";
      cin>>valor;
      insertarUltimo(lista,valor);
      i++;
   }
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

void comunesLista(Nodo *lista1,Nodo *lista2,Nodo **lista3){
   Nodo *auxiliar=lista1;
   while(auxiliar!=NULL){
      if((buscarElemento(lista2,auxiliar->dato)==true) && *lista3==NULL)
         insertarUltimo(lista3,auxiliar->dato);
      else if(buscarElemento(lista2,auxiliar->dato)==true)
         insertarUltimo(lista3,auxiliar->dato);
      auxiliar=auxiliar->prox;
   }
}

void eliminarLista(Nodo **inicio){ 
   Nodo *mover=NULL; 
   
   if (listaVacia(*inicio))
      cout<<"Lista esta vacia"<<endl;
   else {
      while (*inicio != NULL){
         mover=*inicio;
         *inicio=(*inicio)->prox;
         delete mover;
         mostrarLista(*inicio);
      }
   }
}
