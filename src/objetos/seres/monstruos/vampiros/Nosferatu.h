#ifndef NOSFERATU_H
#define NOSFERATU_H

#include "Vampiro.h"

class Nosferatu : public Vampiro
{
	public:
		Nosferatu();
		Nosferatu(Casilla *casilla,char nombre,string ID);
		void mostrar();
		void regnerar_energia();
		~Nosferatu();
	protected:
};

#endif
