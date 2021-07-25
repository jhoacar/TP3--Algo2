#ifndef ATAQUE_HUMANO_CPP_ATAQUE_CAZADOR_H
#define ATAQUE_HUMANO_CPP_ATAQUE_CAZADOR_H

#include "Ataque_humano.h"
#include "Cazador.h"

class Ataque_cazador : public Ataque_humano {

public:
    Ataque_cazador(Cazador *personaje);
    ~Ataque_cazador();

    void atacar(Casilla *casilla, Tablero* tablero, char arma);


    //PRE: recibe la casilla del personaje a bajarle la vida
    //POST: le baja la vida al personaje
    void bajar_vida(Casilla* casilla, char arma_elegida);

    bool validacion_atacar_personaje(Casilla *casilla, Tablero* tablero);
    bool validacion_atacar_personaje(Casilla *casilla, Tablero* tablero, char arma);

    //PRE:
    //POST:
    void bajar_vida_vampiro(int indice, int porcentaje_escopeta, int porcentaje_agua, int porcentaje_estaca, Casilla* casilla, char arma_elegida);




};


#endif //ATAQUE_HUMANO_CPP_ATAQUE_CAZADOR_H
