#ifndef SER_H
#define SER_H

#include "../Objeto.h"
#include "../elementos/Elemento.h"
#include "../../constantes/Constantes.h"
#include "../../funcionalidades/Funciones.h"
#include "../../mapa/Casilla.h"

bool es_elemento(Objeto* objeto_a_comprobar);

class Ser : public Objeto
{
    protected:
        int armadura, vida, fuerza, energia;
        Lista<Objeto*> inventario;
		Objeto *objeto_referencia; //Objeto de comparacion para la clase Lista
	public:
		Ser();
		Ser(Casilla *casilla,char nombre,string ID);
		~Ser();
		int devolver_armadura();
		int devolver_vida();
		int devolver_energia();
		int devolver_fuerza();
		virtual void regenerar_energia()=0;
		virtual void encuentro_con_elemento()=0;

        bool es_elemento(Objeto* objeto_a_comprobar);
        virtual void validacion_ataque(Ataque* ataque, int posicion_x_elegida, int posicion_y_elegida, string arma_elegida) = 0;
        void consumir_energia(int cantidad_gastada);
        void quitar_vida(int puntos);
        int calcular_vida_con_armadura(int vida_a_bajar);

};

#endif
