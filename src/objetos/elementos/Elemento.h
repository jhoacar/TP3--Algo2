#ifndef ELEMENTO_H
#define ELEMENTO_H

#include "../Objeto.h"
#include "../../mapa/Casilla.h"

class Elemento : public Objeto
{
	public:
		Elemento();
		Elemento(Casilla *casilla,char nombre,int cantidad,string ID);
		/*
		PRE:
		POST: Devuelve la cantidad del elemento
		*/
        int obtener_cantidad();

        void disminuir_cantidad(int cantidad_gastada);
		~Elemento();


	protected:
        int cantidad;
};

#endif
