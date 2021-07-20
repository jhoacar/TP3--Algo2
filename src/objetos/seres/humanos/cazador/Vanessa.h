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


        /*void validacion_ataque(Ataque* ataque, int posicion_x_elegida, int posicion_y_elegida, string arma_elegida);

        void atacar(Tablero* tablero, int posicion_x_elegida, int posicion_y_elegida, string arma_elegida);*/


		void defender();
		void atacar(Casilla *casilla);
		

	protected:
};

#endif
