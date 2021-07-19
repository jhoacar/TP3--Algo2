#ifndef SER_H
#define SER_H

#include "../Objeto.h"
#include "../elementos/Elemento.h"
#include "../../constantes/Constantes.h"
#include "../../funcionalidades/Funciones.h"
#include "../../mapa/Casilla.h"

class Defensa;
class Ataque;

bool es_elemento(Objeto* objeto_a_comprobar);

class Ser : public Objeto
{
    protected:
        int armadura, vida, fuerza, energia;
        Lista<Objeto*> inventario;
		Objeto *objeto_referencia; //Objeto de comparacion para la clase Lista
		Defensa *defensa;
		Ataque *ataque;
	public:
		Ser();
		Ser(Casilla *casilla,char nombre,string ID);
		~Ser();
		int devolver_armadura();
		int devolver_vida();
		int devolver_energia();
		int devolver_fuerza();
		Lista<Objeto*> obtener_inventario();
		void defender();
		void atacar(Casilla *casilla);
		void atacar(Lista<Casilla*> casilla);
		virtual void regenerar_energia()=0;
		virtual void encuentro_con_elemento()=0;
};

#endif
