#ifndef ATAQUE_ZOMBIE_H
#define ATAQUE_ZOMBIE_H

#include "../../Ataque.h"
#include "../../../objetos/seres/monstruos/zombies/Zombie.h"

#include "../../../objetos/seres/humanos/Humano.h"

class Ataque_zombie:public Ataque{

        void convertir_zombie(Humano *humano);
        void consumir_energia();
        bool puede_atacar();
        bool esta_en_rango_ataque(Coordenada posicion,char arma=NO_ARMA);
        void atacar_casilla(Casilla *casilla_ataque);
    public:
        Ataque_zombie(Zombie *personaje);
        void atacar(Coordenada posicion, Tablero *tablero, char arma=NO_ARMA);
        bool se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma=NO_ARMA);
};

#endif