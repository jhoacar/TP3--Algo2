#ifndef ATAQUE_CAZADOR_H
#define ATAQUE_CAZADOR_H

#include "../Ataque_humano.h"

#include "../../objetos/seres/humanos/cazador/Cazador.h"


class Ataque_cazador:public Ataque_humano{

    bool esta_en_rango_ataque(Coordenada posicion);
    void atacar_casilla(Casilla *casilla_atacar);
    bool puede_atacar();
    public:
        Ataque_cazador(Cazador *personaje);
        ~Ataque_cazador();
        void atacar(Coordenada posicion, Tablero *tablero);
};

#endif