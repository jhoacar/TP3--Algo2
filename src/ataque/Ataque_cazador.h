#ifndef ATAQUE_HUMANO_CPP_ATAQUE_CAZADOR_H
#define ATAQUE_HUMANO_CPP_ATAQUE_CAZADOR_H

#include "Ataque_humano.h"


class Ataque_cazador : public Ataque_humano {

    Ataque_cazador(Humano *personaje);
    ~Ataque_cazador();

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
    void bajar_vida_vampiros(int indice, int porcentaje_escopeta, int porcentaje_agua, int porcentaje_estaca, Casilla* casilla, string arma_elegida);

};


#endif //ATAQUE_HUMANO_CPP_ATAQUE_CAZADOR_H
