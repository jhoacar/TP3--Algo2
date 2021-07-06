#ifndef CAMINO_H
#define CAMINO_H

#include "../Casilla.h"

class Camino: public Casilla{

    public:
        Camino();
        Camino(Coordenada posicion);
        ~Camino();
        char obtener_tipo();
        int obtener_energia(int tipo_personaje);
};

#endif