#ifndef CAZADOR_H
#define CAZADOR_H

#include "../Humano.h"

class Cazador : public Humano
{
	friend class Ataque_cazador;
    friend class Defensa_cazador;

	public:
		Cazador();
		Cazador(Casilla *casilla,char nombre,string ID);
		void mostrar();
		void regenerar_energia();
		~Cazador();
		void defender(Tablero *tablero);
		void atacar(Coordenada posicion, Tablero *tablero);
	protected:
};

#endif
