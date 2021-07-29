#ifndef VACIO_H
#define VACIO_H

#include "../Casilla.h"

class Vacio: public Casilla{

    public:
        Vacio();
        Vacio(Coordenada posicion);
        ~Vacio();
        char obtener_tipo();
        int obtener_energia(int tipo_personaje);
        int obtener_color();
};

#endif