//Elaborado por: Juan Gonzalez

#include <iostream>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <sstream>
using namespace std;

struct Episodio{
   string tituloEpisodio;
   int duracion;
   int numeroEpisodio;
   float puntuacion;
   Episodio *proxEpisodio;
};

struct Serie{
   string nombre;
   string genero;
   int nivelDeAudiencia;
   Serie *proxSerie;
   Episodio *listaEpisodio;
};

Serie* crearSerie(string nombre, string genero, int nivelDeAudiencia){
  Serie *nuevo = new Serie;
  nuevo->nombre=nombre;
  nuevo->genero=genero;
  nuevo->nivelDeAudiencia=nivelDeAudiencia;
  nuevo->proxSerie=NULL;
  nuevo->listaEpisodio=NULL;
  return nuevo;
}

bool listaVaciaSerie(Serie *inicio){
   return inicio==NULL;
}

bool listaVaciaEpisodio(Episodio *inicio){
   return inicio==NULL;
}

void agregarSerie(Serie **inicio, string nombre, string genero, int nivelDeAudiencia){//Permitir al usuario agregar una nueva serie a la lista principal. 
   Serie *nuevo=crearSerie(nombre,genero,nivelDeAudiencia);
   if(listaVaciaSerie(*inicio))
      *inicio=nuevo;
   else{
      Serie *auxiliar=*inicio;
      while(auxiliar->proxSerie!=NULL){
         auxiliar=auxiliar->proxSerie;
      }
      auxiliar->proxSerie=nuevo;
   }
   cout<<endl<<"Se agrego la Serie!"<<endl;
}

string convertirAMinudcula(string cadena){
   char letra;
   string minuscula="";
   int longitud=cadena.length();
   for(int i=0; i<longitud; i++){
      letra=cadena[i];
      minuscula+=towlower(letra);
   }
   return minuscula;
}

void eliminarSerie(Serie **inicio, string nombreSerie){//Permitir eliminar una serie y todos sus episodios. 
   Serie *actual=*inicio;
   Serie *anterior=*inicio;
   Episodio *episodio=NULL;
   string nombre=convertirAMinudcula(nombreSerie);
   if(listaVaciaSerie(*inicio))
      cout<<"No hay Series en la lista!"<<endl;
   else if(convertirAMinudcula((*inicio)->nombre)==nombre){
      *inicio=(*inicio)->proxSerie;
      delete actual;
   }else{
      while(actual!=NULL && convertirAMinudcula(actual->nombre)!=nombre){
         anterior=actual;
         actual=actual->proxSerie;
      }
      if(actual==NULL)
         cout<<"La serie no se encuentra en la lista!"<<endl;
      else{
         episodio=actual->listaEpisodio;
         Episodio *auxiliar=episodio;
         if(listaVaciaEpisodio(episodio))
            cout<<"La serie no tiene episodios"<<endl;
         else{
            while(auxiliar!=NULL){
               episodio=auxiliar->proxEpisodio;
               delete auxiliar;
               auxiliar=episodio;
            }
            cout<<endl<<"Los Episodios fueron eliminados!"<<endl;
         }
         if(actual==*inicio)
            *inicio=(*inicio)->proxSerie;
         else{
            anterior->proxSerie=actual->proxSerie;
            delete actual;
            cout<<endl<<"La Serie fue eliminada!"<<endl;
         }
      }
   }
}

Episodio* crearEpisodio(string titulo,int duracion,int numero, float puntuacion){
   Episodio *nuevo=new Episodio;
   nuevo->tituloEpisodio=titulo;
   nuevo->duracion=duracion;
   nuevo->numeroEpisodio=numero;
   nuevo->puntuacion=puntuacion;
   nuevo->proxEpisodio=NULL;
   return nuevo;
}

void agregarEpisodio(Episodio **inicio, string titulo, int duracion, int numero, float puntuacion){
   Episodio *nuevo=crearEpisodio(titulo,duracion,numero,puntuacion);
   if(listaVaciaEpisodio(*inicio)){
      *inicio=nuevo;
   }
   else{
      Episodio *auxiliar=*inicio;
      while(auxiliar->proxEpisodio!=NULL){
         auxiliar=auxiliar->proxEpisodio;
      }
      auxiliar->proxEpisodio=nuevo;
   } 
}

int convertirStringEntero(string cadena){
   return stoi(cadena);
}

float convertirStringFlotante(string cadena){
   return stod(cadena);
}

bool esFlotanteEnetro(string cadena){
   int longitud=cadena.length();
   for(int i=0;i<longitud;i++){
      if(cadena[i]=='.')
         return true;
   }
   return false;
}

bool esNumero(string cadena){
   int longitud=cadena.length();
   bool espacio=false;
   bool ha_visto_punto=false;
   for(int i=0;i<longitud;i++){
      espacio=isspace(cadena[i]);
      if(espacio)
         return false;
      if(isdigit(cadena[i]))
         continue;
      else if(cadena[i]=='.' && !ha_visto_punto)
         ha_visto_punto=true;
      else
         return false;
   }
   return true;
}

bool esLetra(string cadena){
   int longitud=cadena.length();
   for(int i=0;i<longitud;i++){
      if(!isalpha(cadena[i]) && cadena[i]!=' ')
         return false;
   }
   return true;
}

void agregarEpisodioSerieEspecifica(Serie **inicio, string nombre){//Permitir agregar episodios a una serie ya existente. 
   Serie *actual=*inicio, *aux=NULL;
   Episodio *lista=NULL;
   bool encontrado=false,continuar=true;
   string titulo, duracion, numero, cantidad, puntuacion;
   float puntuacionEpisodio;
   int duracionEpisodio, numeroEpisodio, cantidadEpisodios;
   if(listaVaciaSerie(*inicio))
      cout<<"No hay series en la lista"<<endl;
   else{
      while(actual!=NULL && encontrado==false){
         if(convertirAMinudcula(actual->nombre)==convertirAMinudcula(nombre)){
            encontrado=true;
            aux=actual;
         }
         actual=actual->proxSerie;
      }
      if(encontrado==false){
         cout<<"La Serie no se encuentra en la lista"<<endl;
      }else{
         cout<<endl;
         while(continuar){
            cout<<"Indique el numero de espisodios a agregar: ";
            getline(cin,cantidad);
            if(esNumero(cantidad)){
               continuar=false;
               cantidadEpisodios=convertirStringEntero(cantidad);
            }else
               cout<<"Debe ingresar un numero!"<<endl;
         }
         continuar=true;
         while(cantidadEpisodios>0){
            cout<<endl;
            while(continuar){
               cout<<"Indique el titulo del Episodio: ";
               getline(cin,titulo);
               if(esLetra(titulo))
                  continuar=false;
               else
                  cout<<"Debe ingresar un titulo! Sin numeros y sin signos o simbolos."<<endl;
            }
            continuar=true;
            while(continuar){
               cout<<"Indique la duracion del Episodio (minutos): ";
               getline(cin,duracion);
               if(esNumero(duracion)){
                  continuar=false;
                  duracionEpisodio=convertirStringEntero(duracion);
               }else
                  cout<<"Debe ingresar el tiempo de duracion en minutos! Numero entero."<<endl;
            }
            continuar=true;
            while(continuar){
               cout<<"Indique el numero del Episodio: ";
               getline(cin,numero);
               if(esNumero(numero)){
                  continuar=false;
                  numeroEpisodio=convertirStringEntero(numero);
            }else
               cout<<"Debe ingresar un numero!"<<endl;
            }
            continuar=true;
            while(continuar){
               cout<<"Indique la puntuacion del Episodio (0-10): ";
               getline(cin,puntuacion);
               if(esNumero(puntuacion)){
                  continuar=false;
                  if(esFlotanteEnetro(puntuacion)){
                     puntuacionEpisodio=convertirStringFlotante(puntuacion);
                  }else
                     puntuacionEpisodio=convertirStringEntero(puntuacion);
               }else
                  cout<<"Debe ingresar un numero!"<<endl;
            }
            continuar=true;
            agregarEpisodio(&lista,titulo,duracionEpisodio,numeroEpisodio,puntuacionEpisodio);
            cantidadEpisodios--;
         }
         aux->listaEpisodio=lista;
      }
   }
   cout<<endl;
}

