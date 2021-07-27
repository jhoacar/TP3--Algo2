#ifndef ATAQUE_NOSFERATU_H
#define ATAQUE_NOSFERATU_H

#include "Ataque_vampiro.h"

#include "../../../objetos/seres/monstruos/vampiros/Nosferatu.h"

class Ataque_nosferatu:public Ataque_vampiro{
    
    void consumir_energia();
    bool puede_atacar();
    bool esta_en_rango_ataque(Coordenada posicion,char arma=NO_ARMA);
    void atacar_casilla(Casilla *casilla_ataque);
    public:
        Ataque_nosferatu(Nosferatu *personaje);
        void atacar(Coordenada posicion, Tablero *tablero, char arma=NO_ARMA);
        bool se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma=NO_ARMA);
        
};

#endif