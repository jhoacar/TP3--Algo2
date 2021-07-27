#include "Zombie.h"
#include "../../../../defensa/monstruos/zombies/Defensa_zombie.h"
#include "../../../../ataque/monstruos/zombies/Ataque_zombie.h"
#include <iostream>
using std::cout;
using std::endl;

Zombie::Zombie():Monstruo(){
    
}
Zombie::Zombie(Casilla *casilla,char nombre,string ID):Monstruo(casilla,nombre,ID)
{

}
void Zombie::mostrar(){
    cout<<"Objeto: Zombie"<<endl;
}
Zombie::~Zombie()
{
}
void Zombie::regenerar_energia() {
    this -> energia += REGENERAR_ENERGIA[ZOMBIE];
}

void Zombie::encuentro_con_elemento() {
    Lista<Objeto*> solo_agua = casilla->obtener_objetos().filtrar_datos(0, es_agua);
    this ->inventario += solo_agua;
    this -> casilla -> eliminar_objetos(solo_agua);
}

void Zombie::defender(Tablero *tablero) {
    if(defensa == nullptr)
        defensa = new Defensa_zombie(this);
    defensa->defender(tablero);
}
void Zombie::atacar(Coordenada posicion, Tablero *tablero,char arma){
    if(se_puede_atacar(posicion,tablero))
        ataque->atacar(posicion,tablero);
}

bool Zombie::se_puede_atacar(Coordenada posicion, Tablero *tablero,char arma){
    if(ataque==nullptr)
        ataque = new Ataque_zombie(this);
    return ataque->se_puede_atacar(posicion,tablero);
}