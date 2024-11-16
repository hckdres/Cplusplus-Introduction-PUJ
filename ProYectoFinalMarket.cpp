#include <iostream>
#include <string>


using namespace std;

const int tamInven = 4;
const int maxVentas = 100;


struct Producto {
int codigos[tamInven] = {1001, 1002, 1003, 1004};
int cantidades[tamInven] = {50, 100, 30, 100};
float precios[tamInven] = {5000.0, 3500.0, 12000.0, 2400.0};
string nombres[tamInven] = {"Leche", "Pan", "Huevos", "BotellasAgua"};

};
struct Ventas{
string nombreCliente;
int numeroFactura;
int IDcliente;
string nombresProductos[100];
int cantidadProductosadq[100];
float totalVenta;
int totalProductos; 

};



void letrero();
void despedida();
void RegistrarVenta(Ventas& ventas, Producto& producto, int& acumuladorFactura);
void EliminarVenta(Ventas ventas[], Producto& producto, int& totalVentas);
void imprimirFactura(Ventas ventas[], int totalVentas);
void mostrarInventario(Producto& producto);
bool BuscarVenta(Ventas ventas[], int totalVentas);
void ProductoAgota(Producto& producto);
void ProductoVendidos (Producto& producto, Ventas ventas[], int totalVentas);
void Totalventas (Ventas ventas[], int totalVentas);
void inicializarVentaPrecargada(Ventas& venta, Producto& producto, string nombre, int factura, 
   int id, string productos[], int cantidades[], int totalProds);


