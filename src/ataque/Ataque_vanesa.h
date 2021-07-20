#ifndef ATAQUE_HUMANO_H_ATAQUE_VANESA_H
#define ATAQUE_HUMANO_H_ATAQUE_VANESA_H

#include "Ataque_humano.h"
#include "../objetos/seres/humanos/Humano.h"

class Ataque_vanesa : public Ataque_humano {

    Ataque_vanesa(Humano *personaje);
    ~Ataque_vanesa();

    void atacar(Casilla *casilla);

    //PRE: recibe la casilla del personaje a bajarle la vida
    //POST: le baja la vida al personaje
    void bajar_vida(Casilla* casilla, string arma_elegida);

    //PRE:
    //POST:
    bool validacion_ataque(Casilla *casilla_a_atacar, string arma_elegida);

    // Para no repetir mucho codigo
    //PRE:
    //POST:
    void bajar_vida_vampiro(int indice, int porcentaje_escopeta, int porcentaje_agua, Casilla* casilla, string arma_elegida);

    void bajar_vida_completa(int indice, Casilla *casilla);

};


#endif //ATAQUE_HUMANO_H_ATAQUE_VANESA_H
