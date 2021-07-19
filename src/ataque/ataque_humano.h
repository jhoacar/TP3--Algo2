#ifndef ATAQUE_HUMANO_H
#define ATAQUE_HUMANO_H

#include "Ataque.h"
#include "../objetos/seres/humanos/Humano.h"
#include <string>

using namespace std;

class Ataque_humano : public Ataque{

    Ataque_humano(Humano *personaje);
    ~Ataque_humano();

    void atacar(Casilla *casilla);

    //PRE:
    //POST:
    string eleccion_arma();

    //PRE:
    //POST:
    bool tiene_arma(string arma_elegida);

    //PRE:
    //POST:
    int buscar_personaje(Casilla *casilla_a_atacar, string personaje);

    //PRE:
    //POST:
    bool tiene_balas(int cantidad_minima_balas);

    //PRE:
    //POST:
    bool validacion_ataque(Casilla *casilla_a_atacar, string arma_elegida);

    //PRE:
    //POST:
    void bajar_cantidad_objeto(int cantidad_gastada, string arma);

    //PRE:
    //POST:
    int indice_personaje(string personaje, Casilla* casilla);

    //PRE:
    //POST:
    void bajar_vida(Casilla* casilla);

    //PRE:
    //POST:
    char devolver_inicial(string objeto);

};


#endif //ATAQUE_HUMANO_H
