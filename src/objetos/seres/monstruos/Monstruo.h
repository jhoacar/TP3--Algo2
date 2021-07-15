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
	protected:
};

bool es_agua(Objeto* objeto_a_comprobar);
bool es_estaca(Objeto* objeto_a_comprobar);

#endif
