#ifndef AGUA_H
#define AGUA_H

#include "Elemento.h"

class Agua : public Elemento
{
	public:
		Agua();
		Agua(Casilla *casilla,char nombre,int cantidad);
		void mostrar();
		~Agua();
	protected:
};

#endif
