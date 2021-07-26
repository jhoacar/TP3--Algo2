#include "Vampirella.h"
#include "../../../../ataque/monstruo/vampiro/Ataque_vampirella.h"
#include "../../../../defensa/tipos/monstruos/vampiros/Defensa_vampirella.h"
#include <iostream>
using std::cout;
using std::endl;
Vampirella::Vampirella():Vampiro(){
    ataque = nullptr;
}
Vampirella::Vampirella(Casilla *casilla,char nombre,string ID):Vampiro(casilla,nombre,ID)
{
    ataque = nullptr;
}
void Vampirella::mostrar(){
    cout<<"Objeto: Vampirella"<<endl;
}
Vampirella::~Vampirella()
{
    if(ataque != nullptr)
        delete ataque;
}


void Vampirella::atacar(Casilla *casilla, Tablero* tablero){
    if(ataque == nullptr)
        this -> ataque = new Ataque_vampirella(this);
    ataque -> atacar(casilla, tablero);
}
void Vampirella::regenerar_energia() {
    this -> energia += 6;
}

bool Vampirella::validacion_ataque(Casilla *casilla, Tablero* tablero){
    if(ataque == nullptr)
        this -> ataque = new Ataque_vampirella(this);
    return ataque -> validacion_atacar_personaje(casilla, tablero);
}

void Vampirella::convertir_en_murcielago() {
    this->murcielago = true;
}

void Vampirella::convertir_en_vampiro() {
    this->murcielago = false;
}

bool Vampirella::es_murcielago() {
    return this->murcielago;
}

void Vampirella::defender(){
    if(defensa == nullptr)
        this -> defensa = new Defensa_vampirella(this);
    defensa -> defender();
}

bool Vampirella::validacion_defensa(int valor){
    if(defensa == nullptr)
        this -> defensa = new Defensa_vampirella(this);
    return defensa -> validar_energia(valor);
}