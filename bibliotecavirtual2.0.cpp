#include <iostream>
#include <string>
using namespace std;
void buscarLibro(string libros[], int ejempla[]);
void registrarLibro (string libros[], int ejempla[]);
void sumarEjem(string libros[], int ejempla[]);
void vaciar(string libros[], int ejempla[]);
void recargar(string libros[], int ejempla[]);
const int MAX_LIBROS = 10; 



int main() {
  int a;
string libros[10]={"elquijote","laodisea", "elprincipito","losojos","elarte","puntociego","vacio","vacio","vacio","vacio"};
  int ejempla [10]={10,20,3,7,14,8,-1,-1,-1,-1};

   while(true){
cout<<" Ingrese que quiere hacer le la biblioteca virtual"<<endl;
  cout<<"Que desea hacer?"<<endl<<
   "1. Registrar Libro" <<endl<<
    "2. Consultar Inventario"<<endl<<
   "3. Buscar Libro"<<endl<<
    "4. Vaciar Inventario"<<endl<<
    "5. Recargar Inventario"<<endl<<
  "6. Salir"<<endl;
cin>>a;

  switch(a){
    case 1:{
      registrarLibro(libros, ejempla);
      break;
    }  
    case 2:{
    cout<<"Ingreso a la opcion de consultar inventario"<<endl;
      sumarEjem(libros,ejempla);

      break;
    }
    case 3:{
      cout<<"Ingreso a la opcion de buscar libro"<<endl;
       buscarLibro(libros,ejempla);
      break;
    }
    case 4:{
      cout<< "Ingreso a la opcion de vaciar inventario"<<endl;
       vaciar( libros, ejempla);
      break;
    }
    case 5:{
      cout<< "Ingreso a la opcion de recargar inventario"<<endl;
      recargar(libros,ejempla);
      break;
    }
    case 6:{
      cout<<"Salio del programa"<<endl;
      return 0;
    }
  }
}
}
void registrarLibro(string libros[], int ejempla[]){

  for(int i=0; i<MAX_LIBROS; i++){
    if(libros[i]=="vacio"){
    cout<<"Ingrese el libro"<<endl;
    cin>>libros[i];
    cout<<"Ingrese la cantidad de ejemplares del libro"        <<endl;
    cin>>ejempla[i];
    }
    else if (libros[i]!="vacio"){
      cout<<"No hay espacio para mas libros en la posicion : "<<(i+1)<<endl;
    }
  }
  for(int j=0; j<MAX_LIBROS; j++){
    cout<<"Libro "<< "["<<libros[j]<<"]"<<"registrado con "<<"["<<ejempla[j]<<"]"<<"Ejemplares"<<endl; 

  }

}
void buscarLibro(string libros[], int ejempla[]){
  string buscar;
  cout<<"Ingrese el libro que desea buscar"<<endl;
  cin>>buscar;
  for(int i=0; i<MAX_LIBROS; i++)
    {
      if(buscar==libros[i])
      {

        cout<<"Ejemplares disponibles: "<<ejempla[i]<<endl;

      }
    }
}
void sumarEjem(string libros[], int ejempla[]){
  int aux = 0;
  for(int i=0; i<MAX_LIBROS; i++){
    if(ejempla[i]!=-1){
      aux+=ejempla[i];    
    }
    
  }
  cout<<" Ejemplares disponibles: "<<aux<<endl;
}
void vaciar(string libros[], int ejempla[]){
  string buscar;
  cout<< "Ingrese el libro que desea vaciar"<<endl;
  cin>>buscar;
  for(int i=0; i<MAX_LIBROS; i++){
    if(buscar==libros[i]){
      ejempla[i]=0;
    }
  }
  cout<< "Inventario del Libro ´ "<<buscar<< " ´ vaciado"<<endl;
}
void recargar(string libros[], int ejempla[]){
  for(int i = 0; i<MAX_LIBROS; i++){
    if(ejempla[i]!=-1){
      ejempla[i]=50;
    }
  }
  cout<<"Todos los libros recargados a su inventario maximo de 50 ejemplares "<<endl;
}
