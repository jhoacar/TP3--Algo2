#ifndef DEFENSA_VAMPIRELLA_H
#define DEFENSA_VAMPIRELLA_H

#include "Defensa_vampiro.h"
#include "../../../objetos/seres/monstruos/vampiros/Vampirella.h"

class Defensa_vampirella:public Defensa_vampiro{

    protected:
        int cantidad_agua;
        int cantidad_cruces;

    public:
        Defensa_vampirella(Vampirella *personaje);
        void defender(Tablero *tablero, int opcion=NO_ENCONTRADO);
};
#endif