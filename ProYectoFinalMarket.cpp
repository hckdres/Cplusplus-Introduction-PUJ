#include <iostream>
#include <string>
#include <fstream>

using namespace std;


const int tamInven = 4;
const int c = 3;
const int maxVentas = 100;

float inventario [tamInven][c] = {
    {1001, 50, 5000.0},
    {1002, 100, 3500.0},
    {1003, 30, 12000.0},
    {1004, 100, 2400.0}
};

string nombresProductos[tamInven] = {"Leche", "Pan", "Huevos", "BotellasAgua"};

struct Ventas {
    string nombreCliente;
    int numeroFactura;
    int IDcliente;
    string nombresProductos[100];
    int cantidadProductosadq[100];
    float totalVenta;
    int totalProductos;
    float descuento[100]; 
};

void letrero();
void despedida();
void mostrarInventario(float inventario[][c], string nombresProductos[]);
void RegistrarVenta(Ventas& venta, float inventario[][c], string nombresProductos[], int& acumuladorFactura);
void EliminarVenta(Ventas ventas[], float inventario[][c], string nombresProductos[], int& totalVentas);
void imprimirFactura(Ventas ventas[], int totalVentas);
bool BuscarVenta(Ventas ventas[], int totalVentas);
void ProductoAgota(float inventario[][c], string nombresProductos[]);
void ProductoVendidos(float inventario[][c], string nombresProductos[], Ventas ventas[], int totalVentas);
float Totalventas(Ventas ventas[], int totalVentas);
void inicializarVentaPrecargada(Ventas& venta, float inventario[][c], string nombresProductos[], string nombre, int factura,
                                int id, string productos[], int cantidades[], int totalProds);

void ImprimirArchivo(Ventas ventas[], int totalVentas);
void ModificarInventario(float inventario[][c], string nombresProductos[], int& productosActuales);


int main() {
    int productosActuales = 3;
    int opcion;
    Ventas ventas[maxVentas];
    int totalVentas = 2;
    int acumuladorFactura = 3;

    string productos1[] = {"Leche", "Pan"};
    int cantidades1[] = {22, 16};
    inicializarVentaPrecargada(ventas[0], inventario, nombresProductos, "Juan", 1, 1785845, productos1, cantidades1, 2);

    string productos2[] = {"Huevos", "BotellasAgua"};
    int cantidades2[] = {11, 21};
    inicializarVentaPrecargada(ventas[1], inventario, nombresProductos, "Maria", 2, 1245789, productos2, cantidades2, 2);

    letrero();

    while (true) {
        cout << "==============================================================================================" << endl;
          cout << " Que desea hacer el programa de MarketPlaceJaveriana " << endl;
      cout << "==============================================================================================" << endl;
          cout << " 1. ---------------> Registrar un venta <---------------------- " << endl;
          cout << " 2. ---------------> Eliminar una venta <---------------------- " << endl;
          cout << " 3. ---------------> Consultar Inventario <-------------------- " << endl;
          cout << " 4. ---------------> Buscar Venta <---------------------------- " << endl;
          cout << " 5. ---------------> Mostrar todas las ventas realizadas <------- " << endl;
          cout << " 6. ---------------> Consultar Productos agotados <-------------- " << endl;
          cout << " 7. ---------------> Calcular el total de productos vendidos <--- " << endl;
          cout << " 8. ---------------> Calcular el total de ingresos por ventas <-- " << endl;
          cout << " 9. ---------------> Imprimir <------------------------------------- " << endl;
          cout << " 10. ---------------> Modificar Inventario <------------------------ " << endl;
          cout << " 11. ---------------> Salir <------------------------------------- " << endl;

          cout << "==============================================================================================" << endl;
          cout << " Ingrese una opcion: ";


        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << " 1. ---------------> Ingreso a registrar un venta <---------------------- " << endl;
                cout << "Inventario de productos:" << endl;
                mostrarInventario(inventario, nombresProductos);
                cout << " --------------------------------------------------" << endl;
                RegistrarVenta(ventas[totalVentas], inventario, nombresProductos, acumuladorFactura);
                totalVentas++;
                break;
            case 2:
                  cout << " 2. ---------------> Ingreso a eliminar una venta <---------------------- " << endl;
                EliminarVenta(ventas, inventario, nombresProductos, totalVentas);
                break;
            case 3:
                cout << " 3. --------> Entro a consultar Inventario <-------------------- " << endl;
                mostrarInventario(inventario, nombresProductos);
                break;
            case 4:
                  cout << " 4. --------> Entro a buscar Venta <---------------------------- " << endl;
                BuscarVenta(ventas, totalVentas);
                break;
            case 5:
                  cout << " 5. --------> Entro a Mostrar todas las ventas realizadas <------- " << endl;
                imprimirFactura(ventas, totalVentas);
                break;
            case 6:
                cout << " 6. --------> Entro a Consultar Productos agotados <-------------- " << endl;
                ProductoAgota(inventario, nombresProductos);
                break;
            case 7:
                cout << " 7. --------> Entro a Calcular el total de productos vendidos <--- " <<endl;
                ProductoVendidos(inventario, nombresProductos, ventas, totalVentas);
                break;
            case 8:
                cout << " 8. --------> Entro a Calcular el total de ingresos por ventas <--- " << endl;
                Totalventas(ventas, totalVentas);
                break;
            case 9:
                cout << " 9. --------> Entro a Imprimir <------------------------------------- " << endl;
                ImprimirArchivo(ventas, totalVentas);
                break;
            case 10:
                cout << " 10. --------> Entro a Modificar Inventario <--------------------- " << endl;
                ModificarInventario(inventario, nombresProductos, productosActuales);
                break;
            case 11:
                cout << " 11. ---------------> Entro a salir <------------------------------------- " << endl;
                despedida();
                return 0;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    }
}


