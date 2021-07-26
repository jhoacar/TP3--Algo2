#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../Monstruo.h"

class Zombie : public Monstruo
{
	friend class Ataque_zombie;
	friend class Defensa_zombie;

	public:
        Zombie();
		Zombie(Casilla *casilla,char nombre,string ID);
		void mostrar();
		void regenerar_energia();
		void encuentro_con_elemento();

        // PRE: Una instancia de zombie ha decidido defenderse.
        // POS: El zombie se defiende. Es decir:
        //      Consume 2 puntos de energía y se esconde por un turno.
        //      Aumenta 20 puntos de vida.
		void defender(Tablero *tablero);

		void atacar(Coordenada posicion,Tablero *tablero);
		
		~Zombie();

};

#endif
