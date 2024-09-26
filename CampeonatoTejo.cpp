#include <iostream>
#include <string>
using namespace std;

const int MAX_EQUIPOS = 10;
const int MAX_LANZAMIENTOS = 6;  // Cantidad fija de lanzamientos por equipo

// Declaración de funciones
void ingresarLanzamientos(int numEquipos, char lanzamientos[]);
void calcularLanzamientos(int numEquipos, char lanzamientos[], int puntajes[]);
void ordenarPuntajes(int numEquipos, int puntajes[], string nombres[]);

int main() {
    int num;
    string nombres[MAX_EQUIPOS];  // Arreglo para los nombres de los equipos
    int puntajes[MAX_EQUIPOS] = {0};  // Arreglo para los puntajes de los equipos

    // Pedir el número de equipos
    cout << "Ingrese el número de equipos (máximo " << MAX_EQUIPOS << "): ";
    cin >> num;

    if (num > MAX_EQUIPOS) {
        cout << "Número de equipos excede el máximo permitido." << endl;
        return 1;
    }

    // Declarar el arreglo para los lanzamientos
    char lanzamientos[MAX_EQUIPOS * MAX_LANZAMIENTOS];

    // Ingresar los nombres de los equipos
    for (int i = 0; i < num; i++) {
        cout << "Ingrese el nombre del equipo " << i + 1 << ": ";
        cin >> nombres[i];
    }

    // Ingresar los lanzamientos
    ingresarLanzamientos(num, lanzamientos);

    // Calcular los puntajes
    calcularLanzamientos(num, lanzamientos, puntajes);

    // Ordenar los puntajes y nombres según el puntaje
    ordenarPuntajes(num, puntajes, nombres);

    // Mostrar el equipo ganador
    cout << "El equipo ganador es: " << nombres[0] << " con un puntaje de " << puntajes[0] << " puntos." << endl;

    // Mostrar los puntajes ordenados
    for (int i = 0; i < num; i++) {
        cout << "Equipo " << nombres[i] << " tuvo un puntaje de " << puntajes[i] << endl;
    }

    return 0;
}

void ingresarLanzamientos(int numEquipos, char lanzamientos[]) {
    for (int i = 0; i < numEquipos; i++) {
        cout << "Equipo " << i + 1 << ":" << endl;
        for (int j = 0; j < MAX_LANZAMIENTOS; j++) {
            cout << "Ingrese el lanzamiento " << j + 1 << ": ";
            cin >> lanzamientos[i * MAX_LANZAMIENTOS + j];
        }
    }
}

void calcularLanzamientos(int numEquipos, char lanzamientos[], int puntajes[]) {
    const int B = 6;
    const int C = 4;
    const int R = -3;
    const int A = 0;

    for (int i = 0; i < numEquipos; i++) {
        int puntaje = 0;

        for (int j = 0; j < MAX_LANZAMIENTOS; j++) {
            if (lanzamientos[i * MAX_LANZAMIENTOS + j] == 'B') {
                puntaje += B;
            } else if (lanzamientos[i * MAX_LANZAMIENTOS + j] == 'C') {
                puntaje += C;
            } else if (lanzamientos[i * MAX_LANZAMIENTOS + j] == 'R') {
                puntaje += R;
            } else if (lanzamientos[i * MAX_LANZAMIENTOS + j] == 'A') {
                puntaje += A;
            }
        }

        puntajes[i] = puntaje;  // Guardar el puntaje total de cada equipo
    }
}

void ordenarPuntajes(int numEquipos, int puntajes[], string nombres[]) {
    // Ordenar los puntajes usando el algoritmo de burbuja
    for (int i = 0; i < numEquipos - 1; i++) {
        for (int j = 0; j < numEquipos - i - 1; j++) {
            if (puntajes[j] < puntajes[j + 1]) {  // Ordenar de mayor a menor
                // Intercambiar puntajes
                int tempPuntaje = puntajes[j];
                puntajes[j] = puntajes[j + 1];
                puntajes[j + 1] = tempPuntaje;

                // Intercambiar nombres para que coincidan con los puntajes
                string tempNombre = nombres[j];
                nombres[j] = nombres[j + 1];
                nombres[j + 1] = tempNombre;
            }
        }
    }
}
