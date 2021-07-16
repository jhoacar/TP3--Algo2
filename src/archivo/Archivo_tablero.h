#ifndef ARCHIVO_TABLERO_H
#define ARCHIVO_TABLERO_H

#include "Archivo.h"
#include "../mapa/Tablero.h"
#include "../funcionalidades/Includes_Objetos.h"


class Archivo_tablero : Archivo {

    private:

        Tablero *tablero;
        int fila;
        int columna;

        Casilla* separar_terrenos(string texto, Coordenada posicion);
        int obtener_tipo_terreno(char terreno);
        void extraer_dimensiones();
        //POST: lee un archivo con los datos del mapa de juego, y retorna un puntero a una lista
        //con los datos del archivo en orden a medida que se leen de el mismo;
        Lista<Casilla*> obtener_datos_de_terreno();

    public:

        Archivo_tablero(string nombre_fichero);
        Tablero *obtener_tablero();
};

#endif