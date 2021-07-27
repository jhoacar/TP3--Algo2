#ifndef ATAQUE_CAZADOR_H
#define ATAQUE_CAZADOR_H

#include "../Ataque_humano.h"

#include "../../../objetos/seres/humanos/cazador/Cazador.h"

#include "../../../objetos/seres/monstruos/vampiros/Vampiro.h"
#include "../../../objetos/seres/monstruos/zombies/Zombie.h"


class Ataque_cazador:public Ataque_humano{

    protected: 
        char arma;
        void consumir_energia();
        bool esta_en_rango_ataque(Coordenada posicion,char arma);
        void atacar_casilla(Casilla *casilla_atacar,char arma);
        bool puede_atacar();
        bool tiene_arma(const char arma);
        void consumir_arma(const char arma);
        void consumir_agua();
        void consumir_toda_agua();
    public:
        Ataque_cazador(Cazador *personaje);
        void atacar(Coordenada posicion, Tablero *tablero, char arma);
        bool se_puede_atacar(Coordenada posicion,Tablero *tablero,char arma);
};

#endif