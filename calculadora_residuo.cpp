#include <iostream>
using namespace std;

int main() {
    int a,b;
    

    cout<< "Ingrese el dividiendo" << endl;
    cin >> a;
    cout<<"Ingrese el divisor" <<endl;
    cin>>b;
    
        int residuo = a % b; // Calcula el residuo
        int division = a / b; // Calcula la parte entera de la división
      cout << "El número es el residuo " << residuo << endl;
  cout<<"Este es el resultado de la división " <<division <<endl;

  cout<<endl;
  cout<<endl;
  cout<<endl;

  
  cout<<"Asi se veria mejor para entender" <<endl;
  cout<<a<<"["<<b<<"]<---- Divisor"<<endl;
  cout<<residuo<<"|["<<division<<"]<---- Division"<<endl;
  cout<<"^"<<endl;
  cout<<"|"<<endl;
  cout<<"Residuo"<<endl;
    return 0;
}
