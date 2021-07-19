#ifndef SER_H
#define SER_H

#include "../Objeto.h"
#include "../elementos/Elemento.h"
#include "../../constantes/Constantes.h"
#include "../../funcionalidades/Funciones.h"
#include "../../mapa/Casilla.h"
#include "../../ataque/Ataque.h"

class Ataque;

bool es_elemento(Objeto* objeto_a_comprobar);



class Ser : public Objeto
{
    protected:
        int armadura, vida, fuerza, energia;
        Lista<Objeto*> inventario;
		Objeto *objeto_referencia; //Objeto de comparacion para la clase Lista
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
		virtual void regenerar_energia()=0;
		virtual void encuentro_con_elemento()=0;
		bool es_elemento(Objeto* objeto_a_comprobar);

		void bajar_energia(int cantidad);
		void atacar(Casilla *casilla);

		void bajar_vida(int cantidad);
		void consumir_energia(int cantidad_gastada);


		/*//PRE: recive las posiciones donde quiere atacar, con que arma y el ataque
        //POST: devuelve si la posicion es valida para atacar
		virtual void validacion_ataque(Ataque* ataque, int posicion_x_elegida, int posicion_y_elegida, string arma_elegida) = 0;

        //PRE: recive las posiciones donde quiere atacar, con que arma y el ataque
        //POST: devuelve si la posicion es valida para atacar
        virtual void atacar(Tablero* tablero, int posicion_x_elegida, int posicion_y_elegida, string arma_elegida) = 0;

		//PRE: recibe la energia que consume
        //POST: baja la energia al personaje
		void consumir_energia(int cantidad_gastada);

        //PRE: recibe los puntos a bajar
        //POST: baja la vida del personaje
		void quitar_vida(int puntos);

		//PRE: recibe la vida momentanea a bajar
        //POST: devuelve el valor final para bajar la vida
		int calcular_vida_con_armadura(int vida_a_bajar);*/

};

#endif
