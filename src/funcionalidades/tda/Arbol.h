#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

#include "Vertice.h"
#include "../Funciones.h"

#include <iostream>
using namespace std;

template <class Llave,class Dato>
class Arbol_B{

    Vertice<Llave,Dato> *raiz;

    
    void asignar_factor_equilibrio(Vertice<Llave,Dato> *vertice){
        if(!esta_vacio(vertice)){
            vertice->factor_equilibrio = obtener_factor_equilibrio(vertice);
            asignar_factor_equilibrio(vertice->izquierdo);
            asignar_factor_equilibrio(vertice->derecho);
        }
    }

    Vertice<Llave,Dato>* obtener_pivote(Vertice<Llave,Dato> *vertice_origen){
        
        if(!esta_vacio(vertice_origen)){
            
            if(valor_absoluto(vertice_origen->factor_equilibrio)<=1)
                return vertice_origen->padre;
            
            obtener_pivote(vertice_origen->izquierdo);
            obtener_pivote(vertice_origen->derecho);
        }
    }

    void balancear(){

        if(valor_absoluto(obtener_factor_equilibrio(raiz))<=1 || esta_vacio(obtener_pivote(raiz)))
            return;

        Vertice<Llave,Dato> *pivote = obtener_pivote(raiz);

        Vertice<Llave,Dato> *padre = pivote->padre;
        int hijo_izquierdo = esta_vacio(padre) ? NO_ENCONTRADO : padre->izquierdo == pivote ;
         
        if(pivote->factor_equilibrio > 1 ){
            
            if(esta_vacio(pivote->izquierdo) && esta_vacio(pivote->derecho->izquierdo))
                rotar_izquierda(pivote);
            else if(esta_vacio(pivote->izquierdo) && esta_vacio(pivote->derecho->derecho){
                rotar_derecha(pivote->derecho);
                rotar_izquierda(pivote);
            }
        }
        if(pivote->factor_equilibrio < -1){

            if(esta_vacio(pivote->derecho) && esta_vacio(pivote->izquierdo->derecho))
                rotar_derecha(pivote)
            else if(esta_vacio(pivote->derecho) && esta_vacio(pivote->izquierdo->izquierdo)){
                rotar_izquierda(pivote->izquierdo);
                rotar_derecha(pivote);
            }
            
            rotar_derecha(pivote);
        }
        if(hijo_izquierdo!=NO_ENCONTRADO){

            if(hijo_izquierdo)
                padre->izquierdo = pivote;
            else   
                padre->derecho = pivote;
        }
    }
    /* 
    Rotación simple a la izquierda

    De un árbol de raíz (r) y de hijos izquierdo (i) y derecho (d), 
    consiste en formar un nuevo árbol cuya raíz sea la raíz del hijo derecho,
     como hijo derecho colocamos el hijo derecho de d (nuestro d’) y como hijo izquierdo 
     construimos un nuevo árbol que tendrá como raíz la raíz del árbol (r),
      el hijo izquierdo de d será el hijo derecho (i’) de r y el hijo izquierdo será el hijo izquierdo del árbol (i).

    Precondición : Tiene que tener hijo derecho no vacío. 
    */
    void rotar_izquierda( Vertice<Llave,Dato> *&vertice){    

        Vertice<Llave,Dato> *aux = vertice;
        
        vertice = vertice->derecho; //El nodo principal sera el de la derecha
        vertice->padre = aux->padre;//Su padre sera el que tenia antes el vertice

        vertice->izquierdo = aux;
        vertice->izquierdo->padre = vertice;
        aux->derecho = nullptr;
        
    }
    void rotar_derecha( Vertice<Llave,Dato> *&vertice){
        
        Vertice<Llave,Dato> *aux = vertice;

        vertice = vertice->izquierdo; //El nodo principal sera el de la izquierda
        vertice->padre = aux->padre;//Su padre sera el que tenia antes el vertice

        vertice->derecho = aux;
        vertice->derecho->padre = vertice;
        aux->izquierdo = nullptr;  

    }

    void aux_obtener_altura(Vertice<Llave,Dato> *vertice, int altura_cambiante , int &altura_salida)
    {
        if(!esta_vacio(vertice)){
            if(vertice->izquierdo!=nullptr) aux_obtener_altura(vertice->izquierdo, altura_cambiante+1, altura_salida);
            if(vertice->derecho!= nullptr ) aux_obtener_altura(vertice->derecho  , altura_cambiante+1, altura_salida);
            if(es_hoja(vertice) && altura_cambiante > altura_salida) altura_salida = altura_cambiante;
        }    
    }
    bool esta_vacio(Vertice<Llave,Dato> *vertice){
        return vertice==nullptr;
    }
    public: 
        Arbol_B(){
            raiz = nullptr;
        }
        ~Arbol_B(){
            borrar(raiz);
        }
        void borrar(Vertice<Llave,Dato> *vertice){

            if (vertice != nullptr)
            {
                borrar(vertice->izquierdo);
                borrar(vertice->derecho);
                delete vertice;
            }
        }
        Dato& buscar(Llave llave, int (*comparar_llaves)(Llave A , Llave B)){
            
            Vertice<Llave,Dato> *anterior=nullptr;
            Vertice<Llave,Dato> *recorrido = raiz;
            bool encontrado = false;
            
            while(recorrido!= nullptr && !encontrado){

                anterior = recorrido;

                if(comparar_llaves( llave, *(recorrido->llave)) == IGUAL)
                    encontrado=true;
                else if(comparar_llaves( llave , *(recorrido->llave)) == PEQUENO)
                    recorrido = recorrido->izquierdo;
                else
                    recorrido = recorrido->derecho;
            }
            if(esta_vacio(raiz)){
                raiz = new Vertice<Llave,Dato>(llave,nullptr);
                return *(raiz->dato);
            }
            else if(encontrado)
                return *(anterior->dato);
            else if(comparar_llaves(llave,*(anterior->llave))==PEQUENO){
                anterior->izquierdo = new Vertice<Llave,Dato>(llave,anterior);
                asignar_factor_equilibrio(raiz);
                balancear();
                return *(anterior->izquierdo->dato);
            }
            else{
                anterior->derecho = new Vertice<Llave,Dato>(llave,anterior);
                asignar_factor_equilibrio(raiz);
                balancear();
                return *(anterior->derecho->dato);
            }
        }
        Vertice<Llave,Dato>* obtener_arbol(){
            return raiz;
        }
        int obtener_altura(Vertice<Llave,Dato> *vertice){
            int altura=0;
            aux_obtener_altura(vertice,0,altura);
            return altura;
        }
        int obtener_factor_equilibrio(Vertice<Llave,Dato> *vertice){
            int altura_derecha=0, altura_izquierda=0;
            if(!esta_vacio(vertice)){
                altura_derecha   = obtener_altura(vertice->derecho);
                altura_izquierda = obtener_altura(vertice->izquierdo);
            }
            return altura_derecha-altura_izquierda;
        }
        
        bool es_hoja(Vertice<Llave,Dato> *vertice){
            return vertice->derecho==nullptr && vertice->izquierdo==nullptr;
        }
};

#endif