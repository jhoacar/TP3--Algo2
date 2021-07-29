#ifndef AVL_H
#define AVL_H

#include "Vertice.h"
#include "../Funciones.h"

#include <iostream>
using namespace std;

template <class Llave,class Dato>
class AVL{

    Vertice<Llave,Dato> *raiz;
    //Pre: Un vertice del arbol
    //Post: Recorre el arbol hasta el nivel 0, 
    //devuelve la primera coincidencia de vertice con factor de equilibrio (en valor absoluto) mayor a 1 
    Vertice<Llave,Dato>* obtener_pivote(Vertice<Llave,Dato> *vertice_origen);
    //Pre: Un vertice donde se comenzara a balancear
    //Post: Balancea el arbol acorde del vertice del parametro realizando sus correspondientes rotaciones
    void balancear(Vertice<Llave,Dato> *vertice_origen);
    //Pre: Un vertice con hijo derecho no vacio
    //Post: Realiza un giro a la izquierda correspondiente al AVL, conservando sus referencias de punteros
    void rotar_izquierda( Vertice<Llave,Dato> *&vertice);
    //Pre: Un vertice con hijo izquierdo no vacio
    //Post: Realiza un giro a la derecha correspondiente al AVL, conservando sus referencias de punteros
    void rotar_derecha( Vertice<Llave,Dato> *&vertice);
    //Pre: Un vertice a evaluar, una altura inicial, y una altura de salida
    //Post: Metodo recursivo encargado de encontrar la altura del vertice almacenandola en altura de salida
    void obtener_altura(Vertice<Llave,Dato> *vertice, int altura_cambiante , int &altura_salida);
    //Pre: Un vertice a evaluar
    //Post: Devuelve si no se encuentra nada en el vertice
    bool esta_vacio(Vertice<Llave,Dato> *vertice);
    //Pre: Un vertice a evaluar
    //Post: Devuelve si es un vertice hoja
    bool es_hoja(Vertice<Llave,Dato> *vertice);
    //Pre: Un vertice de partida
    //Post: Borra todo el subarbol apartir del vertice de partida
    void borrar(Vertice<Llave,Dato> *vertice);

    public:
        //Post: Construye un AVL 
        AVL();
        //Post: Elimina el AVL y su memoria reservada
        ~AVL();
        //Pre: Una llave a buscar, una variable booleana a cambiar y una funcion de comparacion
        //Esta funcion debe devolver un numero entero que representa
        // 0 : son iguales
        // 1 : si el primer argumento es mayor al segundo
        // -1: si el primer argumento es menor al segundo 
        //Post: Devuelve una referencia del dato donde fue encontrado, 
        //o una nueva en caso que no se encuentre la llave, cambiando a verdadero el valor de la variable booleana
        Dato& buscar(Llave llave,bool &se_agrego, int (*comparar_llaves)(Llave A , Llave B));
        //Post: Devuelve la raiz del AVL
        Vertice<Llave,Dato>* obtener_arbol();
        //Pre: Un vertice a evaluar
        //Post: Devuelve la altura del vertice
        int obtener_altura(Vertice<Llave,Dato> *vertice);
        //Pre: Un vertice a evaluar
        //Post: Devuelve la diferencia entre la altura del subarbol derecho con el izquierdo
        int obtener_factor_equilibrio(Vertice<Llave,Dato> *vertice);
        //Pre: Un vertice de partida y una lista donde almacenara la informacion
        //Post: Devuelve una lista en in-orden con las llaves del AVL
        void obtener_llaves(Vertice<Llave,Dato> *vertice , Lista<Llave> &llaves);
        //Pre: Un vertice de partida y una lista donde almacenara la informacion
        //Post: Devuelve una lista en in-orden con los valores del AVL
        void obtener_valores(Vertice<Llave,Dato> *vertice , Lista<Dato> &valores);
};

template <class Llave, class Dato>
AVL<Llave,Dato>::AVL(){
    raiz = nullptr;
}
template <class Llave, class Dato>
AVL<Llave,Dato>::~AVL(){
    borrar(raiz);
}
template <class Llave, class Dato>
void AVL<Llave,Dato>::borrar(Vertice<Llave,Dato> *vertice){

    if (vertice != nullptr)
    {
        borrar(vertice->izquierdo);
        borrar(vertice->derecho);
        delete vertice;
        vertice = nullptr;
    }
}
template <class Llave, class Dato>
Dato& AVL<Llave,Dato>::buscar(Llave llave,bool &se_agrego, int (*comparar_llaves)(Llave A , Llave B)){
    
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
        se_agrego=true;
        return *(raiz->dato);
    }
    else if(encontrado)
        return *(anterior->dato);
    else if(comparar_llaves(llave,*(anterior->llave))==PEQUENO){
        anterior->izquierdo = new Vertice<Llave,Dato>(llave,anterior);
        se_agrego=true;
        //balancear(anterior);
        return *(anterior->izquierdo->dato);
    }
    else{
        anterior->derecho = new Vertice<Llave,Dato>(llave,anterior);
        se_agrego=true;
        //balancear(anterior);
        return *(anterior->derecho->dato);
    }
}
template <class Llave, class Dato>
Vertice<Llave,Dato>* AVL<Llave,Dato>::obtener_arbol(){
    return raiz;
}
template <class Llave, class Dato>
int AVL<Llave,Dato>::obtener_altura(Vertice<Llave,Dato> *vertice){
    int altura=0;
    obtener_altura(vertice,0,altura);
    return altura;
}
template <class Llave, class Dato>
int AVL<Llave,Dato>::obtener_factor_equilibrio(Vertice<Llave,Dato> *vertice){
    int altura_derecha=0, altura_izquierda=0;
    if(!esta_vacio(vertice)){
        altura_derecha   = obtener_altura(vertice->derecho);
        altura_izquierda = obtener_altura(vertice->izquierdo);
    }
    return altura_derecha-altura_izquierda;
}
template <class Llave, class Dato>
void AVL<Llave,Dato>::obtener_llaves(Vertice<Llave,Dato> *vertice , Lista<Llave> &llaves){
    
    //Recorrido In-orden para insercion de llaves a la lista!
    if(!esta_vacio(vertice)){
        obtener_llaves(vertice->izquierdo,llaves);
        llaves.agregar(*(vertice->llave));
        obtener_llaves(vertice->derecho,llaves);
    }
}
template <class Llave, class Dato>
void AVL<Llave,Dato>::obtener_valores(Vertice<Llave,Dato> *vertice , Lista<Dato> &valores){
    
    //Recorrido In-orden para insercion de valores a la lista!
    if(!esta_vacio(vertice)){
        obtener_valores(vertice->izquierdo,valores);
        valores.agregar(*(vertice->dato));
        obtener_valores(vertice->derecho,valores);
    }
}

