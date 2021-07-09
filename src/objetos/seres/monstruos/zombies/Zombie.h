#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../Monstruo.h"

class Zombie : public Monstruo
{
	public:
		Zombie();
		Zombie(Casilla *Casilla,char nombre);
		void mostrar();
		void regenerar_energia();
		void encuentro_con_elemento();
		~Zombie();
	protected:
};

#endif
