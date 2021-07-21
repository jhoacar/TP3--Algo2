#ifndef DEFENSA_HUMANO_H
#define DEFENSA_HUMANO_H

#include "../Defensa.h"
#include "../../objetos/seres/humanos/Humano.h"

class Defensa_humano:public Defensa{

    public:
        Defensa_humano(Humano *personaje);
        ~Defensa_humano();
        void defender();
};
#endif