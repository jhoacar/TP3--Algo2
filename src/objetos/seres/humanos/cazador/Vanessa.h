#ifndef VANESSA_H
#define VANESSA_H

#include "Cazador.h"

class Vanessa : public Cazador
{
    private:
        bool defendido_de_vampiro;
	public:
		Vanessa();
		Vanessa(Casilla *casilla,char nombre,string ID);
		void mostrar();
		void regenerar_energia();
		~Vanessa();

        void atacar(Casilla *casilla, Tablero* tablero, char arma);
        void atacar(Casilla *casilla, Tablero* tablero);
        bool validacion_ataque(Casilla *casilla, Tablero* tablero, char arma);

        bool validacion_defensa(int valor);


        void defender(Tablero* tablero);
        void defender(int accion){}
        void defender(){}
        void defender(int accion, Tablero*){}

        bool tengo_agua_bendita();
        bool tengo_cruz();
        void proteccion_de_ataque_vampiro();
        bool devolver_proteccion_de_vampiro();
		
	protected:
};

#endif
