#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "../constantes/Constantes.h"
#include "tda/Lista.h"
#include "../mapa/Coordenada.h"

#include <string>
#include <iostream>

using namespace std;

//Pre: Dos numeros enteros cargados
//Post: Devuelve el numero mas pequeño entre los dos
int minimo(int A, int B);

//Pre: Un caracter a evaluar
//Post: Verdadero si es minuscula, falso caso contrario
bool es_minuscula(char letra);

//Pre: Un caracter a cambiar
//Post: Devuelve un caracter transformado a mayuscula
char caracter_mayuscula(char caracter);

//Pre: Una cadena a cambiar
//Post: Devuelve la cadena transformada a mayusculas
string cadena_mayuscula(string cadena);
<<<<<<< HEAD
/*
PRE: Un nombre del fichero de texto
POST: Un string con toda la informacion del fichero, o un string vacio si ocurre un error
*/
=======

//Pre: Un nombre del fichero de texto
//Post: Un string con toda la informacion del fichero, o un string vacio si ocurre un error
string obtener_texto(const string nombre_fichero);

//Pre: Un texto y un delimitador del texto
//Post: Una lista de string donde cada dato fue separado del string por el delimitador
>>>>>>> 1a1fbf920d772274e7d223ce8c51d7a0df2eef63
Lista<string> dividir_texto(const string texto,const char delim);

//Pre: Una cadena a evaluar
//Post: Devuelve un string con solo numeros
string solo_numeros(string &cadena);

//Pre: Una cadena a evaluar
//Post: Devuelve un entero transformado de la cadena
int convertir_entero(string cadena);

//Pre:
//Post: Realiza una pausa en la consola y espera la pulsacion de una tecla
void pausa();

//Pre:
//Post: Limpia la consola
void limpiar_pantalla();

//Pre: Dos numeros enteros para la posicion de la pantalla
//Post: Coloca el cursor donde se escoga en la pantalla
void gotoxy(int x, int y);

//Pre: Las opciones que se muestran al usuario, el error por si se equivoca, el inicio (mayor que 0) y el fin de las opciones a encontrar y una opcion de salir
//Post: Devuelve la opcion del dato elegido del string de opciones o NO_ENCONTRADO (-1) si la opcion fue salir
int pedir_dato(string opciones,string error,int inicio,int fin,char opcion_salir);

<<<<<<< HEAD
int obtener_numero_aleatorio(int min, int max);
bool mostrar_fichero(string name);
/*
PRE: Un color comprendido en las constantes de colores
POST: Cambia en la consola el formato de impresion al color de correspondiente
*/
=======
//Pre: Dos numeros referentes a un intervalo, tomando valor minimo y maximo
//Post: Devuelve un numero comprendido entre ambos, incluyendolos
int obtener_numero_aleatorio(int minimo, int maximo);

//Pre: Un nombre del fichero a buscar
//Post: Muestra la informacion del fichero en pantalla, validando los caracteres especiales
bool mostrar_fichero(string nombre_fichero);

//Post: Permite la impresion de color en consola al igual que posicionamientos
>>>>>>> 1a1fbf920d772274e7d223ce8c51d7a0df2eef63
void activar_color(void);

//Pre: Un color comprendido en las constantes de colores
//Post: Cambia en la consola el formato de impresion al color que corresponde
void color(int color);

//Pre: Un numero entero
//Post: Devuelve verdadero si es par
bool es_par(int numero);

//Pre: Una posicion de referencia y una longitud
//Post: Devuelve una lista de coordenadas, positivas referentes a una cruz de esa longitud
Lista<Coordenada> obtener_cruz(Coordenada centro , int longitud, Coordenada limite_inferior, Coordenada limite_superior);

//Pre: Una posicion de referencia y un tamano
//Post: Devueve una lista de coordenadas, positivas referentes a un cuadrado de ese tamano
Lista<Coordenada> obtener_cuadrado(Coordenada centro, int tamano, Coordenada limite_inferior, Coordenada limite_superior);

//Pre: Un nombre encontrado en el vector de objetos
//Post: Obtiene la conversion en string del nombre del objeto
string obtener_nombre_del_objeto(char nombre_char);

//Pre: Un vector de datos, un tamaño especifico y un dato a buscar
//Post: Devuelve el indice donde se encontro el dato o NO_ENCONTRADO (-1) en caso contrario
template <class Dato>
int buscar_dato(const Dato vector[],const size_t tope , Dato dato, int inicio_busqueda = 0){
	
	int indice = inicio_busqueda;
	
	bool encontrado=false;
	
	while(! encontrado && indice < (int)tope ){
	
		if(vector[indice]==dato)
			encontrado=true;
		else
			indice++;
	}
	return encontrado? indice : NO_ENCONTRADO;
}

#endif
