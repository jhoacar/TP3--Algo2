#ifndef DEFENSA_H
#define DEFENSA_H

#include "../mapa/Tablero.h"

class Ser;

class Defensa{

    protected:
        Ser *personaje;
    public:
        Defensa(Ser *personaje);
        virtual ~Defensa()=default;
        virtual void defender(Tablero *tablero)=0;
};
#endif