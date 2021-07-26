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
		void defender(Tablero *tablero);
		void atacar(Coordenada posicion,Tablero *tablero);
		~Nosferatu();
	protected:
};

#endif
