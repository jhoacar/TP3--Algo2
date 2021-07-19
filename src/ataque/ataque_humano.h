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
    bool validacion_ataque(Casilla *casilla_a_atacar, string arma_elegida);
    void bajar_cantidad_objeto(int cantidad_gastada, string arma);
    int indice_personaje(string personaje, Casilla* casilla);
    void bajar_vida(Casilla* casilla);
    char devolver_inicial(string objeto);

};


#endif //ATAQUE_HUMANO_H
