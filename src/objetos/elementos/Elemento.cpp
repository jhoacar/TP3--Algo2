#include "Elemento.h"
#include <iostream>

Elemento::Elemento():Objeto(){

}

Elemento::Elemento(Casilla *casilla, char nombre ,int cantidad,string ID):Objeto(casilla,nombre,ID){
	this->cantidad=cantidad;
}

Elemento::~Elemento()
{

}
