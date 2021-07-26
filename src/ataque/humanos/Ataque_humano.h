#ifndef ATAQUE_HUMANO_H
#define ATAQUE_HUMANO_H

#include "../Ataque.h"
#include "../../objetos/seres/humanos/Humano.h"

bool tiene_monstruo(Casilla *casilla);

class Ataque_humano:public Ataque{

    protected: 

        bool puede_atacar();
        bool esta_en_rango_ataque(Coordenada posicion);
        Casilla *obtener_casilla_ataque(Tablero *tablero);
        void atacar_casilla(Casilla *casilla_ataque);
        void consumir_balas();
        void eliminar_balas_inventario();

    public:
        Ataque_humano(Humano *personaje);
        ~Ataque_humano();
        void atacar(Coordenada posicion, Tablero *tablero);

};

#endif