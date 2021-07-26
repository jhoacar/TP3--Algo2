#include "Vanessa.h"
#include "../../../../defensa/tipos/Defensa_vanesa.h"
#include <iostream>
#include "../../../../ataque/humanos/cazador/Ataque_vanesa.h"
using std::cout;
using std::endl;
Vanessa::Vanessa():Cazador(){
    ataque = nullptr;
    defensa = nullptr;
}
Vanessa::Vanessa(Casilla *casilla,char nombre,string ID):Cazador(casilla,nombre,ID)
{
    ataque= nullptr;
    defensa = nullptr;
}
void Vanessa::mostrar(){
    cout<<"Objeto: Vanessa"<<endl;
}
Vanessa::~Vanessa()
{
    if(ataque != nullptr)
        delete ataque;
    if(defensa != nullptr)
        delete defensa;
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

void Vanessa::defender(Tablero* tablero){
    if(defensa == nullptr)
        this -> defensa = new Defensa_vanesa(this);
    defensa -> defender(tablero);
}

bool Vanessa::validacion_defensa(int valor){
    if(defensa == nullptr)
        this -> defensa = new Defensa_vanesa(this);
    return defensa -> validar_energia(valor);
}

void Vanessa::proteccion_de_ataque_vampiro(){
    defendido_de_vampiro = true;
}

bool Vanessa::devolver_proteccion_de_vampiro(){
    return defendido_de_vampiro;
}