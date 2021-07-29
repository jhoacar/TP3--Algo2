#include "Bala.h"
#include <iostream>
using std::cout;
using std::endl;

Bala::Bala():Elemento(){

}
Bala::Bala(Casilla *casilla,char nombre,int cantidad,string ID):Elemento(casilla,nombre,cantidad,ID)
{
}
void Bala::mostrar(){
    cout<<"Nombre: Bala - Cantidad: "<<this->cantidad<<endl;
}
Bala::~Bala()
{
}
