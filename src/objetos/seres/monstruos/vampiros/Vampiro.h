#ifndef VAMPIRO_H
#define VAMPIRO_H

#include "../Monstruo.h"

class Vampiro : public Monstruo
{

    friend class Ataque_vampiro;
    friend class Defensa_vampiro;

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
		void defender(Tablero *tablero, int opcion = NO_ENCONTRADO);

        void atacar(Coordenada posicion, Tablero *tablero,char arma=NO_ARMA);

        int se_puede_atacar(Coordenada posicion, Tablero *tablero,char arma=NO_ARMA);

        // PRE: -
        // POS: Devuelve true si tiene la armadura aumentada por defenderse, caso contrario devuelve false.
        bool tiene_armadura_aumentada();

		~Vampiro();

    protected:

        bool armadura_aumentada;
};

#endif
