#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "../constantes/Constantes.h"
#include "tda/Lista.h"
#include "../mapa/Coordenada.h"

#include <string>
#include <iostream>

using namespace std;

int minimo(int A, int B);
/*
PRE: Un caracter a evaluar
POST: Verdadero si es minuscula, falso caso contrario
*/
bool es_minuscula(char letra);
/*
PRE: Un caracter a cambiar
POST: Devuelve un caracter transformado a mayuscula
*/
char caracter_mayuscula(char caracter);
/*
PRE: Una cadena a cambiar
POST: Devuelve la cadena transformada a mayusculas
*/
string cadena_mayuscula(string cadena);
/*
PRE: Un nombre del fichero de texto
POST: Un string con toda la informacion del fichero, o un string vacio si ocurre un error
*/
string obtener_texto(const string nombre_fichero);
/*
PRE: Un texto y un delimitador del texto
POST: Una lista de string donde cada dato es el separado por el delimitador
*/
Lista<string> dividir_texto(const string texto,const char delim);
/*
PRE: Una cadena a evaluar
POST: Devuelve un string con solo numeros
*/
string solo_numeros(string &cadena);
/*
PRE: Una cadena a evaluar
POST: Devuelve un entero transformado de la cadena
*/
int convertir_entero(string cadena);
/*
PRE:
POST: Realiza una pausa en la consola y espera la pulsacion de una tecla
*/
void pausa();
/*
PRE:
POST: Limpia la consola
*/
void limpiar_pantalla();
/*
PRE: Dos numeros enteros para la posicion de la pantalla
POST: Coloca el cursor donde se escoga en la pantalla
*/
void gotoxy(int x, int y);
/*
PRE: Las opciones que se muestran al usuario, el error por si se equivoca, el inicio (mayor que 0) y el fin de las opciones a encontrar y una opcion de salir
POST: Devuelve la opcion del dato elegido del string de opciones o NO_ENCONTRADO (-1) si la opcion fue salir
*/
int pedir_dato(string opciones,string error,int inicio,int fin,char opcion_salir);
/*
PRE: Dos numeros referentes a un intervalo, tomando valor minimo y maximo
POST: Devuelve un numero comprendido entre ambos, incluyendolos
*/
int obtener_numero_aleatorio(int min, int max);
/*
PRE: Un nombre del fichero a buscar
POST: Muestra la informacion del fichero en pantalla, validando los caracteres especiales
*/
bool mostrar_fichero(string name);
/*
PRE: Un color comprendido en las constantes de colores
POST: Cambia en la consola el formato de impresion al color de correspondiente
*/
void activar_color(void);
/*
PRE: Un color comprendido en las constantes de colores
POST: Cambia en la consola el formato de impresion al color de correspondiente
*/
void color(int color);
/*
PRE: Un numero entero
POST: Devuelve verdadero si es par
*/
bool es_par(int numero);
/*
PRE: una posicion de referencia y una longitud
POST: Devuelve una lista de coordenadas, positivas referentes a una cruz de esa longitud
*/
Lista<Coordenada> obtener_cruz(Coordenada centro , int longitud, Coordenada limite_inferior, Coordenada limite_superior);
/*
PRE: Una posicion de referencia y un tamano
POST: Devueve una lista de coordenadas, positivas referentes a un cuadrado de ese tamano
*/
Lista<Coordenada> obtener_cuadrado(Coordenada centro, int tamano, Coordenada limite_inferior, Coordenada limite_superior);

/*
PRE: Un vector de datos, un tamaño especifico y un dato a buscar
POST: Devuelve el indice donde se encontro el dato o NO_ENCONTRADO (-1) en caso contrario
*/
template <class Dato>
int buscar_dato(const Dato vector[],const size_t tope , Dato dato){
	
	int indice = 0;
	
	bool encontrado=false;
	
	while(! encontrado && indice < (int)tope ){
	
		if(vector[indice]==dato)
			encontrado=true;
		else
			indice++;
	}
	return encontrado? indice : NO_ENCONTRADO;
}

string nombre_del_objeto(char nombre_char);

#endif
