#ifndef SER_H
#define SER_H

#include "../Objeto.h"
#include "../elementos/Elemento.h"
#include "../../constantes/Constantes.h"
#include "../../funcionalidades/Funciones.h"
#include "../../mapa/Casilla.h"

class Ser : public Objeto
{
    protected:
        int armadura, vida, fuerza, energia;
        Lista<Objeto*> inventario;
	public:
		Ser();
		Ser(Casilla *casilla,char nombre);
		~Ser();
		int devolver_armadura();
		int devolver_vida();
		int devolver_energia();
		int devolver_fuerza();
		virtual void regenerar_energia()=0;
		virtual void encuentro_con_elemento()=0;
		bool comprobar_es_elemento(Objeto* objeto_a_comprobar);
};

#endif
