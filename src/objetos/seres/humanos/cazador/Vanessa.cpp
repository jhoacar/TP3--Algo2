#include "Vanessa.h"
#include <iostream>
#include "../../../../ataque/Ataque_vanesa.h"
using std::cout;
using std::endl;
Vanessa::Vanessa():Cazador(){
    ataque = nullptr;
}
Vanessa::Vanessa(Casilla *casilla,char nombre,string ID):Cazador(casilla,nombre,ID)
{
    ataque= nullptr;
}
void Vanessa::mostrar(){
    cout<<"Objeto: Vanessa"<<endl;
}
Vanessa::~Vanessa()
{
    if(ataque != nullptr)
        delete ataque;
}
void Vanessa::defender(){

}

bool Vanessa::validacion_ataque(Casilla *casilla, Tablero* tablero, char arma){
    if(ataque == nullptr)
        this -> ataque = new Ataque_vanesa(this);
    return ataque -> validacion_atacar_personaje(casilla, tablero, arma);
}

void Vanessa::atacar(Casilla *casilla, Tablero* tablero, char arma){
    if(ataque == nullptr)
        this -> ataque = new Ataque_vanesa(this);
    ataque -> atacar(casilla, tablero, arma);
}
void Vanessa::atacar(Casilla *casilla, Tablero* tablero){
}

void Vanessa::regenerar_energia() {
    this -> energia += 10;
}

