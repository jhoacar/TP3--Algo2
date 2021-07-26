#ifndef DEFENSA_ZOMBIE_H
#define DEFENSA_ZOMBIE_H

#include "../Defensa.h"
#include "../../../objetos/seres/monstruos/zombies/Zombie.h"

class Defensa_zombie:public Defensa{

    protected:
        int cantidad_agua;
        int cantidad_cruces;

    public:
        Defensa_zombie(Zombie *personaje);
        ~Defensa_zombie();
        void defender(Tablero *tablero);
};
#endif