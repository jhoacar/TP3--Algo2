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
	protected:
	
	private:
		bool armadura_aumentada;
};

#endif
