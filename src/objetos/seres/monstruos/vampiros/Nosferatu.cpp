#include "Nosferatu.h"
#include "../../../../ataque/Ataque_nosferatu.h"
#include "../../../../defensa/tipos/Defensa_nosferatu.h"
#include <iostream>
using std::cout;
using std::endl;
Nosferatu::Nosferatu():Vampiro(){
    ataque = nullptr;
}
Nosferatu::Nosferatu(Casilla *casilla,char nombre,string ID):Vampiro(casilla,nombre,ID)
{
    ataque = nullptr;
}
void Nosferatu::mostrar(){
    cout<<"Objeto: Nosferatu"<<endl;
}
Nosferatu::~Nosferatu()
{
    if(ataque != nullptr)
        delete ataque;
}


void Nosferatu::atacar(Casilla *casilla, Tablero* tablero){
    if(ataque == nullptr)
        this -> ataque = new Ataque_nosferatu(this);
    ataque -> atacar(casilla, tablero);
}

bool Nosferatu::validacion_ataque(Casilla *casilla, Tablero* tablero){
    if(ataque == nullptr)
        this -> ataque = new Ataque_nosferatu(this);
    return ataque -> validacion_atacar_personaje(casilla, tablero);
}


void Nosferatu::regnerar_energia() {
    this -> energia += 10;
}


void Nosferatu::defender(Tablero* tablero){
    if(defensa == nullptr)
        this -> defensa = new Defensa_nosferatu(this);
    defensa -> defender();
}

bool Nosferatu::validacion_defensa(int valor){
    if(defensa == nullptr)
        this -> defensa = new Defensa_vampiro(this);
    return defensa -> validar_energia(valor);
}