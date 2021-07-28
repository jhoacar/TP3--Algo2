#ifndef ATAQUE_HUMANO_H
#define ATAQUE_HUMANO_H

#include "../Ataque.h"
#include "../../objetos/seres/humanos/Humano.h"

#include "../../objetos/seres/monstruos/vampiros/Vampiro.h"
#include "../../objetos/seres/monstruos/zombies/Zombie.h"


class Ataque_humano:public Ataque{

    protected: 
        
        virtual bool tiene_energia();
        void consumir_energia();
        virtual bool esta_en_rango_ataque(Coordenada posicion,char arma);
        void atacar_casilla(Casilla *casilla_ataque, char arma);
        
        bool tiene_arma(const char arma);
        void consumir_arma(const char arma);
        void consumir_agua();
        void consumir_toda_agua();
        void consumir_balas();
        void eliminar_balas_inventario();
        bool hay_casos_especiales(Monstruo *monstruo, char arma);
        
        virtual float obtener_ataque(char nombre_mostruo,char arma);

    public:
        Ataque_humano(Humano *personaje);
        void atacar(Coordenada posicion, Tablero *tablero, char arma=NOMBRES_CHAR[ESCOPETA]);
        bool se_puede_atacar(Coordenada posicion,Tablero *tablero, char arma=NO_ARMA);

};

#endif