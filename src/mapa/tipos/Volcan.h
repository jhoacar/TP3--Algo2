#ifndef VOLCAN_H
#define VOLCAN_H

#include "../Casilla.h"

class Volcan: public Casilla{

    public:
        Volcan();
        Volcan(Coordenada posicion);
        ~Volcan();
        char obtener_tipo();
        int obtener_energia(int tipo_personaje);
};

#endif