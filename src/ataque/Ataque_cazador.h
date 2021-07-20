#ifndef ATAQUE_HUMANO_CPP_ATAQUE_CAZADOR_H
#define ATAQUE_HUMANO_CPP_ATAQUE_CAZADOR_H

#include "Ataque_humano.h"


class Ataque_cazador : public Ataque_humano {

    Ataque_cazador(Humano *personaje);
    ~Ataque_cazador();

    void atacar(Casilla *casilla);


};


#endif //ATAQUE_HUMANO_CPP_ATAQUE_CAZADOR_H
