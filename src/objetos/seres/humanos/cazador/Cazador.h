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

        void validacion_ataque(Ataque* ataque, int posicion_x_elegida, int posicion_y_elegida, string arma_elegida);

        void atacar(Tablero* tablero, int posicion_x_elegida, int posicion_y_elegida, string arma_elegida);

	protected:
};

#endif