void eliminarEpisodio(Episodio **lista, string titulo){
   Episodio *auxiliar=*lista;
   Episodio *anterior=NULL;
   bool encontrado=false;
   if(listaVaciaEpisodio(*lista))
      cout<<"No hay Episodios en la Serie!"<<endl;
   else{
      while(auxiliar!=NULL && encontrado==false){
         if(convertirAMinudcula(auxiliar->tituloEpisodio)==convertirAMinudcula(titulo))
            encontrado=true;
         else {
            anterior=auxiliar;
            auxiliar=auxiliar->proxEpisodio;
         }
      }
      if(encontrado==false)
         cout<<"El Episodio no se encuentra en la lista!"<<endl;
      else{
         if(auxiliar==*lista)
            *lista=(*lista)->proxEpisodio;
         else
            anterior->proxEpisodio=auxiliar->proxEpisodio;
         delete auxiliar;
         cout<<endl<<"El Episodio fue eliminado!"<<endl;
      }
   }
}

void eliminarEpisodioSerie(Serie **inicio, string nombre){//Permitir al usuario eliminar un episodio específico de una serie dada.
   Serie *actual=*inicio, *aux=NULL;
   bool encontrado=false, continuar=true;
   string titulo;
   if(listaVaciaSerie(*inicio))
      cout<<"No hay Series en la lista!"<<endl;
   else{
      while(actual!=NULL && encontrado==false){
         if(convertirAMinudcula(actual->nombre)==convertirAMinudcula(nombre)){
            encontrado=true;
            aux=actual;
         }
         actual=actual->proxSerie;
      }
      if(encontrado==false)
         cout<<"La serie no se encuentra en la lista!"<<endl;
      else{
         cout<<endl;
         while(continuar){
            cout<<"Indique el titulo del Episodio a eliminar: ";
            getline(cin,titulo);
            if(esLetra(titulo))
               continuar=false;
            else
               cout<<"Debe ingresar un titulo! Sin numeros y sin signos o simbolos."<<endl;
         }
         eliminarEpisodio(&aux->listaEpisodio,titulo);
      }
   }
}

void listarSeriesEpisodios(Serie *inicio){//Mostrar al usuario todas las series y sus episodios asociados. 
   Serie *actual=inicio;
   Episodio *auxiliar=NULL;
   cout<<"                 _                                  _               _ _            "<<endl;
   cout<<"                (_)                                (_)             | (_)           "<<endl;
   cout<<"   ___  ___ _ __ _  ___  ___    _   _     ___ _ __  _ ___  ___   __| |_  ___  ___  "<<endl;
   cout<<"  / __|/ _ \\ '__| |/ _ \\/ __|  | | | |   / _ \\ '_ \\| / __|/ _ \\ / _` | |/ _ \\/ __| "<<endl;
   cout<<"  \\__ \\  __/ |  | |  __/\\__ \\  | |_| |  |  __/ |_) | \\__ \\ (_) | (_| | | (_) \\__ \\ "<<endl;
   cout<<"  |___/\\___|_|  |_|\\___||___/   \\__, |   \\___| .__/|_|___/\\___/ \\__,_|_|\\___/|___/ "<<endl;
   cout<<"                                 __/ |       | |                                   "<<endl;
   cout<<"                                |___/        |_|                                   "<<endl;
   cout<<"------------------------------------------------------------------------------------"<<endl;
   if(listaVaciaSerie(inicio))
      cout<<"No hay Series en la lista"<<endl;
   else{
      while(actual!=NULL){
         cout<<"  --------------------------------------------------------------------------------"<<endl;
         cout<<"Nombre de la Serie: "<<actual->nombre<<endl;
         cout<<"Genero de la Serie: "<<actual->genero<<endl;
         cout<<"Nivel de Audiencia de la Serie: "<<actual->nivelDeAudiencia<<endl;
         cout<<endl;
         auxiliar=actual->listaEpisodio;
         if(auxiliar==NULL)
            cout<<"No hay Episodios en la Serie!"<<endl;
         else{
            cout<<"Lista de Episodios: "<<endl;
            while(auxiliar!=NULL){
               cout<<endl<<"Titulo del Episodio: "<<auxiliar->tituloEpisodio<<endl;
               cout<<"Duracion del Episodio: "<<auxiliar->duracion<<endl;
               cout<<"Numero del Episodio: "<<auxiliar->numeroEpisodio<<endl;
               cout<<"Puntuacion del Episodio: "<<auxiliar->puntuacion<<endl;
               auxiliar=auxiliar->proxEpisodio;
            }
         }
         cout<<endl;
         cout<<"  --------------------------------------------------------------------------------"<<endl;
         actual=actual->proxSerie;
      }
   }
   cout<<"------------------------------------------------------------------------------------"<<endl;
}

void mostrarEpisodio(Episodio *lista){
   Episodio *auxiliar=lista;
   cout<<"                         _               _ _                        "<<endl;
   cout<<"                        (_)             | (_)                       "<<endl;
   cout<<"               ___ _ __  _ ___  ___   __| |_  ___  ___              "<<endl;
   cout<<"              / _ \\ '_ \\| / __|/ _ \\ / _` | |/ _ \\/ __|             "<<endl;
   cout<<"             |  __/ |_) | \\__ \\ (_) | (_| | | (_) \\__ \\             "<<endl;
   cout<<"              \\___| .__/|_|___/\\___/ \\__,_|_|\\___/|___/             "<<endl;
   cout<<"                  | |                                               "<<endl;
   cout<<"                  |_|                                               "<<endl;
   cout<<"--------------------------------------------------------------------"<<endl;
   if(listaVaciaEpisodio(lista))
      cout<<"No hay Episodios en la Serie!"<<endl;
   else{
      while(auxiliar!=NULL){
         cout<<endl<<"Titulo del Episodio: "<<auxiliar->tituloEpisodio<<endl;
         cout<<"Duracion del Episodio: "<<auxiliar->duracion<<endl;
         cout<<"Numero del Episodio: "<<auxiliar->numeroEpisodio<<endl;
         cout<<"Puntuacion del Episodio: "<<auxiliar->puntuacion<<endl;
         auxiliar=auxiliar->proxEpisodio;
      }
   }
   cout<<"--------------------------------------------------------------------"<<endl;
}

