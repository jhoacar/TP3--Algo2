#ifndef VAMPIRELLA_H
#define VAMPIRELLA_H

#include "Vampiro.h"

class Vampirella : public Vampiro
{
    private:
        bool murcielago;
	public:
		Vampirella();
		Vampirella(Casilla *casilla,char nombre,string ID);
		void mostrar();
		void regenerar_energia();
		~Vampirella();

		// PRE: Vampirella ha decidido defenderse.
        // POS: Consume 5 puntos de energía y se vuelve murcielago por un turno.
        //      No puede ser atacada por estacas, ni agua bendita por un turno.
		void defender();

		// PRE: Vampirella se defiende.
		// POS: Se convierte en murcielago, por lo tanto establece murcielago en true.
		void convertir_en_murcielago();

		// PRE: Vampirella se ha defendido en el turno anterior, por lo tanto muricelago es true.
        // POS: Vampirella se vuelve a convertir en vampiro, por lo tanto se establece murcielago en false.
		void convertir_en_vampiro();

		// PRE: -
		// POS: Devuelve true si es murcielago, caso contrario devuelve false.
		bool es_murcielago();

		void atacar(Casilla *casilla);
	protected:
};

#endif
