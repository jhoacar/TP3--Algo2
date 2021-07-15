#ifndef ARCHIVO_TABLERO_H
#define ARCHIVO_TABLERO_H

#include "Archivo.h"

class Archivo_tablero : Archivo {

    public:

    //POST: lee un archivo con los datos del mapa de juego, y retorna un puntero a una lista
    //con los datos del archivo en orden a medida que se leen de el mismo;
    Lista<string>* obtener_datos_de_mapa();

};

#endif