template <class Llave, class Dato>
Vertice<Llave,Dato>* AVL<Llave,Dato>::obtener_pivote(Vertice<Llave,Dato> *vertice_origen){
    
    if(!esta_vacio(vertice_origen)){
        
        if( valor_absoluto( obtener_factor_equilibrio(vertice_origen) ) > 1 )
            return vertice_origen;
        
        obtener_pivote(vertice_origen->padre);
    }
    return nullptr;
}

template <class Llave, class Dato>
void AVL<Llave,Dato>::balancear(Vertice<Llave,Dato> *vertice_origen){

    if(valor_absoluto(obtener_factor_equilibrio(raiz))<=1 )
        return;

    Vertice<Llave,Dato> *pivote = obtener_pivote(vertice_origen);

    if(esta_vacio(pivote))
        return;

    Vertice<Llave,Dato> *padre = pivote->padre;
    int factor_equilibrio = obtener_factor_equilibrio(pivote);
    
    int hijo_izquierdo = esta_vacio(padre) ? NO_ENCONTRADO : padre->izquierdo == pivote ;
    //Luego de realizar rotaciones el padre tendra un hijo nuevo, sea el derecho o el izquierdo.

    if( factor_equilibrio > 1 ){ 
        //Hay que hacer rotaciones hacia la izquierda, hay mas peso en el subarbol derecho

        if(esta_vacio(pivote->izquierdo) && esta_vacio(pivote->derecho->izquierdo))
            rotar_izquierda(pivote);

        else if(esta_vacio(pivote->izquierdo) && esta_vacio(pivote->derecho->derecho)){
            rotar_derecha(pivote->derecho);
            rotar_izquierda(pivote);
        }
    }
    else if( factor_equilibrio < -1){
        //Hay que hacer rotaciones hacia la derecha, hay mas peso en el subarbol izquierdo

        if(esta_vacio(pivote->derecho) && esta_vacio(pivote->izquierdo->derecho))
            rotar_derecha(pivote);

        else if(esta_vacio(pivote->derecho) && esta_vacio(pivote->izquierdo->izquierdo)){
            rotar_izquierda(pivote->izquierdo);
            rotar_derecha(pivote);
        }
    }
    if(hijo_izquierdo!=NO_ENCONTRADO){

        if(hijo_izquierdo)
            padre->izquierdo = pivote;
        else   
            padre->derecho = pivote;
    }
}

template <class Llave, class Dato>
void AVL<Llave,Dato>::rotar_izquierda( Vertice<Llave,Dato> *&vertice){    

    Vertice<Llave,Dato> *aux = vertice;
    
    vertice = vertice->derecho; //El nodo principal sera el de la derecha
    vertice->padre = aux->padre;//Su padre sera el que tenia antes el vertice

    vertice->izquierdo = aux;
    vertice->izquierdo->padre = vertice;
    aux->derecho = nullptr;
    
}

template <class Llave, class Dato>
void AVL<Llave,Dato>::rotar_derecha( Vertice<Llave,Dato> *&vertice){
    
    Vertice<Llave,Dato> *aux = vertice;

    vertice = vertice->izquierdo; //El nodo principal sera el de la izquierda
    vertice->padre = aux->padre;//Su padre sera el que tenia antes el vertice

    vertice->derecho = aux;
    vertice->derecho->padre = vertice;
    aux->izquierdo = nullptr;  

}

template <class Llave, class Dato>
void AVL<Llave,Dato>::obtener_altura(Vertice<Llave,Dato> *vertice, int altura_cambiante , int &altura_salida)
{
    if(!esta_vacio(vertice)){
        if(vertice->izquierdo!=nullptr) obtener_altura(vertice->izquierdo, altura_cambiante+1, altura_salida);
        if(vertice->derecho!= nullptr ) obtener_altura(vertice->derecho  , altura_cambiante+1, altura_salida);
        if(es_hoja(vertice) && altura_cambiante > altura_salida) altura_salida = altura_cambiante;
    }    
}

template <class Llave, class Dato>
bool AVL<Llave,Dato>::esta_vacio(Vertice<Llave,Dato> *vertice){
    return vertice==nullptr;
}

template <class Llave, class Dato>
bool AVL<Llave,Dato>::es_hoja(Vertice<Llave,Dato> *vertice){
    return vertice->izquierdo ==nullptr && vertice->derecho == nullptr;
}


#endif