#ifndef DEFENSA_VANESA_H
#define DEFENSA_VANESA_H

#include "../Defensa_humano.h"
#include "../../../objetos/seres/humanos/cazador/Vanessa.h"

class Defensa_vanesa:public Defensa_humano{

    protected:
        int cantidad_agua;
        int cantidad_cruces;

    public:
        Defensa_vanesa(Vanessa *personaje);
        ~Defensa_vanesa();
        void defender(Tablero *tablero);
};
#endif