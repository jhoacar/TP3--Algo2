#ifndef ATAQUE_HUMANO_H
#define ATAQUE_HUMANO_H

#include "Ataque.h"
#include "Humano.h"
#include <string>

using namespace std;

class Ataque_humano : public Ataque{


public:
    Ataque_humano(Humano *personaje);
    ~Ataque_humano();

    void atacar(Casilla *casilla);
    void atacar(Tablero *tablero);
    char eleccion_arma();

    //PRE: recibe el arma que utilizara
    //POST: verifica si existe ese arma en su inventario
    bool tiene_arma(char arma_elegida);



    //PRE: recibe la cantidad minima de balas para atacar
    //POST: devuelve si tiene suficientes balas o no
    bool tiene_balas(int cantidad_minima_balas);

    //PRE: recibe la casilla a atacar y el arma que va a utilizar
    //POST: devuelve si puede atacar o no
    bool validacion_ataque(Casilla *casilla_a_atacar, char arma_elegida);

    //PRE: recibe una cantidad de cuantos objetos gasto y que objeto
    //POST: baja la cantidad de ese objeto
    void bajar_cantidad_objeto(char arma);


    //PRE: recibe la casilla del personaje a bajarle la vida
    //POST: le baja la vida al personaje
    void bajar_vida(Casilla* casilla);


    bool validacion_mounstruo_oculto(Casilla* casilla, char arma_elegida);


    void calcular_ataque_valores_fijos(int indice, int valor_a_sacar, Casilla* casilla);


    Casilla* validacion_hay_personaje_en_casilla(Lista<Casilla *> lista_casillas);


};


#endif //ATAQUE_HUMANO_H
