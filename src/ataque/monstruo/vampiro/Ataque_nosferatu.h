#ifndef FUNCIONES_H_ATAQUE_NOSFERATU_H
#define FUNCIONES_H_ATAQUE_NOSFERATU_H


#include "Ataque_vampiro.h"
#include "../../../objetos/seres/monstruos/vampiros/Nosferatu.h"

class Ataque_nosferatu:public Ataque_vampiro{

    public:
        Ataque_nosferatu(Nosferatu *personaje);
        ~Ataque_nosferatu();

        void atacar(Casilla *casilla, Tablero* tablero);

        /*//PRE: recibe la casilla a atacar y el arma que va a utilizar
        //POST: devuelve si puede atacar o no
        bool validacion_ataque(Casilla *casilla_a_atacar);*/

        //PRE: recibe la casilla del personaje a bajarle la vida
        //POST: le baja la vida al personaje
        void bajar_vida(Casilla* casilla);


        void atacar(Tablero* tablero);

        bool validacion_rango_aleatorio(Tablero* tablero,Coordenada centro);
        bool validacion_rango_especifico(Casilla* casilla_a_atacar);
        Casilla* devolver_casilla_aleatoria_en_tablero(Tablero* tablero, Coordenada centro);

        void verificar_transformacion_a_vampiro(int indice, Casilla* casilla);


        bool validacion_atacar_personaje(Casilla *casilla, Tablero* tablero);
        bool validacion_atacar_personaje(Casilla *casilla, Tablero* tablero, char arma);

    };


#endif //FUNCIONES_H_ATAQUE_VAMPIRELLA_H