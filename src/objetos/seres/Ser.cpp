#include "Ser.h"

#include <iostream>

Ser::Ser():Objeto(){

}

Ser::Ser(Casilla *casilla,char nombre, string ID):Objeto(casilla,nombre,ID){
    this -> armadura = obtener_numero_aleatorio(ARMADURA_MINIMA, ARMADURA_MAXIMA);
    this -> vida     = obtener_numero_aleatorio(VIDA_MINIMA, VIDA_MAXIMA);
    this -> energia  = obtener_numero_aleatorio(ENERGIA_MINIMA, ENERGIA_MAXIMA);
    this -> fuerza   = obtener_numero_aleatorio(FUERZA_MINIMA, FUERZA_MAXIMA);
}
Ser::~Ser(){
}

int Ser::devolver_armadura() {
    return this -> armadura;
}

int Ser::devolver_energia() {
    return this -> energia;
}

int Ser::devolver_fuerza(){
    return this -> fuerza;
}

int Ser::devolver_vida(){
    return this -> vida;
}


bool es_elemento(Objeto* objeto_a_comprobar) {

    return buscar_dato(NOMBRES_CHAR, MAX_NOMBRES,objeto_a_comprobar->obtener_nombre(),HUMANO) == NO_ENCONTRADO;
}