#include "Zombie.h"
#include <iostream>
using std::cout;
using std::endl;

Zombie::Zombie():Monstruo(){
    this->escondido = false;
}
Zombie::Zombie(Casilla *casilla,char nombre,string ID):Monstruo(casilla,nombre,ID)
{
    this->escondido = false;
}
void Zombie::mostrar(){
    cout<<"Objeto: Zombie"<<endl;
}
Zombie::~Zombie()
{
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
void Zombie::atacar(Casilla *casilla){
    
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