void buscarSerie(Serie *inicio, string nombre){//Buscar una serie por nombre y mostrar sus episodios. 
   Serie *actual=inicio;
   Episodio *lista=NULL;
   bool encontrado=false;
   if(listaVaciaSerie(inicio))
      cout<<"No hay series en la lista!"<<endl;
   else{
      while(actual!=NULL && encontrado==false){
         if(convertirAMinudcula(actual->nombre)==convertirAMinudcula(nombre)){
            encontrado=true;
            lista=actual->listaEpisodio;
            mostrarEpisodio(lista);
         }
         actual=actual->proxSerie;
      }
      if(encontrado==false)
         cout<<"La Serie no se encuentra en la lista!"<<endl;
   }
}

void intercambiarSeries(Serie* serie1, Serie* serie2) {
   string nombreTemporal=serie1->nombre;
   string generoTemporal=serie1->genero;
   int nivelDeAudienciaTemporal=serie1->nivelDeAudiencia;
   Episodio* listaEpisodioTemporal=serie1->listaEpisodio;

   serie1->nombre=serie2->nombre;
   serie1->genero=serie2->genero;
   serie1->nivelDeAudiencia=serie2->nivelDeAudiencia;
   serie1->listaEpisodio=serie2->listaEpisodio;
   serie2->nombre=nombreTemporal;
   serie2->genero=generoTemporal;
   serie2->nivelDeAudiencia=nivelDeAudienciaTemporal;
   serie2->listaEpisodio=listaEpisodioTemporal;
}

void ordenarSeriesAlfabeticamente(Serie** inicio){
   bool intercambiado;
   Serie *actual=*inicio;
   Serie *ultimo=NULL;

   if(listaVaciaSerie(*inicio))
      cout<<"No hay series en la lista!"<<endl;
   else{
      do{
         intercambiado=false;
         actual=*inicio;
         while(actual->proxSerie!=ultimo){
            if(actual->nombre>actual->proxSerie->nombre){
               intercambiarSeries(actual,actual->proxSerie);
               intercambiado=true;
            }
            actual=actual->proxSerie;
         }
         ultimo=actual;
      }while(intercambiado);
   }
}

void mostrarTopSerie(Serie *top, int numero){
   cout<<"Top "<<numero<<" :"<<endl;
   cout<<top->nombre<<endl;
   cout<<top->genero<<endl;
   cout<<top->nivelDeAudiencia<<endl;
}

Serie* buscarTop(Serie *inicio, int audienciaMin, int audienciaMay, Serie *top1, Serie *top2){
   Serie *top=NULL;
   if(listaVaciaSerie(inicio))
      cout<<"No hay Series en la Lista!"<<endl;
   else{
      while(inicio!=NULL){
         if(inicio->nivelDeAudiencia>=audienciaMin && inicio->nivelDeAudiencia<=audienciaMay && inicio!=top1 && inicio!=top2){
            top=inicio;
            audienciaMin=inicio->nivelDeAudiencia;
         }
         inicio=inicio->proxSerie;
      }
   }
   return top;
}

void seriesOcupanTresPrimerosLugares(Serie *inicio){//Mostrar cuales series ocupan los tres primeros lugares según el nivel de audiencia.
   Serie *actual=inicio;
   Serie *top1=NULL, *top2=NULL, *top3=NULL;
   if(listaVaciaSerie(inicio))
      cout<<"No hay series en la lista!"<<endl;
   else{
      cout<<"                    _                ____"<<endl;
      cout<<"                   | |              |___ \\"<<endl;
      cout<<"                   | |_ ___  _ __     __) |"<<endl;
      cout<<"                   | __/ _ \\| '_ \\   |__ <"<<endl;
      cout<<"                   | || (_) | |_) |  ___) |"<<endl;
      cout<<"                    \\__\\___/| .__/  |____/"<<endl;
      cout<<"                            | |"<<endl;
      cout<<"                            |_|"<<endl;
      cout<<"--------------------------------------------------------------"<<endl;
      top1=buscarTop(actual,0,999999999,top1,top2);
      mostrarTopSerie(top1,1);
      cout<<endl;
      top2=buscarTop(actual,0,top1->nivelDeAudiencia,top1,top2);
      mostrarTopSerie(top2,2);
      cout<<endl;
      top3=buscarTop(actual,0,top2->nivelDeAudiencia,top1,top2);
      mostrarTopSerie(top3,3);
      cout<<"--------------------------------------------------------------"<<endl;
   }
}

Episodio* mayorDuracion(Episodio *lista){
   Episodio *mayor=NULL;
   int duracion=0;
   if(listaVaciaEpisodio(lista))
      cout<<"No hay Episodios en la Serie!"<<endl;
   else{
      while(lista!=NULL){
         if(lista->duracion>duracion){
            mayor=lista;
            duracion=lista->duracion;
         }
         lista=lista->proxEpisodio;
      }
   }
   return mayor;
}

void mostrarEpisodioMayorDuracion(Episodio *lista){
   cout<<endl<<"Datos del Episodio de mayor duracion:"<<endl;
   cout<<"Titulo del Episodio: "<<lista->tituloEpisodio<<endl;
   cout<<"Duracion del Episodio: "<<lista->duracion<<endl;
   cout<<"Numero del Episodio: "<<lista->numeroEpisodio<<endl;
   cout<<"Puntuacion del Episodio: "<<lista->puntuacion<<endl;
}

void buscarEpisodioMayorDuracion(Serie *inicio, string nombre){//Mostrar cuál es el episodio de la serie que dura más tiempo. 
   Serie *actual=inicio, *aux=NULL;
   Episodio *epActual=NULL;
   bool encontrado=false;
   if(listaVaciaSerie(inicio))
      cout<<"No hay series en la lista!"<<endl;
   else{
      while(actual!=NULL && encontrado==false){
         if(convertirAMinudcula(actual->nombre)==convertirAMinudcula(nombre)){
            encontrado=true;
            aux=actual;
         }
         actual=actual->proxSerie;
      }
      if(encontrado==false)
         cout<<"La Serie no se encuentra en la lista!"<<endl;
      else{
         if(aux->listaEpisodio==NULL)
            cout<<"No hay Episodios en la Serie!"<<endl;
         else{
            epActual=mayorDuracion(aux->listaEpisodio);
            mostrarEpisodioMayorDuracion(epActual);
         }
      }
   }
}

void buscarEpisodio(Serie *inicio, string nombre, string titulo){//Buscar un episodio en particular dentro de una serie. 
   Serie *actual=inicio;
   Episodio *epActual=NULL;
   bool seEncontrada=false, epEncontrado=false;
   if(listaVaciaSerie(inicio))
      cout<<"No hay Series en la lista!"<<endl;
   else{
      while(actual!=NULL && seEncontrada==false){
         if(convertirAMinudcula(actual->nombre)==convertirAMinudcula(nombre)){
            epActual=actual->listaEpisodio;
            if(listaVaciaEpisodio(epActual))
               cout<<"No hay Episodios en la Serie!"<<endl;
            else{
               while(epActual!=NULL && epEncontrado==false){
                  if(convertirAMinudcula(epActual->tituloEpisodio)==convertirAMinudcula(titulo)){
                     cout<<"Episodio fue encontrado!"<<endl<<endl;
                     cout<<"Datos del Episodio:"<<endl;
                     cout<<"Titulo del Episodio: "<<epActual->tituloEpisodio<<endl;
                     cout<<"Duracion del Episodio: "<<epActual->duracion<<endl;
                     cout<<"Numero del Episodio: "<<epActual->numeroEpisodio<<endl;
                     cout<<"Puntuacion del Episodio: "<<epActual->puntuacion<<endl;
                     epEncontrado=true;
                  }
                  epActual=epActual->proxEpisodio;
               }
            }
            seEncontrada=true;
         }
         actual=actual->proxSerie;
      }
   }
}

