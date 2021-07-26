#include "Zombie.h"
#include <iostream>
#include "../../../../ataque/monstruo/zombie/Ataque_zombie.h"
#include "../../../../defensa/tipos/monstruos/zombie/Defensa_zombie.h"
using std::cout;
using std::endl;

Zombie::Zombie():Monstruo(){
    this->escondido = false;
    ataque = nullptr;
    defensa = nullptr;
}
Zombie::Zombie(Casilla *casilla,char nombre,string ID):Monstruo(casilla,nombre,ID)
{
    this->escondido = false;
    ataque = nullptr;
    defensa = nullptr;
}
void Zombie::mostrar(){
    cout<<"Objeto: Zombie"<<endl;
}
Zombie::~Zombie()
{
    if(ataque != nullptr)
        delete ataque;
    if(defensa != nullptr)
        delete defensa;
}

void Zombie::regenerar_energia() {
    this -> energia += 5;
}

void Zombie::encuentro_con_elemento() {
    Lista<Objeto*> objetos_casilla;
    Lista<Objeto*> solo_agua;

    objetos_casilla = this -> casilla ->obtener_objetos();
    solo_agua = objetos_casilla.filtrar_datos(0, es_agua);

    this ->inventario += solo_agua;
    cout << "Se agregaro con exito el agua al inventario" << endl;

    this -> casilla -> eliminar_objetos(solo_agua);
}



void Zombie::atacar(Casilla *casilla, Tablero* tablero){
    if(ataque == nullptr)
        this -> ataque = new Ataque_zombie(this);
    ataque -> atacar(casilla, tablero);
}

bool Zombie::validacion_ataque(Casilla *casilla, Tablero* tablero){
    if(ataque == nullptr)
        this -> ataque = new Ataque_zombie(this);
    return ataque -> validacion_atacar_personaje(casilla, tablero);
}

void Zombie::resurgir() {
    this->escondido = false;
}

bool Zombie::esta_escondido() {
    return this->escondido;
}
void Zombie::aparecer_zombie(){
    this->escondido = false;
}

void Zombie::atacar(Casilla *casilla, Tablero *tablero, char arma) {

}
void Zombie::esconderse() {
    this->escondido = true;
}


void Zombie::defender(){
    if(defensa == nullptr)
        this -> defensa = new Defensa_zombie(this);
    defensa -> defender();
}

bool Zombie::validacion_defensa(int valor){
    if(defensa == nullptr)
        this -> defensa = new Defensa_zombie(this);
    return defensa -> validar_energia(valor);
}