#ifndef DEFENSA_NOSFERATU_H
#define DEFENSA_NOSFERATU_H

#include "Defensa_vampiro.h"
#include "../../../objetos/seres/monstruos/vampiros/Nosferatu.h"

class Defensa_nosferatu:public Defensa_vampiro{

    protected:
        int cantidad_agua;
        int cantidad_cruces;

    public:
        Defensa_nosferatu(Nosferatu *personaje);
        ~Defensa_nosferatu();
        void defender(Tablero *tablero);
};
#endif