#include "Defensa_zombie.h"


Defensa_zombie::Defensa_zombie(Zombie *personaje):Defensa(personaje){
}


void Defensa_zombie::defender() {

    personaje ->regenerar_vida_defensa(20);
    ((Zombie* )personaje) -> esconderse();

}