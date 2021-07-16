#ifndef HUMANO_H
#define HUMANO_H

#include "../Ser.h"
#include "../../../mapa/Casilla.h"

class Humano : public Ser
{
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
		void defenderse();
		
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
		
	protected:
	
	private:
		//Atributo para saber si el humano ha mejorado su armadura en un turno anterior
        bool armadura_aumentada;
				
		// PRE: Se comprobó previamente que el humano tiene agua bendita en su invenatario.
		//      Es decir, se ejecutó previamente el método tengoAguaBendita.
		// POS: devuelve la posición del inventario en la que hay agua bendita.
		int  buscar_agua_bendita_en_mi_inventario();
    		
		// PRE: -
		// POS: Devuelve la acción a realizar durante la defensa.
		//      Si elige regenerar energía, devuelve 1 = REGENERAR_ENERGIA
		//      Si elige aumentar armadura, devuelve 2 = AUMENTAR_ARMADURA
		int elegir_accion();
};

#endif
