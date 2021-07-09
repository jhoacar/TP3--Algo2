#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../Monstruo.h"

class Zombie : public Monstruo
{
	public:
		Zombie();
		Zombie(Casilla *Casilla,char nombre);
		void mostrar();
		~Zombie();
	protected:
};

#endif
