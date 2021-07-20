#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "../constantes/Constantes.h"
#include "tda/Lista.h"
#include "../mapa/Coordenada.h"

#include <string>
#include <iostream>
#include <sstream>


using namespace std;


//Post: Devuelve el caracter oprimido sin imprimirlo por consola
char tecla_pulsada(void);

//Pre: Un numero entero
//Post: Devuelve el numero sin signo;
int valor_absoluto(int numero);

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

//Pre: Un texto y un delimitador del texto
//Post: Una lista de string donde cada dato fue separado del string por el delimitador
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

//Pre: Una coordenada para la posicion de la pantalla
//Post: Coloca el cursor donde se escoga en la pantalla
void gotoxy(Coordenada posicion);


//Pre: Dos numeros referentes a un intervalo, tomando valor minimo y maximo
//Post: Devuelve un numero comprendido entre ambos, incluyendolos
int obtener_numero_aleatorio(int minimo, int maximo);

//Post: Permite la impresion de color en consola al igual que posicionamientos
void activar_color(void);

//Pre: Un color comprendido en las constantes de colores
//Post: Cambia en la consola el formato de impresion al color que corresponde
void color(int color);

//Pre: Un numero entero
//Post: Devuelve verdadero si es par
bool es_par(int numero);

//Pre: Una posicion de referencia y una longitud
//Post: Devuelve una lista de coordenadas, positivas referentes a una cruz de esa longitud
Lista<Coordenada> obtener_cruz(Coordenada centro , int longitud);


Lista<Coordenada> obtener_cuadrado(Coordenada centro, int longitud);


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
