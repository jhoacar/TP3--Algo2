#ifndef SER_H
#define SER_H

#include "../Objeto.h"
#include "../../mapa/Tablero.h"
#include "../../constantes/Constantes.h"
#include "../../funcionalidades/Funciones.h"
//SE INCLUYE PARA LA INSTANCIA DE OBJETO REFERENCIA
#include "../elementos/Agua.h"

class Defensa;
class Ataque;



bool es_elemento(Objeto* objeto_a_comprobar);
bool es_humano(Objeto* objeto_a_comprobar);

bool es_agua(Objeto *objeto_a_comprobar);
bool es_bala(Objeto *objeto_a_comprobar);
bool es_cruz(Objeto *objeto_a_comprobar);
bool es_escopeta(Objeto *objeto_a_comprobar);
bool es_estaca(Objeto *objeto_a_comprobar);

bool es_tipo_humano(Objeto *objeto_a_comprobar);
bool es_tipo_vampiro(Objeto *objeto_a_comprobar);
bool es_tipo_zombie(Objeto *objeto_a_comprobar);
bool es_tipo_monstruo(Objeto *objeto_a_comprobar);

bool es_elemento(char nombre_objeto);

bool es_agua(char nombre_personaje);
bool es_bala(char nombre_personaje);
bool es_cruz(char nombre_personaje);
bool es_escopeta(char nombre_personaje);
bool es_estaca(char nombre_personaje);


bool es_tipo_humano(char nombre_personaje);
bool es_tipo_vampiro(char nombre_personaje);
bool es_tipo_zombie(char nombre_personaje);
bool es_tipo_monstruo(char nombre_personaje);


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
		int obtener_armadura();
		int obtener_vida();
		int obtener_energia();
		int obtener_fuerza();
		Ataque *obtener_ataque();
		Defensa *obtener_defensa();
		void asignar_armadura(int armadura);
		void asignar_vida(int vida);
		void asignar_energia(int energia);
		void asignar_fuerza(int fuerza);
		void asignar_ataque(Ataque *ataque);
		void asignar_defensa(Defensa *defensa);
		Lista<Objeto*>& obtener_inventario();
		
		virtual void defender(Tablero *tablero,int opcion=NO_ENCONTRADO)=0;
		virtual void atacar(Coordenada posicion, Tablero *tablero, char arma = NO_ARMA)=0;
		virtual bool se_puede_atacar(Coordenada posicion, Tablero *tablero, char arma = NO_ARMA)=0;
		virtual void regenerar_energia()=0;
		virtual void encuentro_con_elemento()=0;
};

#endif
