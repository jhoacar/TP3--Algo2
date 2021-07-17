//
// Created by franco on 7/7/2021.
//

#ifndef ATAQUE_CPP_ATAQUE_HUMANO_H
#define ATAQUE_CPP_ATAQUE_HUMANO_H


#include "Ataque.h"

class Ataque_humano : public Ataque{

    Ataque_humano(Tablero* tablero, int coordenada_x, int coordenada_y, int fuerza_actual);
    Ataque_humano();

    void bajar_vida(Lista<Objeto*> lista_objetos, Casilla* casilla);
    
};


#endif //ATAQUE_CPP_ATAQUE_HUMANO_H
