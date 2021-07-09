#ifndef VAMPIRO_H
#define VAMPIRO_H

#include "../Monstruo.h"

class Vampiro : public Monstruo
{
	public:
		Vampiro();
		Vampiro(Coordenada posicion,char nombre);
		void mostrar();
		void regenerar_energia();
		void encuentro_con_elemento();
		~Vampiro();
	protected:
};

#endif
