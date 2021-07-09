#ifndef VAMPIRO_H
#define VAMPIRO_H

#include "../Monstruo.h"

class Vampiro : public Monstruo
{
	public:
		Vampiro();
		Vampiro(Casilla *casilla,char nombre);
		void mostrar();
		~Vampiro();
	protected:
};

#endif
