#include "Cazador.h"
#include "../../../../ataque/Ataque_cazador.h"
#include <iostream>
using std::cout;
using std::endl;
Cazador::Cazador():Humano(){
    ataque = nullptr;
}
Cazador::Cazador(Casilla *casilla,char nombre,string ID):Humano(casilla,nombre,ID){
    ataque = nullptr;
}
void Cazador::mostrar(){
    cout<<"Objeto: Cazador"<<endl;
}
Cazador::~Cazador()
{

}

void Cazador::defender(){

}

void Cazador::atacar(Casilla *casilla, Tablero* tablero){
}
void Cazador::atacar(Casilla *casilla, Tablero* tablero, char arma){
    if(ataque == nullptr)
        this -> ataque = new Ataque_cazador(this);
    ataque -> atacar(casilla, tablero, arma);
}
bool Cazador::validacion_ataque(Casilla *casilla, Tablero* tablero, char arma){
    if(ataque == nullptr)
        this -> ataque = new Ataque_cazador(this);
    return ataque -> validacion_atacar_personaje(casilla, tablero, arma);


}

void Cazador::regenerar_energia() {
    this -> energia += 8;
}
