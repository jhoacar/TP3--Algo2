#include "Elemento.h"
#include <iostream>

Elemento::Elemento():Objeto(){

}

Elemento::Elemento(Casilla *casilla, char nombre ,int cantidad):Objeto(casilla,nombre){
	this->cantidad=cantidad;
}

Elemento::~Elemento()
{

}
int Elemento::obtener_cantidad(){
	return this->cantidad;
}
