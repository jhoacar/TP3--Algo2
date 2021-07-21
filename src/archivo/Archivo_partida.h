#ifndef ARCHIVO_PARTIDA_H
#define ARCHIVO_PARTIDA_H

#include "Archivo.h"

class Archivo_partida : Archivo {

public:

    //PRE: Un puntero a una lista con datos del juego
    //POST: Genera un archivo y graba en el todos los datos que se reciben de la lista
    void guardar_partida(Lista<string>* datos_juego);

    //POST: lee un archivo con los datos de la partida guardada, y retorna un puntero a una lista
    //con los datos del archivo en orden a medida que se leen de el mismo;
    Lista<string>* obtener_datos_de_partida();

};

#endif