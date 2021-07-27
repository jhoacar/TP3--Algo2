#ifndef DEFENSA_VAMPIRO_H
#define DEFENSA_VAMPIRO_H

#include "../../Defensa.h"
#include "../../../objetos/seres/monstruos/vampiros/Vampiro.h"

class Defensa_vampiro:public Defensa{

    protected:
        int cantidad_agua;
        int cantidad_cruces;

    public:
        Defensa_vampiro(Vampiro *personaje);
        void defender(Tablero *tablero, int opcion=NO_ENCONTRADO);
};
#endif