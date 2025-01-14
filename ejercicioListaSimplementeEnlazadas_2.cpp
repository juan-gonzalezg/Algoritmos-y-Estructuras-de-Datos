// 2) Agregar un elemento X a una lista después de un valor N dado por el usuario. Ejemplo: 
// L1=  {1,33,7,22,1,4,5}  N=7,  X=777  =>  L1={1,33,7,777,22,1,4,5}  .  Realizar  las  validaciones 
// pertinentes.

#include <iostream>
using namespace std;

struct Nodo {
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

void agregarUnElementoDespuesDeNValor(Nodo **inicio, int x, int n){
   Nodo *nuevo = crearNodo(x);
 
   if (listaVacia(*inicio))
      cout << "La lista esta vacia";
   else{
      Nodo *auxiliar = *inicio;
      while (auxiliar != NULL && auxiliar->dato != n) {
         auxiliar = auxiliar->prox;
      }
      buscarElemento(*inicio,n);
      if(auxiliar != NULL && auxiliar->dato == n){
         nuevo->prox = auxiliar->prox;
         auxiliar->prox = nuevo;
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

void mostrarLista(Nodo *inicio){
   Nodo *mover;

   if (!listaVacia(inicio)){
      mover = inicio;
      while (mover != NULL){
         cout << mover->dato <<"->";
         mover = mover->prox;
      }
      cout<<"NULL"<<endl;
   }else
      cout<<"Lista esta vacia"<<endl;
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

main(){
   Nodo *lista=NULL;
   int x,n;
   bool salir=false;
   bool nodoEncontrado=false;
   char desicion=' ';
   llenarLista(&lista);
   while(!salir){
      cout<<"Indica el valor de un elemento en la lista para agregar un valor posterior a ese elemento: ";
      cin>>n;
      cout<<"Indica el valor a agregar a la lista: ";
      cin>>x;
      cout<<"Desea agregar otro valor Y[si] o N[no]: ";
      cin>>desicion;
      nodoEncontrado=buscarElemento(lista,n);
      if(nodoEncontrado)
         agregarUnElementoDespuesDeNValor(&lista,x,n);
      mostrarLista(lista);
      if(desicion=='N')
         salir=true;
   }
   eliminarLista(&lista);
}