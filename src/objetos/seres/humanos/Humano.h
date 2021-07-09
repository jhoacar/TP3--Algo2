#ifndef HUMANO_H
#define HUMANO_H

#include "../Ser.h"

class Humano : public Ser
{
	public:
		Humano();
		Humano(Casilla *casilla,char nombre);
		void mostrar();
		~Humano();
	protected:
};

#endif
