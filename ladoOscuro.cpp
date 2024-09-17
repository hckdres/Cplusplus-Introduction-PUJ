#include <iostream>
using namespace std;

int main() {
    int a;
    int resultado_final = 0; // Variable para almacenar el número combinado de residuos
    int multiplicador = 1;   // Este multiplicador asegura que cada residuo se coloque en la posición correcta
    int contador = 0;
    cout << "Ingrese la cantidad de mitocondrias" << endl;
    cin >> a;

    // Repetir el bucle hasta que `a` llegue a 1
    while (a >= 1) {
        int residuo = a % 5; // Calcula el residuo
        resultado_final += residuo * multiplicador; // Coloca el residuo en la posición correcta

        multiplicador *= 10; // Aumenta el multiplicador para la próxima posición decimal
        a = a / 5; // Actualiza `a` dividiéndolo por 5
    }
    cout << "El número combinado de todos los residuos es: " << resultado_final << endl;

    int res = resultado_final%10;
  int res2 = (resultado_final%100)/10;
  int res3 = (resultado_final%1000)/100;
  int res4 = (resultado_final%10000)/1000;
   int res5 = (resultado_final%100000)/10000; 
   int res6 = (resultado_final%1000000)/100000;
  cout<<res<<"--"<<res2<<"--"<<res3<<"--"<<res4<<"--"<<res5<<"--"<<res6<<endl;

  if(res/4==1||res2/4==1||res3/4==1||res4/4==1||res5/4==1||res6/4==1){
      contador++;
      cout<<contador<<endl;
      if(contador>2){
          cout<<"Si"<<endl;
      }
  }


    return 0;
}
