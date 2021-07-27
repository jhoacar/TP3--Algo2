#ifndef ATAQUE_H
#define ATAQUE_H

#include "../mapa/Tablero.h"

class Ser;

int extraer_cantidad(Objeto *objeto);

class Ataque{

    protected: 
        Ser *personaje;
    public:
        Ataque(Ser *personaje);
        virtual ~Ataque();
        virtual void atacar(Coordenada posicion,Tablero *tablero,char arma=NO_ARMA)=0;
        virtual bool se_puede_atacar(Coordenada posicion,Tablero *tablero,char arma=NO_ARMA)=0;
};

#endif