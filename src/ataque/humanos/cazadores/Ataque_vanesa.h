#ifndef ATAQUE_VANESA_H
#define ATAQUE_VANESA_H

#include "Ataque_cazador.h"

#include "../../../objetos/seres/humanos/cazador/Vanessa.h"

class Ataque_vanesa:public Ataque_cazador{

    virtual void consumir_energia();
    virtual bool tiene_energia();
    virtual float obtener_ataque(char nombre_monstruo,char arma);
    public:
        Ataque_vanesa(Vanessa *personaje);
};

#endif