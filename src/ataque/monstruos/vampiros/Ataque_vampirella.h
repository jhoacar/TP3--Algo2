#ifndef ATAQUE_VAMPIRELLA_H
#define ATAQUE_VAMPIRELLA_H

#include "Ataque_vampiro.h"

#include "../../../objetos/seres/monstruos/vampiros/Vampirella.h"

class Ataque_vampirella:public Ataque_vampiro{

    bool puede_atacar();
    void consumir_energia();
    public:
        Ataque_vampirella(Vampirella *personaje);
        void atacar(Coordenada posicion, Tablero *tablero,char arma=NO_ARMA);
        bool se_puede_atacar(Coordenada posicion, Tablero *tablero,char arma=NO_ARMA);
        
};

#endif