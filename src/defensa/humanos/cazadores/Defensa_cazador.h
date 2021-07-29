#ifndef DEFENSA_CAZADOR_H
#define DEFENSA_CAZADOR_H

#include "../Defensa_humano.h"
#include "../../../objetos/seres/humanos/cazador/Vanessa.h"

class Defensa_cazador:public Defensa_humano{

    protected:
        void aumentar_vida_aliados(Tablero *tablero ,int vida);

    public:
        Defensa_cazador(Cazador *personaje);
        void defender(Tablero *tablero, int opcion);
};
#endif