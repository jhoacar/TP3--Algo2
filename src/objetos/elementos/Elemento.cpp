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
void Elemento::asignar_cantidad(int cantidad){
	this->cantidad=cantidad;
}