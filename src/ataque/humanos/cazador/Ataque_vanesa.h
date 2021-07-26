#ifndef ATAQUE_HUMANO_H_ATAQUE_VANESA_H
#define ATAQUE_HUMANO_H_ATAQUE_VANESA_H

#include "../Ataque_humano.h"
#include "../../../objetos/seres/humanos/cazador/Vanessa.h"

class Ataque_vanesa : public Ataque_humano {

public:
    Ataque_vanesa(Vanessa *personaje);
    ~Ataque_vanesa();

    void atacar(Casilla *casilla, Tablero* tablero, char arma);


    //PRE: recibe la casilla del personaje a bajarle la vida
    //POST: le baja la vida al personaje
    void bajar_vida(Casilla* casilla, char arma_elegida);



    //PRE: recibe el indice donde se encuentra el personaje, los porcentajes, la casilla y el arma elegida
    //POST: le baja la vida a los de tipo vampiro
    void bajar_vida_vampiro(int indice, int porcentaje_escopeta, int porcentaje_agua, Casilla* casilla, char arma_elegida);


    //PRE: recibe el indice donde se encuentra el personaje, y la casilla a atacar
    //POST: le baja la vida completa al personaje
    void bajar_vida_completa(int indice, Casilla *casilla);


    bool validacion_atacar_personaje(Casilla *casilla, Tablero* tablero);

    bool validacion_atacar_personaje(Casilla *casilla, Tablero* tablero, char arma);


};


#endif //ATAQUE_HUMANO_H_ATAQUE_VANESA_H
