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

        // PRE: Vampirella ha decidido defenderse.
        // POS: Vampirella se defiende. Es decir:
        //      Consume -10 puntos de energía.
        //      Si no tiene agua bendita o una cruz, se cura +10 puntos de vida.
        //      Si tiene agua bendita en su inventario, evita que aliados a dos casilleros de
        //      distancia se conviertan en zombies.
        //      Si tiene una cruz, se protege de cualquier ataque vampirico.
		void defender();

        // Comprueba si hay agua bendita en el inventario
        // PRE: -
        // POS: Devuelve true si tiene agua bendita en su inventario, caso contrario devuelve false.
        bool tengo_agua_bendita();

        // Comprueba si hay una cruz en el inventario
        // PRE: -
        // POS: Devuelve true si tiene cruz en su inventario, caso contrario devuelve false.
        bool tengo_cruz();
        
		void atacar(Casilla *casilla);
		
	protected:
};

#endif
