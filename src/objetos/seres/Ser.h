#ifndef SER_H
#define SER_H

#include "../Objeto.h"
#include "../elementos/Elemento.h"
#include "../../constantes/Constantes.h"
#include "../../funcionalidades/Funciones.h"
#include "../../mapa/Casilla.h"
#include "../../ataque/Ataque.h"

class Ataque;

class Defensa;
class Ataque;

bool es_elemento(Objeto* objeto_a_comprobar);



class Ser : public Objeto
{
    protected:
        int armadura, vida, fuerza, energia;
        Lista<Objeto*> inventario;
		Objeto *objeto_referencia; //Objeto de comparacion para la clase Lista
		Ataque *ataque;

		/*Defensa *defensa;
		Ataque *ataque;*/
	public:
		Ser();
		Ser(Casilla *casilla,char nombre,string ID);
		~Ser();
		int devolver_armadura();
		int devolver_vida();
		int devolver_energia();
		int devolver_fuerza();


		Lista<Objeto*> obtener_inventario();

		//void defender();
		void atacar(Casilla *casilla);
		//void atacar(Lista<Casilla*> casilla);

		virtual void regenerar_energia()=0;
		virtual void encuentro_con_elemento()=0;
		bool es_elemento(Objeto* objeto_a_comprobar);


        //PRE: recibe una casilla
        //POST: baja la vida del personaje que se encuentra en esa casilla
		void atacar(Casilla *casilla);

        //PRE: recibe una cantidad
        //POST: baja la vida
		void bajar_vida(int cantidad);

        //PRE: recibe una cantidad a bajar
        //POST: baja la energia
		void consumir_energia(int cantidad_gastada);

        //PRE: recibe una cantidad de vida a bajar
        //POST: baja la vida a partir de cuantos puntos de armadura tenga
		int calcular_vida_con_armadura(int vida_a_bajar);




};

#endif
