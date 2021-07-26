#ifndef ATAQUE_VAMPIRELLA_H
#define ATAQUE_VAMPIRELLA_H

#include "Ataque_vampiro.h"

#include "../../../objetos/seres/monstruos/vampiros/Vampirella.h"

class Ataque_vampirella:public Ataque_vampiro{

    public:
        Ataque_vampirella(Ser *personaje);
        ~Ataque_vampirella();
        void atacar(Coordenada posicion, Tablero *tablero);
};

#endif