#ifndef FUNCIONES_H_ATAQUE_NOSFERATU_H
#define FUNCIONES_H_ATAQUE_NOSFERATU_H


#include "Ataque_vampiro.h"
#include "../objetos/seres/monstruos/vampiros/Nosferatu.h"

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

        //PRE: recibe el tablero y la coordenada del atacante
        //POST: verifica si el personaje a atacar se encuentra en rango
        bool validacion_rango_aleatorio(Tablero* tablero,Coordenada centro);


        //PRE: recibe la casilla del personaje a bajarle la vida
        //POST: verifica si el personaje a atacar se encuentra en rango
        bool validacion_rango_especifico(Casilla* casilla_a_atacar);

        //PRE: recibe el tablero y la coordenada del atacante
        //POST: devuelve una casilla aleatoria con algun personaje
        Casilla* devolver_casilla_aleatoria_en_tablero(Tablero* tablero, Coordenada centro);

        //PRE: recibe el indice del personaje en la lista de la casilla y la casilla
        //POST: verifica si el personaje tiene menos de 30 de vida para transformar a vampiro
        void verificar_transformacion_a_vampiro(int indice, Casilla* casilla);

    };


#endif //FUNCIONES_H_ATAQUE_VAMPIRELLA_H