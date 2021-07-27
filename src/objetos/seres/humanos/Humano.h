#ifndef HUMANO_H
#define HUMANO_H

#include "../Ser.h"

class Humano : public Ser
{

	friend class Defensa_humano;
	friend class Ataque_humano;

	protected: 
	
		bool armadura_aumentada;

		int cantidad_agua;
		int cantidad_estacas;
		int cantidad_balas;
		int cantidad_cruces;
		bool tiene_escopeta;

	public:

		Humano();
		Humano(Casilla *casilla,char nombre,string ID);
		void mostrar();
		~Humano();
		void regenerar_energia();
		void encuentro_con_elemento();
		void extraer_balas();
        void extraer_estacas();
        void extraer_escopeta();
        void extraer_agua();
		
		// PRE: Una instancia de humano ha decidido defenderse.
		// POS: El humano se defiende. Es decir:
		//      Si no tiene agua bendita en su inventario, incrementa 3 puntos su energía.
		//      Si tiene agua bendita, puede regenera toda su energía o incrementa 1 su armadura por un turno.
		void defender(Tablero *tablero);

		void atacar(Coordenada posicion, Tablero *tablero, char arma=NO_ARMA);

		bool se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma=NO_ARMA);

};

#endif
