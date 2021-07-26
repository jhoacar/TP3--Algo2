#ifndef FUNCIONES_H_ATAQUE_ZOMBIE_H
#define FUNCIONES_H_ATAQUE_ZOMBIE_H

#include "../../Ataque.h"
#include "../../../objetos/seres/monstruos/zombies/Zombie.h"
#include "../../../mapa/Tablero.h"
class Ataque_zombie: public Ataque{


    public:

        Ataque_zombie(Zombie *personaje);
        ~Ataque_zombie();

        void atacar(Casilla* casilla, Tablero* tablero);
    void atacar(Casilla* casilla, Tablero* tablero, char arma);

        //PRE: recibe la casilla a atacar y el arma que va a utilizar
        //POST: devuelve si puede atacar o no
        bool validacion_ataque(int energia);

        //PRE: recibe la casilla del personaje a bajarle la vida
        //POST: le baja la vida al personaje
        void bajar_vida(Casilla* casilla);

        //PRE: recibe el tablero y donde se encuentra el atacante
        //POST: devuelve si hay algun personaje para atacar
        bool validacion_rango_aleatorio(Tablero* tablero,Coordenada centro);

        //PRE: recibe la casilla del personaje a bajarle la vida
        //POST: devuelve la casilla donde se encuentra el personaje a atacar
        Casilla* devolver_casilla_aleatoria_en_tablero(Tablero* tablero, Coordenada centro);

        bool validacion_atacar_personaje(Casilla *casilla, Tablero* tablero);

        bool validacion_atacar_personaje(Casilla *casilla, Tablero* tablero, char arma);



};


#endif //FUNCIONES_H_ATAQUE_ZOMBIE_H
