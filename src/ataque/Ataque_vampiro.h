#ifndef FUNCIONES_H_ATAQUE_VAMPIRO_H
#define FUNCIONES_H_ATAQUE_VAMPIRO_H

#include "Ataque.h"
#include "Vampiro.h"

class Ataque_vampiro: public Ataque{

public:

    Ataque_vampiro(Vampiro *personaje);
    ~Ataque_vampiro();

    void atacar(Casilla *casilla, Tablero* tablero);
    void atacar(Casilla *casilla, Tablero* tablero, char arma);


    //PRE: recibe la casilla a atacar y el arma que va a utilizar
    //POST: devuelve si puede atacar o no
    bool validacion_ataque( int energia);

    //PRE: recibe la casilla del personaje a bajarle la vida
    //POST: le baja la vida al personaje
    void bajar_vida(Casilla* casilla);

    bool validacion_rango_aleatorio(Tablero* tablero,Coordenada centro);
    bool validacion_rango_especifico(Casilla* casilla_a_atacar);
    Casilla* devolver_casilla_aleatoria_en_tablero(Tablero* tablero, Coordenada centro);
    Casilla* devolver_casilla_especifica_en_tablero(Tablero* tablero, Casilla* casilla);

};


#endif //FUNCIONES_H_ATAQUE_VAMPIRO_H
