#ifndef FUNCIONES_H_ATAQUE_ZOMBIE_H
#define FUNCIONES_H_ATAQUE_ZOMBIE_H

#include "Ataque.h"
#include "Zombie.h"
#include "Tablero.h"
class Ataque_zombie: public Ataque{


    public:

        Ataque_zombie(Zombie *personaje);
        ~Ataque_zombie();

        void atacar(Tablero* tablero);

        //PRE: recibe la casilla a atacar y el arma que va a utilizar
        //POST: devuelve si puede atacar o no
        bool validacion_ataque(Casilla *casilla_a_atacar);

        //PRE: recibe la casilla del personaje a bajarle la vida
        //POST: le baja la vida al personaje
        void bajar_vida(Casilla* casilla);


        Casilla* validacion_hay_personaje_en_casilla(Lista<Casilla *> lista_casillas);


};


#endif //FUNCIONES_H_ATAQUE_ZOMBIE_H
