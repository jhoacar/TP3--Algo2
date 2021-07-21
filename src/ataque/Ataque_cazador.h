#ifndef ATAQUE_HUMANO_CPP_ATAQUE_CAZADOR_H
#define ATAQUE_HUMANO_CPP_ATAQUE_CAZADOR_H

#include "Ataque_humano.h"
#include "Cazador.h"

class Ataque_cazador : public Ataque_humano {

public:
    Ataque_cazador(Cazador *personaje);
    ~Ataque_cazador();

    void atacar(Casilla *casilla, char arma);
    void atacar(Tablero* tablero, char arma);

    //PRE: recibe la casilla del personaje a bajarle la vida
    //POST: le baja la vida al personaje
    void bajar_vida(Casilla* casilla, char arma_elegida);

    //PRE:
    //POST:
    bool validacion_ataque(Casilla *casilla_a_atacar, char arma_elegida);

    // Para no repetir mucho codigo
    //PRE:
    //POST:
    void bajar_vida_vampiro(int indice, int porcentaje_escopeta, int porcentaje_agua, int porcentaje_estaca, Casilla* casilla, char arma_elegida);



};


#endif //ATAQUE_HUMANO_CPP_ATAQUE_CAZADOR_H
