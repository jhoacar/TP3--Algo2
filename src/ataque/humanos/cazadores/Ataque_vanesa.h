#ifndef ATAQUE_VANESA_H
#define ATAQUE_VANESA_H

#include "Ataque_cazador.h"

#include "../../../objetos/seres/humanos/cazador/Vanessa.h"

class Ataque_vanesa:public Ataque_cazador{

    void consumir_energia();
    void atacar_casilla(Casilla *casilla_atacar,char arma);
    bool puede_atacar();
    float obtener_ataque(char nombre_monstruo,char arma);
    public:
        Ataque_vanesa(Vanessa *personaje);
        void atacar(Coordenada posicion, Tablero *tablero, char arma);
        bool se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma);
};

#endif