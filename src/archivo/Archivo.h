#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../funcionalidades/tda/Lista.h"
#include "../constantes/Constantes.h"

using namespace std;

class Archivo{

    protected:
    //Pre: Un nombre del fichero de texto
    //Post: Un string con toda la informacion del fichero, o un string vacio si ocurre un error
    string obtener_texto(const string nombre_fichero);
    string contenido;

    public:

        Archivo();

        Archivo(const string nombre_fichero);
        
        //Post: Muestra la informacion del fichero en pantalla, validando los caracteres especiales
        bool mostrar_contenido();
};

#endif