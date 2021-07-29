#ifndef ATAQUE_MONSTRUO_H
#define ATAQUE_MONSTRUO_H

#include "../Ataque.h"

#include "../../objetos/seres/humanos/cazador/Vanessa.h"

#include "../../objetos/seres/monstruos/Monstruo.h"

class Ataque_monstruo:public Ataque{

    protected:

    public:
        Ataque_monstruo(Monstruo *personaje);
        void atacar(Coordenada posicion, Tablero *tablero, char arma=NO_ARMA);
        int se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma=NO_ARMA);

};

#endif