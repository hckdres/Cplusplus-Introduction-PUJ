#include <iostream>
#include <cstdlib>
#include <ctime>
using  namespace std;
void ingrese_arreglos2 (int arreglo[]);
void numeroAleatorio(int arreglo2[]);
int picas(int arreglo[], int arreglo2[]);
int fijas(int arreglo[], int arreglo2[]);
int main() {
    int arreglo[4];
    int arreglo2[4];
    numeroAleatorio(arreglo2);


    int fijasCount = 0;
    while (fijasCount < 4) {
        ingrese_arreglos2(arreglo);
        int picasCount = picas(arreglo, arreglo2);
          fijasCount = fijas(arreglo, arreglo2);
    }

    cout << "¡Felicidades! Adivinaste el número." << endl;
    return 0;
}


void ingrese_arreglos2 (int arreglo[]) {

    for (int i = 0; i < 4; i++) {
        cout << "Ingrese el " << (i + 1) << " digito: "<<endl;
        cin >> arreglo[i];
        if(arreglo[i]<1 || arreglo[i]>9){
            cout<<"El numero ingresado no es valido, por favor ingrese un numero entre 1 y 9"<<endl;
           
            break;
        } 
    }


    for(int j=0; j<4; j++){
        if(arreglo[j]==arreglo[j+1]){
            cout<<"Un numero esta repetido"<<endl;
        }
    }
}
void numeroAleatorio(int arreglo2[])
{
    srand(time(0)); 

    for(int i=0;i<4;i++){
       arreglo2[i]=(1+ rand() % 9);
        cout<<" ["<<arreglo2[i]<<"] ";
    }
}
int picas(int arreglo[], int arreglo2[]) {
    int contador = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
             //  1 diferente 1  y arreglo en la pos 1 es igual a arreglo2 en la pos 1
            if (i != j && arreglo[i] == arreglo2[j]) {  // i != j asegura que no sea la misma posición
                contador++;
            }
        }
    }
    cout << "Tuvo " << contador << " PICAS" << endl;
    return contador;
}

int fijas(int arreglo[], int arreglo2[]) {
    int contador = 0;
    for (int i = 0; i < 4; i++) {
        if (arreglo[i] == arreglo2[i]) {
            contador++;
        }
    }
    cout << "Tuvo " << contador << " FIJAS" << endl;
    return contador;  // Devuelve el número de fijas
}
