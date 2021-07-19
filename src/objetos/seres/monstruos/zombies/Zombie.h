#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../Monstruo.h"

class Zombie : public Monstruo
{
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
		void defenderse();

		// PRE: El zombie se ha defendido en el turno anterior, por lo tanto escondido es true.
		// POS: El zombie resurge, por lo tanto se establece escondido en false
		void resurgir();

		// PRE:-
		// POS: Devuelve true si el zombie está escondido, caso contrario devuelve false.
		bool esta_escondido();

		~Zombie();

	protected:

    private:
        bool escondido;

};

#endif
