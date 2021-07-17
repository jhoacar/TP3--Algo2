#ifndef ATAQUE_CPP_ATAQUE_ZOMBIE_H
#define ATAQUE_CPP_ATAQUE_ZOMBIE_H

#include "Ataque.h"

class Ataque_zombie : public Ataque{

    Ataque_zombie(Tablero* tablero, int coordenada_x, int coordenada_y, int fuerza_actual);
    Ataque_zombie();


    void bajar_vida(Lista<Objeto*> lista_objetos, Casilla* casilla);


};


#endif //ATAQUE_CPP_ATAQUE_ZOMBIE_H
