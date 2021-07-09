#include "Ser.h"

#include <iostream>

Ser::Ser():Objeto(){

}

Ser::Ser(Coordenada posicion,char nombre):Objeto(posicion,nombre){
    this -> armadura = asignar_numero_random(VALORES_ARMADURA[TOPE_INFERIOR], VALORES_ARMADURA[TOPE_SUPERIOR]);
    this -> vida = asignar_numero_random(VALORES_VIDA[TOPE_INFERIOR], VALORES_VIDA[TOPE_SUPERIOR]);
    this -> energia = asignar_numero_random(VALORES_ENERGIA[TOPE_INFERIOR], VALORES_ENERGIA[TOPE_SUPERIOR]);
    this -> fuerza = asignar_numero_random(VALORES_FUERZA[TOPE_INFERIOR], VALORES_FUERZA[TOPE_SUPERIOR]);

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
