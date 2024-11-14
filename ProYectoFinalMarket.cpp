#include <iostream>
#include <string>
using namespace std;

const int tamInven = 3;

struct Producto {
int codigos[tamInven] = {1001, 1002, 1003};
int cantidades[tamInven] = {50, 100, 30};
float precios[tamInven] = {5000.0, 3500.0, 12000.0};
string nombres[tamInven] = {"Leche", "Panes", "Huevos"};

};
struct Ventas{
string nombreCliente[tamInven];
int numeroFactura[tamInven];
int IDcliente[tamInven];
string nombresProductos[tamInven];
int cantidadProductosadq[tamInven];
float totalVenta[tamInven];
};



void letrero();
void despedida();
void mostrarInventario(Producto& producto);
void RegistrarVenta(Ventas& ventas, Producto& producto);
void EliminarVenta(Ventas& ventas, Producto& producto);

int main() {
  Producto producto;
  Ventas ventas;
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
      RegistrarVenta(ventas, producto);
      break;
    }
    case 2:{
      cout << " 2. ---------------> Ingreso a eliminar una venta <---------------------- " << endl;
       EliminarVenta(ventas,producto);
      break;
    }
    case 3:{
        cout << " 3. --------> Entro a consultar Inventario <-------------------- " << endl;
       mostrarInventario(producto);
      break;
    }
    case 4:{
      cout << " 4. --------> Entro a buscar Venta <---------------------------- " << endl;
      break;
    }
    case 5:{
      cout << " 5. --------> Entro a Mostrar todas las ventas realizadas <------- " << endl;
      break;
    }
    case 6:{
      cout << " 6. --------> Entro a Consultar Productos agotados <-------------- " << endl;
      break;
    }
    case 7:{
      cout << " 7. --------> Entro a Calcular el total de productos vendidos <--- " <<endl;
      break;
    }
    case 8:{
      cout << " 8. --------> Entro a Calcular el total de ingresos por ventas <--- " << endl;
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
}
void RegistrarVenta(Ventas& ventas, Producto& producto){
  int acumulador = 0;
  int quita = 0;
  for(int i = 0; i < 1; i++){
  cout << "Ingrese el nombre del cliente: ";
  cin >> ventas.nombreCliente[i];  
  acumulador ++;
  ventas.numeroFactura[i] = acumulador;
    if(ventas.numeroFactura[i-1] == 1){
    }
  cout << "Ingrese el ID del cliente: ";
  cin >> ventas.IDcliente[i];
  cout << "Ingrese la cantidad de productos a adquirir: ";
  cin >> ventas.cantidadProductosadq[i];
    if(ventas.cantidadProductosadq[i] > producto.cantidades[i]){
      cout << "No hay suficientes productos para realizar la venta" << endl;
    }
  cout << "Ingrese el nombre del producto a adquirir: ";
  cin >> ventas.nombresProductos[i];
  cout<< "-----------------------------------------------"<<endl;
  }
  for(int i = 0; i < 1; i++){
  if(ventas.nombresProductos[i] == producto.nombres[i]){
    ventas.totalVenta[i] = ventas.cantidadProductosadq[i] * producto.precios[i];
    quita = producto.cantidades[i] - ventas.cantidadProductosadq[i];
    producto.cantidades[i] = quita;
  }  
  }

  for(int j = 0; j < 1; j++){
    cout<<  " --------------------------------------------------"<<endl;
    cout<<  " | F A C T U R A  # " << ventas.numeroFactura[j] << " M A R K E T J A V E R I A N A  |"<<endl;
    cout<<  " --------------------------------------------------"<<endl;
    cout << " |Nombre del cliente : "<< ventas.nombreCliente[j]      <<"     |" << endl;
    cout << " |Numero de factura : " <<ventas.numeroFactura[j]       <<"                   |" << endl;
    cout << " |Numero de documento : "<< ventas.IDcliente[j]         <<"     |" <<endl;
    cout << " |Cantidades : " <<ventas.cantidadProductosadq[j]       <<"                   |" << endl;
    cout << " |Producto adquirido : " << ventas.nombresProductos[j]  <<"     |" << endl;
    cout << " |Total de la venta : $ " <<ventas.totalVenta[j]        <<"    |" << endl;
    cout<< "-----------------------------------------------------"<<endl;
  }
}
void Agotado(Producto& producto, Ventas& ventas){
  for(int i=0; i<tamInven; i++){
    if(producto.cantidades[i] == 0){
      cout << "El producto " << ventas.nombresProductos[i] << " sin stock " << endl;
    }
  }
}
void EliminarVenta(Ventas& ventas, Producto& producto){
  int a;
  cout << "Ingrese el numero de factura: ";
  cin >> a;
  for(int i=0; i<tamInven; i++){
    if(a == ventas.numeroFactura[i]){
      ventas.nombreCliente[i] = "";
      ventas.numeroFactura[i] = 0;
      ventas.IDcliente[i] = 0;
      ventas.cantidadProductosadq[i] = 0;
      ventas.nombresProductos[i] = "";
      ventas.totalVenta[i] = 0;
    }
  }
}
void VentasRealizadas(Ventas& ventas, Producto& producto){
  for(int i=0; i<tamInven; i++){
    cout<< "-----------------------------------------------"<<endl;
    cout << ventas.nombreCliente[i] << endl;
    cout << ventas.numeroFactura[i] << endl;
    cout << ventas.IDcliente[i] << endl;
    cout << ventas.cantidadProductosadq[i] << endl;
    cout << ventas.nombresProductos[i] << endl;
    cout << ventas.totalVenta[i] << endl;
    cout<< "-----------------------------------------------"<<endl;
  }
}
