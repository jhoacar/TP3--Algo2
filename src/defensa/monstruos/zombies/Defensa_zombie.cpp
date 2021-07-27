#include "Defensa_zombie.h"

Defensa_zombie::Defensa_zombie(Zombie *personaje):Defensa(personaje){

}
void Defensa_zombie::defender(Tablero *tablero, int opcion){

    personaje->asignar_energia(personaje->obtener_energia()-2);

    ((Monstruo*)personaje)->ocultar();
    
    personaje->asignar_vida(personaje->obtener_vida()+20);

}