void mostrarTiempoTotalEpisodiosSerie(Serie *inicio, string nombre){//Mostrar el tiempo total de todos los episodios de una serie
   Serie *actual=inicio;
   Episodio *epActual=NULL;
   int tiempoTotal=0;
   bool encontrado=false;
   if(listaVaciaSerie(inicio))
      cout<<"No hay series en la lista!";
   else{
      while(actual!=NULL && encontrado==false){
         if(convertirAMinudcula(actual->nombre)==convertirAMinudcula(nombre)){
            epActual=actual->listaEpisodio;
            if(listaVaciaEpisodio(epActual))
               cout<<"No hay episodios en la serie!"<<endl;
            else{
               while(epActual!=NULL){
                  tiempoTotal+=epActual->duracion;
                  epActual=epActual->proxEpisodio;
               }
            }
            cout<<"El tiempo total de todos los Episodios de la Serie es (minutos): "<<tiempoTotal<<endl<<endl;
            encontrado=true;
         }
         actual=actual->proxSerie;
      }
   }
}

Episodio* mayorPuntuacion(Episodio *lista){
   Episodio *mayor=NULL;
   float puntuacion=0;
   if(listaVaciaEpisodio(lista))
      cout<<"No hay Episodios en la Serie!"<<endl;
   else{
      while(lista!=NULL){
         if(lista->puntuacion>puntuacion){
            mayor=lista;
            puntuacion=lista->puntuacion;
         }
         lista=lista->proxEpisodio;
      }
   }
   return mayor;
}

void mostrarEpisodioMayorPuntuacion(Episodio *lista){
   cout<<endl<<"Datos del Episodio de mayor Puntucion:"<<endl;
   cout<<"Titulo del Episodio: "<<lista->tituloEpisodio<<endl;
   cout<<"Duracion del Episodio: "<<lista->duracion<<endl;
   cout<<"Numero del Episodio: "<<lista->numeroEpisodio<<endl;
   cout<<"Puntuacion del Episodio: "<<lista->puntuacion<<endl;
}

void episodioMayorPuntuacion(Serie *inicio){//Mostrar el episodio con mayor puntuacion de cada serie
   Serie *actual=inicio, *aux=NULL;
   Episodio *epActual=NULL;
   if(listaVaciaSerie(inicio))
      cout<<"No hay series en la lista!"<<endl;
   else{
      cout<<endl;
      cout<<"                __  _ _     _           _        _                 _                 _"<<endl;
      cout<<"               /_/ | (_)   (_)         | |      | |               | |               (_)"<<endl;
      cout<<"   __ _ _ __   __ _| |_ ___ _ ___    __| | ___  | |_ ___ _ __   __| | ___ _ __   ___ _  __ _ ___"<<endl;
      cout<<"  / _` | '_ \\ / _` | | / __| / __|  / _` |/ _ \\ | __/ _ \\ '_ \\ / _` |/ _ \\ '_ \\ / __| |/ _` / __|"<<endl;
      cout<<" | (_| | | | | (_| | | \\__ \\ \\__ \\ | (_| |  __/ | ||  __/ | | | (_| |  __/ | | | (__| | (_| \\__ \\"<<endl;
      cout<<"  \\__,_|_| |_|\\__,_|_|_|___/_|___/  \\__,_|\\___|  \\__\\___|_| |_|\\__,_|\\___|_| |_|\\___|_|\\__,_|___/"<<endl;
      cout<<endl;
      cout<<"--------------------------------------------------------------------------------------------------"<<endl;
      cout<<endl;
      while(actual!=NULL){
         cout<<"Nombre de la serie: "<<actual->nombre<<endl;
         aux=actual;
         if(aux->listaEpisodio!=NULL){
            epActual=mayorPuntuacion(aux->listaEpisodio);
            mostrarEpisodioMayorPuntuacion(epActual);
            cout<<endl;
         }
         actual=actual->proxSerie;
      }
      
   }
}

void puntuacionPromedio(Episodio *lista){
   int cantidadEp=0;
   float sumaPuntuacion=0;
   float puntuacion=0;
   if(listaVaciaEpisodio(lista))
      cout<<"No hay Episodios en la Serie!"<<endl;
   else{
      while(lista!=NULL){
         cantidadEp++;
         sumaPuntuacion+=lista->puntuacion;
         lista=lista->proxEpisodio;
      }
      puntuacion=sumaPuntuacion/cantidadEp;
      cout<<endl<<"La puntuacion promedio de los episodios de la Serie es: "<<puntuacion<<endl;
   }
}

void puntuacionPromedioEpisodios(Serie *inicio, string nombre){//Mostrar el promedio de puntuación de los episodios de una serie
   Serie *actual=inicio, *aux=NULL;
   Episodio *epActual=NULL;
   if(listaVaciaSerie(inicio))
      cout<<"No hay series en la lista!"<<endl;
   else{
      while(actual!=NULL){
         if(convertirAMinudcula(actual->nombre)==convertirAMinudcula(nombre)){
            aux=actual;
            epActual=aux->listaEpisodio;
            cout<<"Nombre de la Serie: "<<aux->nombre<<endl;
            puntuacionPromedio(epActual);
         }
         cout<<endl;
         actual=actual->proxSerie;
      }
   }
}

void escribirSeries(Serie *inicio, string nombreArchivo){
   ofstream archivo(nombreArchivo);
   if(!archivo.is_open()){
      cout<<"Error al abrir el archivo"<<endl;
      return;
   }
   Serie *actual=inicio;
   while(actual!=nullptr){
      archivo<<actual->nombre<<"|"<<actual->genero<<"|"<<actual->nivelDeAudiencia;
      Episodio *episodio=actual->listaEpisodio;
      while(episodio!=nullptr){
         archivo<<"|"<<episodio->tituloEpisodio<<"|"<<episodio->duracion<<"|"<<episodio->numeroEpisodio<<"|"<<episodio->puntuacion;
         episodio=episodio->proxEpisodio;
      }
      archivo<<endl;
      actual=actual->proxSerie;
   }
   archivo.close();
}

