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
int Elemento::obtener_cantidad(){
	return this->cantidad;
}

void Elemento::disminuir_cantidad(int cantidad_gastada){
    this -> cantidad -= cantidad_gastada;
}
