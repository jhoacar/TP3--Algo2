#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

#include "Vertice.h"
#include "Lista.h"

#include <iostream>
using namespace std;

template <class Llave,class Dato>
class Arbol_B{

    Vertice<Llave,Dato> *raiz;

    int obtener_pivote(Vertice<Llave,Dato> *&pivote){


    }

    void balancear(){

        Vertice<Llave,Dato> *pivote;
        int equilibrio = obtener_pivote(pivote);
        
        Vertice<Llave,Dato> *padre = pivote->padre;
        int hijo_izquierdo = esta_vacio(padre) ? NO_ENCONTRADO : padre->izquierdo == pivote;
        
        if(equilibrio > 1 ){
            
            rotar_izquierda();
        }
        if(equilibrio < -1){
            //rotar_derecha();
        }

        if(hijo_izquierdo!=NO_ENCONTRADO){
            if(hijo_izquierdo)
                padre->izquierdo = pivote;
            else   
                padre->derecho = pivote;
        }
    }
    void rotar_izquierda( Vertice<Llave,Dato> *&vertice){
        
        Vertice<Llave,Dato> *aux = vertice->izquierdo->derecho;
	    vertice->izquierdo->derecho = vertice;

	    Vertice<Llave,Dato> *aux2 = vertice->izquierdo;
	    vertice->izquierdo = aux;

	    vertice = aux2;   
    }
    void rotar_derecha( Vertice<Llave,Dato> *&vertice){
        
        Vertice<Llave,Dato> *aux = vertice->derecho->izquierdo;
	    vertice->derecho->izquierdo = vertice;
	    
        Vertice<Llave,Dato> *aux2 = vertice->derecho;
	    vertice->derecho = aux;
	    
        vertice = aux2;
    }
    void rotar_izquierda_derecha(Vertice<Llave,Dato> *&vertice){ //precond: el árbol necesita una rotacion LR
	    rotar_derecha(vertice->izquierdo);
	    rotar_izquierda(vertice);
    }

    void rotar_derecha_izquierda(Vertice<Llave,Dato> *&vertice){ //precond: el árbol necesita una rotacion RL
	    rotar_izquierda(vertice->derecho);
	    rotar_derecha(vertice);
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
            if(raiz==nullptr){
                raiz = new Vertice<Llave,Dato>(llave,nullptr);
                return *(raiz->dato);
            }
            else if(encontrado)
                return *(anterior->dato);
            else if(comparar_llaves(llave,*(anterior->llave))==PEQUENO){
                anterior->izquierdo = new Vertice<Llave,Dato>(llave,anterior);
                balancear();
                return *(anterior->izquierdo->dato);
            }
            else{
                anterior->derecho = new Vertice<Llave,Dato>(llave,anterior);
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
                aux_obtener_altura(vertice->derecho,0,altura_derecha);
                aux_obtener_altura(vertice->izquierdo,0,altura_izquierda);
            }
            return altura_derecha-altura_izquierda;
        }
        
        bool es_hoja(Vertice<Llave,Dato> *vertice){
            return vertice->derecho==nullptr && vertice->izquierdo==nullptr;
        }
};

#endif