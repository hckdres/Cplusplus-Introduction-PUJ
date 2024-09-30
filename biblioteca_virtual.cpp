#include <iostream>
#include <string>
using namespace std;
void buscarLibro(string libros[], int ejem[]);
void registrarLibro (string libros[], int ejem[]);
void sumarEjem(string libros[], int ejem[]);
void vaciar(string libros[], int ejem[]);
void recargar(string libros[], int ejem[]);
const int MAX_LIBROS = 2; 



int main() {
  int a;
  
  string libros[MAX_LIBROS];
  int ejem[MAX_LIBROS];
   while(true){
cout<<" Ingrese que quiere hacer le la biblioteca virtual"<<endl;
  cout<<"Que desea hacer 1. Registrar Libro 2. Consultar Inventario 3. Buscar Libro, 4. Vaciar Inventario, 5. Recargar Inventario, 6. Salir"<<endl;
cin>>a;
 
  switch(a){
    case 1:{
      registrarLibro(libros, ejem);
      break;
    }  
    case 2:{
    cout<<"Ingreso a la opcion de consultar inventario"<<endl;
      sumarEjem(libros,ejem);
    
      break;
    }
    case 3:{
      cout<<"Ingreso a la opcion de buscar libro"<<endl;
       buscarLibro(libros,ejem);
      break;
    }
    case 4:{
      cout<< "Ingreso a la opcion de vaciar inventario"<<endl;
       vaciar( libros, ejem);
    }
    case 5:{
      cout<< "Ingreso a la opcion de recargar inventario"<<endl;
      recargar(libros,ejem);
      break;
    }
    case 6:{
      cout<<"Salio del programa"<<endl;
      return 0;
    }
  }
}
}
void registrarLibro(string libros[], int ejem[]){

  for(int i=0; i<MAX_LIBROS; i++){
    cout<<"Ingrese el libro"<<endl;
    cin>>libros[i];
    cout<<"Ingrese la cantidad de ejemplares del libro"        <<endl;
    cin>>ejem[i];
  
  }
  for(int j=0; j<MAX_LIBROS; j++){
    cout<<"Libro "<< "["<<libros[j]<<"]"<<"registrado con "<<"["<<ejem[j]<<"]"<<"Ejemplares"<<endl; 
   
  }
  
}
void buscarLibro(string libros[], int ejem[]){
  string buscar;
  cout<<"Ingrese el libro que desea buscar"<<endl;
  cin>>buscar;
  for(int i=0; i<MAX_LIBROS; i++)
    {
      if(buscar==libros[i])
      {
       
        cout<<"Ejemplares disponibles: "<<ejem[i]<<endl;
        
      }
    }
}
void sumarEjem(string libros[], int ejem[]){
  int aux = 0;
  for(int i=0; i<MAX_LIBROS; i++){
    aux+=ejem[i];    
  }
  cout<<" Ejemplares disponibles: "<<aux<<endl;
}
void vaciar(string libros[], int ejem[]){
  string buscar;
  cout<< "Ingrese el libro que desea vaciar"<<endl;
  cin>>buscar;
  for(int i=0; i<MAX_LIBROS; i++){
    if(buscar==libros[i]){
      ejem[i]=0;
    }
  }
  cout<< "Inventario del Libro ´ "<<buscar<< " ´ vaciado"<<endl;
}
void recargar(string libros[], int ejem[]){
  for(int i = 0; i<MAX_LIBROS; i++){
    ejem[i]=50;
  }
  cout<<"Todos los libros recargados a su inventario maximo de 50 ejemplares "<<endl;
}
