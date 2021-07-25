#ifndef VAMPIRELLA_H
#define VAMPIRELLA_H

#include "Vampiro.h"

class Vampirella : public Vampiro
{
	public:
		Vampirella();
		Vampirella(Casilla *casilla,char nombre,string ID);
		void mostrar();
		void regenerar_energia();
		~Vampirella();
		void defender();
		void atacar(Casilla *casilla, Tablero* tablero);
        bool validacion_ataque(Casilla *casilla, Tablero* tablero);

	protected:
};

#endif
