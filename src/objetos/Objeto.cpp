#include "Objeto.h"
#include "../mapa/Casilla.h"
#include "seres/humanos/Humano.h"

Objeto::Objeto():nombre(),cuadrante(),ID(){
    this->casilla=nullptr;
}
Objeto::Objeto(Casilla *casilla,char nombre,string ID){
    this->casilla = casilla;
    this->nombre = nombre;
    this->ID = ID;
    this->cuadrante="";
}
Objeto::~Objeto(){
}
Casilla* Objeto::obtener_casilla(){
    return this->casilla;
}
string Objeto::obtener_cuadrante(){
    return this->cuadrante;
}
string Objeto::obtener_ID(){
    return this->ID;
}
char Objeto::obtener_nombre(){
    return this->nombre;
}
void Objeto::asignar_cuadrante(string cuadrante){
    this->cuadrante=cuadrante;
}
void Objeto::asignar_ID(string ID){
    this->ID=ID;
}
void Objeto::asignar_nombre(char nombre){
    this->nombre=nombre;
}
void Objeto::asignar_casilla(Casilla *casilla){
    this->casilla=casilla;
}


