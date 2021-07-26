#include "Vampiro.h"
#include "../../../../ataque/Ataque_vampiro.h"
#include "../../../../defensa/tipos/Defensa_vampiro.h"
#include <iostream>

using std::cout;
using std::endl;

Vampiro::Vampiro():Monstruo(){
    this->oculto = false;
    this->armadura_aumentada = false;
    ataque = nullptr;
    defensa = nullptr;
}
Vampiro::Vampiro(Casilla *casilla,char nombre,string ID):Monstruo(casilla,nombre,ID)
{
    this->oculto = false;
    this->armadura_aumentada = false;
    ataque = nullptr;
    defensa = nullptr;
}
void Vampiro::mostrar(){
    cout<<"Objeto: Vampiro"<<endl;
}
Vampiro::~Vampiro()
{
    if(ataque != nullptr)
        delete ataque;
    if(defensa != nullptr)
        delete defensa;
}

void Vampiro::regenerar_energia() {
    this -> energia += 4;
}

void Vampiro::encuentro_con_elemento() {

    Lista<Objeto*> objetos_casilla;
    Lista<Objeto*> solo_estaca;

    objetos_casilla = this -> casilla ->obtener_objetos();
    solo_estaca = objetos_casilla.filtrar_datos(0, es_estaca);

    this -> casilla -> eliminar_objetos(solo_estaca);
    cout << "Se han destruido las estacas" << endl;
}

void Vampiro::atacar(Casilla *casilla, Tablero* tablero){
    if(ataque == nullptr)
        this -> ataque = new Ataque_vampiro(this);
    ataque -> atacar(casilla, tablero);
}
void Vampiro::atacar(Casilla *casilla, Tablero* tablero, char arma){}

bool Vampiro::validacion_ataque(Casilla *casilla, Tablero* tablero){
    if(ataque == nullptr)
        this -> ataque = new Ataque_vampiro(this);

    return ataque -> validacion_atacar_personaje(casilla, tablero);
}

void Vampiro::defender(){
    if(defensa == nullptr)
        this -> defensa = new Defensa_vampiro(this);
    defensa -> defender();
}

bool Vampiro::validacion_defensa(int valor){
    if(defensa == nullptr)
        this -> defensa = new Defensa_vampiro(this);
    return defensa -> validar_energia(valor);
}



void Vampiro::ocultarse() {
    this->oculto = true;
}

void Vampiro::aparecer() {
    this->oculto = false;
}

bool Vampiro::tiene_armadura_aumentada() {
    return this->armadura_aumentada;
}

bool Vampiro::esta_oculto() {
    return this->oculto;
}