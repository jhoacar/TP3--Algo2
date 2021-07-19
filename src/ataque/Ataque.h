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
    bool validacion_rango_ataque(Casilla *casilla_a_atacar, int max_rango);
    bool energia_suficiente(int minimo);
    void consumir_energia(int cantidad);
    int calcular_vida_con_armadura(int valor_ataque);
    int calcular_porcentaje_fuerza(int fuerza, int porcentaje);
    void quitar_vida(int cantidad);
};


#endif //ATAQUE_H
