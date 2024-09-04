#include <iostream>
using namespace std;
int main() {
int a;
cout<<"Ingrese el numero que desee separar"<<endl;
  cin>>a;
  int res = a%10;
  int res2 = (a%100)/10;
  int res3 = (a%1000)/100;
  int res4 = (a%10000)/1000;
  cout<<res<<"--"<<res2<<"--"<<res3<<"--"<<res4<<endl;

}
