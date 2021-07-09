#ifndef BALA_H
#define BALA_H

#include "Elemento.h"

class Bala : public Elemento
{
	public:
		Bala();
		Bala(Casilla *casilla,char nombre,int cantidad);
		void mostrar();
		~Bala();
	protected:
};

#endif
