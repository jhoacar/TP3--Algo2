#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../funcionalidades/tda/Lista.h"

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;

class Archivo{

    string contenido;

    //Pre: Un nombre del fichero de texto
    //Post: Un string con toda la informacion del fichero, o un string vacio si ocurre un error
    string obtener_texto(const string nombre_fichero);

    public:

        Archivo();

        Archivo(const string nombre_fichero);
        
        //Post: Muestra la informacion del fichero en pantalla, validando los caracteres especiales
        bool mostrar_contenido();

};

#endif