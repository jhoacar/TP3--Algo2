#include "Estaca.h"
#include <iostream>
using std::cout;
using std::endl;
Estaca::Estaca():Elemento(){
    
}
Estaca::Estaca(Casilla *casilla,char nombre,int cantidad,string ID):Elemento(casilla,nombre,cantidad,ID)
{
}
void Estaca::mostrar(){
    cout<<"Objeto: Estaca"<<endl;
}
Estaca::~Estaca()
{
}
