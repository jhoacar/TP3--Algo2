#ifndef ATAQUE_NOSFERATU_H
#define ATAQUE_NOSFERATU_H

#include "Ataque_vampiro.h"

#include "../../../objetos/seres/monstruos/vampiros/Nosferatu.h"

class Ataque_nosferatu:public Ataque_vampiro{

    public:
        Ataque_nosferatu(Nosferatu *personaje);
        ~Ataque_nosferatu();
        void atacar(Coordenada posicion, Tablero *tablero);
};

#endif