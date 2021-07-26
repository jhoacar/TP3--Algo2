#ifndef DEFENSA_CAZADOR_H
#define DEFENSA_CAZADOR_H

#include "../Defensa_humano.h"
#include "../../../objetos/seres/humanos/cazador/Cazador.h"

class Defensa_cazador:public Defensa_humano{

    protected:
        int cantidad_agua;
        int cantidad_cruces;

    public:
        Defensa_cazador(Cazador *personaje);
        ~Defensa_cazador();
        void defender(Tablero *tablero);
};
#endif