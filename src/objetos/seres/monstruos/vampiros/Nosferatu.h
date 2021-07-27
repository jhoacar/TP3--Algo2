#ifndef NOSFERATU_H
#define NOSFERATU_H

#include "Vampiro.h"

class Nosferatu : public Vampiro
{
	friend class Ataque_nosferatu;
    friend class Defensa_nosferatu;

	public:
		Nosferatu();
		Nosferatu(Casilla *casilla,char nombre,string ID);
		void mostrar();
		void regnerar_energia();
		void defender(Tablero *tablero,int opcion = NO_ENCONTRADO);
		void atacar(Coordenada posicion,Tablero *tablero, char arma=NO_ARMA);
		bool se_puede_atacar(Coordenada posicion,Tablero *tablero, char arma=NO_ARMA);
		~Nosferatu();
	protected:
};

#endif
