#include "Cazador.h"
#include "../../../../ataque/humanos/cazador/Ataque_cazador.h"
#include "../../../../defensa/tipos/Defensa_cazador.h"
#include <iostream>

using std::cout;
using std::endl;
Cazador::Cazador():Humano(){
    ataque = nullptr;
    defensa = nullptr;
}
Cazador::Cazador(Casilla *casilla,char nombre,string ID):Humano(casilla,nombre,ID){
    ataque = nullptr;
    defensa = nullptr;
}
void Cazador::mostrar(){
    cout<<"Objeto: Cazador"<<endl;
}
Cazador::~Cazador()
{
    if(ataque != nullptr)
        delete ataque;
    if(defensa != nullptr)
        delete defensa;
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


void Cazador::defender(int accion, Tablero* tablero){
    if(defensa == nullptr)
        this -> defensa = new Defensa_cazador(this);
    defensa -> defender(accion, tablero);
}

bool Cazador::validacion_defensa(int valor){
    if(defensa == nullptr)
        this -> defensa = new Defensa_humano(this);
    return defensa -> validar_energia(valor);
}


void Cazador::regenerar_energia() {
    this -> energia += 8;
}
