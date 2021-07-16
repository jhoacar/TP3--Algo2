#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../funcionalidades/tda/Lista.h"
#include "../constantes/Constantes.h"

<<<<<<< HEAD
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;
=======
>>>>>>> fb121e2ac3e01ff7ac50a93c69cb90118da9e088
using namespace std;

class Archivo{

    private:
    string contenido;

    protected:

    int fila;
    int columna;

    protected:
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