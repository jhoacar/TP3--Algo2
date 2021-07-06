#ifndef CASILLA_H
#define CASILLA_H

#include <string>
#include "../objetos/Objeto.h"
#include "../funcionalidades/Lista.h"
using std::string;

class Casilla{
    protected:
        char tipo;
        string cuadrante;
        Coordenada posicion;
        Lista<Objeto*> objetos;
    public:
        Casilla();
        ~Casilla();
};

#endif