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

        Lista<Casilla*>* separar_terrenos(string texto);
        int obtener_tipo_terreno(char terreno);
        void extraer_dimensiones();
        
        
    public:

        Archivo_tablero(string nombre_fichero);
        Tablero* obtener_datos_de_terreno();
};

#endif