#ifndef ATAQUE_ZOMBIE_H
#define ATAQUE_ZOMBIE_H

#include "../../Ataque.h"
#include "../../../objetos/seres/monstruos/zombies/Zombie.h"

class Ataque_zombie:public Ataque{

    public:
        Ataque_zombie(Zombie *personaje);
        ~Ataque_zombie();
        void atacar(Coordenada posicion, Tablero *tablero, char arma=NO_ARMA);
        bool se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma=NO_ARMA);
};

#endif