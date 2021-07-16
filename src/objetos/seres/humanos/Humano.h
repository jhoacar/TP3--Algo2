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
		
		// PRE: Se comprobó previamente que el humano no tiene agua bendita en su invenatario.
    		//      Es decir, se ejecutó previamente el método tengoAguaBendita y devolvió false.
    		// POS: Incrementa 3 puntos la energía del humano.
    		void aumentar_energia();

    		// PRE: Se comprobó previamente que el humano tiene agua bendita en su invenatario.
    		//      Es decir, se ejecutó previamente el método tengoAguaBendita y devolvió true.
    		// POS: Incrementa 1 punto la armadura del humano por un turno.
    		void aumentar_armadura();
		
	protected:
	
	private:
		bool armadura_aumentada;
};

#endif
