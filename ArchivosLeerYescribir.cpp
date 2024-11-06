#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct iden {
    int id;
    string name;
    int nivel;
    string desc;
};

const int n = 100; 
void lectura(iden casos[], int& numCasos);
void buscar(iden casos[], int numCasos);
void agregarNuevo(iden casos[], int& numCasos);
void actualizardescr(iden casos[], int numCasos);
void eliminar(iden casos[], int& numCasos);
void actualizar(iden casos[], int numCasos);
void mostrar(iden casos[], int numCasos);
int main() {
    int a;
    iden casos[n]; 
    int numCasos = 0; 

    while (true) {
        cout << endl << "¿Qué desea hacer en el programa?" << endl;
        cout << "1. Leer archivos de casos" << endl;
        cout << "2. Buscar casos por nivel de propiedad" << endl;
        cout << "3. Agregar nuevo caso" << endl;
        cout << "4. Actualizar descripción de un caso" << endl;
        cout << "5. Eliminar un caso" << endl;
        cout << "6. Actualizar el archivo de caso" << endl;
        cout << "7. Salir" << endl;
        cin >> a;
        cin.ignore();
         
        switch (a) {
            case 1:
                cout << "Leyendo archivos de casos exitosamente" << endl;
                lectura(casos,numCasos);
                break;
            case 2:
                buscar(casos,numCasos);
                break;
            case 3:
               agregarNuevo(casos,numCasos);
                mostrar( casos,numCasos);
                break;
            case 4:
               actualizardescr(casos,numCasos);
                mostrar( casos,numCasos);
                break;
            case 5:
               eliminar(casos,numCasos);
                mostrar( casos,numCasos);
                break;
            case 6:
               actualizar(casos,numCasos);
                break;
            case 7:
                cout << "Saliste del programa" << endl;
                return 0;
            break;
            default:
                cout << "Opción no válida" << endl;
        }
    
    }
}

void lectura(iden casos[], int& numCasos) {
    ifstream archivo("casos.txt");
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo." << endl;
        exit(1);
    }

    string linea;
    numCasos = 0;

    while (numCasos < n && getline(archivo, linea)) {
        int pos = 0;

        pos = linea.find(',');
        casos[numCasos].id = stoi(linea.substr(0, pos));
        linea = linea.substr(pos + 1);

        pos = linea.find(',');
        casos[numCasos].name = linea.substr(0, pos);
        linea = linea.substr(pos + 1);

        pos = linea.find(',');
        casos[numCasos].nivel = stoi(linea.substr(0, pos));
        linea = linea.substr(pos + 1);

        casos[numCasos].desc = linea;

        numCasos++;
    }

    archivo.close();

    for (int i = 0; i < numCasos; i++) {
        cout << "ID: " << casos[i].id << ", Nombre: " << casos[i].name
             << ", Nivel: " << casos[i].nivel << ", Descripción: " << casos[i].desc << endl;
    }
}

void buscar(iden casos[], int numCasos) {
    int nivelBuscado;
    cout << "¿Qué nivel desea buscar?" << endl;
    cin >> nivelBuscado;
    for (int i = 0; i < numCasos; i++) {
        if (casos[i].nivel == nivelBuscado) {
            cout << "ID: " << casos[i].id << endl;
            cout << "Nombre: " << casos[i].name << endl;
            cout << "Nivel: " << casos[i].nivel << endl;
            cout << "Descripción: " << casos[i].desc << endl;
        }
    }
}

void agregarNuevo(iden casos[], int& numCasos) {
    if (numCasos >= n) {
        cout << "No se pueden agregar más casos, arreglo lleno." << endl;
        return;
    }

    cout << "Ingrese el ID del nuevo caso: ";
    cin >> casos[numCasos].id;
    cin.ignore();

    cout << "Ingrese el nombre del nuevo caso: ";
    getline(cin, casos[numCasos].name);

    cout << "Ingrese el nivel del nuevo caso: ";
    cin >> casos[numCasos].nivel;
    cin.ignore();

    cout << "Ingrese la descripción del nuevo caso: ";
    getline(cin, casos[numCasos].desc);

    numCasos++;
}
void actualizardescr(iden casos[], int numCasos){
  int id;
  cout << "Ingrese el id del caso que desea actualizar: ";
  cin >> id;

  int a = 0;  

  for (int i = 0; i < numCasos; i++){
      if (casos[i].id == id) {
          cout << "Ingrese la nueva descripcion: ";
          cin.ignore();  
          getline(cin, casos[i].desc);  
          cout << "Descripcion actualizada con exito" << endl;
          a++;  
          break;  
    }
  }
  if (a == 0) {
      cout << "No se encontro el caso" << endl;
    }
}
void eliminar(iden casos[], int& numCasos){
  int id;
  cout << "Ingrese el id del caso que desea eliminar: ";
  cin >> id;
 
  for (int i = 0; i < numCasos; i++){
      if (casos[i].id == id){
          for (int j = i; j < numCasos - 1; j++){
              casos[j] = casos[j + 1];
            }
          numCasos--;
          cout << "Caso eliminado con exito" << endl;
      }
    }
  if (numCasos == 0) {
    cout << "No se encontro el caso" << endl;
  }
}
void actualizar(iden casos[], int numCasos) {
    ofstream archivo;
    archivo.open("casos.txt", ios::out);  

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo para escritura." << endl;
        return;
    }

    cout << "Actualizando archivo con los casos actuales..." << endl;

    for (int i = 0; i < numCasos; i++) {
        archivo << casos[i].id << "," 
                << casos[i].name << "," 
                << casos[i].nivel << "," 
                << casos[i].desc << endl;
        
    }

    archivo.close();  
    cout << "Archivo actualizado con éxito." << endl;
}
void mostrar(iden casos[], int numCasos){
    cout << "  Casos actuales:" << endl;
    for (int i = 0; i < numCasos; i++) {
        cout << "ID: " << casos[i].id << ", Nombre: " << casos[i].name
             << ", Nivel: " << casos[i].nivel << ", Descripción: " << casos[i].desc << endl;
    }
}