void menu(Serie **inicio, string rutaArchivo){
   string opcion;
   int opcionElegida;
   bool continuar=true;
   while(opcionElegida!=14){
      cout<<endl;
      continuar=true;
      while(continuar){
         cout<<"                                      __               _            _             _"<<endl;
         cout<<"                                     /_/              (_)          (_)           | |"<<endl;
         cout<<"              _ __ ___   ___ _ __  _   _    _ __  _ __ _ _ __   ___ _ _ __   __ _| |"<<endl;
         cout<<"             | '_ ` _ \\ / _ \\ '_ \\| | | |  | '_ \\| '__| | '_ \\ / __| | '_ \\ / _` | |"<<endl;
         cout<<"             | | | | | |  __/ | | | |_| |  | |_) | |  | | | | | (__| | |_) | (_| | |"<<endl;
         cout<<"             |_| |_| |_|\\___|_| |_|\\__,_|  | .__/|_|  |_|_| |_|\\___|_| .__/ \\__,_|_|"<<endl;
         cout<<"                                           | |                       | |"<<endl;
         cout<<"                                           |_|                       |_|"<<endl;
         cout<<"--------------------------------------------------------------------------------------------------"<<endl;
         cout<<"1. Agregar una serie"<<endl;
         cout<<"2. Eliminar una serie"<<endl;
         cout<<"3. Agregar un episodio a una serie especifica"<<endl;
         cout<<"4. Eliminar un episodio de una serie"<<endl;
         cout<<"5. Listar series y episodios"<<endl;
         cout<<"6. Buscar serie"<<endl;
         cout<<"7. Ordenar las series alfabeticamente"<<endl;
         cout<<"8. Mostrar cuales son las series que ocupan los tres primeros lugares segun el nivel de audiencia"<<endl;
         cout<<"9. Mostrar cual es el episodio de la serie que dura mas tiempo"<<endl;
         cout<<"10. Buscar un episodio en particular dentro de una serie"<<endl;
         cout<<"11. Mostrar el tiempo total de todos los episodios de una serie"<<endl;
         cout<<"12. Mostrar el analisis de tendencias a lo largo de cada serie"<<endl;
         cout<<"13. Mostrar el promedio de puntuacion de los episodios de una serie"<<endl;
         cout<<"14. Salir"<<endl;
         cout<<"--------------------------------------------------------------------------------------------------"<<endl;
         cout<<endl;
         cout<<"Opcion: ";
         getline(cin,opcion);
         if(esNumero(opcion)){
            continuar=false;
            opcionElegida=convertirStringEntero(opcion);
         }else
            cout<<"Debe ingresar un numero!"<<endl;
      }
      string nombre, genero, titulo, nivelDeAudiencia, cantidad, op;
      int opElegida=1, nivelDeAudienciaSerie, cantidadDeSeries;
      system("cls");
      switch(opcionElegida){
         case 1:{
               while(opElegida==1){
                  continuar=true;
                  while(continuar){
                     cout<<"Indique la cantidad de Series a agregar: ";
                     getline(cin,cantidad);
                     if(esNumero(cantidad)){
                        continuar=false;
                        cantidadDeSeries=convertirStringEntero(cantidad);
                     }else
                        cout<<"Debe ingresar un numero!"<<endl;
                  }
                  cout<<endl;
                  while(cantidadDeSeries>0){
                     continuar=true;
                     while(continuar){
                        cout<<"Indique el nombre de la Serie: ";
                        getline(cin,nombre);
                        if(esLetra(nombre))
                           continuar=false;
                        else
                           cout<<"Debe ingresar un nombre! Sin numeros y sin signos o simbolos."<<endl;
                     }
                     continuar=true;
                     while(continuar){
                        cout<<"Indique el genero de la Serie: ";
                        getline(cin,genero);
                        if(esLetra(genero))
                           continuar=false;
                        else
                           cout<<"Debe ingresar un genero! Sin numeros y sin signos o simbolos."<<endl;
                     }
                     continuar=true;
                     while(continuar){
                        cout<<"Indique el nivel de audiencia: ";
                        getline(cin,nivelDeAudiencia);
                        if(esNumero(nivelDeAudiencia)){
                           continuar=false;
                           nivelDeAudienciaSerie=convertirStringEntero(nivelDeAudiencia);
                        }else
                        cout<<"Debe ingresar un numero!"<<endl;
                     }
                     agregarSerie(inicio,nombre,genero,nivelDeAudienciaSerie);
                     cantidadDeSeries--;
                     cout<<endl;
                  }
                  system("pause");
                  cout<<endl<<endl;
                  continuar=true;
                  while(continuar){
                     cout<<"Desea agregar mas Series a la Lista?"<<endl;
                     cout<<"Indique 1 para SI o 0 para NO: ";
                     getline(cin,op);
                     if(esNumero(op)){
                        opElegida=convertirStringEntero(op);
                        if(opElegida==0 || opElegida==1)
                           continuar=false;
                        else
                           cout<<"Debe ingresar 1 o 0!"<<endl;
                     }else
                        cout<<"Debe ingresar un numero!"<<endl;
                  }
                  system("cls");
               }
               escribirSeries(*inicio,rutaArchivo);
            }
            break;
         case 2:{
               while(opElegida==1){
                  continuar=true;
                  while(continuar){
                        cout<<"Indique el nombre de la Serie a Eliminar: ";
                        getline(cin,nombre);
                        if(esLetra(nombre))
                           continuar=false;
                        else
                           cout<<"Debe ingresar un nombre! Sin numeros y sin signos o simbolos."<<endl;
                  }
                  cout<<endl;
                  eliminarSerie(inicio,nombre);
                  system("pause");
                  cout<<endl<<endl;
                  continuar=true;
                  while(continuar){
                     cout<<"Desea Eliminar otra Serie de la Lista?"<<endl;
                     cout<<"Indique 1 para SI o 0 para NO: ";
                     getline(cin,op);
                     if(esNumero(op)){
                        opElegida=convertirStringEntero(op);
                        if(opElegida==0 || opElegida==1)
                           continuar=false;
                        else
                           cout<<"Debe ingresar 1 o 0!"<<endl;
                     }else
                        cout<<"Debe ingresar un numero!"<<endl;
                  }
                  system("cls");
               }
               escribirSeries(*inicio,rutaArchivo);
            }
            break;
         case 3:{
               while(opElegida==1){
                  continuar=true;
                  while(continuar){
                     cout<<"Indique el nombre de la Serie para agregar Episodios: ";
                     getline(cin,nombre);
                     if(esLetra(nombre))
                        continuar=false;
                     else
                        cout<<"Debe ingresar un nombre! Sin numeros y sin signos o simbolos."<<endl;
                  }
                  agregarEpisodioSerieEspecifica(inicio,nombre);
                  system("pause");
                  cout<<endl<<endl;
                  continuar=true;
                  while(continuar){
                     cout<<"Desea agregar mas Episodios a la Serie o a otra Serie de la Lista?"<<endl;
                     cout<<"Indique 1 para SI o 0 para NO: ";
                     getline(cin,op);
                     if(esNumero(op)){
                        opElegida=convertirStringEntero(op);
                        if(opElegida==0 || opElegida==1)
                           continuar=false;
                        else
                           cout<<"Debe ingresar 1 o 0!"<<endl;
                     }else
                        cout<<"Debe ingresar un numero!"<<endl;
                  }
                  system("cls");
               }
               escribirSeries(*inicio,rutaArchivo);
            }
            break;
         case 4:{
               while(opElegida==1){
                  continuar=true;
                  while(continuar){
                     cout<<"Indique el nombre de la Serie para eliminar un Episodio especifico: ";
                     getline(cin,nombre);
                     if(esLetra(nombre))
                        continuar=false;
                     else
                        cout<<"Debe ingresar un nombre! Sin numeros y sin signos o simbolos."<<endl;
                  }
                  eliminarEpisodioSerie(inicio,nombre);
                  system("pause");
                  cout<<endl<<endl;
                  continuar=true;
                  while(continuar){
                     cout<<"Desea eliminar otro Episodio de la Serie o de otra Serie de la Lista?"<<endl;
                     cout<<"Indique 1 para SI o 0 para NO: ";
                     getline(cin,op);
                     if(esNumero(op)){
                        opElegida=convertirStringEntero(op);
                        if(opElegida==0 || opElegida==1)
                           continuar=false;
                        else
                           cout<<"Debe ingresar 1 o 0!"<<endl;
                     }else
                        cout<<"Debe ingresar un numero!"<<endl;
                  }
                  system("cls");
               }
               escribirSeries(*inicio,rutaArchivo);
            }
            break;
         case 5:{
               listarSeriesEpisodios(*inicio);
               system("pause");
               system("cls");
               continuar=true;
            }
            break;
         case 6:{
               while(opElegida==1){
                  continuar=true;
                  while(continuar){
                     cout<<"Indique el nombre de la Serie: ";
                     getline(cin,nombre);
                     if(esLetra(nombre))
                        continuar=false;
                     else
                        cout<<"Debe ingresar un nombre! Sin numeros y sin signos o simbolos."<<endl;
                  }
                  buscarSerie(*inicio,nombre);
                  system("pause");
                  cout<<endl<<endl;
                  continuar=true;
                  while(continuar){
                     cout<<"Desea buscar otra Serie de la Lista?"<<endl;
                     cout<<"Indique 1 para SI o 0 para NO: ";
                     getline(cin,op);
                     if(esNumero(op)){
                        opElegida=convertirStringEntero(op);
                        if(opElegida==0 || opElegida==1)
                           continuar=false;
                        else
                           cout<<"Debe ingresar 1 o 0!"<<endl;
                     }else
                        cout<<"Debe ingresar un numero!"<<endl;
                  }
                  system("cls");
               }
            }
            break;
         case 7:{
               ordenarSeriesAlfabeticamente(inicio);
               cout<<"Las Series han sido ordenadas alfabeticamente!"<<endl;
               system("pause");
               system("cls");
               escribirSeries(*inicio,rutaArchivo);
            }
            break;
         case 8:{
               seriesOcupanTresPrimerosLugares(*inicio);
               system("pause");
               system("cls");
            }
            break;
         case 9:{
               while(opElegida==1){
                  continuar=true;
                  while(continuar){
                     cout<<"Indique el nombre de la Serie para mostrar su Episodio de mayor duracion: ";
                     getline(cin,nombre);
                     if(esLetra(nombre))
                        continuar=false;
                     else
                        cout<<"Debe ingresar un nombre! Sin numeros y sin signos o simbolos."<<endl;
                  }
                  buscarEpisodioMayorDuracion(*inicio,nombre);
                  cout<<endl;
                  system("pause");
                  cout<<endl<<endl;
                  continuar=true;
                  while(continuar){
                     cout<<"Desea buscar otra Serie de la Lista?"<<endl;
                     cout<<"Indique 1 para SI o 0 para NO: ";
                     getline(cin,op);
                     if(esNumero(op)){
                        opElegida=convertirStringEntero(op);
                        if(opElegida==0 || opElegida==1)
                           continuar=false;
                        else
                           cout<<"Debe ingresar 1 o 0!"<<endl;
                     }else
                        cout<<"Debe ingresar un numero!"<<endl;
                  }
                  system("cls");
               }
            }
            break;
         case 10:{
               while(opElegida==1){
                  continuar=true;
                  while(continuar){
                     cout<<"Indique el nombre de la Serie: ";
                     getline(cin,nombre);
                     if(esLetra(nombre))
                        continuar=false;
                     else
                        cout<<"Debe ingresar un nombre! Sin numeros y sin signos o simbolos."<<endl;
                  }
                  continuar=true;
                  while(continuar){
                     cout<<"Indique el titulo del Episodio: ";
                     getline(cin,titulo);
                     if(esLetra(cantidad))
                        continuar=false;
                     else
                        cout<<"Debe ingresar un titulo! Sin numeros y sin signos o simbolos."<<endl;
                  }
                  buscarEpisodio(*inicio,nombre,titulo);
                  cout<<endl;
                  system("pause");
                  cout<<endl<<endl;
                  continuar=true;
                  while(continuar){
                     cout<<"Desea buscar otro Episodio de una Serie de la Lista?"<<endl;
                     cout<<"Indique 1 para SI o 0 para NO: ";
                     getline(cin,op);
                     if(esNumero(op)){
                        opElegida=convertirStringEntero(op);
                        if(opElegida==0 || opElegida==1)
                           continuar=false;
                        else
                           cout<<"Debe ingresar 1 o 0!"<<endl;
                     }else
                        cout<<"Debe ingresar un numero!"<<endl;
                  }
                  system("cls");
               }
            }
            break;
         case 11:{
               while(opElegida==1){
                  continuar=true;
                  while(continuar){
                     cout<<"Indique el nombre de la Serie: ";
                     getline(cin,nombre);
                     if(esLetra(nombre))
                        continuar=false;
                     else
                        cout<<"Debe ingresar un nombre! Sin numeros y sin signos o simbolos."<<endl;
                  }
                  mostrarTiempoTotalEpisodiosSerie(*inicio,nombre);
                  system("pause");
                  cout<<endl<<endl;
                  continuar=true;
                  while(continuar){
                     cout<<"Desea buscar otra Serie de la Lista?"<<endl;
                     cout<<"Indique 1 para SI o 0 para NO: ";
                     getline(cin,op);
                     if(esNumero(op)){
                        opElegida=convertirStringEntero(op);
                        if(opElegida==0 || opElegida==1)
                           continuar=false;
                        else
                           cout<<"Debe ingresar 1 o 0!"<<endl;
                     }else
                        cout<<"Debe ingresar un numero!"<<endl;
                  }
                  system("cls");
               }
            }
            break;
         case 12:{
               episodioMayorPuntuacion(*inicio);
               system("pause");
               system("cls");
            }
            break;
         case 13:{
               while(opElegida==1){
                  continuar=true;
                  while(continuar){
                     cout<<"Indique el nombre de la Serie: ";
                     getline(cin,nombre);
                     if(esLetra(nombre))
                        continuar=false;
                     else
                        cout<<"Debe ingresar un nombre! Sin numeros y sin signos o simbolos."<<endl;
                  }
                  mostrarTiempoTotalEpisodiosSerie(*inicio,nombre);
                  system("pause");
                  cout<<endl<<endl;
                  continuar=true;
                  while(continuar){
                     cout<<"Desea consultar otra Serie de la Lista?"<<endl;
                     cout<<"Indique 1 para SI o 0 para NO: ";
                     getline(cin,op);
                     if(esNumero(op)){
                        opElegida=convertirStringEntero(op);
                        if(opElegida==0 || opElegida==1)
                           continuar=false;
                        else
                           cout<<"Debe ingresar 1 o 0!"<<endl;
                     }else
                        cout<<"Debe ingresar un numero!"<<endl;
                  }
                  system("cls");
               }
            }
            break;
         case 14:
            cout<<"Hasta luego!";
            break;
         default:
            if(opcionElegida<1 || opcionElegida>14){
               system("cls");
               cout<<"Opcion invalida. Intente nuevamente."<<endl;
               cout<<endl;
            }
      }
   }
}

