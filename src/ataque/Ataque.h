#ifndef ATAQUE_H
#define ATAQUE_H

#include "../mapa/Tablero.h"

class Ser;

bool tiene_humano(Casilla *casilla);

bool tiene_monstruo(Casilla *casilla);

int extraer_cantidad(Objeto *objeto);

class Ataque{

    protected: 
        Ser *personaje;
        virtual bool tiene_energia()=0;
        virtual bool esta_en_rango_ataque(Coordenada posicion,char arma=NO_ARMA)=0;
        virtual void atacar_casilla(Casilla *casilla_ataque, char arma=NO_ARMA)=0;
        virtual void consumir_energia()=0;
        float obtener_armadura(Ser *personaje);
    public:
        Ataque(Ser *personaje);
        virtual ~Ataque();
        virtual void atacar(Coordenada posicion,Tablero *tablero,char arma=NO_ARMA)=0;
        virtual bool se_puede_atacar(Coordenada posicion,Tablero *tablero,char arma=NO_ARMA)=0;
};

#endif