#ifndef ATAQUE_VAMPIRO_H
#define ATAQUE_VAMPIRO_H

#include "../../Ataque.h"

#include "../../../objetos/seres/monstruos/vampiros/Vampiro.h"

#include "../../../objetos/seres/humanos/Humano.h"

class Ataque_vampiro:public Ataque{
    
    protected:
        void consumir_energia();
        bool puede_atacar();
        bool esta_en_rango_ataque(Coordenada posicion,char arma=NO_ARMA);
        void atacar_casilla(Casilla *casilla_ataque);
    public:
        Ataque_vampiro(Vampiro *personaje);
        void atacar(Coordenada posicion, Tablero *tablero, char arma=NO_ARMA);
        bool se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma=NO_ARMA);

};

#endif