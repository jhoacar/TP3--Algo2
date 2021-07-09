#ifndef NOSFERATU_H
#define NOSFERATU_H

#include "Vampiro.h"

class Nosferatu : public Vampiro
{
	public:
		Nosferatu();
		Nosferatu(Coordenada posicion,char nombre);
		void mostrar();
		void regnerar_energia();
		~Nosferatu();
	protected:
};

#endif
