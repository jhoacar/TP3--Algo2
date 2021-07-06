#ifndef PRECIPICIO_H
#define PRECIPICIO_H

#include "../Casilla.h"

class Precipicio: public Casilla{

    public:
        Precipicio();
        Precipicio(Coordenada posicion);
        ~Precipicio();
        char obtener_tipo();
        int obtener_energia(int tipo_personaje);
};

#endif