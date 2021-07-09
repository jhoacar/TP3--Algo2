#include "Bala.h"
#include <iostream>
using std::cout;
using std::endl;

Bala::Bala():Elemento(){

}
Bala::Bala(Casilla *casilla,char nombre,int cantidad):Elemento(casilla,nombre,cantidad)
{
}
void Bala::mostrar(){
    cout<<"Nombre: Bala - Cantidad: "<<this->cantidad<<endl;
}
Bala::~Bala()
{
}
