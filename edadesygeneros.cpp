#include <iostream>
using namespace std;

int main() {
    int a;
    char b;
    int contadorh = 0;
    int contadorm = 0;
    int contadorg = 0;

    // Pedir la edad al menos una vez
    cout << "Ingrese la edad de la persona: " << endl;
    cin >> a;

    while(a >= 18) { // El bucle continúa mientras la edad sea 18 o más
        contadorg++;

        cout << "Ingrese el género de la persona (h para hombre, m para mujer): " << endl;
        cin >> b;

        if(b == 'h') {
            contadorh++;
            cout << "Ingresaron " << contadorh << " hombres." << endl;
        } else if (b == 'm') {
            contadorm++;
            cout << "Ingresaron " << contadorm << " mujeres." << endl;
        }

        // Volver a pedir la edad
        cout << "Ingrese la edad de la persona: " << endl;
        cin >> a;
    }

    // Mensaje de salida cuando se ingresa una edad menor a 18
    cout << "No se permiten menores de edad." << endl;
    cout << "El total de personas que ingresaron es: " << contadorg << endl;
    int sumt = contadorh + contadorm;
    cout<<"Ingresaron un total de "<<sumt<<" personas"<<endl;
    int promeh = (contadorh * 100) / sumt;
    int promm = (contadorm * 100) / sumt;
    cout<<"El promedio de hombres es "<<promeh<<"%"<<endl;
    cout<<"El promedio de mujeres es "<<promm<<"%"<<endl;
  
  
    return 0;
}
