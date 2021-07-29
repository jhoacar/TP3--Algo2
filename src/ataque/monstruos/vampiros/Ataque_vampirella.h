#ifndef ATAQUE_VAMPIRELLA_H
#define ATAQUE_VAMPIRELLA_H

#include "Ataque_vampiro.h"

#include "../../../objetos/seres/monstruos/vampiros/Vampirella.h"

class Ataque_vampirella:public Ataque_vampiro{

    virtual bool tiene_energia();
    virtual void consumir_energia();
    virtual void atacar_casilla(Casilla *casilla_ataque,char arma=NO_ARMA);
    public:
        Ataque_vampirella(Vampirella *personaje); 
};

#endif