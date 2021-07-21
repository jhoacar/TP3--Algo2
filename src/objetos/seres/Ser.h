#ifndef SER_H
#define SER_H

#include "../Objeto.h"
#include "../../mapa/Casilla.h"
#include "../../constantes/Constantes.h"
#include "../../funcionalidades/Funciones.h"


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
		void asignar_armadura(int armadura);
		void asignar_vida(int vida);
		void asignar_energia(int energia);
		void asignar_fuerza(int fuerza);
		Lista<Objeto*> obtener_inventario();
		
		virtual void defender()=0;
		virtual void atacar(Casilla *casilla)=0;
		virtual void regenerar_energia()=0;
		virtual void encuentro_con_elemento()=0;
		virtual void defenderse() = 0;
};

#endif
