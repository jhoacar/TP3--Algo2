#ifndef HUMANO_H
#define HUMANO_H

#include "../Ser.h"
#include "../../../mapa/Tablero.h"

class Humano : public Ser
{

	friend class Defensa_humano;

	private:

		bool armadura_aumentada;
		bool en_transformacion;

		// PRE: Se comprobó previamente que el humano tiene agua bendita en su invenatario.
		//      Es decir, se ejecutó previamente el método tengoAguaBendita.
		// POS: devuelve la posición del inventario en la que hay agua bendita.
		int  buscar_agua_bendita();
    		
		// PRE: -
		// POS: Devuelve la acción a realizar durante la defensa.
		//      Si elige regenerar energía, devuelve 1 = REGENERAR_ENERGIA
		//      Si elige aumentar armadura, devuelve 2 = AUMENTAR_ARMADURA
		int elegir_accion();

	public:

		Humano();
		Humano(Casilla *casilla,char nombre,string ID);
		void mostrar();
		~Humano();
		void regenerar_energia();
		void encuentro_con_elemento();
		
		// PRE: Una instancia de humano ha decidido defenderse.
		// POS: El humano se defiende. Es decir:
		//      Si no tiene agua bendita en su inventario, incrementa 3 puntos su energía.
		//      Si tiene agua bendita, puede regenera toda su energía o incrementa 1 su armadura por un turno.
        void defender(int eleccion);
        void defender(){}
        void defender(Tablero* tablero){}
        void defender(int accion, Tablero* tablero){}


        bool validacion_ataque(Casilla *casilla, Tablero* tablero);
		void atacar(Casilla *casilla, Tablero* tablero);
        void atacar(Casilla *casilla, Tablero* tablero, char arma);

        bool validacion_defensa(int valor);

		// Comprueba si hay agua bendita en el inventario
		// PRE: -
		// POS: Devuelve true si el humano tiene agua bendita en su inventario, caso contrario devuelve false.
		bool tengo_agua_bendita();

		// PRE: Se comprobó previamente que el humano no tiene agua bendita en su invenatario.
		//      Es decir, se ejecutó previamente el método tengoAguaBendita y devolvió false.
		// POS: Incrementa 3 puntos la energía del humano.
		void aumentar_energia();

		// PRE: Se comprobó previamente que el humano tiene agua bendita en su invenatario.
		//      Es decir, se ejecutó previamente el método tengoAguaBendita y devolvió true.
		// POS: Incrementa 1 punto la armadura del humano por un turno.
		void aumentar_armadura();
    		
		// Regenera toda la energía del humano consumiendo agua bendita del inventario.
		// PRE: Se comprobó previamente que el humano tiene agua bendita en su invenatario.
		//      Es decir, se ejecutó previamente el método tengoAguaBendita y devolvió true.
		// POS: Regenera toda la energía del humano y remueve del inventario el agua bendita utilizada.
		void consumir_agua_bendita();

		// PRE: -
		// POS: Devuelve true si tiene la armadura aumentada por defenderse, caso contrario devuelve false.
		bool tiene_armadura_aumentada();

		void regenerar_energia_defensa();

		void regeneracion_maxima_energia(int maximo);

		void frenar_transformacion();



};

#endif
