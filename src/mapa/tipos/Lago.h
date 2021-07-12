#ifndef LAGO_H
#define LAGO_H

#include "../Casilla.h"

class Lago: public Casilla{

    public:
        Lago();
        Lago(Coordenada posicion);
        ~Lago();
        char obtener_tipo();
        int obtener_energia(int tipo_personaje);
        int obtener_color();
};

#endif