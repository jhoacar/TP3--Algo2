#ifndef VERTICE_H
#define VERTICE_H

template <class Dato>
class Vertice{
    Dato *dato;
    Vertice *derecho;
    Vertice *izquierdo;
    Vertice *padre;
    public:
        //Usado para poder acceder a estos miembros desde la clase Arbol
        template <class> friend class Arbol_B;
        Vertice(Dato dato){
            this->dato = new Dato;
            *(this->dato) = dato;
        }
        Vertice(Vertice *padre){
            dato = new Dato;
            derecho=nullptr;
            izquierdo=nullptr;
            this->padre=padre;
        }
        ~Vertice(){
            delete dato;
            dato=nullptr;
        }
};

#endif