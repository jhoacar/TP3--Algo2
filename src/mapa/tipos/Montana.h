#ifndef MONTANA_H
#define MONTANA_H

#include "../Casilla.h"

class Montana: public Casilla{

    public:
        Montana();
        Montana(Coordenada posicion);
        ~Montana();
        char obtener_tipo();
        int obtener_energia(int tipo_personaje);
};

#endif