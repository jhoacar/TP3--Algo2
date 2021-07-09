#ifndef CAZADOR_H
#define CAZADOR_H

#include "../Humano.h"

class Cazador : public Humano
{
	public:
		Cazador();
		Cazador(Casilla *casilla,char nombre);
		void mostrar();
		void regenerar_energia();
		~Cazador();
	protected:
};

#endif
