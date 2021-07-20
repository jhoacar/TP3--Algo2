#ifndef ATAQUE_HUMANO_H
#define ATAQUE_HUMANO_H

#include "Ataque.h"
#include "../objetos/seres/humanos/Humano.h"
#include <string>

using namespace std;

class Ataque_humano : public Ataque{


public:
    Ataque_humano(Humano *personaje);
    ~Ataque_humano();

    void atacar(Casilla *casilla);

    string eleccion_arma();

    //PRE: recibe el arma que utilizara
    //POST: verifica si existe ese arma en su inventario
    bool tiene_arma(string arma_elegida);

    //PRE: recibe una casilla que atacara y el nombre del personaje que atacara
    //POST: devuelve la posicion donde se encuentra el personaje en la lista,
    //si no lo encuentra devolvera -1
    int buscar_personaje(Casilla *casilla_a_atacar, string personaje);

    //PRE: recibe la cantidad minima de balas para atacar
    //POST: devuelve si tiene suficientes balas o no
    bool tiene_balas(int cantidad_minima_balas);

    //PRE: recibe la casilla a atacar y el arma que va a utilizar
    //POST: devuelve si puede atacar o no
    bool validacion_ataque(Casilla *casilla_a_atacar, string arma_elegida);

    //PRE: recibe una cantidad de cuantos objetos gasto y que objeto
    //POST: baja la cantidad de ese objeto
    void bajar_cantidad_objeto(int cantidad_gastada, string arma);

    //PRE: recibe el nombre y la casilla que se encuentra el personaje
    //POST: devuelve la posicion del personaje
    int indice_personaje(string personaje, Casilla* casilla);

    //PRE: recibe la casilla del personaje a bajarle la vida
    //POST: le baja la vida al personaje
    void bajar_vida(Casilla* casilla);

    //PRE: recibe el nombre del objeto
    //POST: devuelve la inicial
    char devolver_inicial(string objeto);

    void calcular_valores_ataque(int indice, int porcentaje, Casilla* casilla);


};


#endif //ATAQUE_HUMANO_H