void letrero() {
     cout << "==============================================================================================" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "||                                M A R K E T P L A C E                                     ||" << endl;
      cout << "||                                 J A V E R I A N A                                        ||" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "==============================================================================================" << endl;
      cout << "                                                                                             " << endl;
      cout << "███    ███  █████  ██████  ██   ██ ███████ ████████ ███████ ██     █████  ██████  ███████   " << endl;
      cout << "████  ████ ██   ██ ██   ██ ██  ██  ██         ██    ██   ██ ██    ██   ██ ██      ██        " << endl;
      cout << "██ ████ ██ ███████ ██████  █████   █████      ██    ███████ ██    ███████ ██      ██████    " << endl;
      cout << "██  ██  ██ ██   ██ ██   ██ ██  ██  ██         ██    ██      ██    ██   ██ ██      ██        " << endl;
      cout << "██      ██ ██   ██ ██   ██ ██   ██ ███████    ██    ██      █████ ██   ██ ██████  ██████    " << endl;
      cout << "                                                                  " << endl;
      cout << "     ██  █████  ██    ██ ███████ ██████  ██  █████  ███    ██  █████  " << endl;
      cout << "     ██ ██   ██ ██    ██ ██      ██   ██ ██ ██   ██ ████   ██ ██   ██ " << endl;
      cout << "     ██ ███████ ██    ██ █████   ██████  ██ ███████ ██ ██  ██ ███████ " << endl;
      cout << "██   ██ ██   ██  ██  ██  ██      ██   ██ ██ ██   ██ ██  ██ ██ ██   ██ " << endl;
      cout << " █████  ██   ██   ████   ███████ ██   ██ ██ ██   ██ ██   ████ ██   ██ " << endl;
      cout << "                                                                        " << endl;
      cout << "==============================================================================================" << endl;
}
void despedida() {
      cout << "==============================================================================================" << endl;
      cout << "||                                 G R A C I A S  P O R                                     ||" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "||                            U T I L I Z A R  N U E S T R O                                ||" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "||                                  S E R V I C I O                                         ||" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "||                                M A R K E T P L A C E                                     ||" << endl;
      cout << "||                                 J A V E R I A N A                                        ||" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "==============================================================================================" << endl;
      cout << "                                                                                             " << endl;
      cout << "███    ███  █████  ██████  ██   ██ ███████ ████████ ███████ ██     █████  ██████  ███████   " << endl;
      cout << "████  ████ ██   ██ ██   ██ ██  ██  ██         ██    ██   ██ ██    ██   ██ ██      ██        " << endl;
      cout << "██ ████ ██ ███████ ██████  █████   █████      ██    ███████ ██    ███████ ██      ██████    " << endl;
      cout << "██  ██  ██ ██   ██ ██   ██ ██  ██  ██         ██    ██      ██    ██   ██ ██      ██        " << endl;
      cout << "██      ██ ██   ██ ██   ██ ██   ██ ███████    ██    ██      █████ ██   ██ ██████  ██████    " << endl;
      cout << "                                                                                            " << endl;
      cout << "             ██  █████  ██    ██ ███████ ██████  ██  █████  ███    ██  █████                  " << endl;
      cout << "             ██ ██   ██ ██    ██ ██      ██   ██ ██ ██   ██ ████   ██ ██   ██                 " << endl;
      cout << "             ██ ███████ ██    ██ █████   ██████  ██ ███████ ██ ██  ██ ███████                 " << endl;
      cout << "        ██   ██ ██   ██  ██  ██  ██      ██   ██ ██ ██   ██ ██  ██ ██ ██   ██                 " << endl;
      cout << "         █████  ██   ██   ████   ███████ ██   ██ ██ ██   ██ ██   ████ ██   ██                 " << endl;
      cout << "                                                                                              " << endl;
      cout << "==============================================================================================" << endl;
      cout << "           ███████  ██████     █████   ███████  ██   █████   █████████                        " << endl;
      cout << "           ██       ██   ██   ██   ██  ██       ██  ██   ██  ██                               " << endl;
      cout << "           ██   ██  ██████    ███████  ██       ██  ███████  █████████                        " << endl;
      cout << "           ██   ██  ██   ██   ██   ██  ██       ██  ██   ██         ██                        " << endl;
      cout << "           ███████  ██   ██   ██   ██  ███████  ██  ██   ██  █████████                        " << endl;
      cout << "============================================================================================= " << endl;
      cout << "||                               E L A B O R A D O   P O R                                  ||" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "||                                A N D R E S C O R T E S                                   ||" << endl;
      cout << "||                                         &                                                ||" << endl;
      cout << "||                                J U A N  P U E R T O                                      ||" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "||                              P R O Y E C T O  F I N A L                                  ||" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "||                         I N T R O. P R O G R A M A C I O N                               ||" << endl;
      cout << "==============================================================================================" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "||                                M A R K E T P L A C E                                     ||" << endl;
      cout << "||                                 J A V E R I A N A                                        ||" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "||                                                                                          ||" << endl;
      cout << "==============================================================================================" << endl;
}

