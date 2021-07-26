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
        ~Ataque();
        virtual void atacar(Coordenada posicion,Tablero *tablero)=0;

};

#endif