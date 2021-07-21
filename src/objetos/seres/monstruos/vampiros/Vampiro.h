#ifndef VAMPIRO_H
#define VAMPIRO_H

#include "../Monstruo.h"

class Vampiro : public Monstruo
{
	public:
		Vampiro();
		Vampiro(Casilla *casilla,char nombre,string ID);
		void mostrar();
		void regenerar_energia();
		void encuentro_con_elemento();

        // PRE: Una instancia de vampiro ha decidido defenderse.
        // POS: El vampiro se defiende. Es decir:
        //      Consume 4 puntos de energía y se oculta por un turno.
        //      Aumenta 1 punto de armadura por un turno.
		void defender();
        void atacar(Casilla *casilla);

		// PRE: -
		// POS:
		void ocultarse();

        // PRE: El vampiro se ha defendido en el turno anterior, por lo tanto oculto es true.
        // POS: El vampiro aparece, por lo tanto se establece oculto en false
		void aparecer();

        // PRE: -
        // POS: Devuelve true si tiene la armadura aumentada por defenderse, caso contrario devuelve false.
        bool tiene_armadura_aumentada();

        // PRE:-
        // POS: Devuelve true si el vampiro está oculto, caso contrario devuelve false.
        bool esta_oculto();

		~Vampiro();

    protected:

    private:
        bool oculto;
        bool armadura_aumentada;
};

#endif
