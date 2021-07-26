#ifndef VANESSA_H
#define VANESSA_H

#include "Cazador.h"

class Vanessa : public Cazador
{
	friend class Ataque_vanesa;
    friend class Defensa_vanesa;

	public:
		Vanessa();
		Vanessa(Casilla *casilla,char nombre,string ID);
		void mostrar();
		void regenerar_energia();
		~Vanessa();
		void defender(Tablero *tablero);
		void atacar(Coordenada posicion, Tablero *tablero);
		
	protected:
};

#endif