void mostrarInventario(float inventario[][c], string nombresProductos[]) {
    cout << "--------------------------------------------------------------" << endl;
    cout << "Código\t|Nombre\t\t|Cantidad Disponible\t|Precio por Unidad" << endl;
    cout << "--------------------------------------------------------------" << endl;
    for (int i = 0; i < tamInven; i++) {
        cout << inventario[i][0] << "\t|"
             << nombresProductos[i] << "\t\t|"
             << inventario[i][1] << "\t\t|"
             << "$" << inventario[i][2] << endl;
    }
    cout << "--------------------------------------------------------------" << endl;
}

void RegistrarVenta(Ventas& venta, float inventario[][c], string nombresProductos[], int& acumuladorFactura) {
    cout << "Ingrese el nombre del cliente: ";
    cin >> venta.nombreCliente;
    venta.numeroFactura = acumuladorFactura++;
    cout << "Ingrese el ID del cliente: ";
    cin >> venta.IDcliente;

    cout << "Ingrese la cantidad de productos a adquirir: ";
    int numProductos;
    cin >> numProductos;
    venta.totalProductos = numProductos;

    float totalVenta = 0.0;

    for (int i = 0; i < numProductos; i++) {
        string nombreProducto;
        int cantidadAdquirida;

        cout << "Ingrese el nombre del producto #" << (i + 1) << ": ";
        cin >> nombreProducto;
        cout << "Ingrese la cantidad de " << nombreProducto << ": ";
        cin >> cantidadAdquirida;

        bool productoEncontrado = false;

        for (int j = 0; j < tamInven; j++) {
            if (nombresProductos[j] == nombreProducto) {
                if (cantidadAdquirida <= inventario[j][1]) {
                    inventario[j][1] -= cantidadAdquirida;
                    venta.nombresProductos[i] = nombreProducto;
                    venta.cantidadProductosadq[i] = cantidadAdquirida;

                    if (cantidadAdquirida > 10) {
                        venta.descuento[i] = 0.1; // 10% descuento
                        totalVenta += cantidadAdquirida * inventario[j][2] * (1 - venta.descuento[i]);
                        cout << "Se aplicó un descuento del 10% al producto: " << nombreProducto << endl;
                    } else {
                        venta.descuento[i] = 0.0; // Sin descuento
                        totalVenta += cantidadAdquirida * inventario[j][2];
                    }

                    productoEncontrado = true;
                } else {
                    cout << "Sin stock suficiente para el producto: " << nombreProducto << endl;
                }
                break;
            }
        }

        if (!productoEncontrado) {
            cout << "Producto " << nombreProducto << " no encontrado en el inventario." << endl;
            i--; // Reintentar ingresar el producto
        }
    }

    venta.totalVenta = totalVenta;
    cout << "Venta registrada exitosamente con factura #" << venta.numeroFactura << endl;
}


