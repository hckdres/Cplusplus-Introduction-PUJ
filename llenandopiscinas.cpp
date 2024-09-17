#include <iostream>
using namespace std;

int main() {

    int litroy, caey, llevy, litrov, caev, llevv;

    int pisv = 0;
    int pis = 0;
    int contador = 0;
    int contadorv = 0;

    cout << "Ingrese la cantidad litro de piscina suya: ";
    cin >> litroy;
    cout << "Ingrese la cantidad de litros que lleva usted: ";
    cin >> llevy;
    cout << "Ingrese la cantidad que se le cae de litros a usted: ";
    cin >> caey;
    cout << "Ingrese la cantidad litro de piscina del vecino: ";
    cin >> litrov;
    cout << "Ingrese la cantidad de litros que lleva el vecino: ";
    cin >> llevv;
    cout << "Ingrese la cantidad que se le cae de litros al vecino: ";
    cin >> caev;

    int resv = llevv - caev;
    int res = llevy - caey;

    if(llevy > 0){
        while(pis < litroy){
            pis += res;
            contador++;
            
        } 

        while(pisv < litrov){
            pisv += resv;
            contadorv++;
            
        }
    }
if(contador < contadorv){
    cout << "Ganaste";  
  
}
else if(contador > contadorv){
    cout << "Ganoo el vecino";
}
  else if(contador == contadorv){
    cout << "Empate";
  }
    return 0;
}
