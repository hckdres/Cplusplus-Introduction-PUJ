#include <iostream>
using namespace std;
void leerarreglo();
int sumaArreglo();
int valorPromedio();
void mayorArreglo();
void menorArreglos();
int arreglo[7];
int main() {
  
  int a;
  leerarreglo();
  while (true){
  cout<<"Que desea hacer 1. Sumar, 2. Valor promedio, 3. Valor mayor, 4. Valor menor, 5. Salir"<<endl;
  cin>>a;

  switch(a){
    case 1:{
      cout<<"Entraste a suma"<<endl;
      cout<<"La suma es: "<<sumaArreglo()<<endl;
      break;
    }
    case 2:{
      cout<<"Entraste a promedio"<<endl;
      cout<<"Valor Promedio"<<valorPromedio()<<endl;
      break;
    }
    case 3:{
      cout<<"Entraste a mayor"<<endl;
      for(int i=0;i<7;i++){
        cout<<arreglo[i]<<" ";
      }
      cout<<"El mayor son: "<<endl;
      mayorArreglo();

      for(int i=0;i<7;i++){
        cout<<arreglo[i]<<endl;
      }
      break;
    }
    case 4:{
      cout<<"Entraste a menor"<<endl;
      for(int i=0;i<7;i++){
        cout<<arreglo[i]<<" ";
      }
      cout<<"El menor son: "<<endl;
        menorArreglos();

      for(int i=0;i<7;i++){
        cout<<arreglo[i]<<endl;
      }
      break;
    }
      case 5:{
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
void menorArreglos(){
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
