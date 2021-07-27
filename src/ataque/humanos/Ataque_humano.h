#ifndef ATAQUE_HUMANO_H
#define ATAQUE_HUMANO_H

#include "../Ataque.h"
#include "../../objetos/seres/humanos/Humano.h"

#include "../../objetos/seres/monstruos/vampiros/Vampiro.h"
#include "../../objetos/seres/monstruos/zombies/Zombie.h"


class Ataque_humano:public Ataque{

    protected: 
        void consumir_energia();
        bool puede_atacar();
        bool esta_en_rango_ataque(Coordenada posicion,char arma=NO_ARMA);
        Casilla *obtener_casilla_ataque(Tablero *tablero);
        void atacar_casilla(Casilla *casilla_ataque);
        void consumir_balas();
        void eliminar_balas_inventario();
        bool hay_casos_especiales(Monstruo *monstruo, char arma=NOMBRES_CHAR[ESCOPETA]);
        float obtener_ataque(char nombre_mostruo,char arma=NOMBRES_CHAR[ESCOPETA]);
    public:
        Ataque_humano(Humano *personaje);
        void atacar(Coordenada posicion, Tablero *tablero, char arma=NO_ARMA);
        bool se_puede_atacar(Coordenada posicion,Tablero *tablero, char arma=NO_ARMA);

};

#endif