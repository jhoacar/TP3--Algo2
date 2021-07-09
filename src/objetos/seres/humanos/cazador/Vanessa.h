#ifndef VANESSA_H
#define VANESSA_H

#include "Cazador.h"

class Vanessa : public Cazador
{
	public:
		Vanessa();
		Vanessa(Casilla *casilla,char nombre);
		void mostrar();
		~Vanessa();
	protected:
};

#endif
