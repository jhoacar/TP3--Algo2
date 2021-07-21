#ifndef VERTICE_H
#define VERTICE_H

template <class Llave,class Dato>
class Vertice{

    Llave *llave;
    Dato *dato;
    Vertice *derecho;
    Vertice *izquierdo;
    Vertice *padre;
    
    public:
        //Usado para poder acceder a estos miembros desde la clase Arbol
        template <class,class> friend class AVL;

        Vertice(){
            this->dato  = nullptr;
            this->llave = nullptr;
            derecho     = nullptr;
            izquierdo   = nullptr;
            padre       = nullptr;
        }
        Vertice(const Llave llave, Vertice<Llave,Dato> *padre){
            this->dato = new Dato;
            this->llave = new Llave;
            *(this->llave) = llave;
            derecho = nullptr;
            izquierdo=nullptr;
            this->padre = padre; 
        }
        ~Vertice(){
            delete dato;
            delete llave;
            dato=nullptr;
            llave=nullptr;
        }
};

#endif