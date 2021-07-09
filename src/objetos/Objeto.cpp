#include "Objeto.h"
#include "../mapa/Casilla.h"

Objeto::Objeto():nombre(),cuadrante(){
    this->casilla=nullptr;
}
Objeto::Objeto(Casilla *casilla,char nombre){

}
Casilla* Objeto::obtener_casilla(){
    return this->casilla;
}
string Objeto::obtener_cuadrante(){
    return this->cuadrante;
}
char Objeto::obtener_nombre(){
    return this->nombre;
}
void Objeto::asignar_cuadrante(string cuadrante){
    this->cuadrante=cuadrante;
}

void Objeto::asignar_nombre(char nombre){
    this->nombre=nombre;
}
void Objeto::asignar_casilla(Casilla *casilla){
    this->casilla=casilla;
}