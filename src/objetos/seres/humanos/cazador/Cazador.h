#ifndef CAZADOR_H
#define CAZADOR_H

#include "../Humano.h"

class Cazador : public Humano
{
	public:
		Cazador();
		Cazador(Casilla *casilla,char nombre,string ID);
		void mostrar();
		void regenerar_energia();
		~Cazador();
		void defender();
		void atacar(Casilla *casilla, Tablero* tablero);
        void atacar(Casilla *casilla, Tablero* tablero, char arma);
	protected:
};

#endif
