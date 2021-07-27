#ifndef MONSTRUO_H
#define MONSTRUO_H

#include "../Ser.h"

class Monstruo : public Ser
{
	public:
		Monstruo();
		Monstruo(Casilla *casilla,char nombre,string ID);
		~Monstruo();
		void mostrar();
		bool esta_oculto();
		void ocultar();
		void aparecer();
	protected:
		bool oculto;
};

#endif
