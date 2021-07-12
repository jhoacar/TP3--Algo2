#include "Agua.h"

#include <iostream>
using std::cout;
using std::endl;
Agua::Agua():Elemento(){

}
Agua::Agua(Casilla *casilla,char nombre,int cantidad,string ID):Elemento(casilla,nombre,cantidad,ID)
{
}

Agua::~Agua()
{
}

void Agua::mostrar(){
    cout<<"Objeto: Agua - Cantidad: "<<this->cantidad<<endl;
}