//7) Mezclar dos listas ordenadas en una nueva lista ordenada sin elementos repetidos.

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

bool buscarElemento(Nodo *inicio, int valor) {
  Nodo *aux = inicio; bool encontrado = false;
  if (listaVacia(inicio))
     cout<<"Lista vacia"<<endl;
  else
    {   
      while (aux != NULL && encontrado == false) {
         if (aux->dato == valor)
            encontrado = true;
      else 
          aux = aux->prox;
     }
    }
    return encontrado;  
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

void insertarPrincipio(Nodo **inicio, int valor) {
  Nodo *nuevo = crearNodo(valor);
  nuevo->prox = *inicio;
  *inicio = nuevo;
}

void mezclarLista(Nodo *lista1, Nodo *lista2, Nodo **lista3){
   Nodo *actual1=lista1, *actual2=lista2;
   if(listaVacia(lista1) && listaVacia(lista2))
      cout<<"Las listas estan vacias";
   else if(listaVacia(lista1) && !listaVacia(lista2)){
      while(actual2!=NULL){
         insertarUltimo(lista3,actual2->dato);
         actual2=actual2->prox;
      }
   }else if(!listaVacia(lista1) && listaVacia(lista2)){
      while(actual1!=NULL){
         insertarUltimo(lista3,actual1->dato);
         actual1=actual1->prox;
      }
   }else{
      while(actual1!=NULL && actual2!=NULL){
         if(actual1->dato<actual2->dato){
            if(listaVacia(*lista3)){
               insertarUltimo(lista3,actual1->dato);
               insertarUltimo(lista3,actual2->dato);
            }else{
               if(buscarElemento(*lista3,actual1->dato) && !buscarElemento(*lista3,actual2->dato))
                  insertarUltimo(lista3,actual2->dato);
            }
         }else{
            if(listaVacia(*lista3)){
               insertarUltimo(lista3,actual1->dato);
               insertarUltimo(lista3,actual2->dato);
            }else{
               if(buscarElemento(*lista3,actual2->dato) && !buscarElemento(*lista3,actual1->dato))
                  insertarUltimo(lista3,actual1->dato);
            }
         }
         actual1=actual1->prox;
         actual2=actual2->prox;
      }
   }
}