void opcionesInicio(Serie **inicio, string rutaArchivo){
   int opElegida=0;
   string opcion;
   bool continuar=true;
   while(opElegida!=1 && opElegida!=2){
      while(continuar){
         cout<<"  _ __ ___   ___ _ __  _   _"<<endl;
         cout<<" | '_ ` _ \\ / _ \\ '_ \\| | | |"<<endl;
         cout<<" | | | | | |  __/ | | | |_| |"<<endl;
         cout<<" |_| |_| |_|\\___|_| |_|\\__,_|"<<endl;
         cout<<"------------------------------"<<endl;
         cout<<" 1. Ver Series"<<endl;
         cout<<" 2. Salir"<<endl;
         cout<<"------------------------------"<<endl;
         cout<<endl;
         cout<<"Opcion: ";
         getline(cin,opcion);
         if(esNumero(opcion)){
            opElegida=convertirStringEntero(opcion);
            continuar=false;
         }else
            cout<<"Debe ingresar un numero!"<<endl;
      }
      continuar=true;
      switch(opElegida){
         case 1:{
               system("cls");
               menu(inicio,rutaArchivo);
            }
            break;
         case 2:{
               system("cls");
               cout<<"Hasta luego";
            }
            break;
         default: 
            if(opElegida<1 || opElegida>2){
               cout<<"Opcion invalida. Intente nuevamente."<<endl;
               cout<<endl;
            }
      }
   }
}

