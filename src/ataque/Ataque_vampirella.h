#ifndef FUNCIONES_H_ATAQUE_VAMPIRELLA_H
#define FUNCIONES_H_ATAQUE_VAMPIRELLA_H

#include "Ataque_vampiro.h"
#include "Vampirella.h"

class Ataque_vampirella:public Ataque_vampiro{

public:
    Ataque_vampirella(Vampirella *personaje);
    ~Ataque_vampirella();

    void atacar(Casilla *casilla);

    //PRE: recibe la casilla a atacar y el arma que va a utilizar
    //POST: devuelve si puede atacar o no
    bool validacion_ataque(Casilla *casilla_a_atacar);

    //PRE: recibe la casilla del personaje a bajarle la vida
    //POST: le baja la vida al personaje
    void bajar_vida(Casilla* casilla);

    void atacar(Tablero* tablero);


};


#endif //FUNCIONES_H_ATAQUE_VAMPIRELLA_H
