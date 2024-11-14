#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Pacientes {
    string nombre;
    int edad;
    string enfermedad;
    int fecha;
};

const int num = 100;

int leer(Pacientes paciente[], int num);
void mostrar(Pacientes pacientes[], int numPacientes);

int main() {
    Pacientes paciente[num];
    cout << "Se leerán los datos de los pacienteas" << endl;

    int numPacientes = leer(paciente, num);
    cout << "Se mostrarán los datos de los pacientes" << endl;

    mostrar(paciente, numPacientes);

    return 0;
}

int leer(Pacientes paciente[], int num) {
    ifstream archivo("pacientes.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return 0;
    }

    string linea;
    int contador = 0;

    while (getline(archivo, linea) && contador < num) {
        int pos = 0;
        int lastPos = 0;

        // Encontrar la primera coma (edad)
        pos = linea.find(',', lastPos);
        paciente[contador].edad = stoi(linea.substr(lastPos, pos - lastPos));
        lastPos = pos + 1;

        // Encontrar la segunda coma (nombre)
        pos = linea.find(',', lastPos);
        paciente[contador].nombre = linea.substr(lastPos, pos - lastPos);
        lastPos = pos + 1;

        // Encontrar la tercera coma (enfermedad)
        pos = linea.find(',', lastPos);
        paciente[contador].enfermedad = linea.substr(lastPos, pos - lastPos);
        lastPos = pos + 1;

        // El campo final (fecha)
        paciente[contador].fecha = stoi(linea.substr(lastPos));

        contador++;
    }

    archivo.close();
    cout << "Archivo leído con éxito" << endl;
    return contador;
}

void mostrar(Pacientes pacientes[], int numPacientes) {
    for (int a = 0; a < numPacientes; a++) {
        cout << "Nombre: " << pacientes[a].nombre
             << ", Edad: " << pacientes[a].edad
             << ", Enfermedad: " << pacientes[a].enfermedad
             << ", Fecha: " << pacientes[a].fecha << endl;
    }
}
