#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Estudiante {
    string nombre;
    string apellido;
    int lista;
    float notas[10];  // Arreglo para almacenar hasta 10 notas por estudiante
    int numNotas;     // Cantidad de notas que tiene el estudiante
    float promedio;   // Promedio de las notas
};

// Prototipos de funciones
void leerArchivos(Estudiante estudiantes[], int &numEstudiantes);
void mostrar(Estudiante estudiantes[], int numEstudiantes);
void calcularPromedio(Estudiante &estudiante);

int main() {
    const int MAX_ESTUDIANTES = 100;
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int numEstudiantes = 0;

    leerArchivos(estudiantes, numEstudiantes);
    mostrar(estudiantes, numEstudiantes);
    return 0;
}

// Función para leer los archivos de texto y cargar datos en el arreglo de estudiantes
void leerArchivos(Estudiante estudiantes[], int &numEstudiantes) {
    ifstream archivoLista("lista.txt");
    ifstream archivoNotas("nota.txt");
    ifstream archivoEstudiantes("estudiante.txt");

    // Verificar que los archivos se abrieron correctamente
    if (archivoLista.fail() || archivoNotas.fail() || archivoEstudiantes.fail()) {
        cout << "No se pudo abrir uno o más archivos" << endl;
        exit(1);
    }

    string linea;
    // Leer archivo de estudiantes (estudiante.txt)
    while (getline(archivoEstudiantes, linea)) {
        int pos = 0;

        // Leer código de lista
        pos = linea.find(',');
        estudiantes[numEstudiantes].lista = stoi(linea.substr(0, pos));
        linea = linea.substr(pos + 1);

        // Leer nombre
        pos = linea.find(',');
        estudiantes[numEstudiantes].nombre = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        // Leer apellido
        estudiantes[numEstudiantes].apellido = linea;

        // Inicializar las notas del estudiante
        estudiantes[numEstudiantes].numNotas = 0;
        estudiantes[numEstudiantes].promedio = 0;

        numEstudiantes++;
    }
    archivoEstudiantes.close(); 

    // Leer archivo de notas (nota.txt)
    while (getline(archivoNotas, linea)) {
        int pos = linea.find(',');
        int lista = stoi(linea.substr(0, pos)); // Código de lista
        float nota = stof(linea.substr(pos + 1)); // Nota del estudiante

        // Buscar el estudiante con el código de lista correspondiente
        for (int i = 0; i < numEstudiantes; i++) {
            if (estudiantes[i].lista == lista) {
                // Añadir la nota al estudiante
                int notaIndex = estudiantes[i].numNotas;
                estudiantes[i].notas[notaIndex] = nota;
                estudiantes[i].numNotas++;
                break;
            }
        }
    }
    archivoNotas.close();

    // Calcular el promedio de notas para cada estudiante
    for (int i = 0; i < numEstudiantes; i++) {
        calcularPromedio(estudiantes[i]);
    }
}

// Función para calcular el promedio de un estudiante
void calcularPromedio(Estudiante &estudiante) {
    if (estudiante.numNotas == 0) {
        estudiante.promedio = 0;
        return;
    }

    float suma = 0;
    for (int i = 0; i < estudiante.numNotas; i++) {
        suma += estudiante.notas[i];
    }
    estudiante.promedio = suma / estudiante.numNotas;
}

// Función para mostrar los datos de los estudiantes
void mostrar(Estudiante estudiantes[], int numEstudiantes, int lista) {

    for(int a=0; a<numEstudiantes; a++){
        if(estudiantes[a].lista == lista ){
            cout << "Lista: " << estudiantes[a].lista
                 << ", Nombre: " << estudiantes[a].nombre
                 << ", Apellido: " << estudiantes[a].apellido
                 << ", Nota promedio: " << estudiantes[a].promedio << endl;
        }
    }
}
