#ifndef ATAQUE_HUMANO_H_ATAQUE_VANESA_H
#define ATAQUE_HUMANO_H_ATAQUE_VANESA_H

#include "Ataque_humano.h"
#include "../objetos/seres/humanos/Humano.h"
#include "../objetos/seres/humanos/cazador/Vanessa.h"

class Ataque_vanesa : public Ataque_humano {

public:
    Ataque_vanesa(Vanessa *personaje);
    ~Ataque_vanesa();

    void atacar(Casilla *casilla, Tablero* tablero, char arma);


    //PRE: recibe la casilla del personaje a bajarle la vida
    //POST: le baja la vida al personaje
    void bajar_vida(Casilla* casilla, char arma_elegida);



    //PRE:
    //POST:
    void bajar_vida_vampiro(int indice, int porcentaje_escopeta, int porcentaje_agua, Casilla* casilla, char arma_elegida);

    void bajar_vida_completa(int indice, Casilla *casilla);



};


#endif //ATAQUE_HUMANO_H_ATAQUE_VANESA_H
