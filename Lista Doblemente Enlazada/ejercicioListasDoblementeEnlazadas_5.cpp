//5) Desarrolla  una  función  que  devuelva  verdad  si  a  partir  de  dos  listas  dadas,  la 
//primera  lista  está  contenida  en  la  segunda  en  el  mismo  orden  consecutivo. 
//Ejemplo: 
//L1 = {1, 2, 55, 3, 4} 
//L2 = {80, 1, 23, 1, 2, 55, 3, 4, 100, 200} 
//En este caso L1 se encuentra en L2

#include <iostream>
using namespace std;

//Elaborado por Lia Mendoza

// Definicion de la estructura de un nodo de lista doblemente enlazada
struct Nodo {
  int dato;
  Nodo *previo;
  Nodo *prox;
};

// Funcion para crear un nuevo nodo de lista doblemente enlazada
Nodo* crearNodo(int dato) {
  Nodo *nuevo = new Nodo;
  nuevo->dato = dato;
  nuevo->previo = NULL;
  nuevo->prox = NULL;
  return nuevo;
}

// Funcion para insertar un elemento al principio de una lista doblemente enlazada
void insertarInicio(Nodo **inicio, int valor) {
  Nodo *nuevo = crearNodo(valor);
  nuevo->prox = *inicio;
  if (*inicio != NULL) {
   (*inicio)->previo = nuevo;
  }
   *inicio = nuevo;
}

// Funcion para comprobar si una lista doblemente enlazada esta vacia
bool listaVacia(Nodo *inicio) {
  return inicio == NULL;
}

// Funcion para mostrar el contenido de una lista doblemente enlazada
void mostrarLista(Nodo *inicio) {
  if (!listaVacia(inicio)) {
    Nodo *actual = inicio;
    while (actual != NULL) {
      cout << actual->dato << "->"; 
      actual = actual->prox;
    }
    cout<<"NULL"<<endl;
  } else {
       cout << "La lista esta vacia" << endl;
  }
}

// Funcion para eliminar un elemento de una lista doblemente enlazada
void eliminar(Nodo **inicio, int dato) {
  Nodo *actual = *inicio;

  if (listaVacia(*inicio))
       cout<<"Lista esta vacia"<<endl;
  else {   
        while (actual != NULL && actual->dato != dato) {
                  actual = actual->prox;
             } 

          // Si el elemento no se encuentra en la lista
            if (actual == NULL) 
                  cout<<"El elemento no existe en la lista: ";
            else {
                  // Si el elemento a eliminar es el primero de la lista
                  if (actual->previo == NULL){
                       *inicio = actual->prox;
                        if (*inicio != NULL)
                           (*inicio)->previo=NULL;
                      
                      }
                  else {
                    if (actual->prox == NULL)  //si es el ultimo
                        actual->previo->prox= NULL;
                    else
                    { // si es cualquier posicion
                     actual->previo->prox = actual->prox;
                     actual->prox->previo = actual->previo;
                    }
                  }                 
                
                // Liberamos la memoria del nodo eliminado
                 delete actual;
            } 
     }
}    

// Funcion para buscar un elemento en una lista doblemente enlazada
bool buscar(Nodo *inicio, int dato) {
  Nodo *actual = inicio;
  while (actual != NULL && actual->dato != dato) {
    actual = actual->prox;
  }

  // Si el elemento se encuentra en la lista
  return actual != NULL;
}


void insertarUltimo(Nodo **inicio, int valor) 
{
 
   Nodo *nuevo = crearNodo(valor);
 
  // Si la lista esta vacia
    if (listaVacia(*inicio))
       *inicio = nuevo;
    else 
     {

       // Recorremos la lista hasta el ultimo nodo
       Nodo *actual = *inicio;
       while (actual->prox != NULL) {
            actual = actual->prox;
        }

      // Insertamos el nuevo nodo al final de la lista
        actual->prox = nuevo;
        actual->prox->previo = actual;
     }
}

// No es una operacion basica, es para imprimir de derecha a izquierda
void moverIZD (Nodo *inicio){
 Nodo *actual;

 actual = inicio;
 while (actual->prox != NULL)
   {
     actual=actual->prox;
   } 
  while (actual  != NULL){
    cout<<actual->dato<<"->";
    actual=actual->previo;
  }

  cout<<"inicio"<<endl;


}


bool l1enl2(Nodo *inicio1, Nodo *inicio2, int cantNodosL1, int cantNodosL2){
   bool distintos=false;
   while(inicio2!=NULL){
      Nodo *aux1=inicio1;
      Nodo *aux2=inicio2;
      if(cantNodosL1<=cantNodosL2){
         distintos=false;
         while(aux1!=NULL && distintos==false){
            if(aux1->dato!=aux2->dato)
               distintos=true;
            aux1=aux1->prox;
            aux2=aux2->prox;
         }
      }
      inicio1=inicio1->prox;
      inicio2=inicio2->prox;
      cantNodosL2--;
   }
   return distintos;
}