int main() {

  int totalVentas = 2; 
  

  Producto producto;
  Ventas ventas[maxVentas];

    string productos1[] = {"Leche", "Pan"};
    int cantidades1[] = {22, 16};
    inicializarVentaPrecargada(ventas[0], producto, "Juan", 1, 1785845, productos1, cantidades1, 2);


    string productos2[] = {"Huevos", "BotellasAgua"};
    int cantidades2[] = {11, 21};
    inicializarVentaPrecargada(ventas[1], producto, "Maria", 2, 1245789, productos2, cantidades2, 2);

  int acumuladorFactura = 1;
  for(int i = 0; i < totalVentas; i++) {
      if(ventas[i].numeroFactura >= acumuladorFactura) {
          acumuladorFactura = ventas[i].numeroFactura + 1;
      }
  }
  

  
  letrero();
  while (true){
  cout << " Que desea hacer el programa de MarketPlaceJaveriana " << endl;
  cout << " 1. ---------------> Registrar un venta <---------------------- " << endl;
  cout << " 2. ---------------> Eliminar una venta <---------------------- " << endl;
  cout << " 3. ---------------> Consultar Inventario <-------------------- " << endl;
  cout << " 4. ---------------> Buscar Venta <---------------------------- " << endl;
  cout << " 5. ---------------> Mostrar todas las ventas realizadas <------- " << endl;
  cout << " 6. ---------------> Consultar Productos agotados <-------------- " << endl;
  cout << " 7. ---------------> Calcular el total de productos vendidos <--- " << endl;
  cout << " 8. ---------------> Calcular el total de ingresos por ventas <-- " << endl;
  cout << " 9. ---------------> Salir <------------------------------------- " << endl;
  cout << "==============================================================================================" << endl;
  cout << " Ingrese una opcion: ";
  int opcion;
  cin >> opcion;
  switch (opcion){
    case 1:{
      cout << " 1. ---------------> Ingreso a registrar un venta <---------------------- " << endl;
        cout << "Inventario de productos:" << endl;
        mostrarInventario(producto);
        cout << " --------------------------------------------------" << endl;
       RegistrarVenta(ventas[totalVentas], producto, acumuladorFactura);
      totalVentas++;
      break;
    }
    case 2:{
      cout << " 2. ---------------> Ingreso a eliminar una venta <---------------------- " << endl;
        EliminarVenta(ventas, producto, totalVentas);
      break;
    }
    case 3:{
        cout << " 3. --------> Entro a consultar Inventario <-------------------- " << endl;
        mostrarInventario(producto);

      break;
    }
    case 4:{
      cout << " 4. --------> Entro a buscar Venta <---------------------------- " << endl;
       BuscarVenta(ventas,totalVentas);
      break;
    }
    case 5:{
      cout << " 5. --------> Entro a Mostrar todas las ventas realizadas <------- " << endl;
      imprimirFactura(ventas, totalVentas);
      break;
    }
    case 6:{
      cout << " 6. --------> Entro a Consultar Productos agotados <-------------- " << endl;
      ProductoAgota(producto);
      break;
    }
    case 7:{
      cout << " 7. --------> Entro a Calcular el total de productos vendidos <--- " <<endl;
      ProductoVendidos(producto,ventas, totalVentas);

      break;
    }
    case 8:{
      cout << " 8. --------> Entro a Calcular el total de ingresos por ventas <--- " << endl;
       Totalventas(ventas, totalVentas);
      break;
    }
    case 9:{
      cout << " 9. ---------------> Entro a salir <------------------------------------- " << endl;
      despedida();
      return 0;
      break;
    }
    }
  }
}
void letrero(){
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
void despedida(){
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
void mostrarInventario(Producto& producto) {
  cout << "Código\t|Nombre\t\t|Cantidad Disponible\t|Precio por Unidad" << endl;
  cout << "--------------------------------------------------------------" << endl;
  for (int i = 0; i < tamInven; i++) {
      cout << producto.codigos[i] << "\t|";              
      cout << producto.nombres[i] << "\t\t|";            
      cout << producto.cantidades[i] << "\t\t|";       
      cout << "$" << producto.precios[i] << endl;       
  }
  cout << " --------------------------------------------------------------" << endl;
}
void RegistrarVenta(Ventas& venta, Producto& producto, int& acumuladorFactura) {
    string nombreProducto;
    int cantidadAdquirida;
    
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
        cout << "Ingrese el nombre del producto #" << (i + 1) << ": ";
        cin >> nombreProducto;
        cout << "Ingrese la cantidad de " << nombreProducto << ": ";
        cin >> cantidadAdquirida;

        bool productoEncontrado = false;

        for (int j = 0; j < tamInven; j++) {
            if (producto.nombres[j] == nombreProducto) {
                if (cantidadAdquirida <= producto.cantidades[j]) {
                    venta.nombresProductos[i] = nombreProducto;
                    venta.cantidadProductosadq[i] = cantidadAdquirida;
                    float precio = producto.precios[j];
                    totalVenta += cantidadAdquirida * precio;

                    productoEncontrado = true;
                    venta.nombresProductos[i] = nombreProducto;
                    venta.cantidadProductosadq[i] = cantidadAdquirida;
                } else {
                    cout << " Sin stock " << nombreProducto << endl;
                }
                break;
            }
        }

        if (!productoEncontrado) {
            cout << "Producto " << nombreProducto << " \033[31msin Stock\033[0m " << endl;
            i--;
        }
    }

    venta.totalVenta = totalVenta;
    cout << "Venta registrada exitosamente con factura #" << venta.numeroFactura << endl;
}
void EliminarVenta(Ventas ventas[], Producto& producto, int& totalVentas) {
    int a;
    cout << "Ingrese el número de factura de la venta que desea eliminar: ";
    cin >> a;

    int encontradosi = -1;
    for (int i = 0; i < totalVentas; i++) {
        if (ventas[i].numeroFactura == a) {
            encontradosi = i;
            break;
        }
    }

    if (encontradosi == -1) {
        cout << "No se encontró ninguna venta con el número de factura " << a << "." << endl;
        return;
    }

    for (int i = 0; i < ventas[encontradosi].totalProductos; i++) {
        string nombreProducto = ventas[encontradosi].nombresProductos[i];
        int cantidadRestaurar = ventas[encontradosi].cantidadProductosadq[i];

        for (int j = 0; j < tamInven; j++) {
            if (producto.nombres[j] == nombreProducto) {
                producto.cantidades[j] += cantidadRestaurar;
                break;
            }
        }
    }

    for (int i = encontradosi; i < totalVentas - 1; i++) {
        ventas[i] = ventas[i + 1];
    }
    totalVentas--; 

    cout << "La venta con el número de factura " << a << " ha sido eliminada. " << endl;
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
bool BuscarVenta(Ventas ventas[], int totalVentas){
  cout<< "Ingrese el numero de documento del cliente: ";
  int IDcliente;
  cin>> IDcliente;
  for (int j = 0; j < totalVentas; j++){
    if (ventas[j].IDcliente == IDcliente){
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
void ProductoAgota(Producto& producto){
  for (int i = 0; i < tamInven; i++){
    if (producto.cantidades[i] == 0){
      cout << "\033[31mEl producto\033[0m " << producto.nombres[i] << " \033[31msin Stock\033[0m "<< endl;
    }
  }
}
void ProductoVendidos (Producto& producto, Ventas ventas[], int totalVentas){
  int totalProductosVendidos[tamInven] = {0}; 

  for(int i = 0; i < totalVentas; i++) {
      for(int j = 0; j < ventas[i].totalProductos; j++) {
          string nombreProducto = ventas[i].nombresProductos[j];
          for(int k = 0; k < tamInven; k++) {
              if(producto.nombres[k] == nombreProducto) {
                  totalProductosVendidos[k] += ventas[i].cantidadProductosadq[j];
                  break;
              }
          }
      }
  }

  for(int i = 0; i < tamInven; i++) {
      cout << "\033[32mProducto\033[0m " << producto.nombres[i] 
           << " \033[32mse vendió\033[0m " << totalProductosVendidos[i] 
           << " \033[32mUnidades\033[0m" << endl;
  }
}

void Totalventas (Ventas ventas[], int totalVentas){
  float totalIngresos = 0;
  for(int i = 0; i < totalVentas; i++) {
      totalIngresos += ventas[i].totalVenta;
  }
  cout << "El total de ventas es: $" << totalIngresos << endl;
}
void inicializarVentaPrecargada(Ventas& venta, Producto& producto, string nombre, int factura, 
                               int id, string productos[], int cantidades[], int totalProds) {
    venta.nombreCliente = nombre;
    venta.numeroFactura = factura;
    venta.IDcliente = id;
    venta.totalProductos = totalProds;
    float totalVenta = 0;

for (int i = 0; i < totalProds; i++) {
    bool productoEncontrado = false;

    for (int j = 0; j < tamInven; j++) {
        if (producto.nombres[j] == productos[i]) {
            if (producto.cantidades[j] >= cantidades[i]) {
                producto.cantidades[j] -= cantidades[i];

                totalVenta += cantidades[i] * producto.precios[j];

                venta.nombresProductos[i] = productos[i];
                venta.cantidadProductosadq[i] = cantidades[i];

                productoEncontrado = true;
            } else {
                cout << " Sin stock " 
                     << productos[i] << ".\n";
            }
            break;
        }
    }

    if (!productoEncontrado) {
        cout << "Error: Producto " << productos[i] << " no encontrado en el inventario.\n";
        venta.nombresProductos[i] = "Producto no encontrado";
        venta.cantidadProductosadq[i] = 0; 
    }
}
venta.totalVenta = totalVenta;

}

