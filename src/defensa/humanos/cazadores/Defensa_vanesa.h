#ifndef DEFENSA_VANESA_H
#define DEFENSA_VANESA_H

#include "Defensa_cazador.h"
#include "../../../objetos/seres/humanos/cazador/Vanessa.h"

class Defensa_vanesa:public Defensa_cazador{

    protected:
        int cantidad_agua;
        int cantidad_cruces;

    public:
        Defensa_vanesa(Vanessa *personaje);
        void defender(Tablero *tablero);
};
#endif