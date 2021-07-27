#ifndef ATAQUE_CAZADOR_H
#define ATAQUE_CAZADOR_H

#include "../Ataque_humano.h"

#include "../../../objetos/seres/humanos/cazador/Cazador.h"


class Ataque_cazador:public Ataque_humano{

    char arma;
    bool esta_en_rango_ataque(Coordenada posicion);
    void atacar_casilla(Casilla *casilla_atacar,char arma);
    bool puede_atacar();
    void elegir_arma();
    public:
        Ataque_cazador(Cazador *personaje);
        ~Ataque_cazador();
        void atacar(Coordenada posicion, Tablero *tablero, char arma);
        bool se_puede_atacar(Coordenada posicion,Tablero *tablero,char arma);
};

#endif