#include <iostream>
using namespace std;

// Declaración de un tamaño máximo para la matriz
const int MAX_SIZE = 100;

void cuadrantes(int matriz[][MAX_SIZE], int b);
void mostra(int matriz[][MAX_SIZE], int b);
void cu(int matriz[][MAX_SIZE], int b);
int main() {
  int a;
  cout << "Ingrese la dimension de la matriz 2N * 2N: ";
  cin >> a;
  int b = 2 * a;  // Calcula el tamaño de la matriz completa

  // Declaración de la matriz con el tamaño máximo permitido
  int matriz[MAX_SIZE][MAX_SIZE];

  // Llenar la matriz con los valores ingresados por el usuario
  cuadrantes(matriz, b);


  
  // Mostrar la matriz completa
  mostra(matriz, b);

  // Mostrar los cuadrantes
  cu(matriz, b);

  return 0;
}

// Función para llenar la matriz con valores ingresados por el usuario
void cuadrantes(int matriz[][MAX_SIZE], int b) {
  for (int i = 0; i < b; i++) {
    for (int j = 0; j < b; j++) {
      cout << "Ingrese el valor de la posicion " << i << "," << j << ": ";
      cin >> matriz[i][j];
    }
  }
}

// Función para mostrar la matriz
void mostra(int matriz[][MAX_SIZE], int b) {
  cout << "Matriz completa:" << endl;
  for (int i = 0; i < b; i++) {
    for (int j = 0; j < b; j++) {
      cout << matriz[i][j] << " ";
    }  
    cout << endl;
  }
}

void cu(int matriz[][MAX_SIZE], int b) {
  // Calcular valores para determinar el intercambio
  int v1 = matriz[0][0];
  int v2 = matriz[0][1];
  int val = v1 * v2;
  cout << "Valor de multiplicación: " << val << endl;

  // Si el producto es mayor a 15, intercambiamos cuadrantes I y II
  if (val > 15) {
    cout << "Intercambiando cuadrantes I y II:" << endl;
    for (int i = 0; i < b / 2; i++) {
      for (int j = 0; j < b / 2; j++) {
        // Intercambio de cuadrantes I y II
        int temp = matriz[i][j];
        cout<<" ..  "<<temp<<endl; 
        int nu =j + b / 2;
        cout<<nu<<endl;
        matriz[i][j] = matriz[i][nu];
        matriz[i][nu] = temp;
      }
    }
  }
  // Si el producto es menor o igual a 15, intercambiamos cuadrantes III y IV
  else {
    cout << "Intercambiando cuadrantes III y IV:" << endl;
    for (int i = b / 2; i < b; i++) {
      for (int j = 0; j < b / 2; j++) {
        // Intercambio de cuadrantes III y IV
        int temp = matriz[i][j];
        int nu =j + b / 2;
        cout<<nu<<endl;
        matriz[i][j] = matriz[i][nu];
        matriz[i][j + b / 2] = temp;
      }
    }
  }

  // Mostrar matriz después del intercambio
  cout << "Matriz después del intercambio:" << endl;
  for (int i = 0; i < b; i++) {
    for (int j = 0; j < b; j++) {
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
}

