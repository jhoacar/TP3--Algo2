#ifndef VAMPIRELLA_H
#define VAMPIRELLA_H

#include "Vampiro.h"

class Vampirella : public Vampiro
{
	public:
		Vampirella();
		Vampirella(Coordenada posicion,char nombre);
		void mostrar();
		void regenerar_energia();
		~Vampirella();
	protected:
};

#endif