void EliminarVenta(Ventas ventas[], float inventario[][c], string nombresProductos[], int& totalVentas) {
    cout << "Ingrese el número de factura que desea eliminar: ";
    int numFactura;
    cin >> numFactura;

    int index = -1;
    for (int i = 0; i < totalVentas; i++) {
        if (ventas[i].numeroFactura == numFactura) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "No se encontró ninguna venta con ese número de factura." << endl;
        return;
    }

    for (int i = 0; i < ventas[index].totalProductos; i++) {
        string nombreProducto = ventas[index].nombresProductos[i];
        int cantidad = ventas[index].cantidadProductosadq[i];

        for (int j = 0; j < tamInven; j++) {
            if (nombresProductos[j] == nombreProducto) {
                inventario[j][1] += cantidad;
                break;
            }
        }
    }

    for (int i = index; i < totalVentas - 1; i++) {
        ventas[i] = ventas[i + 1];
    }
    totalVentas--;

    cout << "La venta ha sido eliminada." << endl;
}

void imprimirFactura(Ventas ventas[], int totalVentas) {
    for (int j = 0; j < totalVentas; j++) {
          cout << " --------------------------------------------------" << endl;
          cout << " | F A C T U R A  # " << ventas[j].numeroFactura << " M A R K E T J A V E R I A N A  |" << endl;
          cout << " --------------------------------------------------" << endl;
          cout << " | Nombre del cliente : " << ventas[j].nombreCliente << "     |" << endl;
          cout << " | Numero de factura : " << ventas[j].numeroFactura << "                   |" << endl;
          cout << " | Numero de documento : " << ventas[j].IDcliente << "     |" << endl;
          cout << " --------------------------------------------------" << endl;
          cout << " | Productos adquiridos:                           |" << endl;

          for (int i = 0; i < ventas[j].totalProductos; i++) {
              cout << " | " << ventas[j].nombresProductos[i] << " - Cantidad: " << ventas[j].cantidadProductosadq[i] << " |" << endl;
          }

          cout << " --------------------------------------------------" << endl;
          cout << " |\033[32mTotal de la venta : $\033[0m " << ventas[j].totalVenta << " |" << endl;
          cout << " --------------------------------------------------" << endl;
      }
}

bool BuscarVenta(Ventas ventas[], int totalVentas) {
    int ID;

    cout<< "Ingrese el numero de documento del cliente: ";
    cin>> ID;
      for (int j = 0; j < totalVentas; j++){
        if (ventas[j].IDcliente == ID){
        cout << " --------------------------------------------------" << endl;
            cout << " | F A C T U R A  # " << ventas[j].numeroFactura << " M A R K E T J A V E R I A N A  |" << endl;
            cout << " --------------------------------------------------" << endl;
            cout << " | Nombre del cliente : " << ventas[j].nombreCliente << "     |" << endl;
            cout << " | Numero de factura : " << ventas[j].numeroFactura << "                   |" << endl;
            cout << " | Numero de documento : " << ventas[j].IDcliente << "     |" << endl;
            cout << " --------------------------------------------------" << endl;
            cout << " | Productos adquiridos:                           |" << endl;

            for (int i = 0; i < ventas[j].totalProductos; i++) {
                cout << " | " << ventas[j].nombresProductos[i] << " - Cantidad: " << ventas[j].cantidadProductosadq[i] << " |" << endl;
            }

            cout << " --------------------------------------------------" << endl;
            cout << " | Total de la venta : $ " << ventas[j].totalVenta << " |" << endl;
            cout << " --------------------------------------------------" << endl;
        }
      }

    return true;
}

