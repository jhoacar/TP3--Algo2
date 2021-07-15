#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "Arbol.h"

template < class Llave, class Dato>
class Diccionario{

    Arbol_B<Llave,Dato> arbol_binario;
    Lista<Llave> llaves;
    Lista<Dato> valores;
	unsigned long tamano;

    public:
        Diccionario(){
            
        }
        ~Diccionario(){

        }
        //Pre: Una llave a encontrar el dato, y una funcion de comparacion para el tipo de dato de la llave
        //Esta funcion debe devolver un numero entero que representa
        // 0 : son iguales
        // 1 : si el primer argumento es mayor al segundo
        // -1: si el primer argumento es menor al segundo 
        //Post: Si no encuentra la llave, crea un nuevo espacio y devuelve la referencia del dato donde se encontro
        Dato& buscar_dato(Llave llave, int (*comparar_llaves)(Llave A , Llave B)){
            return arbol_binario.buscar(llave,comparar_llaves);
        }
        //Pre: Una llave a encontrar el dato, el tipo de dato de la llave debera tener sobrecargado los operadores ==,> y <
        //Post: Si no encuentra la llave, crea un nuevo espacio y devuelve la referencia del dato donde se encontro
        Dato& operator[](const Llave llave){
            return buscar_dato(llave, comparacion);
        }
        

};

#endif