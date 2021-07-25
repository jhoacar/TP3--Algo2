#ifndef FUNCIONES_H_ATAQUE_VAMPIRELLA_H
#define FUNCIONES_H_ATAQUE_VAMPIRELLA_H

#include "Ataque_vampiro.h"
#include "../objetos/seres/monstruos/vampiros/Vampirella.h"

class Ataque_vampirella:public Ataque_vampiro{

public:
    Ataque_vampirella(Vampirella *personaje);
    ~Ataque_vampirella();

    void atacar(Casilla *casilla, Tablero* tablero);


    //PRE: recibe la casilla del personaje a bajarle la vida
    //POST: le baja la vida al personaje
    void bajar_vida(Casilla* casilla);

    bool validacion_atacar_personaje(Casilla *casilla, Tablero* tablero);

    bool validacion_atacar_personaje(Casilla *casilla, Tablero* tablero, char arma);

};


#endif //FUNCIONES_H_ATAQUE_VAMPIRELLA_H