void presentacion(){
   system("cls");
   cout<<endl<<"                                                 Bienvenido a                                                  "<<endl;
   cout<<endl;
   cout<<"NNNNNNNN        NNNNNNNN EEEEEEEEEEEEEEEEEEEEEE XXXXXXX       XXXXXXX UUUUUUUU     UUUUUUUU    SSSSSSSSSSSSSSS "<<endl;
   cout<<"N:::::::N       N::::::N E::::::::::::::::::::E X:::::X       X:::::X U::::::U     U::::::U  SS:::::::::::::::S"<<endl;
   cout<<"N::::::::N      N::::::N E::::::::::::::::::::E X:::::X       X:::::X U::::::U     U::::::U S:::::SSSSSS::::::S"<<endl;
   cout<<"N:::::::::N     N::::::N EE::::::EEEEEEEEE::::E X::::::X     X::::::X UU:::::U     U:::::UU S:::::S     SSSSSSS"<<endl;
   cout<<"N::::::::::N    N::::::N   E:::::E       EEEEEE XXX:::::X   X:::::XXX  U:::::U     U:::::U  S:::::S            "<<endl;
   cout<<"N:::::::::::N   N::::::N   E:::::E                 X:::::X X:::::X     U:::::D     D:::::U  S:::::S            "<<endl;
   cout<<"N:::::::N::::N  N::::::N   E::::::EEEEEEEEEE        X:::::X:::::X      U:::::D     D:::::U   S::::SSSS         "<<endl;
   cout<<"N::::::N N::::N N::::::N   E:::::::::::::::E         X:::::::::X       U:::::D     D:::::U    SS::::::SSSSS    "<<endl;
   cout<<"N::::::N  N::::N:::::::N   E:::::::::::::::E         X:::::::::X       U:::::D     D:::::U      SSS::::::::SS  "<<endl;
   cout<<"N::::::N   N:::::::::::N   E::::::EEEEEEEEEE        X:::::X:::::X      U:::::D     D:::::U         SSSSSS::::S "<<endl;
   cout<<"N::::::N    N::::::::::N   E:::::E                 X:::::X X:::::X     U:::::D     D:::::U              S:::::S"<<endl;
   cout<<"N::::::N     N:::::::::N   E:::::E       EEEEEE XXX:::::X   X:::::XXX  U::::::U   U::::::U              S:::::S"<<endl;
   cout<<"N::::::N      N::::::::N EE::::::EEEEEEEE:::::E X::::::X     X::::::X  U:::::::UUU:::::::U  SSSSSSS     S:::::S"<<endl;
   cout<<"N::::::N       N:::::::N E::::::::::::::::::::E X:::::X       X:::::X  UU:::::::::::::UU    S::::::SSSSSS:::::S"<<endl;
   cout<<"N::::::N        N::::::N E::::::::::::::::::::E X:::::X       X:::::X    UU:::::::::UU      S:::::::::::::::SS "<<endl;
   cout<<"NNNNNNNN         NNNNNNN EEEEEEEEEEEEEEEEEEEEEE XXXXXXX       XXXXXXX      UUUUUUUUU         SSSSSSSSSSSSSSS   "<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   system("pause");
   system("cls");
}

fstream abrirArchivo(string ruta, ios::openmode modo){// Funcion para abrir un archivo
   fstream archivo(ruta,modo);
   if(!archivo.is_open()){
      cout<<"No se pudo abrir el archivo: "<<ruta<<endl;
   }
   return archivo;
}

void agregarEpisodioSerieEspecificaPorLecturaArchivo(Serie **inicio, string nombre, string titulo, int duracion, int numero, float puntuacion){//Permitir agregar episodios a una serie ya existente. 
   Serie *actual=*inicio;
   bool encontrado=false;
   if(listaVaciaSerie(*inicio))
      cout<<"No hay series en la lista"<<endl;
   else{
      while(actual!=NULL && encontrado==false){
         if(actual->nombre==nombre){
            encontrado=true;
            agregarEpisodio(&(actual->listaEpisodio), titulo, duracion, numero, puntuacion);
         }
         actual=actual->proxSerie;
      }
      if(encontrado==false){
         cout<<"La Serie no se encuentra en la lista"<<endl;
      }
   }
}

void leerSeries(Serie **inicio, string nombreArchivo){
   ifstream archivo(nombreArchivo);
   if(!archivo.is_open()){
      cout<<"Error al abrir el archivo"<<endl;
      return;
   }

   string linea;
   while(getline(archivo, linea)){
      stringstream palabras(linea);
      string nombre, genero, nivelDeAudienciaStr;
      getline(palabras, nombre, '|');
      getline(palabras, genero, '|');
      getline(palabras, nivelDeAudienciaStr, '|');
      int nivelDeAudiencia = convertirStringEntero(nivelDeAudienciaStr);

      agregarSerie(inicio, nombre, genero, nivelDeAudiencia);

      string tituloEpisodio, duracionStr, numeroEpisodioStr, puntuacionStr;
      while(getline( palabras, tituloEpisodio, '|') &&
            getline( palabras, duracionStr, '|') &&
            getline( palabras, numeroEpisodioStr, '|') &&
            getline( palabras, puntuacionStr, '|')){
         int duracion = convertirStringEntero(duracionStr);
         int numeroEpisodio = convertirStringEntero(numeroEpisodioStr);
         float puntuacion = convertirStringFlotante(puntuacionStr);

         agregarEpisodioSerieEspecificaPorLecturaArchivo(inicio, nombre, tituloEpisodio, duracion, numeroEpisodio, puntuacion);
      }
   }
   archivo.close();
}

