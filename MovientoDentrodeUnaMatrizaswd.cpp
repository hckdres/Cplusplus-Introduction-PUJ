#include <iostream>
using namespace std;

const int SIZE = 5; // Tamaño de la matriz

void imprimirMatriz(char matriz[SIZE][SIZE], int posX, int posY) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == posX && j == posY) {
                cout << "[X] "; // Representa la posición actual
            } else {
                cout << "[" << matriz[i][j] << "] "; // Elementos de la matriz
            }
        }
        cout << endl;
    }
}

int main() {
    char matriz[SIZE][SIZE];
    int posX = 2, posY = 2; // Posición inicial en el centro

    // Inicializar la matriz con espacios
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matriz[i][j] = ' '; // Llena la matriz con espacios
        }
    }

    char movimiento;
    do {
        imprimirMatriz(matriz, posX, posY);
        cout << "Mover (w=arriba, s=abajo, a=izquierda, d=derecha, q=salir): ";
        cin >> movimiento;

        // Mover según la entrada del usuario
        if (movimiento == 'w' && posX > 0) posX--; // Arriba
        else if (movimiento == 's' && posX < SIZE - 1) posX++; // Abajo
        else if (movimiento == 'a' && posY > 0) posY--; // Izquierda
        else if (movimiento == 'd' && posY < SIZE - 1) posY++; // Derecha

    } while (movimiento != 'q');

    return 0;
}
