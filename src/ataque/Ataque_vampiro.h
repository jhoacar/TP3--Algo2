#ifndef FUNCIONES_H_ATAQUE_VAMPIRO_H
#define FUNCIONES_H_ATAQUE_VAMPIRO_H

#include "Ataque.h"
#include "../objetos/seres/monstruos/vampiros/Vampiro.h"

class Ataque_vampiro: public Ataque{

public:

    Ataque_vampiro(Vampiro *personaje);
    ~Ataque_vampiro();

    void atacar(Casilla *casilla);

    //PRE: recibe la casilla a atacar y el arma que va a utilizar
    //POST: devuelve si puede atacar o no
    bool validacion_ataque(Casilla *casilla_a_atacar);

    //PRE: recibe la casilla del personaje a bajarle la vida
    //POST: le baja la vida al personaje
    void bajar_vida(Casilla* casilla);

};


#endif //FUNCIONES_H_ATAQUE_VAMPIRO_H
