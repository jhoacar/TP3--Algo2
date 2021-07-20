#ifndef ATAQUE_H
#define ATAQUE_H

#include "../mapa/Casilla.h"

class Ser;

class Ataque {

protected:
    Ser *personaje;

public:

    Ataque(Ser *personaje);
    ~Ataque();
    virtual void atacar(Casilla *casilla) = 0;


    //PRE: recibe una casilla y un rango de distancia
    //POST: devuelve true si el objeto a atacar esta a su alcance
    bool validacion_rango_ataque(Lista<Coordenada> lista_casillas_posibles, Casilla *casilla_a_atacar);

    //PRE: recibe el minimo de energia necesario para atacar
    //POST: devuelve true si le alcanza
    bool energia_suficiente(int minimo);

    //PRE: recibe la cantidad a bajar
    //POST: baja la energia del personaje
    void consumir_energia(int cantidad);

    //PRE: recibe el valor del ataque
    //POST: baja la vida a partir de cuantos puntos de armadura tenga
    int calcular_vida_con_armadura(int valor_ataque);

    //PRE: recibe la fuerza del personaje y el porcentaje que se aplicara
    //POST: devuelve el valor del danio que hara el ataque
    int calcular_porcentaje_fuerza(int fuerza, int porcentaje);

    //PRE: recibe una cantidad
    //POST: le baja la vida al personaje
    void quitar_vida(int cantidad);
};


#endif //ATAQUE_H
