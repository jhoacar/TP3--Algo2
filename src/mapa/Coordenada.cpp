#include "Coordenada.h"

Coordenada::Coordenada(){
	this->fila=0;
	this->columna=0;
}

Coordenada::Coordenada(int fila, int columna){
	this->fila=fila;
	this->columna=columna;
}

Coordenada& Coordenada::operator =(Coordenada coordenada){
	this->fila=coordenada.fila;
	this->columna=coordenada.columna;
	return *this;
}

bool Coordenada::operator ==(Coordenada coordenada){
	return this->fila==coordenada.fila && this->columna==coordenada.columna;
}
bool Coordenada::operator !=(Coordenada coordenada){
	return this->fila!=coordenada.fila || this->columna!=coordenada.columna;
}
bool Coordenada::operator<(Coordenada limite){
	return this->fila >= 0 && this->fila < limite.fila &&
		   this->columna >= 0 && this->columna < limite.columna;
}
bool Coordenada::operator>(Coordenada borde){
	return this->fila > borde.fila && this->columna > borde.columna;
}
Coordenada Coordenada::operator+(Coordenada coordenada){
	return {this->fila + coordenada.fila , this->columna + coordenada.columna};
}
Coordenada Coordenada::operator-(Coordenada coordenada){
	return {this->fila - coordenada.fila , this->columna - coordenada.columna};
} 
void Coordenada::operator-=(Coordenada coordenada){
	(this->fila)-=coordenada.fila;
	(this->columna)-=coordenada.columna;
}
void Coordenada::operator+=(Coordenada coordenada){
	(this->fila)+=coordenada.fila;
	(this->columna)+=coordenada.columna;
}


int Coordenada::obtener_fila(){
	return this->fila;
}

int Coordenada::obtener_columna(){
	return this->columna;
}