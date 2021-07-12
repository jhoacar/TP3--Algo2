#ifndef TABLERO_H
#define TABLERO_H

#include "../constantes/Constantes.h"
#include "../funcionalidades/tda/Grafo.h"
#include "../objetos/Objeto.h"
#include "Casilla.h"


class Tablero
{
	Casilla ***casillas;
	Grafo<Coordenada> grafo;
	int filas;
    int columnas;
	
	//Pre: Un tipo de personaje
	//Dicho tipo de personaje podra ser
	//TIPO_CAZADOR: 0
	//TIPO_HUMANO:  1
	//TIPO_VAMPIRO: 2
	//TIPO_ZOMBIE : 3
	//Post: Inicializa la matrices Floyd con todos los pesos correspondientes al tipo de personaje
	void cargar_grafo(int tipo_personaje);

	public:
		
		//Post: Construye un tablero sin ningun dato 
        Tablero();

		//Pre:  Dimensiones del tablero, filas y columnas
		//Post: Construye un tablero reservando memoria dinamica para cada casilla
		Tablero(int filas,int columnas);
		
		//Post: Destruye la memoria reservada previamente
		~Tablero();
		
		//Pre:  Una posicion a evaluar
		//Post: Devuelve si se encuentra adentro del tablero
		bool es_valida(Coordenada posicion);
		
		//Pre: 
		//Post: Devuelve el numero de filas
		int obtener_filas();

		//Pre: 
		//Post: Devuelve el numero de columnas
		int obtener_columnas();

		//Pre:  Una posicion a buscar
		//Post: Devuelve un string con el cuadrante donde pertenece
		string obtener_cuadrante(Coordenada posicion);
		
		
		//Pre: Una casilla previamente bien cargada, con sus posiciones.
		//Post: Carga al tablero en la posicion de la casilla dicha casilla
		void asignar_casilla(Casilla *casilla);
		
		
		//Pre: Una lista de casillas previamente bien cargadas, con sus posiciones
		//Post: Carga al tablero en la posicion de cada casilla, todas las casillas de la lista
		void asignar_casillas(Lista<Casilla*> casillas);
		
		//Pre: Una posicion del tablero
		//Post: Devuelve la casilla en la posicion indicada
		Casilla* obtener_casilla(Coordenada posicion);
		
		//Pre: Una lista de posiciones del tablero
		//Post: Devuelve una lista de casillas encontradas en cada posicion
		Lista<Casilla *> obtener_lista_casillas(Lista<Coordenada> posiciones);
		
		//Pre: Una coordenada de origen y una coordenada del destino y el tipo de personaje que realizara en el camino
		//Dicho tipo de personaje podra ser
		//TIPO_CAZADOR: 0
		//TIPO_HUMANO:  1
		//TIPO_VAMPIRO: 2
		//TIPO_ZOMBIE : 3
		//Post: Devuelve una lista con las coordenadas donde se encuentra el camino minimo para ir desde el origen hasta el destino
		Lista<Casilla*> obtener_camino_minimo(Coordenada origen, Coordenada destino, int tipo_personaje);
		
		//Pre: Una coordenada de origen y una coordenada del destino y el tipo de personaje que realizara en el camino
		//Dicho tipo de personaje podra ser
		//TIPO_CAZADOR: 0
		//TIPO_HUMANO:  1
		//TIPO_VAMPIRO: 2
		//TIPO_ZOMBIE : 3
		//Post: Devuelve un entero con la energia desde el origen hasta el destino
		int obtener_energia_total(Coordenada origen, Coordenada destino, int tipo_personaje);

		//Pre: Un objeto previamente cargado con su casilla
		//Post: Carga al tablero en la casilla de la posicion del objeto, dicho objeto
		void cargar_objeto(Objeto *objeto);
		
		//Pre: Una lista de objetos previamente cargados cada uno con su casilla
		//Post: Carga al tablero en la casilla de la posicion de cada objeto objeto, todos los objetos de la lista
		void cargar_lista_objetos(Lista<Objeto *>objeto);

		//Pre:  Una posicion a buscar y un char representando el nombre del objeto
		//Post: Devuelve verdadero si logro eliminar el objeto de la casilla, falso en caso contrario		
		bool eliminar_objeto(Coordenada posicion,const char nombre_objeto);

		//Pre:  Una posicion a buscar y un ID representando el ID del objeto
		//Post: Devuelve verdadero si logro eliminar el objeto de la casilla, falso en caso contrario		
		bool eliminar_objeto(Coordenada posicion,const string ID);

		//Pre:  
		//Post: Muestra el tablero con un formato especifico
		void mostrar_tablero();
		
		//Pre: 
		//Post: Muestra en la pantalla la convencion de letras para el tablero y sus personajes
		void mostrar_leyenda();

	protected:
};

#endif
