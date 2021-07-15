#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

#include "Vertice.h"
#include "Lista.h"

template <class Dato>
class Arbol_B{

    Vertice<Dato> *raiz;
    public:
        Arbol_B(Dato dato){
            raiz = new Vertice(dato)
        }
        ~Arbol_B(){
            
        }
};

#endif