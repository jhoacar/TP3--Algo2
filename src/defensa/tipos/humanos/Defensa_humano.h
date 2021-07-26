#ifndef DEFENSA_HUMANO_H
#define DEFENSA_HUMANO_H

#include "../../Defensa.h"
#include "../../../objetos/seres/humanos/Humano.h"

class Defensa_humano:public Defensa{

    public:
        Defensa_humano(Humano *personaje);
        ~Defensa_humano();

        void defender(int accion);
        void defender(){};
        void defender(Tablero* tablero){};
        void defender(int accion, Tablero*){};

        bool tengo_objeto(char arma);
        void aumentar_energia();
        void aumentar_armadura();
        void consumir_agua_bendita();
        int buscar_objeto(char arma);
        void consumir_objeto(char arma);
        void regenerar_vida_aliados(Casilla* casilla);


};
#endif