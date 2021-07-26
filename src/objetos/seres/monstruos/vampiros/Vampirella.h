#ifndef VAMPIRELLA_H
#define VAMPIRELLA_H

#include "Vampiro.h"

class Vampirella : public Vampiro
{
	friend class Ataque_vampirella;
    friend class Defensa_vampirella;

	public:
		Vampirella();
		Vampirella(Casilla *casilla,char nombre,string ID);
		void mostrar();
		void regenerar_energia();
		~Vampirella();
		void defender(Tablero *tablero);
		void atacar(Coordenada posicion,Tablero *tablero);
	protected:
};

#endif
