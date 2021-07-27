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
		void defender(Tablero *tablero, int opcion=NO_ENCONTRADO);
		void atacar(Coordenada posicion,Tablero *tablero,char arma=NO_ARMA);
		bool se_puede_atacar(Coordenada posicion,Tablero *tablero,char arma=NO_ARMA);
		
	protected:
};

#endif
