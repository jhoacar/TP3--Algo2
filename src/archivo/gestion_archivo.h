#ifndef GESTION_ARCHIVO_H
#define GESTION_ARCHIVO_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../funcionalidades/tda/Lista.h"

using std::fstream;
using namespace std;

class Gestion_archivo {

public:

    /*PRE: Un nombre del fichero de texto
    POST: Un string con toda la informacion del fichero, o un string vacio si ocurre un error
    */
    string obtener_texto(const string nombre_fichero);

    /*
    PRE: Un nombre del fichero a buscar
    POST: Muestra la informacion del fichero en pantalla, validando los caracteres especiales
    */
    bool mostrar_fichero(string name);

    /*
    PRE: Un puntero a una lista con datos del juego
    POST: Genera un archivo y graba en el todos los datos que se reciben de la lista
    */
    void guardar_partida(Lista<string>* datos_juego);

    /*
    POST: lee un archivo con los datos de la partida guardada, y retorna un puntero a una lista
    con los datos del archivo en orden a medida que se leen de el mismo;
    */
    Lista<string>* obtener_datos_de_partida();
    

};

#endif