float buscarMayorPuntuacionEpisodios(Serie *inicio){//Busca la puntuacion mas alta de todos los episodios
   Serie *actual=inicio, *aux=NULL;
   float puntuacion=0, puntuacionEpisodios=0;
   if(listaVaciaSerie(inicio))
      cout<<"No hay series en la lista!"<<endl;
   else{
      while(actual!=NULL){
         aux=actual;
         if(aux->listaEpisodio!=NULL)
            puntuacion=mayorPuntuacion(aux->listaEpisodio)->puntuacion;
         if(puntuacion>puntuacionEpisodios)
            puntuacionEpisodios=puntuacion;
         actual=actual->proxSerie;
      }
   }
   return puntuacionEpisodios;
}

int buscarMayorNivelAudienciaSeries(Serie *inicio){//Busca la puntuacion mas alta de todos los episodios
   Serie *actual=inicio;
   int audienciaSeries=0;
   if(listaVaciaSerie(inicio))
      cout<<"No hay series en la lista!"<<endl;
   else{
      while(actual!=NULL){
         if(actual->nivelDeAudiencia>audienciaSeries)
            audienciaSeries=actual->nivelDeAudiencia;
         actual=actual->proxSerie;
      }
   }
   return audienciaSeries;
}

void seriesMayorAudienciaEpisodioMayorPuntuacion(Serie *inicio, string rutaArchivo){//Mostrar el episodio con mayor puntuacion de cada serie
   Serie *actual=inicio;
   Episodio *lista=NULL;
   float puntuacion=buscarMayorPuntuacionEpisodios(inicio);
   int audiencia=buscarMayorNivelAudienciaSeries(inicio);
   ofstream archivo(rutaArchivo);
   if(!archivo.is_open()){
      cout<<"Error al abrir el archivo"<<endl;
      return;
   }else{
      if(listaVaciaSerie(inicio))
         cout<<"No hay series en la lista!"<<endl;
      else{
         while(actual!=NULL){
            if(actual->nivelDeAudiencia==audiencia){
               archivo<<"Datos de la Serie de mayor nivel de audiencia:"<<endl;
               archivo<<"Nombre de la Serie: "<<actual->nombre<<endl;
               archivo<<"Genero de la Serie: "<<actual->genero<<endl;
               archivo<<"Nivel de audiencia de la Serie: "<<actual->nivelDeAudiencia<<endl;
               archivo<<endl;
            }
            actual=actual->proxSerie;
         }
         actual=inicio;
         archivo<<endl<<endl;
         while(actual!=NULL){
            if(actual->listaEpisodio!=NULL){
               lista=actual->listaEpisodio;
               while(lista!=NULL){
                  if(lista->puntuacion==puntuacion){
                     archivo<<endl<<"Datos del Episodio de mayor Puntucion de la serie \""<<actual->nombre<<"\":"<<endl;
                     archivo<<"Titulo del Episodio: "<<lista->tituloEpisodio<<endl;
                     archivo<<"Duracion del Episodio: "<<lista->duracion<<endl;
                     archivo<<"Numero del Episodio: "<<lista->numeroEpisodio<<endl;
                     archivo<<"Puntuacion del Episodio: "<<lista->puntuacion<<endl;
                  }
                  lista=lista->proxEpisodio;
               }
            }
            actual=actual->proxSerie;
         }
      }
      archivo.close();
   }
}

void liberarMemoria(Serie **inicio){ 
   Serie *actual=*inicio;
   Episodio *episodio=NULL;
   if(listaVaciaSerie(*inicio)){
      cout<<endl;
      cout<<endl;
   }else{
      while(*inicio!=NULL){
         actual=*inicio;
         *inicio=(*inicio)->proxSerie;
         episodio=actual->listaEpisodio;
         Episodio *auxiliar=episodio;
         if(listaVaciaEpisodio(episodio))
            cout<<endl;
         else{
            while(auxiliar!=NULL){
               episodio=auxiliar->proxEpisodio;
               delete auxiliar;
               auxiliar=episodio;
            }
         }
         delete actual;
      }
   }
}

main(){
   Serie *listaSeries=NULL;
   string rutaArchivo, opcion, nombreArchivo;
   int opElegida=0;
   bool continuar=true,rutaCorrecta=false;
   while(continuar){
      cout<<"Desea ingresar la ruta del archivo o desea utilizar la ruta por defecto (C:\\datos)?"<<endl;
      cout<<"1. Ingresar la ruta del archivo"<<endl;
      cout<<"2. Utilizar la ruta por defecto"<<endl;
      cout<<"Opcion: ";
      getline(cin,opcion);
      if(esNumero(opcion)){
         opElegida=convertirStringEntero(opcion);
         if(opElegida==1 || opElegida==2){
            continuar=false;
            cout<<endl;
         }else
            cout<<endl<<"Debe ingresar 1 o 2!"<<endl<<endl;
      }else
         cout<<"Debe ingresar un numero!"<<endl;
   }
   if(opElegida==1){
      while(!rutaCorrecta){
         cout<<"Ingrese la ruta completa del directorio (sin el nombre del archivo): ";
         getline(cin,rutaArchivo);
         cout<<"Ingrese el nombre del archivo de entrada (con el .txt): ";
         getline(cin,nombreArchivo);
         cout<<endl<<endl;
         continuar=true;
         while(continuar){
            cout<<"La ruta ingresada es: "<<rutaArchivo<<"\\"<<nombreArchivo<<"?"<<endl;
            cout<<"1. Si"<<endl;
            cout<<"2. No"<<endl;
            cout<<"Opcion: ";
            getline(cin,opcion);
            if(esNumero(opcion)){
               opElegida=convertirStringEntero(opcion);
               if(opElegida==1){
                  rutaCorrecta=true;
                  continuar=false;
                  cout<<endl;
               }else if(opElegida==2){
                  continuar=false;
                  cout<<endl;
               }else
                  cout<<endl<<"Debe ingresar un numero (1-2)!"<<endl<<endl;
            }else
               cout<<"Debe ingresar un numero!"<<endl;
         }
      }
      string rutaCompletaArchivo=rutaArchivo+"\\"+nombreArchivo;
      string rutaMayorAudienciaPuntuacion=rutaArchivo+"\\"+"serieMayorAudiencia-y-EpisodiosMayorPuntuacion.txt";
      fstream archivo=abrirArchivo(rutaCompletaArchivo,ios::in | ios::out);
      if(archivo.is_open()){
         leerSeries(&listaSeries,rutaCompletaArchivo);
         presentacion();
         opcionesInicio(&listaSeries,rutaCompletaArchivo);
         seriesMayorAudienciaEpisodioMayorPuntuacion(listaSeries,rutaMayorAudienciaPuntuacion);
         liberarMemoria(&listaSeries);
      }
   }else if(opElegida==2){
      rutaArchivo="C:\\datos";
      fstream archivo=abrirArchivo(rutaArchivo,ios::in | ios::out);
      if(archivo.is_open()){
         leerSeries(&listaSeries,rutaArchivo);
         presentacion();
         opcionesInicio(&listaSeries,rutaArchivo);
         seriesMayorAudienciaEpisodioMayorPuntuacion(listaSeries,rutaArchivo);
         liberarMemoria(&listaSeries);
      }
   }
}