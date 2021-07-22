#ifndef CAZADOR_H
#define CAZADOR_H

#include "../Humano.h"

class Cazador : public Humano
{
    private:
        // PRE: -
        // POS: Devuelve la acción a realizar durante la defensa.
        //      Si elige curarse a si mismo, devuelve 1 = CURARME
        //      Si elige aumentar armadura, devuelve 2 = CURAR_ALIADOS
        int elegir_accion();

    public:
		Cazador();
		Cazador(Casilla *casilla,char nombre,string ID);
		void mostrar();
		void regenerar_energia();
		~Cazador();
		void defender();
		void atacar(Casilla *casilla);
	protected:
};

#endif
