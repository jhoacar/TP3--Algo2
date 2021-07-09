#ifndef NOSFERATU_H
#define NOSFERATU_H

#include "Vampiro.h"

class Nosferatu : public Vampiro
{
	public:
		Nosferatu();
		Nosferatu(Casilla *casilla,char nombre);
		void mostrar();
		~Nosferatu();
	protected:
};

#endif