void ProductoAgota(float inventario[][c], string nombresProductos[]) {
    for (int i = 0; i < tamInven; i++) {
        if (inventario[i][1] == 0) {
            cout << "\033[31mEl producto\033[0m " << nombresProductos[i] << " \033[31msin Stock\033[0m "<< endl;
        }
    }
}

void ProductoVendidos(float inventario[][c], string nombresProductos[], Ventas ventas[], int totalVentas) {
    int vendidos[tamInven] = {0};

    for (int i = 0; i < totalVentas; i++) {
        for (int j = 0; j < ventas[i].totalProductos; j++) {
            string nombreProducto = ventas[i].nombresProductos[j];
            int cantidad = ventas[i].cantidadProductosadq[j];

            for (int k = 0; k < tamInven; k++) {
                if (nombresProductos[k] == nombreProducto) {
                    vendidos[k] += cantidad;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < tamInven; i++) {
        cout << "\033[32mProducto\033[0m " << nombresProductos[i]
                   << " \033[32mse vendio\033[0m " << vendidos[i]
                   << " \033[32mUnidades\033[0m" << endl;
    }
}

float Totalventas(Ventas ventas[], int totalVentas) {
    float totalIngresos = 0;

    for (int i = 0; i < totalVentas; i++) {
        totalIngresos += ventas[i].totalVenta;
    }

    cout << "Total de ingresos por ventas: $" << totalIngresos << endl;

    return totalIngresos;
}

void inicializarVentaPrecargada(Ventas& venta, float inventario[][c], string nombresProductos[], string nombre, int factura,
                                int id, string productos[], int cantidades[], int totalProds) {
    venta.nombreCliente = nombre;
    venta.numeroFactura = factura;
    venta.IDcliente = id;
    venta.totalProductos = totalProds;
    venta.totalVenta = 0;

    for (int i = 0; i < totalProds; i++) {
        for (int j = 0; j < tamInven; j++) {
            if (productos[i] == nombresProductos[j]) {
                inventario[j][1] -= cantidades[i];
                venta.nombresProductos[i] = productos[i];
                venta.cantidadProductosadq[i] = cantidades[i];
                venta.totalVenta += cantidades[i] * inventario[j][2];
                break;
            }
        }
    }
}


void ImprimirArchivo(Ventas ventas[], int totalVentas){
  
  ofstream archivo;
  string nombreArchivo = "ventas.txt";
  string frase;
  
  cout<< "Desea imprimir todas las facturas o solo una? (1 para todas, 2 para una): ";
  int opcion;
  cin>> opcion;
  if (opcion == 1){
    archivo.open(nombreArchivo.c_str(), ios::app);
    if (archivo.fail()){
      cout<< "No se pudo abrir el archivo";
      exit(1);
    }
    for (int i = 0; i < totalVentas; i++){
      archivo << " --------------------------------------------------" << endl;
      archivo << " | F A C T U R A  # " << ventas[i].numeroFactura << " M A R K E T J A V E R I A N A  |" << endl;
      archivo << " --------------------------------------------------" << endl;
      archivo << " | Nombre del cliente : " << ventas[i].nombreCliente << "     |" << endl;
      archivo << " | Numero de factura : " << ventas[i].numeroFactura << "                   |" << endl;
      archivo << " | Numero de documento : " << ventas[i].IDcliente << "     |" << endl;
      archivo << " --------------------------------------------------" << endl;
      archivo << " | Productos adquiridos:                           |" << endl;
      for (int j = 0; j < ventas[i].totalProductos; j++){
        archivo << " | " << ventas[i].nombresProductos[j] << "  - Cantidad: " << ventas[i].cantidadProductosadq[j] << " |" << endl;
          }
      archivo << " --------------------------------------------------" << endl;
      archivo << " | Total de la venta : $ " << ventas[i].totalVenta << " | " <<endl;
      archivo << " --------------------------------------------------" << endl;
      }
    }else if (opcion == 2) {  
    
    int factura;
    cout << "Ingrese el número de factura que desea imprimir: ";
    cin >> factura;

    bool encontrada = false;
    for (int i = 0; i < totalVentas; i++) {
      string nombreArchivo2 = " Factura # " + to_string(ventas[i].numeroFactura) + ".txt";
      ofstream archivo(nombreArchivo2.c_str(), ios::app);

      if (archivo.fail()) {
          cout << "No se pudo abrir el archivo para la factura #" << ventas[i].numeroFactura << endl;
          exit(1);
      }
        if (ventas[i].numeroFactura == factura) {
            encontrada = true;

            archivo << " --------------------------------------------------" << endl;
            archivo << " | F A C T U R A  # " << ventas[i].numeroFactura << " M A R K E T J A V E R I A N A  |" << endl;
            archivo << " --------------------------------------------------" << endl;
            archivo << " | Nombre del cliente : " << ventas[i].nombreCliente << "     |" << endl;
            archivo << " | Numero de factura : " << ventas[i].numeroFactura << "                   |" << endl;
            archivo << " | Numero de documento : " << ventas[i].IDcliente << "     |" << endl;
            archivo << " --------------------------------------------------" << endl;
            archivo << " | Productos adquiridos:                           |" << endl;

            for (int j = 0; j < ventas[i].totalProductos; j++) {
                archivo << " | " << ventas[i].nombresProductos[j] << "  - Cantidad: " << ventas[i].cantidadProductosadq[j] << " |" << endl;
            }

            archivo << " --------------------------------------------------" << endl;
            archivo << " | Total de la venta : $ " << ventas[i].totalVenta << " | " << endl;
            archivo << " --------------------------------------------------" << endl;

          archivo.close();
          cout << "Factura #" << ventas[i].numeroFactura << " guardada en el archivo " << nombreArchivo2 << endl;
          break;
        }
    }

    if (!encontrada) {
        cout << "No se encontró una factura con ese número." << endl;
    }
  }

  archivo.close();
  cout << "Archivo generado correctamente." << endl;
  }

void ModificarInventario(float inventario[][c], string nombresProductos[], int& productosActuales) {
    int opcion;
    cout << "Que desea hacer en el inventario (1. Agregar Productos Nuevos, 2. Cambiar las cantidades, 3.     Cambiar precios): " << endl;
    cin >> opcion;

    if (opcion == 1) {
        if (productosActuales >= tamInven) {
            cout << "El inventario está lleno. No se pueden agregar más productos." << endl;
            return;
        }
      cout << "==============================================================================================" << endl;
        cout << "Ingrese el código del producto: ";
        int codigo;
        cin >> codigo;

        cout << "Ingrese el nombre del producto: ";
        string nombre;
        cin.ignore(); 
        getline(cin, nombre);

        cout << "Ingrese la cantidad del producto: ";
        int cantidad;
        cin >> cantidad;

        cout << "Ingrese el precio del producto: ";
        float precio;
        cin >> precio;

        inventario[productosActuales][0] = codigo;
        inventario[productosActuales][1] = cantidad;
        inventario[productosActuales][2] = precio;
        nombresProductos[productosActuales] = nombre;

        productosActuales++; 
      cout << "==============================================================================================" << endl;
      cout << "==============================================================================================" << endl;
        cout << "Producto agregado correctamente." << endl;
        mostrarInventario(inventario, nombresProductos);
    }
  else if (opcion == 2){
    cout << "==============================================================================================" << endl;
    int codigo;
    cout << "Ingrese el código del producto: ";
    cin >> codigo;
    for (int i = 0; i < productosActuales; i++){
      if (inventario[i][0] == codigo){
        cout << "Ingrese la nueva cantidad del producto: ";
        int nuevaCantidad;
        cin >> nuevaCantidad;
        inventario[i][1] = nuevaCantidad;
        cout << "Cantidad del producto actualizada correctamente." << endl;
        cout << "==============================================================================================" << endl;
        mostrarInventario(inventario, nombresProductos);

      }
    }
  }
  else if(opcion == 3){
    cout << "==============================================================================================" << endl;
    int codigo;
    cout << "Ingrese el código del producto: ";
    cin >> codigo;
    for (int i = 0; i < productosActuales; i++){
      if (inventario[i][0] == codigo){
        cout << "Ingrese el nuevo precio del producto: ";
        float nuevoPrecio;
        cin >> nuevoPrecio;
        inventario[i][2] = nuevoPrecio;
        cout << "Precio del producto actualizado correctamente." << endl;
        cout << "==============================================================================================" << endl;
        mostrarInventario(inventario, nombresProductos);

      }
    }
  }
}
