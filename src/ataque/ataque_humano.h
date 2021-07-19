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
    string eleccion_arma();
    bool tiene_arma(string arma_elegida);
    int buscar_personaje(Casilla *casilla_a_atacar, string personaje);
    bool tiene_balas(int cantidad_minima_balas);
    void validacion_ataque(Casilla *casilla_a_atacar, string arma_elegida);
    void bajar_cantidad_objeto(int cantidad_gastada, string arma);

};


#endif //ATAQUE_HUMANO_H
