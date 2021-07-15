#ifndef ARCHIVO_TABLERO_H
#define ARCHIVO_TABLERO_H

#include "Archivo.h"
#include "../mapa/Tablero.h"
#include "../mapa/tipos/Montana.h"
#include "../mapa/tipos/Lago.h"
#include "../mapa/tipos/Camino.h"
#include "../mapa/tipos/Precipicio.h"
#include "../mapa/tipos/Volcan.h"
#include "../mapa/tipos/Vacio.h"


class Archivo_tablero : Archivo {

    private:

    string datos_tablero;
    int fila;
    int columna;

    public:

    //POST: lee un archivo con los datos del mapa de juego, y retorna un puntero a una lista
    //con los datos del archivo en orden a medida que se leen de el mismo;
    Lista<Casilla*>* obtener_datos_de_terreno();


    private:

    Casilla* separar_terrenos(string texto, Coordenada &posicion);

    int obtener_tipo_terreno(char c);
};

#endif