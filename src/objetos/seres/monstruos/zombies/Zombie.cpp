#include "Zombie.h"
#include <iostream>
#include "../../../../ataque/Ataque_zombie.h"
using std::cout;
using std::endl;

Zombie::Zombie():Monstruo(){
    this->escondido = false;
    ataque = nullptr;
}
Zombie::Zombie(Casilla *casilla,char nombre,string ID):Monstruo(casilla,nombre,ID)
{
    this->escondido = false;
    ataque = nullptr;
}
void Zombie::mostrar(){
    cout<<"Objeto: Zombie"<<endl;
}
Zombie::~Zombie()
{
    if(ataque != nullptr)
        delete ataque;
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

void Zombie::defender() {
    this->energia -=3;
    this->escondido = true;
    this->vida +=20;
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