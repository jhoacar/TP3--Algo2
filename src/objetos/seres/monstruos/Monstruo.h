#ifndef MONSTRUO_H
#define MONSTRUO_H

#include "../Ser.h"

class Monstruo : public Ser
{
	public:
		Monstruo();
		Monstruo(Casilla *casilla,char nombre);
		~Monstruo();
		void mostrar();
	protected:
};

#endif
