#ifndef ARBOL_H
#define ARBOL_H

#include "Vertice.h"
#include "Lista.h"

template <class Dato>
class Arbol{
    Vertice *raiz;
    public:
        Arbol(Arbol *padre){
            dato = new Dato;
            derecho=nullptr;
            izquierdo=nullptr;
            this->padre=padre;
        }
        ~Arbol(){
            delete dato;
            dato=nullptr;
        }
};

#endif