#ifndef DEFENSA_HUMANO_H
#define DEFENSA_HUMANO_H

#include "../Defensa.h"
#include "../../objetos/seres/humanos/Humano.h"
#include "../../objetos/seres/monstruos/vampiros/Vampiro.h"
#include "../../objetos/seres/monstruos/zombies/Zombie.h"

class Defensa_humano:public Defensa{

    protected:
        int cantidad_agua;
        int cantidad_cruces;

    public:
        Defensa_humano(Humano *personaje);
        void defender(Tablero *tablero, int opcion);
};
#endif