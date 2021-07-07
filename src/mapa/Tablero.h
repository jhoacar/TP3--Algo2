#ifndef TABLERO_H
#define TABLERO_H

#include "../constantes/Constantes.h"
#include "../objetos/Objeto.h"
#include "Casilla.h"


class Tablero
{
	Casilla ***casillas;
	int filas;
    int columnas;
	public:
		/*
		PRE: 
		POST: Construye un tablero sin ningun dato 
		*/
        Tablero();
		/*
		PRE: Dimensiones del tablero, filas y columnas
		POST: Construye un tablero reservando memoria dinamica para cada casilla
		*/
		Tablero(int filas,int columnas);
		/*
		PRE:
		POST: Destruye la memoria reservada previamente
		*/
		~Tablero();
		/*
		PRE: Una posicion a evaluar
		POST: Devuelve si se encuentra adentro del tablero
		*/
		bool es_valida(Coordenada posicion);
		/*
		PRE:
		POST: Devuelve el numero de filas
		*/
		int obtener_filas();
		/*
		PRE:
		POST: Devuelve el numero de columnas
		*/
		int obtener_columnas();
		/*
		PRE: Una posicion a buscar
		POST: Devuelve un string con el cuadrante donde pertenece
		*/
		string obtener_cuadrante(Coordenada posicion);
		/*
		PRE:
		POST: Devuelve la casilla en la posicion indicada
		*/
		Casilla* obtener_casilla(Coordenada posicion);
		/*
		PRE: Un objeto previamente cargado
		POST: Carga al tablero la informacion del objeto
		*/
		void cargar_objeto(Objeto *objeto);
		/*
		PRE: Una posicion a buscar
		POST: Devuelve verdadero si logro eliminar el objeto, falso en caso contrario
		*/
		bool eliminar_objeto(Objeto *objeto);
		/*
		PRE: Una posicion a buscar
		POST: Devuelve verdadero si logro eliminar el objeto, falso en caso contrario
		*/
		bool eliminar_objeto(Coordenada posicion,const char nombre_objeto);
		/*
		PRE: 
		POST: Muestra el tablero con un formato especifico
		*/
		void mostrar_tablero();
		/*
		PRE:
		POST: Muestra en la pantalla la convencion de letras para el tablero y sus personajes
		*/
		void mostrar_leyenda();
	protected:
};

#endif
