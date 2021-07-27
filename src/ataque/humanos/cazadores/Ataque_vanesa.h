#ifndef ATAQUE_VANESA_H
#define ATAQUE_VANESA_H

#include "Ataque_cazador.h"

#include "../../../objetos/seres/humanos/cazador/Vanessa.h"

class Ataque_vanesa:public Ataque_cazador{

    bool esta_en_rango_ataque(Coordenada posicion);
    void atacar_casilla(Casilla *casilla_atacar);
    bool puede_atacar();
    public:
        Ataque_vanesa(Vanessa *personaje);
        ~Ataque_vanesa();
        void atacar(Coordenada posicion, Tablero *tablero, char arma);
        bool se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma);
};

#endif