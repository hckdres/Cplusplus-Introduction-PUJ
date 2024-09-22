#include <iostream>
using namespace std;
void leerarreglo();
int sumaArreglo();
int valorPromedio();
void mayorArreglo();
void menorArreglos();
void BusquedadeValores(int valor);
int arreglo[7];
int main() {
  
  int a;
  int valor2;
  leerarreglo();
  while (true){
  cout<<"Que desea hacer 1. Sumar, 2. Valor promedio, 3. Valor mayor, 4. Valor menor, 5. Busquedad de un elemento, 6. Salir"<<endl;
  cin>>a;

  switch(a){
    case 1:{
      cout<<"Entraste a suma"<<endl;
      cout<<"La suma es: "<<sumaArreglo()<<endl;
      
      void menorArreglos();
      cout<< " Asi esta ordenado ascedente"<<endl;
          for(int i=0;i<7;i++){
            cout<<"["<<arreglo[i]<<"]";
      }
      cout<<endl;
      break;
    }
    case 2:{
      cout<<"Entraste a promedio"<<endl;
      cout<<"Valor Promedio"<<valorPromedio()<<endl;

      void menorArreglos();
      cout<< " Asi esta ordenado ascedente"<<endl;
          for(int i=0;i<7;i++){
            cout<<"["<<arreglo[i]<<"]";
      }
      cout<<endl;
      break;
    }
    case 3:{
      cout<<"Entraste a mayor"<<endl;
      cout<<" Asi se diguito anteriormente"<<endl;
      for(int i=0;i<7;i++){
        cout<<"["<<arreglo[i]<<"]";
      }
      cout<<"El mayor es: ";
      mayorArreglo();

        cout<<arreglo[0]<<endl;

      void menorArreglos();
      cout<< " Asi esta ordenado ascedente"<<endl;
          for(int i=0;i<7;i++){
            cout<<"["<<arreglo[i]<<"]";
      }
      cout<<endl;
      break;
    }
    case 4:{
      cout<<"Entraste a menor"<<endl;
      cout<<" Asi se diguito anteriormente"<<endl;
      for(int i=0;i<7;i++){
        cout<<"["<<arreglo[i]<<"]";
      }
      cout<<"El menor es : ";
        menorArreglos();

      
        cout<<arreglo[0]<<endl;


      void menorArreglos();
          
           cout<< " Asi esta ordenado ascedente"<<endl;
            for(int i=0;i<7;i++){
              cout<<"["<<arreglo[i]<<"]";     
      }
      cout<<endl;
      break;
    }
    case 5:{
      cout<<"Entraste a busqueda"<<endl;
      cout<< "Ingrese el valor a buscar: ";
      cin>>valor2;
      BusquedadeValores(valor2);

      break;
    }
      case 6:{
        cout<<"Saliste"<<endl;
        return 0;
      }
    
  }
    
}  
}
void leerarreglo(){
int max=7;
  for(int i=0;i<max;i++){
    cout<<"ingrese el valor de la posicion :"<<i+1<<endl;
    cin>>arreglo[i];
  }
}
int sumaArreglo(){
  int suma=0;
  for(int i=0;i<7;i++){
    suma=suma+arreglo[i];
  }
  return  suma;
}
int valorPromedio(){

int valorPromedio = sumaArreglo()/7;

  return valorPromedio;
}
void mayorArreglo(){
  int aux;
  for (int i = 0; i < 7; i++)
  {
  for (int j = 0; j < 7-1; j++)
  {
  if (arreglo [j] < arreglo [j+1] )
  {
  aux = arreglo [j+1] ;
  arreglo [j+1] = arreglo [j];
  arreglo [j] = aux;

      }
    }
  }
}
void menorArreglos(){ // ascendente
  int aux;
  for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 7 - 1; j++) {
          if (arreglo[j] > arreglo[j + 1]) { 
              aux = arreglo[j + 1];
              arreglo[j + 1] = arreglo[j];
              arreglo[j] = aux;
          }
      }
  }

}
void BusquedadeValores(int valor){
  bool encontrado = false; 
  for (int i = 0; i < 7; i++) {
      if (arreglo[i] == valor) {
          cout << "El valor se encuentra en la posicion: " << i << endl;
          encontrado = true;
      }
  }

  if (!encontrado) {
      cout << "No encontrado" << endl;
  }
}
