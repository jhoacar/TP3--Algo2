#ifndef ATAQUE_VANESA_H
#define ATAQUE_VANESA_H

#include "../Ataque.h"

#include "../../../objetos/seres/humanos/cazador/Vanessa.h"

class Ataque_vanesa:public Ataque{

    public:
        Ataque_vanesa(Vanessa *personaje);
        ~Ataque_vanesa();
        void atacar(Coordenada posicion, Tablero *tablero);
};

#endif