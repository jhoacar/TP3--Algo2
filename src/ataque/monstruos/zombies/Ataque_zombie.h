#ifndef ATAQUE_ZOMBIE_H
#define ATAQUE_ZOMBIE_H

#include "../Ataque_monstruo.h"

#include "../../../objetos/seres/monstruos/zombies/Zombie.h"

#include "../../../objetos/seres/humanos/Humano.h"

class Ataque_zombie:public Ataque_monstruo{

        //PRE: recibe el humano a convertir
        //POST: le cambia el nombre y su ataque y defensa
        void convertir_zombie(Humano *humano);
        void consumir_energia();
        bool tiene_energia();
        bool esta_en_rango_ataque(Coordenada posicion,char arma=NO_ARMA);
        void atacar_casilla(Casilla *casilla_ataque,char arma=NO_ARMA);
    public:
        Ataque_zombie(Zombie *personaje);
};

#endif
