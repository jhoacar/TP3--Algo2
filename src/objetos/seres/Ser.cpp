#include "Ser.h"

#include <iostream>

Ser::Ser():Objeto(){

}

Ser::Ser(Casilla *casilla,char nombre):Objeto(casilla,nombre){
    this -> armadura = obtener_numero_aleatorio(VALORES_ARMADURA[TOPE_INFERIOR], VALORES_ARMADURA[TOPE_SUPERIOR]);
    this -> vida     = obtener_numero_aleatorio(VALORES_VIDA[TOPE_INFERIOR], VALORES_VIDA[TOPE_SUPERIOR]);
    this -> energia  = obtener_numero_aleatorio(VALORES_ENERGIA[TOPE_INFERIOR], VALORES_ENERGIA[TOPE_SUPERIOR]);
    this -> fuerza   = obtener_numero_aleatorio(VALORES_FUERZA[TOPE_INFERIOR], VALORES_FUERZA[TOPE_SUPERIOR]);
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
