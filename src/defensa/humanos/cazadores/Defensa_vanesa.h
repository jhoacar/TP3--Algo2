#ifndef DEFENSA_VANESA_H
#define DEFENSA_VANESA_H

#include "Defensa_cazador.h"

class Defensa_vanesa:public Defensa_cazador{

    protected:
        void curar_aliados(Tablero *tablero);
        void convertir_humano(Monstruo *personaje);
    public:
        Defensa_vanesa(Vanessa *personaje);
        void defender(Tablero *tablero, int opcion=NO_ENCONTRADO);
};
#endif