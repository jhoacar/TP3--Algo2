#ifndef DEFENSA_NOSFERATU_H
#define DEFENSA_NOSFERATU_H

#include "Defensa_vampiro.h"
#include "../../../objetos/seres/monstruos/vampiros/Nosferatu.h"

class Defensa_nosferatu:public Defensa_vampiro{

    protected:
        void intercambiar_vida(Tablero *tablero);
        Lista<Objeto*> obtener_vampiros(Tablero *tablero);
        int cantidad_agua;
        int cantidad_cruces;

    public:
        Defensa_nosferatu(Nosferatu *personaje);
        void defender(Tablero *tablero, int opcion =NO_ENCONTRADO);
};
#endif