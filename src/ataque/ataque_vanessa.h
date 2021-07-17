#ifndef ATAQUE_CPP_ATAQUE_VANESA_H
#define ATAQUE_CPP_ATAQUE_VANESA_H

#include "Ataque.h"

class Ataque_vanessa : public Ataque {

    Ataque_vanessa(Tablero* tablero, int coordenada_x, int coordenada_y, int fuerza_actual);
    Ataque_vanessa();


    void bajar_vida(Lista<Objeto*> lista_objetos, Casilla* casilla);

    bool validacion_rango_ataque_estaca(int coord_x, int coord_y, int max_rango) = 0;


};


#endif //ATAQUE_CPP_ATAQUE_VANESA_H
