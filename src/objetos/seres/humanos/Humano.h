#ifndef HUMANO_H
#define HUMANO_H

#include "../Ser.h"

class Humano : public Ser
{
	public:
		Humano();
		Humano(Coordenada posicion,char nombre);
		void mostrar();
		~Humano();
		void regenerar_energia();
		void encuentro_con_elemento();
	protected:
};

#endif
