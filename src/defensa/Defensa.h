#ifndef DEFENSA_H
#define DEFENSA_H

#include "../mapa/Tablero.h"

class Ser;

class Defensa{

    protected:
        Ser *personaje;
    public:
        Defensa(Ser *personaje);
        ~Defensa();
        virtual void defender(Tablero *tablero)=0;
};
#endif