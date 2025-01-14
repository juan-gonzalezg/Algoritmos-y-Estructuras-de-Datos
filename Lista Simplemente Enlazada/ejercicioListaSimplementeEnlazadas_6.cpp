//6) Biblioteca de Libros: Crea un programa para manejar una biblioteca de libros. Cada libro 
//debe tener un título, un autor y un número de ISBN. Debes proporcionar operaciones para 
//agregar nuevos libros, buscar libros por autor (mostrando en pantalla cada libro 
//encontrado) y eliminar libros por su ISBN

#include <iostream>
#include <string>
using namespace std;

struct Libro{
   string titulo;
   string autor;
   int ISBN;
   Libro *prox;
};

Libro* crearNodo(string titulo, string autor, int isbn) {
  Libro *nuevo = new Libro;
  nuevo->titulo=titulo;
  nuevo->autor=autor;
  nuevo->ISBN=isbn;
  nuevo->prox = NULL;
  return nuevo;
}

bool listaVacia(Libro *inicio){
    return inicio==NULL;
}

int longitudString(string palabra1, string palabra2){
   int longitud;
   if(palabra1.length()>palabra2.length())
      longitud=palabra1.length()+2;
   else
      longitud=palabra2.length()+2;
   return longitud;
}

int contarDigitos(int numero){
   int digitos=0;
   while(numero!=0){
      numero/=10;
      digitos++;
   }
   return digitos;
}

void mostrarBiblioteca(Libro *inicio){
   Libro *mover;

   if (!listaVacia(inicio)){
      mover = inicio;
      while (mover != NULL){
         int longitud=longitudString(mover->titulo,mover->autor);
         for(int i=0; i<longitud; i++){
            cout<<"=";
         }
         cout <<"|"<< mover->titulo;
         int longitud2=longitud-((mover->titulo).length());
         for(int i=0; i<longitud2; i++){
            cout<<" ";
         }
         cout<<"|"<<endl;
         cout <<"|"<< mover->autor;
         longitud2=longitud-((mover->autor).length());
         for(int i=0; i<longitud2; i++){
            cout<<" ";
         }
         cout<<"|"<<endl;
         cout <<"|"<< mover->ISBN;
         for(int i=0; i<(longitud-(contarDigitos(mover->ISBN))); i++){
            cout<<" ";
         }
         cout<<"|"<<endl;
         for(int i=0; i<longitud; i++){
            cout<<"=";
         }
         mover = mover->prox;
      }
      cout<<"NULL"<<endl;
   }else
      cout<<"Lista esta vacia"<<endl;
}

void insertarPrincipio(Libro **inicio, string titulo, string autor, int isbn) {
  Libro *nuevo = crearNodo(titulo,autor,isbn);
  nuevo->prox = *inicio;
  *inicio = nuevo;
}

void eliminarLibro(Libro **inicio, int isbn){
   Libro *mover,*anterior = NULL; 
   
   if (listaVacia(*inicio))
       cout<<"La biblioteca esta vacia"<<endl;
   else {   
        mover = *inicio;
        while (mover != NULL && mover->ISBN != isbn){
            anterior = mover;
            mover = mover->prox;
         }
         if (mover == NULL)
            cout<<"El libro no existe en la lista "<<endl;
         else{ 
            if (mover == *inicio)
               *inicio=(*inicio)->prox;
            else
               anterior->prox = mover->prox;
            delete mover;  
            cout<<"El libro fue eliminado correctamente"<<endl;
         }      
   }

}

void eliminarLista(Libro **inicio){
   Libro *mover=NULL; 
   
   if (listaVacia(*inicio))
      cout<<"Lista esta vacia"<<endl;
   else {
      while (*inicio != NULL){
         mover=*inicio;
         *inicio=(*inicio)->prox;
         delete mover;
      }
   }
}

void buscarLibro(Libro *inicio, string autor) {
  Libro *aux = inicio;
  bool encontrado = false;
  if (listaVacia(inicio))
     cout<<"biblioteca vacia"<<endl;
  else
    {   
      while (aux != NULL && encontrado == false) {
         if (aux->autor == autor) {
            cout<<"El libro del autor "<<autor<< " fue encontrado con exito"<<endl;
            cout<<"Libro: "<<endl;
            cout<<"\tTitulo: "<<aux->titulo<<endl;
            cout<<"\tAutor: "<<aux->autor<<endl;
            cout<<"\tISBN: "<<aux->ISBN<<endl;
            encontrado = true;
         }
      else 
          aux = aux->prox;
     }
     if (encontrado == false)
        cout<<"Libro no encontrado en la biblioteca "<<endl;
    }   
}

int pedir_valor(){
   int valor;
   cout<<"Indica cantidad de libros: ";
   cin>>valor;
   return valor;
}

string pedir_titulo(){
   string titulo;
   cout<<"Indica titulo: ";
   cin>>titulo;
   return titulo;
}

string pedir_autor(){
   string autor;
   cout<<"Indica autor de libros: ";
   cin>>autor;
   return autor;
}

int pedir_isbn(){
   int isbn;
   cout<<"Indica numero ISBN de libros: ";
   cin>>isbn;
   return isbn;
}

main(){
   Libro *biblioteca=NULL;
   bool salir=false;
   int opcion=0;
   while(!salir){
      cout<<"MENU"<<endl;
      cout<<"==================="<<endl;
      cout<<"1. Agregar libros"<<endl;
      cout<<"2. Buscar libro"<<endl;
      cout<<"3. Eliminar libro"<<endl;
      cout<<"4. Salir"<<endl;
      cout<<"==================="<<endl;
      cout<<"Opcion: ";
      cin>>opcion;
      switch(opcion){
         case 1:{
            int i=0,cantidad=pedir_valor();
            while(i!=cantidad){
               insertarPrincipio(&biblioteca,pedir_titulo(),pedir_autor(),pedir_isbn());
               i++;
            }
            break;
         }
         case 2:
            if (listaVacia(biblioteca))
               cout<<"Biblioteca vacia, no es posible hacer una busqueda"<<endl;
            else
               buscarLibro(biblioteca, pedir_autor());
            break;
         case 3:
            if (listaVacia(biblioteca))
               cout<<"Biblioteca vacia, no es posible eliminar"<<endl;
            else
               eliminarLibro(&biblioteca, pedir_isbn());
            break;
         default:
            salir=true;
      }
   }
   eliminarLista(&biblioteca);
}