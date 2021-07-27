#ifndef ATAQUE_VAMPIRO_H
#define ATAQUE_VAMPIRO_H

#include "../../Ataque.h"
#include "../../../objetos/seres/monstruos/vampiros/Vampiro.h"

class Ataque_vampiro:public Ataque{

    public:
        Ataque_vampiro(Vampiro *personaje);
        ~Ataque_vampiro();
        void atacar(Coordenada posicion, Tablero *tablero, char arma=NO_ARMA);
        bool se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma=NO_ARMA);

};

#endif