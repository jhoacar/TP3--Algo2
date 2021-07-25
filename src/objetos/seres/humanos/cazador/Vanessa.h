#ifndef VANESSA_H
#define VANESSA_H

#include "Cazador.h"

class Vanessa : public Cazador
{
	public:
		Vanessa();
		Vanessa(Casilla *casilla,char nombre,string ID);
		void mostrar();
		void regenerar_energia();
		~Vanessa();
		void defender();
        void atacar(Casilla *casilla, Tablero* tablero, char arma);
        void atacar(Casilla *casilla, Tablero* tablero);
        bool validacion_ataque(Casilla *casilla, Tablero* tablero, char arma);
		
	protected:
};

#endif
